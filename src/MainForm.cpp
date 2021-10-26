#include <math.h>
#include "stdafx.h"
#include "MainForm.h"
#include "process.h"
#include "memory.h"
#include "addresses.h"
#include "logger.h"
#include "util.h"
#include "hooks.h"
#include "internalfuncs.h"

using namespace dcsstrainer;
using namespace System;

// forward declarations
void set_stat(Windows::Forms::TextBox^ text, uintptr_t addy);
void set_skill(Windows::Forms::TextBox^ param, uintptr_t addy);
void set_gold(Windows::Forms::TextBox^ param, uintptr_t addy);
void set_piety(Windows::Forms::TextBox^ param, uintptr_t addy);

// globals
static HMODULE hModule;
static bool isAttached = false, autoIdentify = false, oneHP = false, freeze = false, sleep = false;
static bool maxItems = false, magicMap = false, maxCharges = false, allyMaxSpeed = false, convertToAlly = false;;

static unsigned int maxMutVal = 3;
static unsigned int medMutVal = 2;
static unsigned int minMutVal = 1;
static unsigned int noMutVal = 0;

[STAThread]
DWORD APIENTRY Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm());
	Application::Exit();
	return 0;
}


// needed to tell complier this is unmanaged code, otherwise your DLL will not inject.
#pragma unmanaged
BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved) {

	hModule = hModule;
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Main, NULL, 0, NULL));
		break;
	case DLL_PROCESS_DETACH:
		FreeLibraryAndExitThread(hModule, 0);
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	default:
		break;
	}
	return TRUE;
}

#pragma managed
/* should optimize this but meh */
void MainForm::GUITimer_Tick(System::Object^ sender, System::EventArgs^ e) {

	attached->Text = "Active!";
	attached->ForeColor = System::Drawing::Color::DarkGreen;

	if (allyMaxSpeed) {
		uintptr_t spd = 99;
		mem::AllyPatch((uintptr_t*)moduleBase, &spd, 1, envAddrs::speedOffset);
	}

	if (convertToAlly) {
		uintptr_t a = 4;
		uintptr_t mask = 0x00;
		mem::EntityPatch((uintptr_t*)moduleBase, &a, 1, envAddrs::allyOffset);
		/* after we convert, we need to wake them up as a possible edge case */
		mem::AllyPatch((uintptr_t*)moduleBase, &statusMasks::nomask, 4, envAddrs::statusOffset);
		mem::AllyPatch((uintptr_t*)moduleBase, &mask, 1, envAddrs::sleepOffset);
	}

	// each call requires two virtualprotect calls. can be sped up if we just called once for all hacks
	if (autoIdentify) {
		mem::PatchItemFlag((uintptr_t*)moduleBase, &itemFlags::identMask);
	}

	if (oneHP) {
		uintptr_t hp = 1;
		mem::EntityPatch((uintptr_t*)moduleBase, &hp, 4, envAddrs::hpOffset);
	}

	if (freeze) {
		// this works but to undo it, you need to keep pointers to alive enemies
		// uintptr_t speed = 0;
		// mem::EntityPatch((uintptr_t*)moduleBase, &speed, 4, envAddrs::speedOffset, process);
		mem::EntityPatch((uintptr_t*)moduleBase, &statusMasks::petrify, 4, envAddrs::statusOffset);
	}
	else {
		mem::EntityPatch((uintptr_t*)moduleBase, &statusMasks::nomask, 4, envAddrs::statusOffset);
	}

	if (sleep) {
		uintptr_t mask = 0x02;
		mem::EntityPatch((uintptr_t*)moduleBase, &mask, 1, envAddrs::sleepOffset);
	}
	else {
		uintptr_t mask = 0x00;
		mem::EntityPatch((uintptr_t*)moduleBase, &mask, 1, envAddrs::sleepOffset);
	}

	if (maxItems) {
		// this is written in little endian format
		char arr[2] = { 0x00, 0x7F };
		mem::InventoryPatch((uintptr_t*)moduleBase, (uintptr_t*)arr, 2, inventoryAddrs::numItemsOffset);
	}

	if (maxCharges) {
		char arr[2] = { 0x00, 0x7F };
		mem::WandChargePatch((uintptr_t*)moduleBase, (uintptr_t*)arr, 2, inventoryAddrs::numChargeOffset);
	}


	 
}

void MainForm::checkBox108_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->allymaxspd->Checked) {
		allyMaxSpeed = true;
		logger::WriteLinetoConsole("Setting ally speed to maximum.");
	}
	else {
		allyMaxSpeed = false;
	}
}

void MainForm::checkBox109_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->convertally->Checked) {
		convertToAlly = true;
		logger::WriteLinetoConsole("Converting all monsters to allies.");
	}
	else {
		convertToAlly = false;
	}
}

void MainForm::minmovspd_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->minmovspd->Checked) {
		mem::Patch((uintptr_t*)(moduleBase + minMovementSpeedAddy), (uintptr_t*)"\xB8\x01\x00\x00\x00\x90\x90\x90", 8);
		logger::WriteLinetoConsole("Movements now take 0.1 of a turn.");
	}
	else {
		mem::Patch((uintptr_t*)(moduleBase + minMovementSpeedAddy), (uintptr_t*)"\xB8\x06\x00\x00\x00\x0F\x4D\xC3", 8);
		logger::WriteLinetoConsole("Restoring movement speed to normal.");
	}
}

