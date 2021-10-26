#pragma once
#include <unordered_map>

// we need this in order to jmp [moduleBase + offset]
static uintptr_t moduleBase									= (uintptr_t)GetModuleHandle(NULL);
static bool needsMagicMap									= true;

// hooking addresses / function address
static uintptr_t magicMappingAddy							= moduleBase + 0x635580;
static uintptr_t hookMapChangeAddy							= 0x58B7DC;
static uintptr_t disablexAddy								= 0xA53BB9;
static uintptr_t disableyAddy								= 0xA53BC4;
static uintptr_t instakillAddy								= 0x43FE3B;
static uintptr_t calculateSpeedAddy							= 0x4A7896;
static uintptr_t updateTickAddy								= 0x6D60E9; // used to apply magic map on new tick 
static uintptr_t acqCheck1Addy								= moduleBase + 0x2619A0;
static uintptr_t acqScreenAddy								= moduleBase + 0x5EAFF0;
static uintptr_t acquirementAddy							= moduleBase + 0x21F30;

// return addresses for hooks
static uintptr_t hookMapChangeRetAddy						= moduleBase + hookMapChangeAddy + 6;
static uintptr_t disablexRetAddy							= moduleBase + disablexAddy + 8;
static uintptr_t disableyRetAddy							= moduleBase + disableyAddy + 6;
static uintptr_t instakillRetAddy							= moduleBase + instakillAddy + 7;
static uintptr_t updateTickRetAddy							= moduleBase + updateTickAddy + 7;

// in a function call
static const uintptr_t godModeAddy							= 0x4A7FAE;
static const uintptr_t infiniteManaAddy						= 0x4A83B9;
static const uintptr_t noHungerAddy							= 0x198008;
static const uintptr_t minMovementSpeedAddy					= 0x4AB525;

// player 
static const uintptr_t playerAddy							= 0xE7BD24;
static const uintptr_t goldAddy								= 0xE7BD9C;
static const uintptr_t pietyAddy							= 0xE7F1F8;
static const uintptr_t strAddy								= 0xE7BD73;
static const uintptr_t intAddy								= 0xE7BD74;
static const uintptr_t dexAddy								= 0xE7BD75;
static const uintptr_t hungerAddy							= 0xE7BD78;

// skills
static const uintptr_t fightingAddy							= 0xE7E62C;
static const uintptr_t sBladeAddy							= fightingAddy + 0x04;
static const uintptr_t lBladeAddy							= fightingAddy + 0x08;
static const uintptr_t axeAddy								= fightingAddy + 0x0C; // not sure why these two are reversed lol
static const uintptr_t maceAddy								= fightingAddy + 0x10;
static const uintptr_t polearmAddy							= fightingAddy + 0x14;
static const uintptr_t stavesAddy							= fightingAddy + 0x18;
static const uintptr_t unarmedAddy							= fightingAddy + 0x44;

static const uintptr_t slingsAddy							= fightingAddy + 0x1C;
static const uintptr_t bowsAddy								= fightingAddy + 0x20;
static const uintptr_t xbowAddy								= fightingAddy + 0x24;
static const uintptr_t throwingAddy							= fightingAddy + 0x28;

//not sure about offset 0x38, 0x40

static const uintptr_t armourAddy							= fightingAddy + 0x2C;
static const uintptr_t dodgingAddy							= fightingAddy + 0x30;
static const uintptr_t shieldsAddy							= fightingAddy + 0x3C;

static const uintptr_t invocationsAddy						= fightingAddy + 0x7C;
static const uintptr_t evocationsAddy						= fightingAddy + 0x80;
static const uintptr_t stealthAddy							= fightingAddy + 0x34;

static const uintptr_t spellcastingAddy						= fightingAddy + 0x48;
static const uintptr_t conjurationAddy						= fightingAddy + 0x4C;
static const uintptr_t hexesAddy							= fightingAddy + 0x50;
static const uintptr_t charmsAddy							= fightingAddy + 0x54;
static const uintptr_t summoningAddy						= fightingAddy + 0x58;
static const uintptr_t necromancyAddy						= fightingAddy + 0x5C;
static const uintptr_t translocationsAddy					= fightingAddy + 0x60;
static const uintptr_t transmutationAddy					= fightingAddy + 0x64;
static const uintptr_t fireMagicAddy						= fightingAddy + 0x68;
static const uintptr_t iceMagicAddy							= fightingAddy + 0x6C;
static const uintptr_t airMagicAddy							= fightingAddy + 0x70;
static const uintptr_t earthMagicAddy						= fightingAddy + 0x74;
static const uintptr_t poisonMagicAddy						= fightingAddy + 0x78;

