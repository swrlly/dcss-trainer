#pragma once
#include "process.h"
#include "memory.h"
#include "logger.h"

namespace dcsstrainer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{

	private: System::Windows::Forms::TextBox^ dexterity;
	private: System::Windows::Forms::TextBox^ strength;
	private: System::Windows::Forms::TextBox^ intelligence;
	private: System::Windows::Forms::CheckBox^ godmode;
	private: System::Windows::Forms::CheckBox^ infinitemana;
	public: System::Windows::Forms::ListBox^ ConsoleLog;


	private: System::Windows::Forms::CheckBox^ nohunger;
	private: System::Windows::Forms::Timer^ GUITimer;
	private: System::Windows::Forms::Label^ attached;
	private: System::Windows::Forms::Label^ attachedtext;


	private: System::Windows::Forms::Button^ applystats;


	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ stealth;

	private: System::Windows::Forms::Label^ label60;
	private: System::Windows::Forms::TextBox^ evocations;

	private: System::Windows::Forms::Label^ label61;
	private: System::Windows::Forms::TextBox^ invocations;

	private: System::Windows::Forms::Label^ label62;
	private: System::Windows::Forms::TextBox^ transmutations;



	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::TextBox^ poisonmagic;

	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::TextBox^ earthmagic;

	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::TextBox^ airmagic;

	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::TextBox^ icemagic;

	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::TextBox^ firemagic;

	private: System::Windows::Forms::Label^ label38;
	private: System::Windows::Forms::TextBox^ translocations;

	private: System::Windows::Forms::Label^ label39;
	private: System::Windows::Forms::TextBox^ necromancy;

	private: System::Windows::Forms::Label^ label40;
	private: System::Windows::Forms::TextBox^ summonings;

	private: System::Windows::Forms::Label^ label41;
	private: System::Windows::Forms::TextBox^ charms;

	private: System::Windows::Forms::Label^ label42;
	private: System::Windows::Forms::TextBox^ hexes;

	private: System::Windows::Forms::Label^ label43;
	private: System::Windows::Forms::Label^ label44;
	private: System::Windows::Forms::TextBox^ conjurations;

	private: System::Windows::Forms::TextBox^ fighting;

	private: System::Windows::Forms::Label^ label45;
	private: System::Windows::Forms::TextBox^ spellcasting;

	private: System::Windows::Forms::Label^ label46;
	private: System::Windows::Forms::Label^ label47;
	private: System::Windows::Forms::TextBox^ shortblades;
	private: System::Windows::Forms::TextBox^ shields;


	private: System::Windows::Forms::TextBox^ unarmedcombat;

	private: System::Windows::Forms::Label^ label48;
	private: System::Windows::Forms::Label^ label49;
	private: System::Windows::Forms::TextBox^ dodging;

	private: System::Windows::Forms::Label^ label50;
	private: System::Windows::Forms::Label^ label51;
	private: System::Windows::Forms::TextBox^ staves;

	private: System::Windows::Forms::Label^ label52;
	private: System::Windows::Forms::TextBox^ slings;

	private: System::Windows::Forms::TextBox^ longblades;

	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::TextBox^ throwing;

	private: System::Windows::Forms::TextBox^ polearms;

	private: System::Windows::Forms::Label^ label53;
	private: System::Windows::Forms::Label^ label54;
	private: System::Windows::Forms::TextBox^ crossbows;

	private: System::Windows::Forms::Label^ label55;
	private: System::Windows::Forms::Label^ label56;
	private: System::Windows::Forms::TextBox^ axes;
	private: System::Windows::Forms::TextBox^ bows;



	private: System::Windows::Forms::Label^ label57;
	private: System::Windows::Forms::Label^ label58;
	private: System::Windows::Forms::TextBox^ maces;
private: System::Windows::Forms::CheckBox^ idinven;
private: System::Windows::Forms::TextBox^ armour;
private: System::Windows::Forms::Label^ armor;
private: System::Windows::Forms::CheckBox^ onehp;
private: System::Windows::Forms::Panel^ panel3;
private: System::Windows::Forms::CheckBox^ mfreeze;
private: System::Windows::Forms::CheckBox^ disablemovement;
private: System::Windows::Forms::CheckBox^ instakill;
private: System::Windows::Forms::CheckBox^ permasleep;
private: System::Windows::Forms::CheckBox^ maxitems;
private: System::Windows::Forms::CheckBox^ mmapping;
private: System::Windows::Forms::TabControl^ tabboxthing;


private: System::Windows::Forms::TabPage^ tabpage1;



private: System::Windows::Forms::TabPage^ tabPage2;
private: System::Windows::Forms::Panel^ panel4;
private: System::Windows::Forms::CheckBox^ acqui;
private: System::Windows::Forms::CheckBox^ maxcharge;
private: System::Windows::Forms::TextBox^ piety;

private: System::Windows::Forms::TextBox^ gold;
private: System::Windows::Forms::TabPage^ Mutations;
private: System::Windows::Forms::Panel^ panel5;






private: System::Windows::Forms::CheckBox^ checkBox15;
private: System::Windows::Forms::CheckBox^ checkBox16;
private: System::Windows::Forms::CheckBox^ checkBox5;
private: System::Windows::Forms::CheckBox^ checkBox6;
private: System::Windows::Forms::CheckBox^ checkBox7;
private: System::Windows::Forms::CheckBox^ checkBox8;
private: System::Windows::Forms::CheckBox^ checkBox3;
private: System::Windows::Forms::CheckBox^ checkBox4;
private: System::Windows::Forms::CheckBox^ checkBox2;
private: System::Windows::Forms::CheckBox^ checkBox1;




private: System::Windows::Forms::CheckBox^ checkBox21;
private: System::Windows::Forms::CheckBox^ checkBox22;
private: System::Windows::Forms::CheckBox^ checkBox23;
private: System::Windows::Forms::CheckBox^ checkBox24;
private: System::Windows::Forms::CheckBox^ checkBox25;
private: System::Windows::Forms::CheckBox^ checkBox26;
private: System::Windows::Forms::CheckBox^ checkBox27;
private: System::Windows::Forms::CheckBox^ checkBox28;
private: System::Windows::Forms::CheckBox^ checkBox29;
private: System::Windows::Forms::CheckBox^ yellowscale;


private: System::Windows::Forms::CheckBox^ checkBox17;
private: System::Windows::Forms::CheckBox^ checkBox18;
private: System::Windows::Forms::CheckBox^ checkBox19;
private: System::Windows::Forms::CheckBox^ checkBox20;
private: System::Windows::Forms::CheckBox^ checkBox9;
private: System::Windows::Forms::CheckBox^ checkBox10;
private: System::Windows::Forms::CheckBox^ checkBox11;
private: System::Windows::Forms::CheckBox^ checkBox12;
private: System::Windows::Forms::CheckBox^ checkBox13;
private: System::Windows::Forms::CheckBox^ checkBox14;
private: System::Windows::Forms::CheckBox^ checkBox61;
private: System::Windows::Forms::CheckBox^ checkBox62;
private: System::Windows::Forms::CheckBox^ checkBox63;
private: System::Windows::Forms::CheckBox^ checkBox64;
private: System::Windows::Forms::CheckBox^ checkBox65;
private: System::Windows::Forms::CheckBox^ checkBox66;
private: System::Windows::Forms::CheckBox^ checkBox67;
private: System::Windows::Forms::CheckBox^ checkBox68;
private: System::Windows::Forms::CheckBox^ checkBox69;
private: System::Windows::Forms::CheckBox^ checkBox70;
private: System::Windows::Forms::CheckBox^ checkBox71;
private: System::Windows::Forms::CheckBox^ checkBox72;
private: System::Windows::Forms::CheckBox^ checkBox73;
private: System::Windows::Forms::CheckBox^ checkBox74;
private: System::Windows::Forms::CheckBox^ checkBox75;
private: System::Windows::Forms::CheckBox^ checkBox76;
private: System::Windows::Forms::CheckBox^ checkBox77;
private: System::Windows::Forms::CheckBox^ checkBox78;
private: System::Windows::Forms::CheckBox^ checkBox79;
private: System::Windows::Forms::CheckBox^ checkBox80;
private: System::Windows::Forms::CheckBox^ checkBox41;
private: System::Windows::Forms::CheckBox^ checkBox42;
private: System::Windows::Forms::CheckBox^ checkBox43;
private: System::Windows::Forms::CheckBox^ checkBox44;
private: System::Windows::Forms::CheckBox^ checkBox45;
private: System::Windows::Forms::CheckBox^ checkBox46;
private: System::Windows::Forms::CheckBox^ checkBox47;
private: System::Windows::Forms::CheckBox^ checkBox48;
private: System::Windows::Forms::CheckBox^ checkBox49;
private: System::Windows::Forms::CheckBox^ checkBox50;
private: System::Windows::Forms::CheckBox^ checkBox51;
private: System::Windows::Forms::CheckBox^ checkBox52;
private: System::Windows::Forms::CheckBox^ checkBox53;
private: System::Windows::Forms::CheckBox^ checkBox54;
private: System::Windows::Forms::CheckBox^ checkBox55;
private: System::Windows::Forms::CheckBox^ checkBox56;
private: System::Windows::Forms::CheckBox^ checkBox57;
private: System::Windows::Forms::CheckBox^ checkBox58;
private: System::Windows::Forms::CheckBox^ checkBox59;
private: System::Windows::Forms::CheckBox^ checkBox60;
private: System::Windows::Forms::CheckBox^ checkBox31;
private: System::Windows::Forms::CheckBox^ checkBox32;
private: System::Windows::Forms::CheckBox^ checkBox33;
private: System::Windows::Forms::CheckBox^ checkBox34;
private: System::Windows::Forms::CheckBox^ checkBox35;
private: System::Windows::Forms::CheckBox^ checkBox36;
private: System::Windows::Forms::CheckBox^ checkBox37;
private: System::Windows::Forms::CheckBox^ checkBox38;
private: System::Windows::Forms::CheckBox^ checkBox39;
private: System::Windows::Forms::CheckBox^ checkBox40;
private: System::Windows::Forms::CheckBox^ checkBox81;
private: System::Windows::Forms::CheckBox^ checkBox82;
private: System::Windows::Forms::CheckBox^ checkBox83;
private: System::Windows::Forms::CheckBox^ checkBox84;
private: System::Windows::Forms::CheckBox^ checkBox85;
private: System::Windows::Forms::CheckBox^ checkBox86;
private: System::Windows::Forms::CheckBox^ checkBox87;
private: System::Windows::Forms::CheckBox^ checkBox88;
private: System::Windows::Forms::CheckBox^ checkBox89;
private: System::Windows::Forms::CheckBox^ checkBox90;
private: System::Windows::Forms::CheckBox^ checkBox91;
private: System::Windows::Forms::CheckBox^ checkBox92;
private: System::Windows::Forms::CheckBox^ checkBox93;
private: System::Windows::Forms::CheckBox^ checkBox94;
private: System::Windows::Forms::CheckBox^ checkBox95;
private: System::Windows::Forms::CheckBox^ checkBox96;
private: System::Windows::Forms::CheckBox^ checkBox97;
private: System::Windows::Forms::CheckBox^ checkBox98;
private: System::Windows::Forms::CheckBox^ checkBox99;
private: System::Windows::Forms::CheckBox^ checkBox100;
private: System::Windows::Forms::Panel^ panel6;
private: System::Windows::Forms::CheckBox^ checkBox136;
private: System::Windows::Forms::CheckBox^ checkBox137;
private: System::Windows::Forms::CheckBox^ checkBox138;
private: System::Windows::Forms::CheckBox^ checkBox139;
private: System::Windows::Forms::CheckBox^ checkBox156;
private: System::Windows::Forms::CheckBox^ checkBox157;
private: System::Windows::Forms::CheckBox^ checkBox158;
private: System::Windows::Forms::CheckBox^ checkBox159;
private: System::Windows::Forms::CheckBox^ checkBox176;
private: System::Windows::Forms::CheckBox^ checkBox177;
private: System::Windows::Forms::CheckBox^ checkBox178;
private: System::Windows::Forms::CheckBox^ checkBox179;
private: System::Windows::Forms::CheckBox^ checkBox196;
private: System::Windows::Forms::CheckBox^ checkBox197;
private: System::Windows::Forms::CheckBox^ checkBox198;
private: System::Windows::Forms::CheckBox^ checkBox199;
private: System::Windows::Forms::CheckBox^ checkBox104;
private: System::Windows::Forms::CheckBox^ checkBox105;
private: System::Windows::Forms::CheckBox^ checkBox106;
private: System::Windows::Forms::CheckBox^ checkBox107;
private: System::Windows::Forms::CheckBox^ checkBox30;
private: System::Windows::Forms::CheckBox^ checkBox101;
private: System::Windows::Forms::CheckBox^ checkBox102;
private: System::Windows::Forms::CheckBox^ checkBox103;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::CheckBox^ minmovspd;
private: System::Windows::Forms::CheckBox^ allymaxspd;
private: System::Windows::Forms::CheckBox^ convertally;




















	public:
		static MainForm^ instance;