void MainForm::maxcharge_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->maxcharge->Checked) {
		maxCharges = true;
		logger::WriteLinetoConsole("Setting wand charges to a huge number.");
	}
	else {
		maxCharges = false;
	}
}

void MainForm::acqui_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->acqui->Checked) {
		// at 50, 32
		// ok, the function calls, but the gui is fucked up
		// gonna disable this for now until i can figure out the TIB discrepancies between this thread and crawl's
		// check out the fs moving thing
		Sleep(2000);
		acquirement();
	}
}

void MainForm::mmapping_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->mmapping->Checked) {
		hooks::Hook(moduleBase, hookMapChangeAddy, hooks::MapChange, 6);
		hooks::Hook(moduleBase, updateTickAddy, hooks::ApplyMapChange, 7);
		logger::WriteLinetoConsole("Activated auto-magic mapping.");
	}
	else {
		// crawl-tiles.exe+58B7DC - 8B 85 A4FEFFFF        - mov eax,[ebp-0000015C]
		mem::Patch((uintptr_t*)(moduleBase + hookMapChangeAddy), (uintptr_t*)"\x8B\x85\xA4\xFE\xFF\xFF", 6);
		// crawl - tiles.exe + 6D60E9 - C7 04 24  01000000 - mov[esp], 00000001 { 1 }
		mem::Patch((uintptr_t*)(moduleBase + updateTickAddy), (uintptr_t*)"\xC7\x04\x24\x01\x00\x00\x00", 7);
		logger::WriteLinetoConsole("Deactivated auto-magic mapping.");
	}
}

//change this to a button
// 
void MainForm::maxitems_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->maxitems->Checked) {
		maxItems = true;
		logger::WriteLinetoConsole("Setting items to a huge number.");
	}
	else {
		maxItems = false;
		logger::WriteLinetoConsole("Might undo in the future. Not now tho...");
	}
}

// permasleep
void MainForm::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->permasleep->Checked) {
		sleep = true;
		logger::WriteLinetoConsole("Putting monsters to sleep.");
	}
	else {
		sleep = false;
		logger::WriteLinetoConsole("Waking monsters up.");
	}
}

void MainForm::instakill_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->instakill->Checked) {
		//instakillRetAddy = moduleBase + instakillAddy + 7;
		hooks::Hook(moduleBase, instakillAddy, hooks::instakill, 7);
		logger::WriteLinetoConsole("Enabled instakill.");
	}
	else {
		//crawl - tiles.exe + 43FE3B - 29 F0 - sub eax, esi
		//crawl - tiles.exe + 43FE3D - 39 D0 - cmp eax, edx
		//crawl - tiles.exe + 43FE3F - 89 43 54 - mov[ebx + 54], eax

		mem::Patch((uintptr_t*)(moduleBase + instakillAddy), (uintptr_t*)"\x29\xF0\x39\xD0\x89\x43\x54", 7);
		logger::WriteLinetoConsole("Disabled instakill.");
	}
}

// hook the x and y moves, disable them
void MainForm::disablemovement_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->disablemovement->Checked) {
		// overwriting 8 bytes
		hooks::Hook(moduleBase, disablexAddy, hooks::disableX, 8);
		hooks::Hook(moduleBase, disableyAddy, hooks::disableY, 6);
		logger::WriteLinetoConsole("Disabled enemy movement. They can still attack you tho!");
	}
	else {
		//crawl - tiles.exe + A53BB9 - 03 10 - add edx, [eax]
		//crawl - tiles.exe + A53BBB - 8B 85 60FFFFFF - mov eax, [ebp - 000000A0]
		mem::Patch((uintptr_t*) (moduleBase + disablexAddy), (uintptr_t*)"\x03\x10\x8B\x85\x60\xFF\xFF\xFF", 8);
		//crawl - tiles.exe + A53BC4 - 03 43 04 - add eax, [ebx + 04]
		//crawl - tiles.exe + A53BC7 - 8D 4A FF - lea ecx, [edx - 01]
		mem::Patch((uintptr_t*) (moduleBase + disableyAddy), (uintptr_t*)"\x03\x43\x04\x8D\x4A\xFF", 6);
		logger::WriteLinetoConsole("Enabled enemy movement.");

	}
}



// start setting flags
void MainForm::idinven_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->idinven->Checked) {
		autoIdentify = true;
		logger::WriteLinetoConsole("Activated automatic inventory item identification.");
	}
		
	else {
		autoIdentify = false;
		logger::WriteLinetoConsole("Deactivated automatic inventory item identification.");
	}
}

// set to 1 hp
void MainForm::onehp_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->onehp->Checked) {
		oneHP = true;
		logger::WriteLinetoConsole("Activated One HP monsters.");
	}
	else {
		oneHP = false;
		logger::WriteLinetoConsole("Deactivated One HP monsters.");
	}
}

// monster freeze
// resets when you change map
// should keep track of old speeds 
void MainForm::mfreeze_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->mfreeze->Checked) {
		freeze = true;
		logger::WriteLinetoConsole("Activated monster freeze.");
	}
	else {
		freeze = false;
		logger::WriteLinetoConsole("Deactivated monster freeze.");
	}
}