// inventory
// items are either in the inventory or in the environment

struct itemFlags {
	static const uintptr_t identMask						= 0x0F;
	static const uintptr_t curse							= 0x01;
};

struct inventoryAddrs {
	static const uintptr_t firstInventorySlot				= 0xE7CC90;
	// how many bytes each item_def takes up
	static const uintptr_t inventoryOffset					= 0x5C;
	static const uintptr_t itemTypeOffset					= 0x40;
	static const uintptr_t subItemTypeOffset				= 0x41;
	static const uintptr_t numChargeOffset					= 0x42;
	static const uintptr_t numItemsOffset					= 0x4E;
	static const uintptr_t idStatusFlagOffset				= 0x50;
	static const uintptr_t curseStatusFlagOffset			= 0x51;
};

struct envAddrs {
	static const uintptr_t firstEnvItemSlot					= 0xE81204;
	static const uintptr_t inventoryOffset					= 0x5C;
	static const uintptr_t itemTypeOffset					= 0x40;
	static const uintptr_t subItemTypeOffset				= 0x41;
	static const uintptr_t numItemsOffset					= 0x4E;
	static const uintptr_t idStatusFlagOffset				= 0x50;
	static const uintptr_t curseStatusFlagOffset			= 0x51;
	
	static const uintptr_t firstEntityAddr					= 0xEAE108;
	static const uintptr_t hpOffset							= 0x54;  // weird method, 1000 is dead
	static const uintptr_t speedOffset						= 0x5C;
	static const uintptr_t allyOffset						= 0xB0;
	static const uintptr_t entityOffset						= 0x138;
	static const uintptr_t statusOffset						= 0xE0;
	static const uintptr_t sleepOffset						= 0xDC;
};

struct statusMasks { // little endian
	static const uintptr_t nomask							= 0x00000000;
	static const uintptr_t chaos							= 0x000000F0;
	static const uintptr_t neutral							= 0x00001000;
	static const uintptr_t ally								= 0x00002000;
	static const uintptr_t petrify							= 0x00008000;
	static const uintptr_t maxItems							= 0x00007FFF;
};