		MainForm()
		{
			// initialize form
			InitializeComponent();
			instance = this;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::Label^ label2;
			System::Windows::Forms::Label^ label1;
			System::Windows::Forms::Label^ label3;
			System::Windows::Forms::Label^ customstat;
			System::Windows::Forms::Label^ label5;
			System::Windows::Forms::Label^ label4;
			System::Windows::Forms::Label^ label6;
			System::Windows::Forms::Label^ label9;
			System::Windows::Forms::Label^ label10;
			System::Windows::Forms::Label^ label7;
			System::Windows::Forms::Label^ label8;
			System::Windows::Forms::Label^ label11;
			this->dexterity = (gcnew System::Windows::Forms::TextBox());
			this->strength = (gcnew System::Windows::Forms::TextBox());
			this->intelligence = (gcnew System::Windows::Forms::TextBox());
			this->ConsoleLog = (gcnew System::Windows::Forms::ListBox());
			this->godmode = (gcnew System::Windows::Forms::CheckBox());
			this->infinitemana = (gcnew System::Windows::Forms::CheckBox());
			this->nohunger = (gcnew System::Windows::Forms::CheckBox());
			this->GUITimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->attached = (gcnew System::Windows::Forms::Label());
			this->attachedtext = (gcnew System::Windows::Forms::Label());
			this->applystats = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->minmovspd = (gcnew System::Windows::Forms::CheckBox());
			this->maxitems = (gcnew System::Windows::Forms::CheckBox());
			this->idinven = (gcnew System::Windows::Forms::CheckBox());
			this->onehp = (gcnew System::Windows::Forms::CheckBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->piety = (gcnew System::Windows::Forms::TextBox());
			this->gold = (gcnew System::Windows::Forms::TextBox());
			this->armour = (gcnew System::Windows::Forms::TextBox());
			this->armor = (gcnew System::Windows::Forms::Label());
			this->stealth = (gcnew System::Windows::Forms::TextBox());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->evocations = (gcnew System::Windows::Forms::TextBox());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->invocations = (gcnew System::Windows::Forms::TextBox());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->transmutations = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->poisonmagic = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->earthmagic = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->airmagic = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->icemagic = (gcnew System::Windows::Forms::TextBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->firemagic = (gcnew System::Windows::Forms::TextBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->translocations = (gcnew System::Windows::Forms::TextBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->necromancy = (gcnew System::Windows::Forms::TextBox());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->summonings = (gcnew System::Windows::Forms::TextBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->charms = (gcnew System::Windows::Forms::TextBox());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->hexes = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->conjurations = (gcnew System::Windows::Forms::TextBox());
			this->fighting = (gcnew System::Windows::Forms::TextBox());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->spellcasting = (gcnew System::Windows::Forms::TextBox());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->shortblades = (gcnew System::Windows::Forms::TextBox());
			this->shields = (gcnew System::Windows::Forms::TextBox());
			this->unarmedcombat = (gcnew System::Windows::Forms::TextBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->dodging = (gcnew System::Windows::Forms::TextBox());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->staves = (gcnew System::Windows::Forms::TextBox());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->slings = (gcnew System::Windows::Forms::TextBox());
			this->longblades = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->throwing = (gcnew System::Windows::Forms::TextBox());
			this->polearms = (gcnew System::Windows::Forms::TextBox());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->crossbows = (gcnew System::Windows::Forms::TextBox());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->axes = (gcnew System::Windows::Forms::TextBox());
			this->bows = (gcnew System::Windows::Forms::TextBox());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->maces = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->convertally = (gcnew System::Windows::Forms::CheckBox());
			this->allymaxspd = (gcnew System::Windows::Forms::CheckBox());
			this->permasleep = (gcnew System::Windows::Forms::CheckBox());
			this->instakill = (gcnew System::Windows::Forms::CheckBox());
			this->disablemovement = (gcnew System::Windows::Forms::CheckBox());
			this->mfreeze = (gcnew System::Windows::Forms::CheckBox());
			this->mmapping = (gcnew System::Windows::Forms::CheckBox());
			this->tabboxthing = (gcnew System::Windows::Forms::TabControl());
			this->tabpage1 = (gcnew System::Windows::Forms::TabPage());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->maxcharge = (gcnew System::Windows::Forms::CheckBox());
			this->acqui = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->Mutations = (gcnew System::Windows::Forms::TabPage());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->checkBox105 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox106 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox107 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox30 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox101 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox32 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox102 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox103 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox136 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox137 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox138 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox139 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox156 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox157 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox158 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox159 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox176 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox177 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox178 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox179 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox196 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox197 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox198 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox199 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox35 = (gcnew System::Windows::Forms::CheckBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->checkBox104 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox81 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox82 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox83 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox84 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox85 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox86 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox87 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox88 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox89 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox90 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox91 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox92 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox93 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox94 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox95 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox96 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox97 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox98 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox99 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox100 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox61 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox62 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox63 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox64 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox65 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox66 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox67 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox68 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox69 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox70 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox71 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox72 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox73 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox74 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox75 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox76 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox77 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox78 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox79 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox80 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox41 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox42 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox43 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox44 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox45 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox46 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox47 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox48 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox49 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox50 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox51 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox52 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox53 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox54 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox55 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox56 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox57 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox58 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox59 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox60 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox31 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox33 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox34 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox36 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox37 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox38 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox39 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox40 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox21 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox22 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox23 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox24 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox25 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox26 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox27 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox28 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox29 = (gcnew System::Windows::Forms::CheckBox());
			this->yellowscale = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox17 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox18 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox19 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox20 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox9 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox10 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox11 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox12 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox13 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox14 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox15 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox16 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			label2 = (gcnew System::Windows::Forms::Label());
			label1 = (gcnew System::Windows::Forms::Label());
			label3 = (gcnew System::Windows::Forms::Label());
			customstat = (gcnew System::Windows::Forms::Label());
			label5 = (gcnew System::Windows::Forms::Label());
			label4 = (gcnew System::Windows::Forms::Label());
			label6 = (gcnew System::Windows::Forms::Label());
			label9 = (gcnew System::Windows::Forms::Label());
			label10 = (gcnew System::Windows::Forms::Label());
			label7 = (gcnew System::Windows::Forms::Label());
			label8 = (gcnew System::Windows::Forms::Label());
			label11 = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->tabboxthing->SuspendLayout();
			this->tabpage1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->Mutations->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel5->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			label2->Location = System::Drawing::Point(365, 10);
			label2->Name = L"label2";
			label2->Size = System::Drawing::Size(52, 15);
			label2->TabIndex = 1;
			label2->Text = L"Strength";
			label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			label1->Location = System::Drawing::Point(365, 36);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(68, 22);
			label1->TabIndex = 1;
			label1->Text = L"Intelligence";
			label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			label3->Location = System::Drawing::Point(365, 66);
			label3->Name = L"label3";
			label3->Size = System::Drawing::Size(68, 22);
			label3->TabIndex = 1;
			label3->Text = L"Dexterity";
			label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// customstat
			// 
			customstat->AutoSize = true;
			customstat->BackColor = System::Drawing::Color::Transparent;
			customstat->Location = System::Drawing::Point(6, 4);
			customstat->Name = L"customstat";
			customstat->Size = System::Drawing::Size(98, 15);
			customstat->TabIndex = 1;
			customstat->Text = L"Custom Skill Stats";
			// 
			// label5
			// 
			label5->AutoSize = true;
			label5->Location = System::Drawing::Point(10, 3);
			label5->Name = L"label5";
			label5->Size = System::Drawing::Size(40, 15);
			label5->TabIndex = 1;
			label5->Text = L"Player";
			// 
			// label4
			// 
			label4->AutoSize = true;
			label4->Location = System::Drawing::Point(183, 3);
			label4->Name = L"label4";
			label4->Size = System::Drawing::Size(80, 15);
			label4->TabIndex = 1;
			label4->Text = L"Monster / Ally";
			// 
			// label6
			// 
			label6->AutoSize = true;
			label6->Location = System::Drawing::Point(356, 3);
			label6->Name = L"label6";
			label6->Size = System::Drawing::Size(108, 15);
			label6->TabIndex = 1;
			label6->Text = L"Item / Environment";
			// 
			// label9
			// 
			label9->Location = System::Drawing::Point(365, 130);
			label9->Name = L"label9";
			label9->Size = System::Drawing::Size(68, 22);
			label9->TabIndex = 1;
			label9->Text = L"Gold";
			label9->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label10
			// 
			label10->Location = System::Drawing::Point(365, 160);
			label10->Name = L"label10";
			label10->Size = System::Drawing::Size(68, 22);
			label10->TabIndex = 1;
			label10->Text = L"Piety";
			label10->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label7
			// 
			label7->AutoSize = true;
			label7->BackColor = System::Drawing::Color::Transparent;
			label7->Location = System::Drawing::Point(6, 4);
			label7->Name = L"label7";
			label7->Size = System::Drawing::Size(93, 15);
			label7->TabIndex = 1;
			label7->Text = L"Good Mutations";
			// 
			// label8
			// 
			label8->AutoSize = true;
			label8->BackColor = System::Drawing::Color::Transparent;
			label8->Location = System::Drawing::Point(4, 340);
			label8->Name = L"label8";
			label8->Size = System::Drawing::Size(84, 15);
			label8->TabIndex = 1;
			label8->Text = L"Bad Mutations";
			// 
			// label11
			// 
			label11->AutoSize = true;
			label11->Location = System::Drawing::Point(10, 445);
			label11->Name = L"label11";
			label11->Size = System::Drawing::Size(26, 15);
			label11->TabIndex = 2;
			label11->Text = L"Log";
			// 
			// dexterity
			// 
			this->dexterity->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dexterity->Location = System::Drawing::Point(461, 68);
			this->dexterity->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dexterity->MaxLength = 3;
			this->dexterity->Name = L"dexterity";
			this->dexterity->Size = System::Drawing::Size(37, 22);
			this->dexterity->TabIndex = 34;
			this->dexterity->TextChanged += gcnew System::EventHandler(this, &MainForm::dexterity_TextChanged);
			// 
			// strength
			// 
			this->strength->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->strength->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->strength->Location = System::Drawing::Point(461, 8);
			this->strength->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->strength->MaxLength = 3;
			this->strength->Name = L"strength";
			this->strength->Size = System::Drawing::Size(37, 22);
			this->strength->TabIndex = 32;
			this->strength->TextChanged += gcnew System::EventHandler(this, &MainForm::strength_TextChanged);
			// 
			// intelligence
			// 
			this->intelligence->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->intelligence->Location = System::Drawing::Point(461, 38);
			this->intelligence->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->intelligence->MaxLength = 3;
			this->intelligence->Name = L"intelligence";
			this->intelligence->Size = System::Drawing::Size(37, 22);
			this->intelligence->TabIndex = 33;
			this->intelligence->TextChanged += gcnew System::EventHandler(this, &MainForm::intelligence_TextChanged);
			// 
			// ConsoleLog
			// 
			this->ConsoleLog->BackColor = System::Drawing::Color::White;
			this->ConsoleLog->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ConsoleLog->Enabled = false;
			this->ConsoleLog->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ConsoleLog->FormattingEnabled = true;
			this->ConsoleLog->ItemHeight = 15;
			this->ConsoleLog->Location = System::Drawing::Point(13, 462);
			this->ConsoleLog->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ConsoleLog->Name = L"ConsoleLog";
			this->ConsoleLog->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->ConsoleLog->Size = System::Drawing::Size(510, 62);
			this->ConsoleLog->TabIndex = 1;
			// 
			// godmode
			// 
			this->godmode->AutoSize = true;
			this->godmode->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->godmode->Location = System::Drawing::Point(5, 4);
			this->godmode->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->godmode->Name = L"godmode";
			this->godmode->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->godmode->Size = System::Drawing::Size(79, 19);
			this->godmode->TabIndex = 1;
			this->godmode->Text = L"Godmode";
			this->godmode->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->godmode->UseVisualStyleBackColor = true;
			this->godmode->CheckedChanged += gcnew System::EventHandler(this, &MainForm::godmode_CheckedChanged);
			// 
			// infinitemana
			// 
			this->infinitemana->AutoSize = true;
			this->infinitemana->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->infinitemana->Location = System::Drawing::Point(5, 30);
			this->infinitemana->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->infinitemana->Name = L"infinitemana";
			this->infinitemana->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->infinitemana->Size = System::Drawing::Size(96, 19);
			this->infinitemana->TabIndex = 2;
			this->infinitemana->Text = L"Infinite Mana";
			this->infinitemana->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->infinitemana->UseVisualStyleBackColor = true;
			this->infinitemana->CheckedChanged += gcnew System::EventHandler(this, &MainForm::infinitemana_CheckedChanged);
			// 
			// nohunger
			// 
			this->nohunger->AutoSize = true;
			this->nohunger->Location = System::Drawing::Point(5, 56);
			this->nohunger->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->nohunger->Name = L"nohunger";
			this->nohunger->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->nohunger->Size = System::Drawing::Size(84, 19);
			this->nohunger->TabIndex = 3;
			this->nohunger->Text = L"No Hunger";
			this->nohunger->UseVisualStyleBackColor = true;
			this->nohunger->CheckedChanged += gcnew System::EventHandler(this, &MainForm::nohunger_CheckedChanged);
			// 
			// GUITimer
			// 
			this->GUITimer->Enabled = true;
			this->GUITimer->Interval = 250;
			this->GUITimer->Tick += gcnew System::EventHandler(this, &MainForm::GUITimer_Tick);
			// 
			// attached
			// 
			this->attached->AutoSize = true;
			this->attached->Location = System::Drawing::Point(511, 616);
			this->attached->Name = L"attached";
			this->attached->Size = System::Drawing::Size(0, 15);
			this->attached->TabIndex = 1;
			// 
			// attachedtext
			// 
			this->attachedtext->AutoSize = true;
			this->attachedtext->ForeColor = System::Drawing::SystemColors::ControlText;
			this->attachedtext->Location = System::Drawing::Point(469, 616);
			this->attachedtext->Name = L"attachedtext";
			this->attachedtext->Size = System::Drawing::Size(44, 15);
			this->attachedtext->TabIndex = 1;
			this->attachedtext->Text = L"Status: ";
			// 
			// applystats
			// 
			this->applystats->Location = System::Drawing::Point(371, 470);
			this->applystats->Name = L"applystats";
			this->applystats->Size = System::Drawing::Size(127, 26);
			this->applystats->TabIndex = 37;
			this->applystats->Text = L"Refresh + Apply";
			this->applystats->UseVisualStyleBackColor = true;
			this->applystats->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->minmovspd);
			this->panel2->Controls->Add(this->nohunger);
			this->panel2->Controls->Add(this->godmode);
			this->panel2->Controls->Add(this->infinitemana);
			this->panel2->Location = System::Drawing::Point(13, 21);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(164, 195);
			this->panel2->TabIndex = 1;
			// 
			// minmovspd
			// 
			this->minmovspd->AutoSize = true;
			this->minmovspd->Location = System::Drawing::Point(5, 82);
			this->minmovspd->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->minmovspd->Name = L"minmovspd";
			this->minmovspd->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->minmovspd->Size = System::Drawing::Size(127, 19);
			this->minmovspd->TabIndex = 4;
			this->minmovspd->Text = L"0.1 AUT movement";
			this->minmovspd->UseVisualStyleBackColor = true;
			this->minmovspd->CheckedChanged += gcnew System::EventHandler(this, &MainForm::minmovspd_CheckedChanged);
			// 
			// maxitems
			// 
			this->maxitems->AutoSize = true;
			this->maxitems->Location = System::Drawing::Point(5, 56);
			this->maxitems->Name = L"maxitems";
			this->maxitems->Size = System::Drawing::Size(110, 19);
			this->maxitems->TabIndex = 3;
			this->maxitems->Text = L"Maximum Items";
			this->maxitems->UseVisualStyleBackColor = true;
			this->maxitems->CheckedChanged += gcnew System::EventHandler(this, &MainForm::maxitems_CheckedChanged);
			// 
			// idinven
			// 
			this->idinven->AutoSize = true;
			this->idinven->Location = System::Drawing::Point(5, 30);
			this->idinven->Name = L"idinven";
			this->idinven->Size = System::Drawing::Size(154, 19);
			this->idinven->TabIndex = 2;
			this->idinven->Text = L"Auto-identify most items";
			this->idinven->UseVisualStyleBackColor = true;
			this->idinven->CheckedChanged += gcnew System::EventHandler(this, &MainForm::idinven_CheckedChanged);
			// 
			// onehp
			// 
			this->onehp->AutoSize = true;
			this->onehp->Location = System::Drawing::Point(5, 108);
			this->onehp->Name = L"onehp";
			this->onehp->Size = System::Drawing::Size(67, 19);
			this->onehp->TabIndex = 5;
			this->onehp->Text = L"One HP";
			this->onehp->UseVisualStyleBackColor = true;
			this->onehp->CheckedChanged += gcnew System::EventHandler(this, &MainForm::onehp_CheckedChanged);
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->piety);
			this->panel1->Controls->Add(this->gold);
			this->panel1->Controls->Add(label10);
			this->panel1->Controls->Add(label9);
			this->panel1->Controls->Add(this->armour);
			this->panel1->Controls->Add(this->armor);
			this->panel1->Controls->Add(this->stealth);
			this->panel1->Controls->Add(this->applystats);
			this->panel1->Controls->Add(this->label60);
			this->panel1->Controls->Add(label3);
			this->panel1->Controls->Add(this->evocations);
			this->panel1->Controls->Add(this->label61);
			this->panel1->Controls->Add(this->invocations);
			this->panel1->Controls->Add(this->label62);
			this->panel1->Controls->Add(label2);
			this->panel1->Controls->Add(this->dexterity);
			this->panel1->Controls->Add(this->transmutations);
			this->panel1->Controls->Add(this->label33);
			this->panel1->Controls->Add(this->poisonmagic);
			this->panel1->Controls->Add(this->intelligence);
			this->panel1->Controls->Add(this->label34);
			this->panel1->Controls->Add(this->strength);
			this->panel1->Controls->Add(this->earthmagic);
			this->panel1->Controls->Add(label1);
			this->panel1->Controls->Add(this->label35);
			this->panel1->Controls->Add(this->airmagic);
			this->panel1->Controls->Add(this->label36);
			this->panel1->Controls->Add(this->icemagic);
			this->panel1->Controls->Add(this->label37);
			this->panel1->Controls->Add(this->firemagic);
			this->panel1->Controls->Add(this->label38);
			this->panel1->Controls->Add(this->translocations);
			this->panel1->Controls->Add(this->label39);
			this->panel1->Controls->Add(this->necromancy);
			this->panel1->Controls->Add(this->label40);
			this->panel1->Controls->Add(this->summonings);
			this->panel1->Controls->Add(this->label41);
			this->panel1->Controls->Add(this->charms);
			this->panel1->Controls->Add(this->label42);
			this->panel1->Controls->Add(this->hexes);
			this->panel1->Controls->Add(this->label43);
			this->panel1->Controls->Add(this->label44);
			this->panel1->Controls->Add(this->conjurations);
			this->panel1->Controls->Add(this->fighting);
			this->panel1->Controls->Add(this->label45);
			this->panel1->Controls->Add(this->spellcasting);
			this->panel1->Controls->Add(this->label46);
			this->panel1->Controls->Add(this->label47);
			this->panel1->Controls->Add(this->shortblades);
			this->panel1->Controls->Add(this->shields);
			this->panel1->Controls->Add(this->unarmedcombat);
			this->panel1->Controls->Add(this->label48);
			this->panel1->Controls->Add(this->label49);
			this->panel1->Controls->Add(this->dodging);
			this->panel1->Controls->Add(this->label50);
			this->panel1->Controls->Add(this->label51);
			this->panel1->Controls->Add(this->staves);
			this->panel1->Controls->Add(this->label52);
			this->panel1->Controls->Add(this->slings);
			this->panel1->Controls->Add(this->longblades);
			this->panel1->Controls->Add(this->label32);
			this->panel1->Controls->Add(this->throwing);
			this->panel1->Controls->Add(this->polearms);
			this->panel1->Controls->Add(this->label53);
			this->panel1->Controls->Add(this->label54);
			this->panel1->Controls->Add(this->crossbows);
			this->panel1->Controls->Add(this->label55);
			this->panel1->Controls->Add(this->label56);
			this->panel1->Controls->Add(this->axes);
			this->panel1->Controls->Add(this->bows);
			this->panel1->Controls->Add(this->label57);
			this->panel1->Controls->Add(this->label58);
			this->panel1->Controls->Add(this->maces);
			this->panel1->Location = System::Drawing::Point(6, 22);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(524, 517);
			this->panel1->TabIndex = 1;
			// 
			// piety
			// 
			this->piety->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->piety->Location = System::Drawing::Point(439, 160);
			this->piety->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->piety->MaxLength = 3;
			this->piety->Name = L"piety";
			this->piety->Size = System::Drawing::Size(59, 22);
			this->piety->TabIndex = 36;
			// 
			// gold
			// 
			this->gold->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->gold->Location = System::Drawing::Point(439, 130);
			this->gold->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->gold->MaxLength = 9;
			this->gold->Name = L"gold";
			this->gold->Size = System::Drawing::Size(59, 22);
			this->gold->TabIndex = 35;
			// 
			// armour
			// 
			this->armour->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->armour->Location = System::Drawing::Point(118, 428);
			this->armour->MaxLength = 4;
			this->armour->Name = L"armour";
			this->armour->Size = System::Drawing::Size(37, 22);
			this->armour->TabIndex = 13;
			// 
			// armor
			// 
			this->armor->AutoSize = true;
			this->armor->Location = System::Drawing::Point(12, 430);
			this->armor->Name = L"armor";
			this->armor->Size = System::Drawing::Size(49, 15);
			this->armor->TabIndex = 1;
			this->armor->Text = L"Armour";
			// 
			// stealth
			// 
			this->stealth->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->stealth->Location = System::Drawing::Point(295, 488);
			this->stealth->MaxLength = 4;
			this->stealth->Name = L"stealth";
			this->stealth->Size = System::Drawing::Size(37, 22);
			this->stealth->TabIndex = 31;
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Location = System::Drawing::Point(188, 490);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(43, 15);
			this->label60->TabIndex = 1;
			this->label60->Text = L"Stealth";
			// 
			// evocations
			// 
			this->evocations->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->evocations->Location = System::Drawing::Point(295, 458);
			this->evocations->MaxLength = 4;
			this->evocations->Name = L"evocations";
			this->evocations->Size = System::Drawing::Size(37, 22);
			this->evocations->TabIndex = 30;
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(188, 460);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(65, 15);
			this->label61->TabIndex = 1;
			this->label61->Text = L"Evocations";
			// 
			// invocations
			// 
			this->invocations->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->invocations->Location = System::Drawing::Point(295, 428);
			this->invocations->MaxLength = 4;
			this->invocations->Name = L"invocations";
			this->invocations->Size = System::Drawing::Size(37, 22);
			this->invocations->TabIndex = 29;
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(188, 430);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(69, 15);
			this->label62->TabIndex = 1;
			this->label62->Text = L"Invocations";
			// 
			// transmutations
			// 
			this->transmutations->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->transmutations->Location = System::Drawing::Point(295, 218);
			this->transmutations->MaxLength = 4;
			this->transmutations->Name = L"transmutations";
			this->transmutations->Size = System::Drawing::Size(37, 22);
			this->transmutations->TabIndex = 23;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(188, 220);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(89, 15);
			this->label33->TabIndex = 1;
			this->label33->Text = L"Transmutations";
			// 
			// poisonmagic
			// 
			this->poisonmagic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->poisonmagic->Location = System::Drawing::Point(295, 368);
			this->poisonmagic->MaxLength = 4;
			this->poisonmagic->Name = L"poisonmagic";
			this->poisonmagic->Size = System::Drawing::Size(37, 22);
			this->poisonmagic->TabIndex = 28;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(188, 370);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(77, 15);
			this->label34->TabIndex = 1;
			this->label34->Text = L"Poison Magic";
			// 
			// earthmagic
			// 
			this->earthmagic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->earthmagic->Location = System::Drawing::Point(295, 338);
			this->earthmagic->MaxLength = 4;
			this->earthmagic->Name = L"earthmagic";
			this->earthmagic->Size = System::Drawing::Size(37, 22);
			this->earthmagic->TabIndex = 27;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(188, 340);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(70, 15);
			this->label35->TabIndex = 1;
			this->label35->Text = L"Earth Magic";
			// 
			// airmagic
			// 
			this->airmagic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->airmagic->Location = System::Drawing::Point(295, 308);
			this->airmagic->MaxLength = 4;
			this->airmagic->Name = L"airmagic";
			this->airmagic->Size = System::Drawing::Size(37, 22);
			this->airmagic->TabIndex = 26;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(188, 310);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(57, 15);
			this->label36->TabIndex = 1;
			this->label36->Text = L"Air Magic";
			// 
			// icemagic
			// 
			this->icemagic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->icemagic->Location = System::Drawing::Point(295, 278);
			this->icemagic->MaxLength = 4;
			this->icemagic->Name = L"icemagic";
			this->icemagic->Size = System::Drawing::Size(37, 22);
			this->icemagic->TabIndex = 25;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(188, 280);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(57, 15);
			this->label37->TabIndex = 1;
			this->label37->Text = L"Ice Magic";
			// 
			// firemagic
			// 
			this->firemagic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->firemagic->Location = System::Drawing::Point(295, 248);
			this->firemagic->MaxLength = 4;
			this->firemagic->Name = L"firemagic";
			this->firemagic->Size = System::Drawing::Size(37, 22);
			this->firemagic->TabIndex = 24;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(188, 250);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(62, 15);
			this->label38->TabIndex = 1;
			this->label38->Text = L"Fire Magic";
			// 
			// translocations
			// 
			this->translocations->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->translocations->Location = System::Drawing::Point(295, 188);
			this->translocations->MaxLength = 4;
			this->translocations->Name = L"translocations";
			this->translocations->Size = System::Drawing::Size(37, 22);
			this->translocations->TabIndex = 22;
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(188, 190);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(84, 15);
			this->label39->TabIndex = 1;
			this->label39->Text = L"Translocations";
			// 
			// necromancy
			// 
			this->necromancy->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->necromancy->Location = System::Drawing::Point(295, 158);
			this->necromancy->MaxLength = 4;
			this->necromancy->Name = L"necromancy";
			this->necromancy->Size = System::Drawing::Size(37, 22);
			this->necromancy->TabIndex = 21;
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(188, 160);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(75, 15);
			this->label40->TabIndex = 1;
			this->label40->Text = L"Necromancy";
			// 
			// summonings
			// 
			this->summonings->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->summonings->Location = System::Drawing::Point(295, 128);
			this->summonings->MaxLength = 4;
			this->summonings->Name = L"summonings";
			this->summonings->Size = System::Drawing::Size(37, 22);
			this->summonings->TabIndex = 20;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(188, 130);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(75, 15);
			this->label41->TabIndex = 1;
			this->label41->Text = L"Summonings";
			// 
			// charms
			// 
			this->charms->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->charms->Location = System::Drawing::Point(295, 98);
			this->charms->MaxLength = 4;
			this->charms->Name = L"charms";
			this->charms->Size = System::Drawing::Size(37, 22);
			this->charms->TabIndex = 19;
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(188, 100);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(48, 15);
			this->label42->TabIndex = 1;
			this->label42->Text = L"Charms";
			// 
			// hexes
			// 
			this->hexes->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->hexes->Location = System::Drawing::Point(295, 68);
			this->hexes->MaxLength = 4;
			this->hexes->Name = L"hexes";
			this->hexes->Size = System::Drawing::Size(37, 22);
			this->hexes->TabIndex = 18;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(188, 70);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(39, 15);
			this->label43->TabIndex = 1;
			this->label43->Text = L"Hexes";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(12, 10);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(50, 15);
			this->label44->TabIndex = 1;
			this->label44->Text = L"Fighting";
			// 
			// conjurations
			// 
			this->conjurations->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->conjurations->Location = System::Drawing::Point(295, 38);
			this->conjurations->MaxLength = 4;
			this->conjurations->Name = L"conjurations";
			this->conjurations->Size = System::Drawing::Size(37, 22);
			this->conjurations->TabIndex = 17;
			// 
			// fighting
			// 
			this->fighting->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->fighting->Location = System::Drawing::Point(118, 8);
			this->fighting->MaxLength = 4;
			this->fighting->Name = L"fighting";
			this->fighting->Size = System::Drawing::Size(37, 22);
			this->fighting->TabIndex = 1;
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(188, 40);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(76, 15);
			this->label45->TabIndex = 1;
			this->label45->Text = L"Conjurations";
			// 
			// spellcasting
			// 
			this->spellcasting->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->spellcasting->Location = System::Drawing::Point(295, 8);
			this->spellcasting->MaxLength = 4;
			this->spellcasting->Name = L"spellcasting";
			this->spellcasting->Size = System::Drawing::Size(37, 22);
			this->spellcasting->TabIndex = 16;
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(12, 40);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(73, 15);
			this->label46->TabIndex = 1;
			this->label46->Text = L"Short Blades";
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(188, 10);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(69, 15);
			this->label47->TabIndex = 1;
			this->label47->Text = L"Spellcasting";
			// 
			// shortblades
			// 
			this->shortblades->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->shortblades->Location = System::Drawing::Point(118, 38);
			this->shortblades->MaxLength = 4;
			this->shortblades->Name = L"shortblades";
			this->shortblades->Size = System::Drawing::Size(37, 22);
			this->shortblades->TabIndex = 2;
			// 
			// shields
			// 
			this->shields->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->shields->Location = System::Drawing::Point(118, 488);
			this->shields->MaxLength = 4;
			this->shields->Name = L"shields";
			this->shields->Size = System::Drawing::Size(37, 22);
			this->shields->TabIndex = 15;
			// 
			// unarmedcombat
			// 
			this->unarmedcombat->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->unarmedcombat->Location = System::Drawing::Point(118, 218);
			this->unarmedcombat->MaxLength = 4;
			this->unarmedcombat->Name = L"unarmedcombat";
			this->unarmedcombat->Size = System::Drawing::Size(37, 22);
			this->unarmedcombat->TabIndex = 8;
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(12, 490);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(44, 15);
			this->label48->TabIndex = 1;
			this->label48->Text = L"Shields";
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(12, 220);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(101, 15);
			this->label49->TabIndex = 1;
			this->label49->Text = L"Unarmed Combat";
			// 
			// dodging
			// 
			this->dodging->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dodging->Location = System::Drawing::Point(118, 458);
			this->dodging->MaxLength = 4;
			this->dodging->Name = L"dodging";
			this->dodging->Size = System::Drawing::Size(37, 22);
			this->dodging->TabIndex = 14;
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(12, 70);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(70, 15);
			this->label50->TabIndex = 1;
			this->label50->Text = L"Long Blades";
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(12, 460);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(52, 15);
			this->label51->TabIndex = 1;
			this->label51->Text = L"Dodging";
			// 
			// staves
			// 
			this->staves->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->staves->Location = System::Drawing::Point(118, 188);
			this->staves->MaxLength = 4;
			this->staves->Name = L"staves";
			this->staves->Size = System::Drawing::Size(37, 22);
			this->staves->TabIndex = 7;
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(12, 190);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(40, 15);
			this->label52->TabIndex = 1;
			this->label52->Text = L"Staves";
			// 
			// slings
			// 
			this->slings->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->slings->Location = System::Drawing::Point(118, 368);
			this->slings->MaxLength = 4;
			this->slings->Name = L"slings";
			this->slings->Size = System::Drawing::Size(37, 22);
			this->slings->TabIndex = 12;
			// 
			// longblades
			// 
			this->longblades->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->longblades->Location = System::Drawing::Point(118, 68);
			this->longblades->MaxLength = 4;
			this->longblades->Name = L"longblades";
			this->longblades->Size = System::Drawing::Size(37, 22);
			this->longblades->TabIndex = 3;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(12, 370);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(37, 15);
			this->label32->TabIndex = 1;
			this->label32->Text = L"Slings";
			// 
			// throwing
			// 
			this->throwing->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->throwing->Location = System::Drawing::Point(118, 338);
			this->throwing->MaxLength = 4;
			this->throwing->Name = L"throwing";
			this->throwing->Size = System::Drawing::Size(37, 22);
			this->throwing->TabIndex = 11;
			// 
			// polearms
			// 
			this->polearms->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->polearms->Location = System::Drawing::Point(118, 158);
			this->polearms->MaxLength = 4;
			this->polearms->Name = L"polearms";
			this->polearms->Size = System::Drawing::Size(37, 22);
			this->polearms->TabIndex = 6;
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(12, 340);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(58, 15);
			this->label53->TabIndex = 1;
			this->label53->Text = L"Throwing";
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(12, 160);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(56, 15);
			this->label54->TabIndex = 1;
			this->label54->Text = L"Polearms";
			// 
			// crossbows
			// 
			this->crossbows->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->crossbows->Location = System::Drawing::Point(118, 308);
			this->crossbows->MaxLength = 4;
			this->crossbows->Name = L"crossbows";
			this->crossbows->Size = System::Drawing::Size(37, 22);
			this->crossbows->TabIndex = 10;
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Location = System::Drawing::Point(12, 100);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(92, 15);
			this->label55->TabIndex = 1;
			this->label55->Text = L"Maces and Flails";
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Location = System::Drawing::Point(12, 310);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(65, 15);
			this->label56->TabIndex = 1;
			this->label56->Text = L"Crossbows";
			// 
			// axes
			// 
			this->axes->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->axes->Location = System::Drawing::Point(118, 128);
			this->axes->MaxLength = 4;
			this->axes->Name = L"axes";
			this->axes->Size = System::Drawing::Size(37, 22);
			this->axes->TabIndex = 5;
			// 
			// bows
			// 
			this->bows->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bows->Location = System::Drawing::Point(118, 278);
			this->bows->MaxLength = 4;
			this->bows->Name = L"bows";
			this->bows->Size = System::Drawing::Size(37, 22);
			this->bows->TabIndex = 9;
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Location = System::Drawing::Point(12, 130);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(32, 15);
			this->label57->TabIndex = 1;
			this->label57->Text = L"Axes";
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Location = System::Drawing::Point(12, 280);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(36, 15);
			this->label58->TabIndex = 1;
			this->label58->Text = L"Bows";
			// 
			// maces
			// 
			this->maces->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->maces->Location = System::Drawing::Point(118, 98);
			this->maces->MaxLength = 4;
			this->maces->Name = L"maces";
			this->maces->Size = System::Drawing::Size(37, 22);
			this->maces->TabIndex = 4;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->convertally);
			this->panel3->Controls->Add(this->allymaxspd);
			this->panel3->Controls->Add(this->permasleep);
			this->panel3->Controls->Add(this->instakill);
			this->panel3->Controls->Add(this->disablemovement);
			this->panel3->Controls->Add(this->mfreeze);
			this->panel3->Controls->Add(this->onehp);
			this->panel3->Location = System::Drawing::Point(186, 21);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(164, 195);
			this->panel3->TabIndex = 1;
			// 
			// convertally
			// 
			this->convertally->AutoSize = true;
			this->convertally->Location = System::Drawing::Point(5, 160);
			this->convertally->Name = L"convertally";
			this->convertally->Size = System::Drawing::Size(120, 19);
			this->convertally->TabIndex = 7;
			this->convertally->Text = L"Convert All to Ally";
			this->convertally->UseVisualStyleBackColor = true;
			this->convertally->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox109_CheckedChanged);
			// 
			// allymaxspd
			// 
			this->allymaxspd->AutoSize = true;
			this->allymaxspd->Location = System::Drawing::Point(5, 134);
			this->allymaxspd->Name = L"allymaxspd";
			this->allymaxspd->Size = System::Drawing::Size(105, 19);
			this->allymaxspd->TabIndex = 6;
			this->allymaxspd->Text = L"Ally Max Speed";
			this->allymaxspd->UseVisualStyleBackColor = true;
			this->allymaxspd->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox108_CheckedChanged);
			// 
			// permasleep
			// 
			this->permasleep->AutoSize = true;
			this->permasleep->Location = System::Drawing::Point(5, 82);
			this->permasleep->Name = L"permasleep";
			this->permasleep->Size = System::Drawing::Size(87, 19);
			this->permasleep->TabIndex = 4;
			this->permasleep->Text = L"Permasleep";
			this->permasleep->UseVisualStyleBackColor = true;
			this->permasleep->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox1_CheckedChanged);
			// 
			// instakill
			// 
			this->instakill->AutoSize = true;
			this->instakill->Location = System::Drawing::Point(5, 4);
			this->instakill->Name = L"instakill";
			this->instakill->Size = System::Drawing::Size(67, 19);
			this->instakill->TabIndex = 1;
			this->instakill->Text = L"Instakill";
			this->instakill->UseVisualStyleBackColor = true;
			this->instakill->CheckedChanged += gcnew System::EventHandler(this, &MainForm::instakill_CheckedChanged);
			// 
			// disablemovement
			// 
			this->disablemovement->AutoSize = true;
			this->disablemovement->Location = System::Drawing::Point(5, 56);
			this->disablemovement->Name = L"disablemovement";
			this->disablemovement->Size = System::Drawing::Size(124, 19);
			this->disablemovement->TabIndex = 3;
			this->disablemovement->Text = L"Disable Movement";
			this->disablemovement->UseVisualStyleBackColor = true;
			this->disablemovement->CheckedChanged += gcnew System::EventHandler(this, &MainForm::disablemovement_CheckedChanged);
			// 
			// mfreeze
			// 
			this->mfreeze->AutoSize = true;
			this->mfreeze->Location = System::Drawing::Point(5, 30);
			this->mfreeze->Name = L"mfreeze";
			this->mfreeze->Size = System::Drawing::Size(62, 19);
			this->mfreeze->TabIndex = 2;
			this->mfreeze->Text = L"Freeze";
			this->mfreeze->UseVisualStyleBackColor = true;
			this->mfreeze->CheckedChanged += gcnew System::EventHandler(this, &MainForm::mfreeze_CheckedChanged);
			// 
			// mmapping
			// 
			this->mmapping->AutoSize = true;
			this->mmapping->Location = System::Drawing::Point(5, 4);
			this->mmapping->Name = L"mmapping";
			this->mmapping->Size = System::Drawing::Size(110, 19);
			this->mmapping->TabIndex = 1;
			this->mmapping->Text = L"Auto MagicMap";
			this->mmapping->UseVisualStyleBackColor = true;
			this->mmapping->CheckedChanged += gcnew System::EventHandler(this, &MainForm::mmapping_CheckedChanged);
			// 
			// tabboxthing
			// 
			this->tabboxthing->AccessibleDescription = L"";
			this->tabboxthing->AccessibleName = L"";
			this->tabboxthing->Controls->Add(this->tabpage1);
			this->tabboxthing->Controls->Add(this->tabPage2);
			this->tabboxthing->Controls->Add(this->Mutations);
			this->tabboxthing->Location = System::Drawing::Point(9, 17);
			this->tabboxthing->Margin = System::Windows::Forms::Padding(0);
			this->tabboxthing->Name = L"tabboxthing";
			this->tabboxthing->SelectedIndex = 0;
			this->tabboxthing->Size = System::Drawing::Size(544, 576);
			this->tabboxthing->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->tabboxthing->TabIndex = 1;
			// 
			// tabpage1
			// 
			this->tabpage1->BackColor = System::Drawing::SystemColors::Control;
			this->tabpage1->Controls->Add(label11);
			this->tabpage1->Controls->Add(label6);
			this->tabpage1->Controls->Add(this->panel4);
			this->tabpage1->Controls->Add(label5);
			this->tabpage1->Controls->Add(this->ConsoleLog);
			this->tabpage1->Controls->Add(this->panel2);
			this->tabpage1->Controls->Add(this->panel3);
			this->tabpage1->Controls->Add(label4);
			this->tabpage1->Location = System::Drawing::Point(4, 24);
			this->tabpage1->Name = L"tabpage1";
			this->tabpage1->Size = System::Drawing::Size(536, 548);
			this->tabpage1->TabIndex = 1;
			this->tabpage1->Text = L"Hacks";
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->maxcharge);
			this->panel4->Controls->Add(this->acqui);
			this->panel4->Controls->Add(this->maxitems);
			this->panel4->Controls->Add(this->mmapping);
			this->panel4->Controls->Add(this->idinven);
			this->panel4->Location = System::Drawing::Point(359, 21);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(164, 195);
			this->panel4->TabIndex = 1;
			// 
			// maxcharge
			// 
			this->maxcharge->AutoSize = true;
			this->maxcharge->Location = System::Drawing::Point(5, 82);
			this->maxcharge->Name = L"maxcharge";
			this->maxcharge->Size = System::Drawing::Size(157, 19);
			this->maxcharge->TabIndex = 4;
			this->maxcharge->Text = L"Maximum Wand Charges";
			this->maxcharge->UseVisualStyleBackColor = true;
			this->maxcharge->CheckedChanged += gcnew System::EventHandler(this, &MainForm::maxcharge_CheckedChanged);
			// 
			// acqui
			// 
			this->acqui->AutoSize = true;
			this->acqui->Enabled = false;
			this->acqui->Location = System::Drawing::Point(5, 108);
			this->acqui->Name = L"acqui";
			this->acqui->Size = System::Drawing::Size(95, 19);
			this->acqui->TabIndex = 5;
			this->acqui->TabStop = false;
			this->acqui->Text = L"Acquirement";
			this->acqui->UseVisualStyleBackColor = true;
			this->acqui->Visible = false;
			this->acqui->CheckedChanged += gcnew System::EventHandler(this, &MainForm::acqui_CheckedChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::Control;
			this->tabPage2->Controls->Add(this->panel1);
			this->tabPage2->Controls->Add(customstat);
			this->tabPage2->Location = System::Drawing::Point(4, 24);
			this->tabPage2->Margin = System::Windows::Forms::Padding(0);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Size = System::Drawing::Size(536, 548);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Skills / Various";
			// 
			// Mutations
			// 
			this->Mutations->BackColor = System::Drawing::SystemColors::Control;
			this->Mutations->Controls->Add(this->button2);
			this->Mutations->Controls->Add(this->button1);
			this->Mutations->Controls->Add(this->panel6);
			this->Mutations->Controls->Add(this->panel5);
			this->Mutations->Controls->Add(label8);
			this->Mutations->Controls->Add(label7);
			this->Mutations->Location = System::Drawing::Point(4, 24);
			this->Mutations->Name = L"Mutations";
			this->Mutations->Size = System::Drawing::Size(536, 548);
			this->Mutations->TabIndex = 1;
			this->Mutations->Text = L"Mutations";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(289, 508);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(176, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Remove all Bad Mutations";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(71, 508);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(176, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Activate all Good Mutations";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click_1);
			// 
			// panel6
			// 
			this->panel6->AutoScroll = true;
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Controls->Add(this->checkBox105);
			this->panel6->Controls->Add(this->checkBox106);
			this->panel6->Controls->Add(this->checkBox107);
			this->panel6->Controls->Add(this->checkBox30);
			this->panel6->Controls->Add(this->checkBox101);
			this->panel6->Controls->Add(this->checkBox32);
			this->panel6->Controls->Add(this->checkBox102);
			this->panel6->Controls->Add(this->checkBox103);
			this->panel6->Controls->Add(this->checkBox136);
			this->panel6->Controls->Add(this->checkBox137);
			this->panel6->Controls->Add(this->checkBox138);
			this->panel6->Controls->Add(this->checkBox139);
			this->panel6->Controls->Add(this->checkBox156);
			this->panel6->Controls->Add(this->checkBox157);
			this->panel6->Controls->Add(this->checkBox158);
			this->panel6->Controls->Add(this->checkBox159);
			this->panel6->Controls->Add(this->checkBox176);
			this->panel6->Controls->Add(this->checkBox177);
			this->panel6->Controls->Add(this->checkBox178);
			this->panel6->Controls->Add(this->checkBox179);
			this->panel6->Controls->Add(this->checkBox196);
			this->panel6->Controls->Add(this->checkBox197);
			this->panel6->Controls->Add(this->checkBox198);
			this->panel6->Controls->Add(this->checkBox199);
			this->panel6->Controls->Add(this->checkBox35);
			this->panel6->Location = System::Drawing::Point(3, 358);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(530, 134);
			this->panel6->TabIndex = 1;
			// 
			// checkBox105
			// 
			this->checkBox105->AutoSize = true;
			this->checkBox105->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox105->Location = System::Drawing::Point(126, 113);
			this->checkBox105->Name = L"checkBox105";
			this->checkBox105->Size = System::Drawing::Size(67, 17);
			this->checkBox105->TabIndex = 1;
			this->checkBox105->Text = L"No Read";
			this->checkBox105->UseVisualStyleBackColor = true;
			this->checkBox105->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox105_CheckedChanged);
			// 
			// checkBox106
			// 
			this->checkBox106->AutoSize = true;
			this->checkBox106->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox106->Location = System::Drawing::Point(5, 113);
			this->checkBox106->Name = L"checkBox106";
			this->checkBox106->Size = System::Drawing::Size(69, 17);
			this->checkBox106->TabIndex = 1;
			this->checkBox106->Text = L"No Drink";
			this->checkBox106->UseVisualStyleBackColor = true;
			this->checkBox106->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox106_CheckedChanged);
			// 
			// checkBox107
			// 
			this->checkBox107->AutoSize = true;
			this->checkBox107->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox107->Location = System::Drawing::Point(375, 114);
			this->checkBox107->Name = L"checkBox107";
			this->checkBox107->Size = System::Drawing::Size(73, 17);
			this->checkBox107->TabIndex = 1;
			this->checkBox107->Text = L"No Regen";
			this->checkBox107->UseVisualStyleBackColor = true;
			this->checkBox107->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox107_CheckedChanged);
			// 
			// checkBox30
			// 
			this->checkBox30->AutoSize = true;
			this->checkBox30->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox30->Location = System::Drawing::Point(249, 91);
			this->checkBox30->Name = L"checkBox30";
			this->checkBox30->Size = System::Drawing::Size(61, 17);
			this->checkBox30->TabIndex = 1;
			this->checkBox30->Text = L"Forlorn";
			this->checkBox30->UseVisualStyleBackColor = true;
			this->checkBox30->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox30_CheckedChanged);
			// 
			// checkBox101
			// 
			this->checkBox101->AutoSize = true;
			this->checkBox101->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox101->Location = System::Drawing::Point(126, 91);
			this->checkBox101->Name = L"checkBox101";
			this->checkBox101->Size = System::Drawing::Size(93, 17);
			this->checkBox101->TabIndex = 1;
			this->checkBox101->Text = L"Cold-Blooded";
			this->checkBox101->UseVisualStyleBackColor = true;
			this->checkBox101->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox101_CheckedChanged);
			// 
			// checkBox32
			// 
			this->checkBox32->AutoSize = true;
			this->checkBox32->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox32->Location = System::Drawing::Point(5, 135);
			this->checkBox32->Name = L"checkBox32";
			this->checkBox32->Size = System::Drawing::Size(107, 17);
			this->checkBox32->TabIndex = 1;
			this->checkBox32->Text = L"Fast Metabolism";
			this->checkBox32->UseVisualStyleBackColor = true;
			this->checkBox32->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox32_CheckedChanged);
			// 
			// checkBox102
			// 
			this->checkBox102->AutoSize = true;
			this->checkBox102->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox102->Location = System::Drawing::Point(5, 91);
			this->checkBox102->Name = L"checkBox102";
			this->checkBox102->Size = System::Drawing::Size(56, 17);
			this->checkBox102->TabIndex = 1;
			this->checkBox102->Text = L"rElec -";
			this->checkBox102->UseVisualStyleBackColor = true;
			this->checkBox102->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox102_CheckedChanged);
			// 
			// checkBox103
			// 
			this->checkBox103->AutoSize = true;
			this->checkBox103->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox103->Location = System::Drawing::Point(375, 92);
			this->checkBox103->Name = L"checkBox103";
			this->checkBox103->Size = System::Drawing::Size(100, 17);
			this->checkBox103->TabIndex = 1;
			this->checkBox103->Text = L"Subdued Magic";
			this->checkBox103->UseVisualStyleBackColor = true;
			this->checkBox103->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox103_CheckedChanged);
			// 
			// checkBox136
			// 
			this->checkBox136->AutoSize = true;
			this->checkBox136->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox136->Location = System::Drawing::Point(249, 69);
			this->checkBox136->Name = L"checkBox136";
			this->checkBox136->Size = System::Drawing::Size(44, 17);
			this->checkBox136->TabIndex = 1;
			this->checkBox136->Text = L"rC -";
			this->checkBox136->UseVisualStyleBackColor = true;
			this->checkBox136->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox136_CheckedChanged);
			// 
			// checkBox137
			// 
			this->checkBox137->AutoSize = true;
			this->checkBox137->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox137->Location = System::Drawing::Point(249, 47);
			this->checkBox137->Name = L"checkBox137";
			this->checkBox137->Size = System::Drawing::Size(102, 17);
			this->checkBox137->TabIndex = 1;
			this->checkBox137->Text = L"Inhibited Regen";
			this->checkBox137->UseVisualStyleBackColor = true;
			this->checkBox137->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox137_CheckedChanged);
			// 
			// checkBox138
			// 
			this->checkBox138->AutoSize = true;
			this->checkBox138->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox138->Location = System::Drawing::Point(249, 25);
			this->checkBox138->Name = L"checkBox138";
			this->checkBox138->Size = System::Drawing::Size(48, 17);
			this->checkBox138->TabIndex = 1;
			this->checkBox138->Text = L"Frail";
			this->checkBox138->UseVisualStyleBackColor = true;
			this->checkBox138->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox138_CheckedChanged);
			// 
			// checkBox139
			// 
			this->checkBox139->AutoSize = true;
			this->checkBox139->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox139->Location = System::Drawing::Point(249, 3);
			this->checkBox139->Name = L"checkBox139";
			this->checkBox139->Size = System::Drawing::Size(63, 17);
			this->checkBox139->TabIndex = 1;
			this->checkBox139->Text = L"Clumsy";
			this->checkBox139->UseVisualStyleBackColor = true;
			this->checkBox139->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox139_CheckedChanged);
			// 
			// checkBox156
			// 
			this->checkBox156->AutoSize = true;
			this->checkBox156->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox156->Location = System::Drawing::Point(126, 69);
			this->checkBox156->Name = L"checkBox156";
			this->checkBox156->Size = System::Drawing::Size(99, 17);
			this->checkBox156->TabIndex = 1;
			this->checkBox156->Text = L"No Potion Heal";
			this->checkBox156->UseVisualStyleBackColor = true;
			this->checkBox156->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox156_CheckedChanged);
			// 
			// checkBox157
			// 
			this->checkBox157->AutoSize = true;
			this->checkBox157->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox157->Location = System::Drawing::Point(126, 47);
			this->checkBox157->Name = L"checkBox157";
			this->checkBox157->Size = System::Drawing::Size(71, 17);
			this->checkBox157->TabIndex = 1;
			this->checkBox157->Text = L"Slowness";
			this->checkBox157->UseVisualStyleBackColor = true;
			this->checkBox157->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox157_CheckedChanged);
			// 
			// checkBox158
			// 
			this->checkBox158->AutoSize = true;
			this->checkBox158->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox158->Location = System::Drawing::Point(126, 25);
			this->checkBox158->Name = L"checkBox158";
			this->checkBox158->Size = System::Drawing::Size(58, 17);
			this->checkBox158->TabIndex = 1;
			this->checkBox158->Text = L"Dopey";
			this->checkBox158->UseVisualStyleBackColor = true;
			this->checkBox158->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox158_CheckedChanged);
			// 
			// checkBox159
			// 
			this->checkBox159->AutoSize = true;
			this->checkBox159->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox159->Location = System::Drawing::Point(126, 3);
			this->checkBox159->Name = L"checkBox159";
			this->checkBox159->Size = System::Drawing::Size(88, 17);
			this->checkBox159->TabIndex = 1;
			this->checkBox159->Text = L"Blurry Vision";
			this->checkBox159->UseVisualStyleBackColor = true;
			this->checkBox159->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox159_CheckedChanged);
			// 
			// checkBox176
			// 
			this->checkBox176->AutoSize = true;
			this->checkBox176->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox176->Location = System::Drawing::Point(5, 69);
			this->checkBox176->Name = L"checkBox176";
			this->checkBox176->Size = System::Drawing::Size(55, 17);
			this->checkBox176->TabIndex = 1;
			this->checkBox176->Text = L"Weak";
			this->checkBox176->UseVisualStyleBackColor = true;
			this->checkBox176->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox176_CheckedChanged);
			// 
			// checkBox177
			// 
			this->checkBox177->AutoSize = true;
			this->checkBox177->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox177->Location = System::Drawing::Point(5, 47);
			this->checkBox177->Name = L"checkBox177";
			this->checkBox177->Size = System::Drawing::Size(77, 17);
			this->checkBox177->TabIndex = 1;
			this->checkBox177->Text = L"Screaming";
			this->checkBox177->UseVisualStyleBackColor = true;
			this->checkBox177->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox177_CheckedChanged);
			// 
			// checkBox178
			// 
			this->checkBox178->AutoSize = true;
			this->checkBox178->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox178->Location = System::Drawing::Point(5, 25);
			this->checkBox178->Name = L"checkBox178";
			this->checkBox178->Size = System::Drawing::Size(92, 17);
			this->checkBox178->TabIndex = 1;
			this->checkBox178->Text = L"Deterioration";
			this->checkBox178->UseVisualStyleBackColor = true;
			this->checkBox178->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox178_CheckedChanged);
			// 
			// checkBox179
			// 
			this->checkBox179->AutoSize = true;
			this->checkBox179->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox179->Location = System::Drawing::Point(5, 3);
			this->checkBox179->Name = L"checkBox179";
			this->checkBox179->Size = System::Drawing::Size(64, 17);
			this->checkBox179->TabIndex = 1;
			this->checkBox179->Text = L"Berserk";
			this->checkBox179->UseVisualStyleBackColor = true;
			this->checkBox179->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox179_CheckedChanged);
			// 
			// checkBox196
			// 
			this->checkBox196->AutoSize = true;
			this->checkBox196->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox196->Location = System::Drawing::Point(375, 70);
			this->checkBox196->Name = L"checkBox196";
			this->checkBox196->Size = System::Drawing::Size(44, 17);
			this->checkBox196->TabIndex = 1;
			this->checkBox196->Text = L"rF - ";
			this->checkBox196->UseVisualStyleBackColor = true;
			this->checkBox196->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox196_CheckedChanged);
			// 
			// checkBox197
			// 
			this->checkBox197->AutoSize = true;
			this->checkBox197->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox197->Location = System::Drawing::Point(375, 48);
			this->checkBox197->Name = L"checkBox197";
			this->checkBox197->Size = System::Drawing::Size(81, 17);
			this->checkBox197->TabIndex = 1;
			this->checkBox197->Text = L"Teleportitis";
			this->checkBox197->UseVisualStyleBackColor = true;
			this->checkBox197->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox197_CheckedChanged);
			// 
			// checkBox198
			// 
			this->checkBox198->AutoSize = true;
			this->checkBox198->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox198->Location = System::Drawing::Point(375, 26);
			this->checkBox198->Name = L"checkBox198";
			this->checkBox198->Size = System::Drawing::Size(65, 17);
			this->checkBox198->TabIndex = 1;
			this->checkBox198->Text = L"Low MP";
			this->checkBox198->UseVisualStyleBackColor = true;
			this->checkBox198->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox198_CheckedChanged);
			// 
			// checkBox199
			// 
			this->checkBox199->AutoSize = true;
			this->checkBox199->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox199->Location = System::Drawing::Point(375, 4);
			this->checkBox199->Name = L"checkBox199";
			this->checkBox199->Size = System::Drawing::Size(102, 17);
			this->checkBox199->TabIndex = 1;
			this->checkBox199->Text = L"Deformed Body";
			this->checkBox199->UseVisualStyleBackColor = true;
			this->checkBox199->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox199_CheckedChanged);
			// 
			// checkBox35
			// 
			this->checkBox35->AutoSize = true;
			this->checkBox35->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox35->Location = System::Drawing::Point(249, 113);
			this->checkBox35->Name = L"checkBox35";
			this->checkBox35->Size = System::Drawing::Size(75, 17);
			this->checkBox35->TabIndex = 1;
			this->checkBox35->Text = L"Herbivore";
			this->checkBox35->UseVisualStyleBackColor = true;
			this->checkBox35->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox35_CheckedChanged);
			// 
			// panel5
			// 
			this->panel5->AutoScroll = true;
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Controls->Add(this->checkBox104);
			this->panel5->Controls->Add(this->checkBox81);
			this->panel5->Controls->Add(this->checkBox82);
			this->panel5->Controls->Add(this->checkBox83);
			this->panel5->Controls->Add(this->checkBox84);
			this->panel5->Controls->Add(this->checkBox85);
			this->panel5->Controls->Add(this->checkBox86);
			this->panel5->Controls->Add(this->checkBox87);
			this->panel5->Controls->Add(this->checkBox88);
			this->panel5->Controls->Add(this->checkBox89);
			this->panel5->Controls->Add(this->checkBox90);
			this->panel5->Controls->Add(this->checkBox91);
			this->panel5->Controls->Add(this->checkBox92);
			this->panel5->Controls->Add(this->checkBox93);
			this->panel5->Controls->Add(this->checkBox94);
			this->panel5->Controls->Add(this->checkBox95);
			this->panel5->Controls->Add(this->checkBox96);
			this->panel5->Controls->Add(this->checkBox97);
			this->panel5->Controls->Add(this->checkBox98);
			this->panel5->Controls->Add(this->checkBox99);
			this->panel5->Controls->Add(this->checkBox100);
			this->panel5->Controls->Add(this->checkBox61);
			this->panel5->Controls->Add(this->checkBox62);
			this->panel5->Controls->Add(this->checkBox63);
			this->panel5->Controls->Add(this->checkBox64);
			this->panel5->Controls->Add(this->checkBox65);
			this->panel5->Controls->Add(this->checkBox66);
			this->panel5->Controls->Add(this->checkBox67);
			this->panel5->Controls->Add(this->checkBox68);
			this->panel5->Controls->Add(this->checkBox69);
			this->panel5->Controls->Add(this->checkBox70);
			this->panel5->Controls->Add(this->checkBox71);
			this->panel5->Controls->Add(this->checkBox72);
			this->panel5->Controls->Add(this->checkBox73);
			this->panel5->Controls->Add(this->checkBox74);
			this->panel5->Controls->Add(this->checkBox75);
			this->panel5->Controls->Add(this->checkBox76);
			this->panel5->Controls->Add(this->checkBox77);
			this->panel5->Controls->Add(this->checkBox78);
			this->panel5->Controls->Add(this->checkBox79);
			this->panel5->Controls->Add(this->checkBox80);
			this->panel5->Controls->Add(this->checkBox41);
			this->panel5->Controls->Add(this->checkBox42);
			this->panel5->Controls->Add(this->checkBox43);
			this->panel5->Controls->Add(this->checkBox44);
			this->panel5->Controls->Add(this->checkBox45);
			this->panel5->Controls->Add(this->checkBox46);
			this->panel5->Controls->Add(this->checkBox47);
			this->panel5->Controls->Add(this->checkBox48);
			this->panel5->Controls->Add(this->checkBox49);
			this->panel5->Controls->Add(this->checkBox50);
			this->panel5->Controls->Add(this->checkBox51);
			this->panel5->Controls->Add(this->checkBox52);
			this->panel5->Controls->Add(this->checkBox53);
			this->panel5->Controls->Add(this->checkBox54);
			this->panel5->Controls->Add(this->checkBox55);
			this->panel5->Controls->Add(this->checkBox56);
			this->panel5->Controls->Add(this->checkBox57);
			this->panel5->Controls->Add(this->checkBox58);
			this->panel5->Controls->Add(this->checkBox59);
			this->panel5->Controls->Add(this->checkBox60);
			this->panel5->Controls->Add(this->checkBox31);
			this->panel5->Controls->Add(this->checkBox33);
			this->panel5->Controls->Add(this->checkBox34);
			this->panel5->Controls->Add(this->checkBox36);
			this->panel5->Controls->Add(this->checkBox37);
			this->panel5->Controls->Add(this->checkBox38);
			this->panel5->Controls->Add(this->checkBox39);
			this->panel5->Controls->Add(this->checkBox40);
			this->panel5->Controls->Add(this->checkBox21);
			this->panel5->Controls->Add(this->checkBox22);
			this->panel5->Controls->Add(this->checkBox23);
			this->panel5->Controls->Add(this->checkBox24);
			this->panel5->Controls->Add(this->checkBox25);
			this->panel5->Controls->Add(this->checkBox26);
			this->panel5->Controls->Add(this->checkBox27);
			this->panel5->Controls->Add(this->checkBox28);
			this->panel5->Controls->Add(this->checkBox29);
			this->panel5->Controls->Add(this->yellowscale);
			this->panel5->Controls->Add(this->checkBox17);
			this->panel5->Controls->Add(this->checkBox18);
			this->panel5->Controls->Add(this->checkBox19);
			this->panel5->Controls->Add(this->checkBox20);
			this->panel5->Controls->Add(this->checkBox9);
			this->panel5->Controls->Add(this->checkBox10);
			this->panel5->Controls->Add(this->checkBox11);
			this->panel5->Controls->Add(this->checkBox12);
			this->panel5->Controls->Add(this->checkBox13);
			this->panel5->Controls->Add(this->checkBox14);
			this->panel5->Controls->Add(this->checkBox15);
			this->panel5->Controls->Add(this->checkBox16);
			this->panel5->Controls->Add(this->checkBox5);
			this->panel5->Controls->Add(this->checkBox6);
			this->panel5->Controls->Add(this->checkBox7);
			this->panel5->Controls->Add(this->checkBox8);
			this->panel5->Controls->Add(this->checkBox3);
			this->panel5->Controls->Add(this->checkBox4);
			this->panel5->Controls->Add(this->checkBox2);
			this->panel5->Controls->Add(this->checkBox1);
			this->panel5->Location = System::Drawing::Point(3, 22);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(530, 310);
			this->panel5->TabIndex = 1;
			// 
			// checkBox104
			// 
			this->checkBox104->AutoSize = true;
			this->checkBox104->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox104->Location = System::Drawing::Point(249, 531);
			this->checkBox104->Name = L"checkBox104";
			this->checkBox104->Size = System::Drawing::Size(124, 17);
			this->checkBox104->TabIndex = 1;
			this->checkBox104->Text = L"MP Powered Wands";
			this->checkBox104->UseVisualStyleBackColor = true;
			this->checkBox104->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox104_CheckedChanged);
			// 
			// checkBox81
			// 
			this->checkBox81->AutoSize = true;
			this->checkBox81->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox81->Location = System::Drawing::Point(5, 399);
			this->checkBox81->Name = L"checkBox81";
			this->checkBox81->Size = System::Drawing::Size(52, 17);
			this->checkBox81->TabIndex = 1;
			this->checkBox81->Text = L"rCorr";
			this->checkBox81->UseVisualStyleBackColor = true;
			this->checkBox81->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox81_CheckedChanged);
			// 
			// checkBox82
			// 
			this->checkBox82->AutoSize = true;
			this->checkBox82->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox82->Location = System::Drawing::Point(249, 509);
			this->checkBox82->Name = L"checkBox82";
			this->checkBox82->Size = System::Drawing::Size(91, 17);
			this->checkBox82->TabIndex = 1;
			this->checkBox82->Text = L"Sturdy Frame";
			this->checkBox82->UseVisualStyleBackColor = true;
			this->checkBox82->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox82_CheckedChanged);
			// 
			// checkBox83
			// 
			this->checkBox83->AutoSize = true;
			this->checkBox83->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox83->Location = System::Drawing::Point(249, 487);
			this->checkBox83->Name = L"checkBox83";
			this->checkBox83->Size = System::Drawing::Size(81, 17);
			this->checkBox83->TabIndex = 1;
			this->checkBox83->Text = L"Black Mark";
			this->checkBox83->UseVisualStyleBackColor = true;
			this->checkBox83->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox83_CheckedChanged);
			// 
			// checkBox84
			// 
			this->checkBox84->AutoSize = true;
			this->checkBox84->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox84->Location = System::Drawing::Point(249, 465);
			this->checkBox84->Name = L"checkBox84";
			this->checkBox84->Size = System::Drawing::Size(62, 17);
			this->checkBox84->TabIndex = 1;
			this->checkBox84->Text = L"Fuming";
			this->checkBox84->UseVisualStyleBackColor = true;
			this->checkBox84->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox84_CheckedChanged);
			// 
			// checkBox85
			// 
			this->checkBox85->AutoSize = true;
			this->checkBox85->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox85->Location = System::Drawing::Point(249, 443);
			this->checkBox85->Name = L"checkBox85";
			this->checkBox85->Size = System::Drawing::Size(79, 17);
			this->checkBox85->TabIndex = 1;
			this->checkBox85->Text = L"Magic Link";
			this->checkBox85->UseVisualStyleBackColor = true;
			this->checkBox85->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox85_CheckedChanged);
			// 
			// checkBox86
			// 
			this->checkBox86->AutoSize = true;
			this->checkBox86->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox86->Location = System::Drawing::Point(126, 531);
			this->checkBox86->Name = L"checkBox86";
			this->checkBox86->Size = System::Drawing::Size(85, 17);
			this->checkBox86->TabIndex = 1;
			this->checkBox86->Text = L"Strong Nose";
			this->checkBox86->UseVisualStyleBackColor = true;
			this->checkBox86->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox86_CheckedChanged);
			// 
			// checkBox87
			// 
			this->checkBox87->AutoSize = true;
			this->checkBox87->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox87->Location = System::Drawing::Point(126, 509);
			this->checkBox87->Name = L"checkBox87";
			this->checkBox87->Size = System::Drawing::Size(87, 17);
			this->checkBox87->TabIndex = 1;
			this->checkBox87->Text = L"Flame Cloud";
			this->checkBox87->UseVisualStyleBackColor = true;
			this->checkBox87->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox87_CheckedChanged);
			// 
			// checkBox88
			// 
			this->checkBox88->AutoSize = true;
			this->checkBox88->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox88->Location = System::Drawing::Point(126, 487);
			this->checkBox88->Name = L"checkBox88";
			this->checkBox88->Size = System::Drawing::Size(101, 17);
			this->checkBox88->TabIndex = 1;
			this->checkBox88->Text = L"Anti-magic Bite";
			this->checkBox88->UseVisualStyleBackColor = true;
			this->checkBox88->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox88_CheckedChanged);
			// 
			// checkBox89
			// 
			this->checkBox89->AutoSize = true;
			this->checkBox89->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox89->Location = System::Drawing::Point(126, 465);
			this->checkBox89->Name = L"checkBox89";
			this->checkBox89->Size = System::Drawing::Size(52, 17);
			this->checkBox89->TabIndex = 1;
			this->checkBox89->Text = L"Cling";
			this->checkBox89->UseVisualStyleBackColor = true;
			this->checkBox89->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox89_CheckedChanged);
			// 
			// checkBox90
			// 
			this->checkBox90->AutoSize = true;
			this->checkBox90->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox90->Location = System::Drawing::Point(126, 443);
			this->checkBox90->Name = L"checkBox90";
			this->checkBox90->Size = System::Drawing::Size(89, 17);
			this->checkBox90->TabIndex = 1;
			this->checkBox90->Text = L"Magic Regen";
			this->checkBox90->UseVisualStyleBackColor = true;
			this->checkBox90->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox90_CheckedChanged);
			// 
			// checkBox91
			// 
			this->checkBox91->AutoSize = true;
			this->checkBox91->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox91->Location = System::Drawing::Point(5, 531);
			this->checkBox91->Name = L"checkBox91";
			this->checkBox91->Size = System::Drawing::Size(83, 17);
			this->checkBox91->TabIndex = 1;
			this->checkBox91->Text = L"Strong Legs";
			this->checkBox91->UseVisualStyleBackColor = true;
			this->checkBox91->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox91_CheckedChanged);
			// 
			// checkBox92
			// 
			this->checkBox92->AutoSize = true;
			this->checkBox92->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox92->Location = System::Drawing::Point(5, 509);
			this->checkBox92->Name = L"checkBox92";
			this->checkBox92->Size = System::Drawing::Size(99, 17);
			this->checkBox92->TabIndex = 1;
			this->checkBox92->Text = L"Freezing Cloud";
			this->checkBox92->UseVisualStyleBackColor = true;
			this->checkBox92->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox92_CheckedChanged);
			// 
			// checkBox93
			// 
			this->checkBox93->AutoSize = true;
			this->checkBox93->Enabled = false;
			this->checkBox93->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox93->Location = System::Drawing::Point(5, 487);
			this->checkBox93->Name = L"checkBox93";
			this->checkBox93->Size = System::Drawing::Size(86, 17);
			this->checkBox93->TabIndex = 1;
			this->checkBox93->Text = L"Exoskeleton";
			this->checkBox93->UseVisualStyleBackColor = true;
			this->checkBox93->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox93_CheckedChanged);
			// 
			// checkBox94
			// 
			this->checkBox94->AutoSize = true;
			this->checkBox94->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox94->Location = System::Drawing::Point(5, 465);
			this->checkBox94->Name = L"checkBox94";
			this->checkBox94->Size = System::Drawing::Size(69, 17);
			this->checkBox94->TabIndex = 1;
			this->checkBox94->Text = L"rTrample";
			this->checkBox94->UseVisualStyleBackColor = true;
			this->checkBox94->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox94_CheckedChanged);
			// 
			// checkBox95
			// 
			this->checkBox95->AutoSize = true;
			this->checkBox95->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox95->Location = System::Drawing::Point(5, 443);
			this->checkBox95->Name = L"checkBox95";
			this->checkBox95->Size = System::Drawing::Size(88, 17);
			this->checkBox95->TabIndex = 1;
			this->checkBox95->Text = L"Magic Shield";
			this->checkBox95->UseVisualStyleBackColor = true;
			this->checkBox95->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox95_CheckedChanged);
			// 
			// checkBox96
			// 
			this->checkBox96->AutoSize = true;
			this->checkBox96->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox96->Location = System::Drawing::Point(5, 333);
			this->checkBox96->Name = L"checkBox96";
			this->checkBox96->Size = System::Drawing::Size(105, 17);
			this->checkBox96->TabIndex = 1;
			this->checkBox96->Text = L"Constrict (Naga)";
			this->checkBox96->UseVisualStyleBackColor = true;
			this->checkBox96->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox96_CheckedChanged);
			// 
			// checkBox97
			// 
			this->checkBox97->AutoSize = true;
			this->checkBox97->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox97->Location = System::Drawing::Point(375, 510);
			this->checkBox97->Name = L"checkBox97";
			this->checkBox97->Size = System::Drawing::Size(103, 17);
			this->checkBox97->TabIndex = 1;
			this->checkBox97->Text = L"Sanguine Armor";
			this->checkBox97->UseVisualStyleBackColor = true;
			this->checkBox97->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox97_CheckedChanged);
			// 
			// checkBox98
			// 
			this->checkBox98->AutoSize = true;
			this->checkBox98->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox98->Location = System::Drawing::Point(375, 488);
			this->checkBox98->Name = L"checkBox98";
			this->checkBox98->Size = System::Drawing::Size(91, 17);
			this->checkBox98->TabIndex = 1;
			this->checkBox98->Text = L"Rot Immunity";
			this->checkBox98->UseVisualStyleBackColor = true;
			this->checkBox98->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox98_CheckedChanged);
			// 
			// checkBox99
			// 
			this->checkBox99->AutoSize = true;
			this->checkBox99->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox99->Location = System::Drawing::Point(375, 466);
			this->checkBox99->Name = L"checkBox99";
			this->checkBox99->Size = System::Drawing::Size(52, 17);
			this->checkBox99->TabIndex = 1;
			this->checkBox99->Text = L"Jump";
			this->checkBox99->UseVisualStyleBackColor = true;
			this->checkBox99->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox99_CheckedChanged);
			// 
			// checkBox100
			// 
			this->checkBox100->AutoSize = true;
			this->checkBox100->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox100->Location = System::Drawing::Point(375, 444);
			this->checkBox100->Name = L"checkBox100";
			this->checkBox100->Size = System::Drawing::Size(51, 17);
			this->checkBox100->TabIndex = 1;
			this->checkBox100->Text = L"rPetr";
			this->checkBox100->UseVisualStyleBackColor = true;
			this->checkBox100->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox100_CheckedChanged);
			// 
			// checkBox61
			// 
			this->checkBox61->AutoSize = true;
			this->checkBox61->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox61->Location = System::Drawing::Point(249, 421);
			this->checkBox61->Name = L"checkBox61";
			this->checkBox61->Size = System::Drawing::Size(100, 17);
			this->checkBox61->TabIndex = 1;
			this->checkBox61->Text = L"Absorbing Jelly";
			this->checkBox61->UseVisualStyleBackColor = true;
			this->checkBox61->CheckedChanged += gcnew System::EventHandler(this, &MainForm::absorbingjelly_CheckedChanged);
			// 
			// checkBox62
			// 
			this->checkBox62->AutoSize = true;
			this->checkBox62->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox62->Location = System::Drawing::Point(249, 399);
			this->checkBox62->Name = L"checkBox62";
			this->checkBox62->Size = System::Drawing::Size(89, 17);
			this->checkBox62->TabIndex = 1;
			this->checkBox62->Text = L"Sensing Jelly";
			this->checkBox62->UseVisualStyleBackColor = true;
			this->checkBox62->CheckedChanged += gcnew System::EventHandler(this, &MainForm::sensingjelly_CheckedChanged);
			// 
			// checkBox63
			// 
			this->checkBox63->AutoSize = true;
			this->checkBox63->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox63->Location = System::Drawing::Point(249, 377);
			this->checkBox63->Name = L"checkBox63";
			this->checkBox63->Size = System::Drawing::Size(64, 17);
			this->checkBox63->TabIndex = 1;
			this->checkBox63->Text = L"Tendrils";
			this->checkBox63->UseVisualStyleBackColor = true;
			this->checkBox63->CheckedChanged += gcnew System::EventHandler(this, &MainForm::tendrils_CheckedChanged);
			// 
			// checkBox64
			// 
			this->checkBox64->AutoSize = true;
			this->checkBox64->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox64->Location = System::Drawing::Point(249, 355);
			this->checkBox64->Name = L"checkBox64";
			this->checkBox64->Size = System::Drawing::Size(95, 17);
			this->checkBox64->TabIndex = 1;
			this->checkBox64->Text = L"Augmentation";
			this->checkBox64->UseVisualStyleBackColor = true;
			this->checkBox64->CheckedChanged += gcnew System::EventHandler(this, &MainForm::augmentation_CheckedChanged);
			// 
			// checkBox65
			// 
			this->checkBox65->AutoSize = true;
			this->checkBox65->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox65->Location = System::Drawing::Point(249, 333);
			this->checkBox65->Name = L"checkBox65";
			this->checkBox65->Size = System::Drawing::Size(72, 17);
			this->checkBox65->TabIndex = 1;
			this->checkBox65->Text = L"Evolution";
			this->checkBox65->UseVisualStyleBackColor = true;
			this->checkBox65->CheckedChanged += gcnew System::EventHandler(this, &MainForm::Evolution_CheckedChanged);
			// 
			// checkBox66
			// 
			this->checkBox66->AutoSize = true;
			this->checkBox66->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox66->Location = System::Drawing::Point(249, 311);
			this->checkBox66->Name = L"checkBox66";
			this->checkBox66->Size = System::Drawing::Size(105, 17);
			this->checkBox66->TabIndex = 1;
			this->checkBox66->Text = L"Translucent Skin";
			this->checkBox66->UseVisualStyleBackColor = true;
			this->checkBox66->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox66_CheckedChanged);
			// 
			// checkBox67
			// 
			this->checkBox67->AutoSize = true;
			this->checkBox67->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox67->Location = System::Drawing::Point(249, 289);
			this->checkBox67->Name = L"checkBox67";
			this->checkBox67->Size = System::Drawing::Size(85, 17);
			this->checkBox67->TabIndex = 1;
			this->checkBox67->Text = L"Pseudopods";
			this->checkBox67->UseVisualStyleBackColor = true;
			this->checkBox67->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox67_CheckedChanged);
			// 
			// checkBox68
			// 
			this->checkBox68->AutoSize = true;
			this->checkBox68->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox68->Location = System::Drawing::Point(249, 267);
			this->checkBox68->Name = L"checkBox68";
			this->checkBox68->Size = System::Drawing::Size(106, 17);
			this->checkBox68->TabIndex = 1;
			this->checkBox68->Text = L"Gelatinous Body";
			this->checkBox68->UseVisualStyleBackColor = true;
			this->checkBox68->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox68_CheckedChanged);
			// 
			// checkBox69
			// 
			this->checkBox69->AutoSize = true;
			this->checkBox69->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox69->Location = System::Drawing::Point(249, 245);
			this->checkBox69->Name = L"checkBox69";
			this->checkBox69->Size = System::Drawing::Size(91, 17);
			this->checkBox69->TabIndex = 1;
			this->checkBox69->Text = L"Spawn Jellies";
			this->checkBox69->UseVisualStyleBackColor = true;
			this->checkBox69->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox69_CheckedChanged);
			// 
			// checkBox70
			// 
			this->checkBox70->AutoSize = true;
			this->checkBox70->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox70->Location = System::Drawing::Point(249, 223);
			this->checkBox70->Name = L"checkBox70";
			this->checkBox70->Size = System::Drawing::Size(67, 17);
			this->checkBox70->TabIndex = 1;
			this->checkBox70->Text = L"Eyeballs";
			this->checkBox70->UseVisualStyleBackColor = true;
			this->checkBox70->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox70_CheckedChanged);
			// 
			// checkBox71
			// 
			this->checkBox71->AutoSize = true;
			this->checkBox71->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox71->Location = System::Drawing::Point(249, 201);
			this->checkBox71->Name = L"checkBox71";
			this->checkBox71->Size = System::Drawing::Size(77, 17);
			this->checkBox71->TabIndex = 1;
			this->checkBox71->Text = L"Acidic Bite";
			this->checkBox71->UseVisualStyleBackColor = true;
			this->checkBox71->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox71_CheckedChanged);
			// 
			// checkBox72
			// 
			this->checkBox72->AutoSize = true;
			this->checkBox72->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox72->Location = System::Drawing::Point(249, 179);
			this->checkBox72->Name = L"checkBox72";
			this->checkBox72->Size = System::Drawing::Size(87, 17);
			this->checkBox72->TabIndex = 1;
			this->checkBox72->Text = L"Unbreathing";
			this->checkBox72->UseVisualStyleBackColor = true;
			this->checkBox72->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox72_CheckedChanged);
			// 
			// checkBox73
			// 
			this->checkBox73->AutoSize = true;
			this->checkBox73->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox73->Location = System::Drawing::Point(249, 157);
			this->checkBox73->Name = L"checkBox73";
			this->checkBox73->Size = System::Drawing::Size(81, 17);
			this->checkBox73->TabIndex = 1;
			this->checkBox73->Text = L"Wild Magic";
			this->checkBox73->UseVisualStyleBackColor = true;
			this->checkBox73->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox73_CheckedChanged);
			// 
			// checkBox74
			// 
			this->checkBox74->AutoSize = true;
			this->checkBox74->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox74->Location = System::Drawing::Point(249, 135);
			this->checkBox74->Name = L"checkBox74";
			this->checkBox74->Size = System::Drawing::Size(78, 17);
			this->checkBox74->TabIndex = 1;
			this->checkBox74->Text = L"Tough Skin";
			this->checkBox74->UseVisualStyleBackColor = true;
			this->checkBox74->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox74_CheckedChanged);
			// 
			// checkBox75
			// 
			this->checkBox75->AutoSize = true;
			this->checkBox75->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox75->Location = System::Drawing::Point(249, 113);
			this->checkBox75->Name = L"checkBox75";
			this->checkBox75->Size = System::Drawing::Size(98, 17);
			this->checkBox75->TabIndex = 1;
			this->checkBox75->Text = L"Torment Resist";
			this->checkBox75->UseVisualStyleBackColor = true;
			this->checkBox75->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox75_CheckedChanged);
			// 
			// checkBox76
			// 
			this->checkBox76->AutoSize = true;
			this->checkBox76->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox76->Location = System::Drawing::Point(249, 91);
			this->checkBox76->Name = L"checkBox76";
			this->checkBox76->Size = System::Drawing::Size(99, 17);
			this->checkBox76->TabIndex = 1;
			this->checkBox76->Text = L"Strong but Stiff";
			this->checkBox76->UseVisualStyleBackColor = true;
			this->checkBox76->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox76_CheckedChanged);
			// 
			// checkBox77
			// 
			this->checkBox77->AutoSize = true;
			this->checkBox77->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox77->Location = System::Drawing::Point(249, 69);
			this->checkBox77->Name = L"checkBox77";
			this->checkBox77->Size = System::Drawing::Size(58, 17);
			this->checkBox77->TabIndex = 1;
			this->checkBox77->Text = L"Strong";
			this->checkBox77->UseVisualStyleBackColor = true;
			this->checkBox77->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox77_CheckedChanged);
			// 
			// checkBox78
			// 
			this->checkBox78->AutoSize = true;
			this->checkBox78->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox78->Location = System::Drawing::Point(249, 47);
			this->checkBox78->Name = L"checkBox78";
			this->checkBox78->Size = System::Drawing::Size(115, 17);
			this->checkBox78->TabIndex = 1;
			this->checkBox78->Text = L"Torment Resist (%)";
			this->checkBox78->UseVisualStyleBackColor = true;
			this->checkBox78->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox78_CheckedChanged);
			// 
			// checkBox79
			// 
			this->checkBox79->AutoSize = true;
			this->checkBox79->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox79->Location = System::Drawing::Point(249, 25);
			this->checkBox79->Name = L"checkBox79";
			this->checkBox79->Size = System::Drawing::Size(80, 17);
			this->checkBox79->TabIndex = 1;
			this->checkBox79->Text = L"Spit Poison";
			this->checkBox79->UseVisualStyleBackColor = true;
			this->checkBox79->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox79_CheckedChanged);
			// 
			// checkBox80
			// 
			this->checkBox80->AutoSize = true;
			this->checkBox80->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox80->Location = System::Drawing::Point(249, 3);
			this->checkBox80->Name = L"checkBox80";
			this->checkBox80->Size = System::Drawing::Size(53, 17);
			this->checkBox80->TabIndex = 1;
			this->checkBox80->Text = L"Spiny";
			this->checkBox80->UseVisualStyleBackColor = true;
			this->checkBox80->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox80_CheckedChanged);
			// 
			// checkBox41
			// 
			this->checkBox41->AutoSize = true;
			this->checkBox41->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox41->Location = System::Drawing::Point(126, 421);
			this->checkBox41->Name = L"checkBox41";
			this->checkBox41->Size = System::Drawing::Size(109, 17);
			this->checkBox41->TabIndex = 1;
			this->checkBox41->Text = L"Slow Metabolism";
			this->checkBox41->UseVisualStyleBackColor = true;
			this->checkBox41->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox41_CheckedChanged);
			// 
			// checkBox42
			// 
			this->checkBox42->AutoSize = true;
			this->checkBox42->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox42->Location = System::Drawing::Point(126, 399);
			this->checkBox42->Name = L"checkBox42";
			this->checkBox42->Size = System::Drawing::Size(50, 17);
			this->checkBox42->TabIndex = 1;
			this->checkBox42->Text = L"rElec";
			this->checkBox42->UseVisualStyleBackColor = true;
			this->checkBox42->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox42_CheckedChanged);
			// 
			// checkBox43
			// 
			this->checkBox43->AutoSize = true;
			this->checkBox43->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox43->Location = System::Drawing::Point(126, 377);
			this->checkBox43->Name = L"checkBox43";
			this->checkBox43->Size = System::Drawing::Size(80, 17);
			this->checkBox43->TabIndex = 1;
			this->checkBox43->Text = L"Shaggy Fur";
			this->checkBox43->UseVisualStyleBackColor = true;
			this->checkBox43->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox43_CheckedChanged);
			// 
			// checkBox44
			// 
			this->checkBox44->AutoSize = true;
			this->checkBox44->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox44->Location = System::Drawing::Point(126, 355);
			this->checkBox44->Name = L"checkBox44";
			this->checkBox44->Size = System::Drawing::Size(76, 17);
			this->checkBox44->TabIndex = 1;
			this->checkBox44->Text = L"Saprovore";
			this->checkBox44->UseVisualStyleBackColor = true;
			this->checkBox44->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox44_CheckedChanged);
			// 
			// checkBox45
			// 
			this->checkBox45->AutoSize = true;
			this->checkBox45->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox45->Location = System::Drawing::Point(126, 333);
			this->checkBox45->Name = L"checkBox45";
			this->checkBox45->Size = System::Drawing::Size(60, 17);
			this->checkBox45->TabIndex = 1;
			this->checkBox45->Text = L"Robust";
			this->checkBox45->UseVisualStyleBackColor = true;
			this->checkBox45->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox45_CheckedChanged);
			// 
			// checkBox46
			// 
			this->checkBox46->AutoSize = true;
			this->checkBox46->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox46->Location = System::Drawing::Point(126, 311);
			this->checkBox46->Name = L"checkBox46";
			this->checkBox46->Size = System::Drawing::Size(92, 17);
			this->checkBox46->TabIndex = 1;
			this->checkBox46->Text = L"Regeneration";
			this->checkBox46->UseVisualStyleBackColor = true;
			this->checkBox46->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox46_CheckedChanged);
			// 
			// checkBox47
			// 
			this->checkBox47->AutoSize = true;
			this->checkBox47->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox47->Location = System::Drawing::Point(126, 289);
			this->checkBox47->Name = L"checkBox47";
			this->checkBox47->Size = System::Drawing::Size(107, 17);
			this->checkBox47->TabIndex = 1;
			this->checkBox47->Text = L"Powered by Pain";
			this->checkBox47->UseVisualStyleBackColor = true;
			this->checkBox47->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox47_CheckedChanged);
			// 
			// checkBox48
			// 
			this->checkBox48->AutoSize = true;
			this->checkBox48->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox48->Location = System::Drawing::Point(126, 267);
			this->checkBox48->Name = L"checkBox48";
			this->checkBox48->Size = System::Drawing::Size(115, 17);
			this->checkBox48->TabIndex = 1;
			this->checkBox48->Text = L"Powered by Death";
			this->checkBox48->UseVisualStyleBackColor = true;
			this->checkBox48->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox48_CheckedChanged);
			// 
			// checkBox49
			// 
			this->checkBox49->AutoSize = true;
			this->checkBox49->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox49->Location = System::Drawing::Point(126, 245);
			this->checkBox49->Name = L"checkBox49";
			this->checkBox49->Size = System::Drawing::Size(51, 17);
			this->checkBox49->TabIndex = 1;
			this->checkBox49->Text = L"rPois";
			this->checkBox49->UseVisualStyleBackColor = true;
			this->checkBox49->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox49_CheckedChanged);
			// 
			// checkBox50
			// 
			this->checkBox50->AutoSize = true;
			this->checkBox50->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox50->Location = System::Drawing::Point(126, 223);
			this->checkBox50->Name = L"checkBox50";
			this->checkBox50->Size = System::Drawing::Size(121, 17);
			this->checkBox50->TabIndex = 1;
			this->checkBox50->Text = L"Sense Surroundings";
			this->checkBox50->UseVisualStyleBackColor = true;
			this->checkBox50->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox50_CheckedChanged);
			// 
			// checkBox51
			// 
			this->checkBox51->AutoSize = true;
			this->checkBox51->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox51->Location = System::Drawing::Point(126, 201);
			this->checkBox51->Name = L"checkBox51";
			this->checkBox51->Size = System::Drawing::Size(99, 17);
			this->checkBox51->TabIndex = 1;
			this->checkBox51->Text = L"Passive Freeze";
			this->checkBox51->UseVisualStyleBackColor = true;
			this->checkBox51->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox51_CheckedChanged);
			// 
			// checkBox52
			// 
			this->checkBox52->AutoSize = true;
			this->checkBox52->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox52->Location = System::Drawing::Point(126, 179);
			this->checkBox52->Name = L"checkBox52";
			this->checkBox52->Size = System::Drawing::Size(87, 17);
			this->checkBox52->TabIndex = 1;
			this->checkBox52->Text = L"Nightstalker";
			this->checkBox52->UseVisualStyleBackColor = true;
			this->checkBox52->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox52_CheckedChanged);
			// 
			// checkBox53
			// 
			this->checkBox53->AutoSize = true;
			this->checkBox53->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox53->Location = System::Drawing::Point(126, 157);
			this->checkBox53->Name = L"checkBox53";
			this->checkBox53->Size = System::Drawing::Size(44, 17);
			this->checkBox53->TabIndex = 1;
			this->checkBox53->Text = L"rN+";
			this->checkBox53->UseVisualStyleBackColor = true;
			this->checkBox53->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox53_CheckedChanged);
			// 
			// checkBox54
			// 
			this->checkBox54->AutoSize = true;
			this->checkBox54->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox54->Location = System::Drawing::Point(126, 135);
			this->checkBox54->Name = L"checkBox54";
			this->checkBox54->Size = System::Drawing::Size(103, 17);
			this->checkBox54->TabIndex = 1;
			this->checkBox54->Text = L"Mutation Resist";
			this->checkBox54->UseVisualStyleBackColor = true;
			this->checkBox54->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox54_CheckedChanged);
			// 
			// checkBox55
			// 
			this->checkBox55->AutoSize = true;
			this->checkBox55->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox55->Location = System::Drawing::Point(126, 113);
			this->checkBox55->Name = L"checkBox55";
			this->checkBox55->Size = System::Drawing::Size(49, 17);
			this->checkBox55->TabIndex = 1;
			this->checkBox55->Text = L"MR+";
			this->checkBox55->UseVisualStyleBackColor = true;
			this->checkBox55->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox55_CheckedChanged);
			// 
			// checkBox56
			// 
			this->checkBox56->AutoSize = true;
			this->checkBox56->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox56->Location = System::Drawing::Point(126, 91);
			this->checkBox56->Name = L"checkBox56";
			this->checkBox56->Size = System::Drawing::Size(84, 17);
			this->checkBox56->TabIndex = 1;
			this->checkBox56->Text = L"Ignite Blood";
			this->checkBox56->UseVisualStyleBackColor = true;
			this->checkBox56->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox56_CheckedChanged);
			// 
			// checkBox57
			// 
			this->checkBox57->AutoSize = true;
			this->checkBox57->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox57->Location = System::Drawing::Point(126, 69);
			this->checkBox57->Name = L"checkBox57";
			this->checkBox57->Size = System::Drawing::Size(61, 17);
			this->checkBox57->TabIndex = 1;
			this->checkBox57->Text = L"Icemail";
			this->checkBox57->UseVisualStyleBackColor = true;
			this->checkBox57->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox57_CheckedChanged);
			// 
			// checkBox58
			// 
			this->checkBox58->AutoSize = true;
			this->checkBox58->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox58->Location = System::Drawing::Point(126, 47);
			this->checkBox58->Name = L"checkBox58";
			this->checkBox58->Size = System::Drawing::Size(68, 17);
			this->checkBox58->TabIndex = 1;
			this->checkBox58->Text = L"High MP";
			this->checkBox58->UseVisualStyleBackColor = true;
			this->checkBox58->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox58_CheckedChanged);
			// 
			// checkBox59
			// 
			this->checkBox59->AutoSize = true;
			this->checkBox59->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox59->Location = System::Drawing::Point(126, 25);
			this->checkBox59->Name = L"checkBox59";
			this->checkBox59->Size = System::Drawing::Size(77, 17);
			this->checkBox59->TabIndex = 1;
			this->checkBox59->Text = L"Gourmand";
			this->checkBox59->UseVisualStyleBackColor = true;
			this->checkBox59->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox59_CheckedChanged);
			// 
			// checkBox60
			// 
			this->checkBox60->AutoSize = true;
			this->checkBox60->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox60->Location = System::Drawing::Point(126, 3);
			this->checkBox60->Name = L"checkBox60";
			this->checkBox60->Size = System::Drawing::Size(82, 17);
			this->checkBox60->TabIndex = 1;
			this->checkBox60->Text = L"Foul Stench";
			this->checkBox60->UseVisualStyleBackColor = true;
			this->checkBox60->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox60_CheckedChanged);
			// 
			// checkBox31
			// 
			this->checkBox31->AutoSize = true;
			this->checkBox31->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox31->Location = System::Drawing::Point(5, 421);
			this->checkBox31->Name = L"checkBox31";
			this->checkBox31->Size = System::Drawing::Size(96, 17);
			this->checkBox31->TabIndex = 1;
			this->checkBox31->Text = L"Flexible Weak";
			this->checkBox31->UseVisualStyleBackColor = true;
			this->checkBox31->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox31_CheckedChanged);
			// 
			// checkBox33
			// 
			this->checkBox33->AutoSize = true;
			this->checkBox33->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox33->Location = System::Drawing::Point(5, 377);
			this->checkBox33->Name = L"checkBox33";
			this->checkBox33->Size = System::Drawing::Size(47, 17);
			this->checkBox33->TabIndex = 1;
			this->checkBox33->Text = L"Fast";
			this->checkBox33->UseVisualStyleBackColor = true;
			this->checkBox33->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox33_CheckedChanged);
			// 
			// checkBox34
			// 
			this->checkBox34->AutoSize = true;
			this->checkBox34->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox34->Location = System::Drawing::Point(5, 355);
			this->checkBox34->Name = L"checkBox34";
			this->checkBox34->Size = System::Drawing::Size(103, 17);
			this->checkBox34->TabIndex = 1;
			this->checkBox34->Text = L"Hurl Damnation";
			this->checkBox34->UseVisualStyleBackColor = true;
			this->checkBox34->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox34_CheckedChanged);
			// 
			// checkBox36
			// 
			this->checkBox36->AutoSize = true;
			this->checkBox36->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox36->Location = System::Drawing::Point(5, 311);
			this->checkBox36->Name = L"checkBox36";
			this->checkBox36->Size = System::Drawing::Size(77, 17);
			this->checkBox36->TabIndex = 1;
			this->checkBox36->Text = L"Resist Fire";
			this->checkBox36->UseVisualStyleBackColor = true;
			this->checkBox36->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox36_CheckedChanged);
			// 
			// checkBox37
			// 
			this->checkBox37->AutoSize = true;
			this->checkBox37->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox37->Location = System::Drawing::Point(5, 289);
			this->checkBox37->Name = L"checkBox37";
			this->checkBox37->Size = System::Drawing::Size(116, 17);
			this->checkBox37->TabIndex = 1;
			this->checkBox37->Text = L"Demonic Guardian";
			this->checkBox37->UseVisualStyleBackColor = true;
			this->checkBox37->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox37_CheckedChanged);
			// 
			// checkBox38
			// 
			this->checkBox38->AutoSize = true;
			this->checkBox38->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox38->Location = System::Drawing::Point(5, 267);
			this->checkBox38->Name = L"checkBox38";
			this->checkBox38->Size = System::Drawing::Size(107, 17);
			this->checkBox38->TabIndex = 1;
			this->checkBox38->Text = L"Conserve Scrolls";
			this->checkBox38->UseVisualStyleBackColor = true;
			this->checkBox38->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox38_CheckedChanged);
			// 
			// checkBox39
			// 
			this->checkBox39->AutoSize = true;
			this->checkBox39->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox39->Location = System::Drawing::Point(5, 245);
			this->checkBox39->Name = L"checkBox39";
			this->checkBox39->Size = System::Drawing::Size(112, 17);
			this->checkBox39->TabIndex = 1;
			this->checkBox39->Text = L"Conserve Potions";
			this->checkBox39->UseVisualStyleBackColor = true;
			this->checkBox39->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox39_CheckedChanged);
			// 
			// checkBox40
			// 
			this->checkBox40->AutoSize = true;
			this->checkBox40->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox40->Location = System::Drawing::Point(5, 223);
			this->checkBox40->Name = L"checkBox40";
			this->checkBox40->Size = System::Drawing::Size(44, 17);
			this->checkBox40->TabIndex = 1;
			this->checkBox40->Text = L"rC+";
			this->checkBox40->UseVisualStyleBackColor = true;
			this->checkBox40->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox40_CheckedChanged);
			// 
			// checkBox21
			// 
			this->checkBox21->AutoSize = true;
			this->checkBox21->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox21->Location = System::Drawing::Point(5, 201);
			this->checkBox21->Name = L"checkBox21";
			this->checkBox21->Size = System::Drawing::Size(59, 17);
			this->checkBox21->TabIndex = 1;
			this->checkBox21->Text = L"Clever";
			this->checkBox21->UseVisualStyleBackColor = true;
			this->checkBox21->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox21_CheckedChanged);
			// 
			// checkBox22
			// 
			this->checkBox22->AutoSize = true;
			this->checkBox22->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox22->Location = System::Drawing::Point(5, 179);
			this->checkBox22->Name = L"checkBox22";
			this->checkBox22->Size = System::Drawing::Size(60, 17);
			this->checkBox22->TabIndex = 1;
			this->checkBox22->Text = L"Clarity";
			this->checkBox22->UseVisualStyleBackColor = true;
			this->checkBox22->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox22_CheckedChanged);
			// 
			// checkBox23
			// 
			this->checkBox23->AutoSize = true;
			this->checkBox23->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox23->Location = System::Drawing::Point(5, 157);
			this->checkBox23->Name = L"checkBox23";
			this->checkBox23->Size = System::Drawing::Size(75, 17);
			this->checkBox23->TabIndex = 1;
			this->checkBox23->Text = L"Carnivore";
			this->checkBox23->UseVisualStyleBackColor = true;
			this->checkBox23->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox23_CheckedChanged);
			// 
			// checkBox24
			// 
			this->checkBox24->AutoSize = true;
			this->checkBox24->Enabled = false;
			this->checkBox24->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox24->Location = System::Drawing::Point(5, 135);
			this->checkBox24->Name = L"checkBox24";
			this->checkBox24->Size = System::Drawing::Size(100, 17);
			this->checkBox24->TabIndex = 1;
			this->checkBox24->Text = L"Breathe Poison";
			this->checkBox24->UseVisualStyleBackColor = true;
			this->checkBox24->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox24_CheckedChanged);
			// 
			// checkBox25
			// 
			this->checkBox25->AutoSize = true;
			this->checkBox25->Enabled = false;
			this->checkBox25->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox25->Location = System::Drawing::Point(5, 113);
			this->checkBox25->Name = L"checkBox25";
			this->checkBox25->Size = System::Drawing::Size(102, 17);
			this->checkBox25->TabIndex = 1;
			this->checkBox25->Text = L"Breathe Flames";
			this->checkBox25->UseVisualStyleBackColor = true;
			this->checkBox25->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox25_CheckedChanged);
			// 
			// checkBox26
			// 
			this->checkBox26->AutoSize = true;
			this->checkBox26->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox26->Location = System::Drawing::Point(5, 91);
			this->checkBox26->Name = L"checkBox26";
			this->checkBox26->Size = System::Drawing::Size(51, 17);
			this->checkBox26->TabIndex = 1;
			this->checkBox26->Text = L"Blink";
			this->checkBox26->UseVisualStyleBackColor = true;
			this->checkBox26->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox26_CheckedChanged);
			// 
			// checkBox27
			// 
			this->checkBox27->AutoSize = true;
			this->checkBox27->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox27->Location = System::Drawing::Point(5, 69);
			this->checkBox27->Name = L"checkBox27";
			this->checkBox27->Size = System::Drawing::Size(51, 17);
			this->checkBox27->TabIndex = 1;
			this->checkBox27->Text = L"Agile";
			this->checkBox27->UseVisualStyleBackColor = true;
			this->checkBox27->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox27_CheckedChanged);
			// 
			// checkBox28
			// 
			this->checkBox28->AutoSize = true;
			this->checkBox28->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox28->Location = System::Drawing::Point(5, 47);
			this->checkBox28->Name = L"checkBox28";
			this->checkBox28->Size = System::Drawing::Size(87, 17);
			this->checkBox28->TabIndex = 1;
			this->checkBox28->Text = L"See Invisible";
			this->checkBox28->UseVisualStyleBackColor = true;
			this->checkBox28->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox28_CheckedChanged);
			// 
			// checkBox29
			// 
			this->checkBox29->AutoSize = true;
			this->checkBox29->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox29->Location = System::Drawing::Point(5, 25);
			this->checkBox29->Name = L"checkBox29";
			this->checkBox29->Size = System::Drawing::Size(86, 17);
			this->checkBox29->TabIndex = 1;
			this->checkBox29->Text = L"Camouflage";
			this->checkBox29->UseVisualStyleBackColor = true;
			this->checkBox29->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox29_CheckedChanged);
			// 
			// yellowscale
			// 
			this->yellowscale->AutoSize = true;
			this->yellowscale->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->yellowscale->Location = System::Drawing::Point(5, 3);
			this->yellowscale->Name = L"yellowscale";
			this->yellowscale->Size = System::Drawing::Size(91, 17);
			this->yellowscale->TabIndex = 1;
			this->yellowscale->Text = L"Yellow Scales";
			this->yellowscale->UseVisualStyleBackColor = true;
			this->yellowscale->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox30_CheckedChanged_1);
			// 
			// checkBox17
			// 
			this->checkBox17->AutoSize = true;
			this->checkBox17->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox17->Location = System::Drawing::Point(375, 422);
			this->checkBox17->Name = L"checkBox17";
			this->checkBox17->Size = System::Drawing::Size(136, 17);
			this->checkBox17->TabIndex = 1;
			this->checkBox17->Text = L"Thin Skeletal Structure";
			this->checkBox17->UseVisualStyleBackColor = true;
			this->checkBox17->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox17_CheckedChanged);
			// 
			// checkBox18
			// 
			this->checkBox18->AutoSize = true;
			this->checkBox18->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox18->Location = System::Drawing::Point(375, 400);
			this->checkBox18->Name = L"checkBox18";
			this->checkBox18->Size = System::Drawing::Size(122, 17);
			this->checkBox18->TabIndex = 1;
			this->checkBox18->Text = L"Thin Metallic Scales";
			this->checkBox18->UseVisualStyleBackColor = true;
			this->checkBox18->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox18_CheckedChanged);
			// 
			// checkBox19
			// 
			this->checkBox19->AutoSize = true;
			this->checkBox19->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox19->Location = System::Drawing::Point(375, 378);
			this->checkBox19->Name = L"checkBox19";
			this->checkBox19->Size = System::Drawing::Size(118, 17);
			this->checkBox19->TabIndex = 1;
			this->checkBox19->Text = L"Slimy Green Scales";
			this->checkBox19->UseVisualStyleBackColor = true;
			this->checkBox19->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox19_CheckedChanged);
			// 
			// checkBox20
			// 
			this->checkBox20->AutoSize = true;
			this->checkBox20->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox20->Location = System::Drawing::Point(375, 356);
			this->checkBox20->Name = L"checkBox20";
			this->checkBox20->Size = System::Drawing::Size(129, 17);
			this->checkBox20->TabIndex = 1;
			this->checkBox20->Text = L"Rugged Brown Scales";
			this->checkBox20->UseVisualStyleBackColor = true;
			this->checkBox20->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox20_CheckedChanged);
			// 
			// checkBox9
			// 
			this->checkBox9->AutoSize = true;
			this->checkBox9->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox9->Location = System::Drawing::Point(375, 334);
			this->checkBox9->Name = L"checkBox9";
			this->checkBox9->Size = System::Drawing::Size(119, 17);
			this->checkBox9->TabIndex = 1;
			this->checkBox9->Text = L"Rough Black Scales";
			this->checkBox9->UseVisualStyleBackColor = true;
			this->checkBox9->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox9_CheckedChanged);
			// 
			// checkBox10
			// 
			this->checkBox10->AutoSize = true;
			this->checkBox10->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox10->Location = System::Drawing::Point(375, 312);
			this->checkBox10->Name = L"checkBox10";
			this->checkBox10->Size = System::Drawing::Size(94, 17);
			this->checkBox10->TabIndex = 1;
			this->checkBox10->Text = L"Molten Scales";
			this->checkBox10->UseVisualStyleBackColor = true;
			this->checkBox10->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox10_CheckedChanged);
			// 
			// checkBox11
			// 
			this->checkBox11->AutoSize = true;
			this->checkBox11->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox11->Location = System::Drawing::Point(375, 290);
			this->checkBox11->Name = L"checkBox11";
			this->checkBox11->Size = System::Drawing::Size(114, 17);
			this->checkBox11->TabIndex = 1;
			this->checkBox11->Text = L"Large Bone Plates";
			this->checkBox11->UseVisualStyleBackColor = true;
			this->checkBox11->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox11_CheckedChanged);
			// 
			// checkBox12
			// 
			this->checkBox12->AutoSize = true;
			this->checkBox12->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox12->Location = System::Drawing::Point(375, 268);
			this->checkBox12->Name = L"checkBox12";
			this->checkBox12->Size = System::Drawing::Size(107, 17);
			this->checkBox12->TabIndex = 1;
			this->checkBox12->Text = L"Iridescent Scales";
			this->checkBox12->UseVisualStyleBackColor = true;
			this->checkBox12->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox12_CheckedChanged);
			// 
			// checkBox13
			// 
			this->checkBox13->AutoSize = true;
			this->checkBox13->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox13->Location = System::Drawing::Point(375, 246);
			this->checkBox13->Name = L"checkBox13";
			this->checkBox13->Size = System::Drawing::Size(81, 17);
			this->checkBox13->TabIndex = 1;
			this->checkBox13->Text = L"Blue Scales";
			this->checkBox13->UseVisualStyleBackColor = true;
			this->checkBox13->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox13_CheckedChanged);
			// 
			// checkBox14
			// 
			this->checkBox14->AutoSize = true;
			this->checkBox14->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox14->Location = System::Drawing::Point(375, 224);
			this->checkBox14->Name = L"checkBox14";
			this->checkBox14->Size = System::Drawing::Size(100, 17);
			this->checkBox14->TabIndex = 1;
			this->checkBox14->Text = L"Repulsion Field";
			this->checkBox14->UseVisualStyleBackColor = true;
			this->checkBox14->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox14_CheckedChanged);
			// 
			// checkBox15
			// 
			this->checkBox15->AutoSize = true;
			this->checkBox15->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox15->Location = System::Drawing::Point(375, 202);
			this->checkBox15->Name = L"checkBox15";
			this->checkBox15->Size = System::Drawing::Size(96, 17);
			this->checkBox15->TabIndex = 1;
			this->checkBox15->Text = L"Tentacle Spike";
			this->checkBox15->UseVisualStyleBackColor = true;
			this->checkBox15->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox15_CheckedChanged);
			// 
			// checkBox16
			// 
			this->checkBox16->AutoSize = true;
			this->checkBox16->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox16->Location = System::Drawing::Point(375, 180);
			this->checkBox16->Name = L"checkBox16";
			this->checkBox16->Size = System::Drawing::Size(57, 17);
			this->checkBox16->TabIndex = 1;
			this->checkBox16->Text = L"Talons";
			this->checkBox16->UseVisualStyleBackColor = true;
			this->checkBox16->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox16_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox5->Location = System::Drawing::Point(375, 158);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(61, 17);
			this->checkBox5->TabIndex = 1;
			this->checkBox5->Text = L"Stinger";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox5_CheckedChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox6->Location = System::Drawing::Point(375, 136);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(55, 17);
			this->checkBox6->TabIndex = 1;
			this->checkBox6->Text = L"Horns";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox6_CheckedChanged);
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox7->Location = System::Drawing::Point(375, 114);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(63, 17);
			this->checkBox7->TabIndex = 1;
			this->checkBox7->Text = L"Hooves";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox7_CheckedChanged);
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox8->Location = System::Drawing::Point(375, 92);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(55, 17);
			this->checkBox8->TabIndex = 1;
			this->checkBox8->Text = L"Fangs";
			this->checkBox8->UseVisualStyleBackColor = true;
			this->checkBox8->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox8_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox3->Location = System::Drawing::Point(375, 70);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(56, 17);
			this->checkBox3->TabIndex = 1;
			this->checkBox3->Text = L"Claws";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox3_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox4->Location = System::Drawing::Point(375, 48);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(51, 17);
			this->checkBox4->TabIndex = 1;
			this->checkBox4->Text = L"Beak";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox4_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox2->Location = System::Drawing::Point(375, 26);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(57, 17);
			this->checkBox2->TabIndex = 1;
			this->checkBox2->Text = L"Wings";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox2_CheckedChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Lato", 8));
			this->checkBox1->Location = System::Drawing::Point(375, 4);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(73, 17);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"Antennae";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox1_CheckedChanged_1);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(562, 637);
			this->Controls->Add(this->attached);
			this->Controls->Add(this->tabboxthing);
			this->Controls->Add(this->attachedtext);
			this->Font = (gcnew System::Drawing::Font(L"Lato", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"DCSS v25.0 Trainer - made by swrlly";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->tabboxthing->ResumeLayout(false);
			this->tabpage1->ResumeLayout(false);
			this->tabpage1->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->Mutations->ResumeLayout(false);
			this->Mutations->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	private: System::Void godmode_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void infinitemana_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void intelligence_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dexterity_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void strength_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nohunger_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	//private: System::Void ConsoleLog_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void GUITimer_Tick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void idinven_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void onehp_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void mfreeze_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void disablemovement_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void instakill_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void maxitems_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void mmapping_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void acqui_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void maxcharge_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox60_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox42_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox43_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox44_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox45_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox46_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox47_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox48_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox49_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox50_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox51_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox52_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox53_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox54_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox55_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox56_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox57_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox58_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox59_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox41_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox75_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox97_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox82_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox83_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox84_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox85_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox86_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox87_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox88_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox89_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox90_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox91_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox92_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox93_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox94_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox95_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox96_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox81_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox98_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox99_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox100_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void absorbingjelly_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void sensingjelly_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void tendrils_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void augmentation_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void Evolution_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox66_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox67_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox68_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox69_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox70_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox71_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox72_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox73_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox74_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox76_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox77_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox78_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox79_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox80_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox31_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox32_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox33_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox34_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox35_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox36_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox37_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox38_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox39_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox40_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox21_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox22_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox23_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox24_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox25_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox26_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox27_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox28_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox29_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox30_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox17_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox18_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox19_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox20_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox9_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox10_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox11_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox12_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox13_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox14_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox15_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox16_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox5_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox6_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox7_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox8_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox177_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox105_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox106_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox107_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox101_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox102_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox103_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox136_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox137_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox138_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox139_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox156_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox157_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox158_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox159_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox176_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox104_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox178_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox179_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox196_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox197_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox198_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox199_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox30_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void minmovspd_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox108_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void checkBox109_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
};

};