//godmode
void MainForm::godmode_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->godmode->Checked) {
		mem::Nop((uintptr_t*) (moduleBase + godModeAddy), 2);//, process);
		logger::WriteLinetoConsole("Activated godmode.");
	}
		
	else {
		// sub eax, ebx
		mem::Patch((uintptr_t*) (moduleBase + godModeAddy), (uintptr_t*)"\x29\xD8", 2);
		logger::WriteLinetoConsole("Deactivated godmode.");
	}
		

}

// infinite mana
void MainForm::infinitemana_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->infinitemana->Checked) {
		mem::Nop((uintptr_t*) (moduleBase + infiniteManaAddy), 5);//, process);
		logger::WriteLinetoConsole("Activated infinite mana.");
	}
		
	else {
		// 29 D8 - sub eax, ebx
		// 0F 48 C2 - cmovs eax, edx
		mem::Patch((uintptr_t*) (moduleBase + infiniteManaAddy), (uintptr_t*)"\x29\xD8\x0F\x48\xC2", 5);
		logger::WriteLinetoConsole("Deactivated infinite mana.");
	}


}

// no hunger
void MainForm::nohunger_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	// 29 D8 - sub eax, ebx
	// 0F48 C2 - cmovs eax, edx 
	// this is moving the subtracted value only if the hunger value was subtracted (cmovs is move if sign, 48 is the negative flavor)
	if (this->nohunger->Checked) {
		mem::Nop((uintptr_t*) (moduleBase + noHungerAddy), 5);//, process);
		logger::WriteLinetoConsole("Activated no hunger.");
	}
		
	else {
		mem::Patch((uintptr_t*) (moduleBase + noHungerAddy), (uintptr_t*)"\x29\xD8\x0F\x48\xC2", 5);
		logger::WriteLinetoConsole("Deactivated no hunger.");
	}
		
}

void set_stat(Windows::Forms::TextBox^ param, uintptr_t addy) {

	// check if empty
	if (param->Text == "") {
		uintptr_t chr[1] = { 0 };
		
		mem::Read((uintptr_t*)(moduleBase + addy), chr, 1);
		param->Text = Convert::ToString(Convert::ToByte(*chr));
		return;
	}
	// if not, check if converts
	try {
		BYTE stat = Convert::ToByte(param->Text);
		// setting global to the new value
		mem::Patch((uintptr_t*) (moduleBase + addy), (uintptr_t*) &stat, 1);
	
	}
	catch (Exception^) {
		uintptr_t chr[1] = { 0 };
		mem::Read((uintptr_t*) (moduleBase + addy), chr, 1);
		param->Text = Convert::ToString(Convert::ToByte(*chr));
	}
	
}

// called when skill is empty or an exception occured.
// sets value of skill to one found in memory.
void set_empty_skill(Windows::Forms::TextBox^ param, uintptr_t addy) {

	float closestLevel = 27;
	uintptr_t chr[2] = { 0, 0 };
	short read_exp;

	mem::Read((uintptr_t*)(moduleBase + addy), chr, 2);
	read_exp = Convert::ToInt16(*chr);

	// get level rounded up
	for (const auto& exp : exptoLevel) {
		short expdiff = exp.first - read_exp;
		if (expdiff > 0 && exp.second < closestLevel) {
			closestLevel = exp.second;
		}
	}

	// round down
	closestLevel = closestLevel - 1;

	// find difference
	short normalizer = leveltoEXP.at(closestLevel + 1) - leveltoEXP.at(closestLevel);
	closestLevel += round((float)(read_exp - leveltoEXP.at(closestLevel)) / normalizer, 1);
	param->Text = Convert::ToString(closestLevel);

}

// set skill values
void set_skill(Windows::Forms::TextBox^ param, uintptr_t addy) {
	// user will enter a float from 0.0 to 27.0
	// convert to exp, then patch a short
	// todo: deal with class skill modifiers

	// if empty
	if (param->Text == "") {
		set_empty_skill(param, addy);
		return;
	}

	// else apply user input
	try {
		float rawLevel = (float)Convert::ToDecimal(param->Text);
		short roundedLevel = trunc(rawLevel);
		if (roundedLevel < 27) {
			// if negative, just ignore the user
			if (roundedLevel < 0) {
				throw;
			}
			// add remaining exp
			short actualEXP = leveltoEXP.at((int)roundedLevel) + (rawLevel - roundedLevel) * (leveltoEXP.at(roundedLevel + 1) - leveltoEXP.at(roundedLevel));
			mem::Patch((uintptr_t*)(moduleBase + addy), (uintptr_t*) &actualEXP, 2);
		}
		else {
			mem::Patch((uintptr_t*)(moduleBase + addy), (uintptr_t*) &leveltoEXP.at(27), 2);
		}
	}
	catch (Exception^) {
		set_empty_skill(param, addy);
	}

}

void set_empty_gp(Windows::Forms::TextBox^ param, uintptr_t addy, unsigned int n) {
	unsigned char * buffer = new unsigned char[n];
	mem::Read((uintptr_t*)(moduleBase + addy), (uintptr_t*)buffer, n);
	param->Text = Convert::ToString(*buffer);
	delete[] buffer;
}

/* set gold value */
void set_gold(Windows::Forms::TextBox^ param, uintptr_t addy) {

	if (param->Text == "") {
		set_empty_gp(param, addy, 4);
		return;
	}

	try {
		int gold = (int) Convert::ToDecimal(param->Text);
		mem::Patch((uintptr_t*)(moduleBase + addy), (uintptr_t*)&gold, 4);
	}
	catch (Exception^) {
		set_empty_gp(param, addy, 4);
	}

}