// mutations
struct mutAddrs {
	static const uintptr_t antennae							= 0xE7F2C3;
	static const uintptr_t wings							= antennae + 0x1;
	static const uintptr_t beak								= antennae + 0x2;
	static const uintptr_t claws							= antennae + 0x3;
	static const uintptr_t fangs							= antennae + 0x4;
	static const uintptr_t hooves							= antennae + 0x5;
	static const uintptr_t horns							= antennae + 0x6;
	static const uintptr_t stinger							= antennae + 0x7;
	static const uintptr_t talons							= antennae + 0x8;
	static const uintptr_t tentacleSpike					= antennae + 0x9;
	static const uintptr_t repulsionField					= antennae + 0xA;
	static const uintptr_t blueScale						= antennae + 0xB;
	static const uintptr_t iridesecentScale					= antennae + 0xC;
	static const uintptr_t largeBonePlate					= antennae + 0xD;
	static const uintptr_t moltenScale						= antennae + 0xE;
	static const uintptr_t roughBlackScale					= antennae + 0xF;
	static const uintptr_t ruggedBrownScale					= antennae + 0x10;
	static const uintptr_t slimyGreenScale					= antennae + 0x11;
	static const uintptr_t thinMetallicScale				= antennae + 0x12;
	static const uintptr_t thinStruct						= antennae + 0x13;
	static const uintptr_t yellowScale						= antennae + 0x14;
	static const uintptr_t camo								= antennae + 0x15;
	static const uintptr_t seeInv							= antennae + 0x16;
	static const uintptr_t agile							= antennae + 0x17;
	static const uintptr_t berserk							= antennae + 0x18; // bad
	static const uintptr_t blink							= antennae + 0x19;
	static const uintptr_t blurryVision						= antennae + 0x1A; // bad
	static const uintptr_t breatheFlames					= antennae + 0x1B;
	static const uintptr_t breathePoison					= antennae + 0x1C;
	static const uintptr_t carnivore						= antennae + 0x1D;
	static const uintptr_t clarity							= antennae + 0x1E;
	static const uintptr_t clever							= antennae + 0x1F;
	static const uintptr_t clumsy							= antennae + 0x20; // bad
	static const uintptr_t rC								= antennae + 0x21;
	static const uintptr_t conservePotions					= antennae + 0x22;
	static const uintptr_t conserveScrolls					= antennae + 0x23;
	static const uintptr_t deformedBody						= antennae + 0x24; // bad
	static const uintptr_t demonicGuardian					= antennae + 0x25;
	static const uintptr_t deterioration					= antennae + 0x26; // bad
	static const uintptr_t dopey							= antennae + 0x27; // bad
	static const uintptr_t rF								= antennae + 0x28;
	static const uintptr_t herbivore						= antennae + 0x29;
	static const uintptr_t hurlDamnation					= antennae + 0x2A;
	static const uintptr_t fast								= antennae + 0x2B;
	static const uintptr_t fastMetabolism					= antennae + 0x2C; // bad
	static const uintptr_t flexibleWeak						= antennae + 0x2D; // -str +dex
	static const uintptr_t frail							= antennae + 0x2E; // bad
	static const uintptr_t foulStench						= antennae + 0x2F; // demonspawn mutation
	static const uintptr_t gourmand							= antennae + 0x30;
	static const uintptr_t highMP							= antennae + 0x31;
	static const uintptr_t icemail							= antennae + 0x32;
	static const uintptr_t igniteBlood						= antennae + 0x33;
	static const uintptr_t lowMP							= antennae + 0x34; // bad
	static const uintptr_t MR								= antennae + 0x35;
	static const uintptr_t mutationResist					= antennae + 0x36;
	static const uintptr_t rNeg								= antennae + 0x37;
	static const uintptr_t nightstalker						= antennae + 0x38;
	static const uintptr_t passiveFreeze					= antennae + 0x39;
	static const uintptr_t senseSurroundings				= antennae + 0x3A;
	static const uintptr_t rPois							= antennae + 0x3B;
	static const uintptr_t poweredByDeath					= antennae + 0x3C; // ds
	static const uintptr_t poweredByPain					= antennae + 0x3D; // ds
	static const uintptr_t regen							= antennae + 0x3E;
	static const uintptr_t robust							= antennae + 0x3F;
	static const uintptr_t saprovore						= antennae + 0x40;
	static const uintptr_t screaming						= antennae + 0x41; // bad
	static const uintptr_t shaggyFur						= antennae + 0x42;
	static const uintptr_t rElec							= antennae + 0x43;
	static const uintptr_t slowness							= antennae + 0x44; // bad
	static const uintptr_t inhibitedRegen					= antennae + 0x45; // bad
	static const uintptr_t slowMetabolism					= antennae + 0x46; // check this
	static const uintptr_t spiny							= antennae + 0x47;
	static const uintptr_t spitPoison						= antennae + 0x48;
	static const uintptr_t rTorm							= antennae + 0x49;
	static const uintptr_t strong							= antennae + 0x4A;
	static const uintptr_t strongButStiff					= antennae + 0x4B;
	static const uintptr_t teleportitis						= antennae + 0x4C; // bad
	static const uintptr_t teleportControl					= antennae + 0x4D;
	static const uintptr_t tormentResist					= antennae + 0x4E; // gargoyle i think
	static const uintptr_t toughSkin						= antennae + 0x4F;
	static const uintptr_t weak								= antennae + 0x50; // bad
	static const uintptr_t wildMagic						= antennae + 0x51;
	static const uintptr_t unbreathing						= antennae + 0x52;
	static const uintptr_t acidicBite						= antennae + 0x53;

	// jivya mutations
	static const uintptr_t eyeballs							= antennae + 0x54;
	static const uintptr_t spawnJellies						= antennae + 0x55;
	static const uintptr_t gelatinousBody					= antennae + 0x56;
	static const uintptr_t pseudopods						= antennae + 0x57;
	static const uintptr_t translucentSkin					= antennae + 0x58;