/* set piety value */
void set_piety(Windows::Forms::TextBox^ param, uintptr_t addy) {

	if (param->Text == "") {
		set_empty_gp(param, addy, 1);
		return;
	}

	try {
		unsigned char piety = (unsigned char)Convert::ToByte(param->Text);
		mem::Patch((uintptr_t*)(moduleBase + addy), (uintptr_t*)&piety, 1);
	}
	catch (Exception^) {
		set_empty_gp(param, addy, 1);
	}

}

void MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {

	// apply gold
	set_gold(this->gold, goldAddy);

	// apply piety
	set_piety(this->piety, pietyAddy);

	// Apply stats
	set_stat(this->intelligence, intAddy);
	set_stat(this->dexterity, dexAddy);
	set_stat(this->strength, strAddy);
	
	// apply skills
	set_skill(this->fighting, fightingAddy);
	set_skill(this->shortblades, sBladeAddy);
	set_skill(this->longblades, lBladeAddy);
	set_skill(this->maces, maceAddy);
	set_skill(this->axes, axeAddy);
	set_skill(this->polearms, polearmAddy);
	set_skill(this->staves, stavesAddy);
	set_skill(this->unarmedcombat, unarmedAddy);
	set_skill(this->bows, bowsAddy);
	set_skill(this->crossbows, xbowAddy);
	set_skill(this->throwing, throwingAddy);
	set_skill(this->slings, slingsAddy);
	set_skill(this->armour, armourAddy);
	set_skill(this->dodging, dodgingAddy);
	set_skill(this->shields, shieldsAddy);
	set_skill(this->spellcasting, spellcastingAddy);
	set_skill(this->conjurations, conjurationAddy);
	set_skill(this->hexes, hexesAddy);
	set_skill(this->charms, charmsAddy);
	set_skill(this->summonings, summoningAddy);
	set_skill(this->necromancy, necromancyAddy);
	set_skill(this->translocations, translocationsAddy);
	set_skill(this->transmutations, transmutationAddy);
	set_skill(this->firemagic, fireMagicAddy);
	set_skill(this->icemagic, iceMagicAddy);
	set_skill(this->airmagic, airMagicAddy);
	set_skill(this->earthmagic, earthMagicAddy);
	set_skill(this->poisonmagic, poisonMagicAddy);
	set_skill(this->invocations, invocationsAddy);
	set_skill(this->evocations, evocationsAddy);
	set_skill(this->stealth, stealthAddy);

	logger::WriteLinetoConsole("Refreshed / updated a bunch of values.");

}

void set_mutation(Windows::Forms::TextBox^ param, uintptr_t addy) {

}

/* absolute mutation hell oof */
void MainForm::checkBox60_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox60->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::foulStench), &medMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::foulStench), &noMutVal, 1);
}

void MainForm::checkBox42_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox42->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rElec), &minMutVal, 1);
	else 
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rElec), &noMutVal, 1);
}
																					   
void MainForm::checkBox43_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox43->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::shaggyFur), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::shaggyFur), &noMutVal, 1);
}

void MainForm::checkBox44_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox44->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::saprovore), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::saprovore), &noMutVal, 1);
}

void MainForm::checkBox45_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox45->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::robust), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::robust), &noMutVal, 1);
}

void MainForm::checkBox46_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox46->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::regen), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::regen), &noMutVal, 1);
}

void MainForm::checkBox47_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox47->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::poweredByPain), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::poweredByPain), &noMutVal, 1);
}

void MainForm::checkBox48_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox48->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::poweredByDeath), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::poweredByDeath), &noMutVal, 1);
}

void MainForm::checkBox49_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox49->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rPois), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rPois), &noMutVal, 1);
}

void MainForm::checkBox50_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox50->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::senseSurroundings), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::senseSurroundings), &noMutVal, 1);
}

void MainForm::checkBox51_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox51->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::passiveFreeze), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::passiveFreeze), &noMutVal, 1);
}

void MainForm::checkBox52_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox52->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::nightstalker), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::nightstalker), &noMutVal, 1);
}

void MainForm::checkBox53_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox53->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rNeg), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rNeg), &noMutVal, 1);
}

void MainForm::checkBox54_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox54->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::mutationResist), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::mutationResist), &noMutVal, 1);
}

void MainForm::checkBox55_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox55->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::MR), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::MR), &noMutVal, 1);
}

void MainForm::checkBox56_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox56->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::igniteBlood), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::igniteBlood), &noMutVal, 1);
}

void MainForm::checkBox57_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox57->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::icemail), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::icemail), &noMutVal, 1);
}

void MainForm::checkBox58_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox58->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::highMP), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::highMP), &noMutVal, 1);
}

void MainForm::checkBox59_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox59->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::gourmand), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::gourmand), &noMutVal, 1);
}

void MainForm::checkBox41_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox41->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::slowMetabolism), &medMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::slowMetabolism), &noMutVal, 1);
}

void MainForm::checkBox75_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox75->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::tormentResist), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::tormentResist), &noMutVal, 1);
}

void MainForm::checkBox97_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox97->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::sanguineArmor), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::sanguineArmor), &noMutVal, 1);
}

void MainForm::checkBox82_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox82->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::sturdyFrame), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::sturdyFrame), &noMutVal, 1);
}

void MainForm::checkBox83_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox83->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::blackMark), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::blackMark), &noMutVal, 1);
}

void MainForm::checkBox84_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox84->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::fuming), &medMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::fuming), &noMutVal, 1);
}

void MainForm::checkBox85_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox85->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::magicLink), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::magicLink), &noMutVal, 1);
}

void MainForm::checkBox86_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox86->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::strongNose), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::strongNose), &noMutVal, 1);
}

void MainForm::checkBox87_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox87->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::flameCloudImmunity), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::flameCloudImmunity), &noMutVal, 1);
}

void MainForm::checkBox88_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox88->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::antimagicBite), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::antimagicBite), &noMutVal, 1);
}

void MainForm::checkBox89_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox89->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::cling), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::cling), &noMutVal, 1);
}

void MainForm::checkBox90_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox90->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::magicRegen), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::magicRegen), &noMutVal, 1);
}

void MainForm::checkBox91_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox91->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::strongLegs), &medMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::strongLegs), &noMutVal, 1);
}

void MainForm::checkBox92_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox92->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::freezingCloudImmunity), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::freezingCloudImmunity), &noMutVal, 1);
}

void MainForm::checkBox93_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox93->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::exoskeleton), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::exoskeleton), &noMutVal, 1);
}

void MainForm::checkBox94_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox94->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rTrample), &minMutVal, 1);

	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rTrample), &noMutVal, 1);
}

void MainForm::checkBox95_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox95->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::magicShield), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::magicShield), &noMutVal, 1);
}

void MainForm::checkBox96_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox96->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::constrict), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::constrict), &noMutVal, 1);
}

void MainForm::checkBox81_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox81->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::acidResist), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::acidResist), &noMutVal, 1);
}

void MainForm::checkBox98_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox98->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rotImmunity), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rotImmunity), &noMutVal, 1);
}

void MainForm::checkBox99_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox99->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::jump), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::jump), &noMutVal, 1);
}

void MainForm::checkBox100_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox100->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rPetr), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rPetr), &noMutVal, 1);
}

void MainForm::absorbingjelly_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox61->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::jellyAbsorbMissle), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::jellyAbsorbMissle), &noMutVal, 1);
}

void MainForm::sensingjelly_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox62->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::jellySensing), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::jellySensing), &noMutVal, 1);
}

void MainForm::tendrils_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox63->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::tendrils), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::tendrils), &noMutVal, 1);
}

void MainForm::augmentation_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox64->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::augmentation), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::augmentation), &noMutVal, 1);
}

void MainForm::Evolution_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox65->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::evolution), &medMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::evolution), &noMutVal, 1);
}

void MainForm::checkBox66_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox66->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::translucentSkin), &maxMutVal, 1);

	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::translucentSkin), &noMutVal, 1);
}

void MainForm::checkBox67_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox67->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::pseudopods), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::pseudopods), &noMutVal, 1);
}

void MainForm::checkBox68_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox68->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::gelatinousBody), &maxMutVal, 1);

	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::gelatinousBody), &noMutVal, 1);
}

void MainForm::checkBox69_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox69->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::spawnJellies), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::spawnJellies), &noMutVal, 1);
}

void MainForm::checkBox70_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox70->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::eyeballs), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::eyeballs), &noMutVal, 1);
}

void MainForm::checkBox71_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox71->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::acidicBite), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::acidicBite), &noMutVal, 1);
}

void MainForm::checkBox72_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox72->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::unbreathing), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::unbreathing), &noMutVal, 1);
}

void MainForm::checkBox73_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox73->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::wildMagic), &maxMutVal, 1);

	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::wildMagic), &noMutVal, 1);
}

void MainForm::checkBox74_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox74->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::toughSkin), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::toughSkin), &noMutVal, 1);
}

void MainForm::checkBox76_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox76->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::strongButStiff), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::strongButStiff), &noMutVal, 1);
}

void MainForm::checkBox77_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox77->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::strong), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::strong), &noMutVal, 1);
}

void MainForm::checkBox78_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox78->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rTorm), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rTorm), &noMutVal, 1);
}

void MainForm::checkBox79_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox79->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::spitPoison), &medMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::spitPoison), &noMutVal, 1);
}

void MainForm::checkBox80_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox80->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::spitPoison), &medMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::spitPoison), &noMutVal, 1);
}

void MainForm::checkBox31_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox31->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::flexibleWeak), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::flexibleWeak), &noMutVal, 1);
}

void MainForm::checkBox33_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox33->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::fast), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::fast), &noMutVal, 1);
}

void MainForm::checkBox34_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox34->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::hurlDamnation), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::hurlDamnation), &noMutVal, 1);
}

void MainForm::checkBox36_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox36->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rF), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rF), &noMutVal, 1);
}

void MainForm::checkBox37_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox37->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::demonicGuardian), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::demonicGuardian), &noMutVal, 1);
}

void MainForm::checkBox38_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox38->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::conserveScrolls), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::conserveScrolls), &noMutVal, 1);
}

void MainForm::checkBox39_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox39->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::conservePotions), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::conservePotions), &noMutVal, 1);
}