	// strange break xd
	static const uintptr_t evolution						= antennae + 0x59;
	static const uintptr_t augmentation						= antennae + 0x5A; // ds

	// more jivya
	static const uintptr_t tendrils							= antennae + 0x5B;
	static const uintptr_t jellySensing						= antennae + 0x5C;
	static const uintptr_t jellyAbsorbMissle				= antennae + 0x5D;

	static const uintptr_t magicShield						= antennae + 0x5E;
	static const uintptr_t magicRegen						= antennae + 0x5F;
	static const uintptr_t magicLink						= antennae + 0x60;
	static const uintptr_t rPetr							= antennae + 0x61;
	static const uintptr_t rTrample							= antennae + 0x62;
	static const uintptr_t cling							= antennae + 0x63;
	static const uintptr_t fuming							= antennae + 0x64;
	static const uintptr_t jump								= antennae + 0x65;
	static const uintptr_t exoskeleton						= antennae + 0x66;
	static const uintptr_t antimagicBite					= antennae + 0x67;
	static const uintptr_t noPotionHeal						= antennae + 0x68; // bad
	static const uintptr_t coldVuln							= antennae + 0x69; // bad
	static const uintptr_t heatVuln							= antennae + 0x6A; // bad
	static const uintptr_t blackMark						= antennae + 0x6B;
	static const uintptr_t elecVuln							= antennae + 0x6C; // bad
	static const uintptr_t coldBlooded						= antennae + 0x6D; // bad
	static const uintptr_t rotImmunity						= antennae + 0x6E;
	static const uintptr_t freezingCloudImmunity			= antennae + 0x6F;
	static const uintptr_t flameCloudImmunity				= antennae + 0x70;
	static const uintptr_t forlorn							= antennae + 0x71; // bad
	static const uintptr_t subduedMagic						= antennae + 0x72; // bad
	static const uintptr_t noDrink							= antennae + 0x73; // bad
	static const uintptr_t noRead							= antennae + 0x74; // bad

	// everything under here is just Ru stuff, and some rare ones
	static const uintptr_t mpPoweredWand					= antennae + 0x8D; // bad
	static const uintptr_t constrict						= antennae + 0x93;
	static const uintptr_t sturdyFrame						= antennae + 0x97;
	static const uintptr_t sanguineArmor					= antennae + 0x98; 
	static const uintptr_t strongLegs						= antennae + 0x99;
	static const uintptr_t noRegen							= antennae + 0x9A; // bad
	static const uintptr_t strongNose						= antennae + 0x9B;
	static const uintptr_t acidResist						= antennae + 0x9C; 


};

// maybe write an aob scanner?

// the displayed level follows a linear relationship between exp for level n and n + 1
static std::unordered_map<int, int> leveltoEXP = {
	{0, 0}, {1, 50}, {2, 150}, {3, 300}, {4, 500}, {5, 750},			// 0-5
	{6, 1050}, {7, 1400}, {8, 1800}, {9, 2250}, {10, 2800},				// 6-10
	{11, 3450}, {12, 4200}, {13, 5050}, {14, 6000}, {15, 7050},			// 11-15
	{16, 8200}, {17, 9450}, {18, 10800}, {19, 12300}, {20, 13950},		// 16-20
	{21, 15750}, {22, 17700}, {23, 19800}, {24, 22050}, {25, 24450},	// 21-25
	{26, 27000}, {27, 29750}
};

static std::unordered_map<int, int> exptoLevel = {
	{0, 0}, {50, 1}, {150, 2}, {300, 3}, {500, 4}, {750, 5},			// 0-5
	{1050, 6}, {1400, 7}, {1800, 8}, {2250, 9}, {2800, 10},				// 6-10
	{3450, 11}, {4200, 12}, {5050, 13}, {6000, 14}, {7050, 15},			// 11-15
	{8200, 16}, {9450, 17}, {10800, 18}, {12300, 19}, {13950, 20},		// 16-20
	{15750, 21}, {17700, 22}, {19800, 23}, {22050, 24}, {24450, 25},	// 21-25
	{27000, 26}, {29750, 27}
};