void MainForm::checkBox40_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox40->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rC), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rC), &noMutVal, 1);
}

void MainForm::checkBox21_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox21->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::clever), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::clever), &noMutVal, 1);
}

void MainForm::checkBox22_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox22->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::clarity), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::clarity), &noMutVal, 1);
}

void MainForm::checkBox23_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	uintptr_t four = 4;
	if (this->checkBox23->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::carnivore), &four, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::carnivore), &noMutVal, 1);
}

void MainForm::checkBox24_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	// this doesn't work
	if (this->checkBox24->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::breathePoison), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::breathePoison), &noMutVal, 1);
}

void MainForm::checkBox25_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	// this doesn't work
	if (this->checkBox25->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::breatheFlames), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::breatheFlames), &noMutVal, 1);
}

void MainForm::checkBox26_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox26->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::blink), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::blink), &noMutVal, 1);
}

void MainForm::checkBox27_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox27->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::agile), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::agile), &noMutVal, 1);
}

void MainForm::checkBox28_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox28->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::seeInv), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::seeInv), &noMutVal, 1);
}

void MainForm::checkBox29_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox29->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::camo), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::camo), &noMutVal, 1);
}

void MainForm::checkBox17_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox17->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::thinStruct), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::thinStruct), &noMutVal, 1);
}

void MainForm::checkBox18_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox18->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::thinMetallicScale), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::thinMetallicScale), &noMutVal, 1);
}

void MainForm::checkBox19_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox19->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::slimyGreenScale), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::slimyGreenScale), &noMutVal, 1);
}


void MainForm::checkBox20_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox20->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::ruggedBrownScale), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::ruggedBrownScale), &noMutVal, 1);
}

void MainForm::checkBox9_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox9->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::roughBlackScale), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::roughBlackScale), &noMutVal, 1);
}

void MainForm::checkBox10_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox10->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::moltenScale), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::moltenScale), &noMutVal, 1);
}

void MainForm::checkBox11_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox11->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::largeBonePlate), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::largeBonePlate), &noMutVal, 1);
}

void MainForm::checkBox12_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox12->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::iridesecentScale), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::iridesecentScale), &noMutVal, 1);
}


void MainForm::checkBox13_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox13->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::blueScale), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::blueScale), &noMutVal, 1);
}

void MainForm::checkBox14_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox14->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::repulsionField), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::repulsionField), &noMutVal, 1);
}

void MainForm::checkBox15_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox15->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::tentacleSpike), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::tentacleSpike), &noMutVal, 1);
}

void MainForm::checkBox16_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox16->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::talons), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::talons), &noMutVal, 1);
}

void MainForm::checkBox5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox5->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::stinger), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::stinger), &noMutVal, 1);
}

void MainForm::checkBox6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox6->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::horns), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::horns), &noMutVal, 1);
}

void MainForm::checkBox7_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox7->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::hooves), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::hooves), &noMutVal, 1);
}

void MainForm::checkBox8_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox8->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::fangs), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::fangs), &noMutVal, 1);
}

void MainForm::checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox3->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::claws), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::claws), &noMutVal, 1);
}

void MainForm::checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox4->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::beak), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::beak), &noMutVal, 1);
}

void MainForm::checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox2->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::wings), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::wings), &noMutVal, 1);
}

void MainForm::checkBox1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox1->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::antennae), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::antennae), &noMutVal, 1);
}

void MainForm::checkBox30_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
	if (this->yellowscale->Checked) 
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::yellowScale), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::yellowScale), &noMutVal, 1);
}

void MainForm::button1_Click_1(System::Object^ sender, System::EventArgs^ e) {

	/* apply all mutations
	print("\n".join(list(x.group()[:-2] for x in re.finditer("this->.+?->", s))))
	print("\n".join(list(x.group()[:-2] + ");" for x in re.finditer("mem::Patch.+?(max|min|med).+\);", s))))
	*/

	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::yellowScale), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::foulStench), &medMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rElec), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::shaggyFur), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::saprovore), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::robust), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::regen), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::poweredByPain), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::poweredByDeath), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rPois), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::senseSurroundings), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::passiveFreeze), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::nightstalker), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rNeg), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::mutationResist), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::MR), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::igniteBlood), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::icemail), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::highMP), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::gourmand), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::slowMetabolism), &medMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::tormentResist), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::sanguineArmor), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::sturdyFrame), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::blackMark), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::fuming), &medMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::magicLink), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::strongNose), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::flameCloudImmunity), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::antimagicBite), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::cling), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::magicRegen), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::strongLegs), &medMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::freezingCloudImmunity), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rTrample), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::magicShield), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::constrict), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::acidResist), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rotImmunity), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::jump), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rPetr), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::jellyAbsorbMissle), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::jellySensing), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::tendrils), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::augmentation), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::translucentSkin), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::pseudopods), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::gelatinousBody), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::spawnJellies), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::eyeballs), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::acidicBite), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::unbreathing), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::wildMagic), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::toughSkin), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::strongButStiff), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::strong), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rTorm), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::spitPoison), &medMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::flexibleWeak), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::fast), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::hurlDamnation), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rF), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::demonicGuardian), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::conserveScrolls), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::conservePotions), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::rC), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::clever), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::clarity), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::blink), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::agile), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::seeInv), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::camo), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::thinStruct), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::thinMetallicScale), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::slimyGreenScale), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::ruggedBrownScale), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::roughBlackScale), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::moltenScale), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::largeBonePlate), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::iridesecentScale), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::blueScale), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::repulsionField), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::tentacleSpike), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::talons), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::stinger), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::horns), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::hooves), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::fangs), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::claws), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::beak), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::wings), &minMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::antennae), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::flexibleWeak), &maxMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::mpPoweredWand), &noMutVal, 1);

	/* check all the boxes */
	this->yellowscale->Checked = true;
	this->checkBox60->Checked  = true;
	this->checkBox42->Checked  = true;
	this->checkBox43->Checked  = true;
	this->checkBox44->Checked  = true;
	this->checkBox45->Checked  = true;
	this->checkBox46->Checked  = true;
	this->checkBox47->Checked  = true;
	this->checkBox48->Checked  = true;
	this->checkBox49->Checked  = true;
	this->checkBox50->Checked  = true;
	this->checkBox51->Checked  = true;
	this->checkBox52->Checked  = true;
	this->checkBox53->Checked  = true;
	this->checkBox54->Checked  = true;
	this->checkBox55->Checked  = true;
	this->checkBox56->Checked  = true;
	this->checkBox57->Checked  = true;
	this->checkBox58->Checked  = true;
	this->checkBox59->Checked  = true;
	this->checkBox41->Checked  = true;
	this->checkBox75->Checked  = true;
	this->checkBox97->Checked  = true;
	this->checkBox82->Checked  = true;
	this->checkBox83->Checked  = true;
	this->checkBox84->Checked  = true;
	this->checkBox85->Checked  = true;
	this->checkBox86->Checked  = true;
	this->checkBox87->Checked  = true;
	this->checkBox88->Checked  = true;
	this->checkBox89->Checked  = true;
	this->checkBox90->Checked  = true;
	this->checkBox91->Checked  = true;
	this->checkBox92->Checked  = true;
	this->checkBox94->Checked  = true;
	this->checkBox95->Checked  = true;
	this->checkBox96->Checked  = true;
	this->checkBox81->Checked  = true;
	this->checkBox98->Checked  = true;
	this->checkBox99->Checked  = true;
	this->checkBox100->Checked = true;
	this->checkBox61->Checked  = true;
	this->checkBox62->Checked  = true;
	this->checkBox63->Checked  = true;
	this->checkBox64->Checked  = true;
	this->checkBox65->Checked  = true;
	this->checkBox66->Checked  = true;
	this->checkBox67->Checked  = true;
	this->checkBox68->Checked  = true;
	this->checkBox69->Checked  = true;
	this->checkBox70->Checked  = true;
	this->checkBox71->Checked  = true;
	this->checkBox72->Checked  = true;
	this->checkBox73->Checked  = true;
	this->checkBox74->Checked  = true;
	this->checkBox76->Checked  = true;
	this->checkBox77->Checked  = true;
	this->checkBox78->Checked  = true;
	this->checkBox79->Checked  = true;
	this->checkBox80->Checked  = true;
	this->checkBox31->Checked  = true;
	this->checkBox33->Checked  = true;
	this->checkBox34->Checked  = true;
	this->checkBox36->Checked  = true;
	this->checkBox37->Checked  = true;
	this->checkBox38->Checked  = true;
	this->checkBox39->Checked  = true;
	this->checkBox40->Checked  = true;
	this->checkBox21->Checked  = true;
	this->checkBox22->Checked  = true;
	this->checkBox23->Checked  = true;
	this->checkBox26->Checked  = true;
	this->checkBox27->Checked  = true;
	this->checkBox28->Checked  = true;
	this->checkBox29->Checked  = true;
	this->checkBox17->Checked  = true;
	this->checkBox18->Checked  = true;
	this->checkBox19->Checked  = true;
	this->checkBox20->Checked  = true;
	this->checkBox9->Checked   = true;
	this->checkBox10->Checked  = true;
	this->checkBox11->Checked  = true;
	this->checkBox12->Checked  = true;
	this->checkBox13->Checked  = true;
	this->checkBox14->Checked  = true;
	this->checkBox15->Checked  = true;
	this->checkBox16->Checked  = true;
	this->checkBox5->Checked   = true;
	this->checkBox6->Checked   = true;
	this->checkBox7->Checked   = true;
	this->checkBox8->Checked   = true;
	this->checkBox3->Checked   = true;
	this->checkBox4->Checked   = true;
	this->checkBox2->Checked   = true;
	this->checkBox1->Checked   = true;
	this->checkBox104->Checked = true;
	logger::WriteLinetoConsole("Activated all good mutations.");

}

void MainForm::checkBox30_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox30->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::forlorn), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::forlorn), &noMutVal, 1);
}

void MainForm::checkBox35_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox35->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::herbivore), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::herbivore), &noMutVal, 1);
}

void MainForm::checkBox32_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox32->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::fastMetabolism), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::fastMetabolism), &noMutVal, 1);
}

void MainForm::checkBox177_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox177->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::screaming), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::screaming), &noMutVal, 1);
}

void MainForm::checkBox105_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox105->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::noRead), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::noRead), &noMutVal, 1);
}

void MainForm::checkBox106_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox106->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::noDrink), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::noDrink), &noMutVal, 1);
}

void MainForm::checkBox107_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox107->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::noRegen), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::noRegen), &noMutVal, 1);
}

void MainForm::checkBox101_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox101->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::coldBlooded), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::coldBlooded), &noMutVal, 1);
}

void MainForm::checkBox102_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox102->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::elecVuln), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::elecVuln), &noMutVal, 1);
}

void MainForm::checkBox103_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox103->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::subduedMagic), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::subduedMagic), &noMutVal, 1);
}

void MainForm::checkBox136_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox136->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::coldVuln), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::coldVuln), &noMutVal, 1);
}

void MainForm::checkBox137_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox137->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::inhibitedRegen), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::inhibitedRegen), &noMutVal, 1);
}

void MainForm::checkBox138_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox138->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::frail), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::frail), &noMutVal, 1);
}

void MainForm::checkBox139_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox139->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::clumsy), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::clumsy), &noMutVal, 1);
}

void MainForm::checkBox156_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox156->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::noPotionHeal), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::noPotionHeal), &noMutVal, 1);
}

void MainForm::checkBox157_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox157->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::slowness), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::slowness), &noMutVal, 1);
}

void MainForm::checkBox158_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox158->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::dopey), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::dopey), &noMutVal, 1);
}

void MainForm::checkBox159_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox159->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::blurryVision), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::blurryVision), &noMutVal, 1);
}

void MainForm::checkBox176_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox176->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::weak), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::weak), &noMutVal, 1);
}

void MainForm::checkBox104_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox104->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::mpPoweredWand), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::mpPoweredWand), &noMutVal, 1);
}

void MainForm::checkBox178_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox178->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::deterioration), &medMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::deterioration), &noMutVal, 1);
}

void MainForm::checkBox179_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox179->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::berserk), &medMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::berserk), &noMutVal, 1);
}

void MainForm::checkBox196_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox196->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::heatVuln), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::heatVuln), &noMutVal, 1);
}

void MainForm::checkBox197_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox197->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::teleportitis), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::teleportitis), &noMutVal, 1);
}

void MainForm::checkBox198_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox198->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::lowMP), &maxMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::lowMP), &noMutVal, 1);
}

void MainForm::checkBox199_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox199->Checked)
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::deformedBody), &minMutVal, 1);
	else
		mem::Patch((uintptr_t*)(moduleBase + mutAddrs::deformedBody), &noMutVal, 1);
}


void MainForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {

	/*
	print("\n".join(list(x.group()[:-2] for x in re.finditer("this->.+?->", s))))
	print("\n".join(list(x.group()[:-2] + ");" for x in re.finditer("mem::Patch.+?noMut.+\);", s))))
	*/
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::screaming), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::noRead), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::noDrink), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::noRegen), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::forlorn), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::coldBlooded), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::elecVuln), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::subduedMagic), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::coldVuln), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::inhibitedRegen), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::frail), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::clumsy), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::noPotionHeal), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::slowness), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::dopey), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::blurryVision), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::weak), &noMutVal, 1);
	//mem::Patch((uintptr_t*)(moduleBase + mutAddrs::mpPoweredWand), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::deterioration), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::berserk), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::heatVuln), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::teleportitis), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::lowMP), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::deformedBody), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::forlorn), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::fastMetabolism), &noMutVal, 1);
	mem::Patch((uintptr_t*)(moduleBase + mutAddrs::herbivore), &noMutVal, 1);

	/* uncheck */
	this->checkBox177->Checked = false;
	this->checkBox105->Checked = false;
	this->checkBox106->Checked = false;
	this->checkBox107->Checked = false;
	this->checkBox30->Checked  = false;
	this->checkBox32->Checked  = false;
	this->checkBox35->Checked  = false;
	this->checkBox101->Checked = false;
	this->checkBox102->Checked = false;
	this->checkBox103->Checked = false;
	this->checkBox136->Checked = false;
	this->checkBox137->Checked = false;
	this->checkBox138->Checked = false;
	this->checkBox139->Checked = false;
	this->checkBox156->Checked = false;
	this->checkBox157->Checked = false;
	this->checkBox158->Checked = false;
	this->checkBox159->Checked = false;
	this->checkBox176->Checked = false;
	//this->checkBox104->Checked = false;
	this->checkBox178->Checked = false;
	this->checkBox179->Checked = false;
	this->checkBox196->Checked = false;
	this->checkBox197->Checked = false;
	this->checkBox198->Checked = false;
	this->checkBox199->Checked = false;
	logger::WriteLinetoConsole("Removed all bad mutations.");

}

// on close
void MainForm::MainForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	// having issues ejecting as this dll loads in other, research this
	Application::ExitThread();
}

void MainForm::intelligence_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
void MainForm::dexterity_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
void MainForm::strength_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) {}

/* testing section

this is the actual fighting addy
crawl - tiles.exe + 522752 - 8B 04 85 2CE60E01 - mov eax, [eax * 4 + crawl - tiles.exe + E7E62C]
crawl - tiles.exe + 522759 - 89 44 24 08 - mov[esp + 08], eax
crawl - tiles.exe + 52275D - 8B 45 08 - mov eax, [ebp + 08]
this is the fighting addy used in the attack calculation?
crawl - tiles.exe + 522760 - 0FB6 80 74E40E01 - movzx eax, byte ptr[eax + crawl - tiles.exe + E7E474]*/



