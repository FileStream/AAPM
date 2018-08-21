#include "BIS_AddonInfo.hpp"
#ifndef SCT_ARMOR_RATINGS
#define SCT_ARMOR_RATINGS 1
#define SCT_NIJII_CMASS 20
#define SCT_NIJII_ARMOR 5
#define SCT_NIJIIIA_CMASS 8
#define SCT_NIJIIIA_ARMOR 8
#define SCT_NIJIII_ARMOR 11
#define SCT_NIJIV_ARMOR 15
#define SCT_LITE_TRAUMAPAD 0.6
#define SCT_TRAUMAPAD 0.65
#endif

class CfgPatches {

	class SonicT_Items {
		units[] = {};
		weapons[] = {"SonicT_Item_Base"};
		requiredVersion = 1.820000;
		version = 2.4100000;
		requiredAddons[] = {
			"A3_Data_F_Loadorder",
            "A3_Data_F_Curator_Loadorder",
            "A3_Data_F_Kart_Loadorder",
            "A3_Data_F_Bootcamp_Loadorder",
            "A3_Data_F_Heli_Loadorder",
            "A3_Data_F_Mark_Loadorder",
            "A3_Data_F_Exp_A_Loadorder",
            "A3_Data_F_Exp_B_Loadorder",
            "A3_Data_F_Exp_Loadorder",
            "A3_Data_F_Jets_Loadorder",
            "A3_Data_F_Argo_Loadorder",
            "A3_Data_F_Patrol_Loadorder",
            "A3_Data_F_Orange_Loadorder",
            "A3_Data_F_Tank_Loadorder",
			"A3_Data_F",
			"A3Data",
			"A3_Characters_F",
			"A3_Weapons_F",
			"a3_3den"
			};
		author = "Sonic.T";
		fileName = "SonicT_vest.pbo";
	};
	
	class SCTEVENT : SonicT_Items {
		author = "";
		weapons[] = {};
	};

};

class CfgMods{
	class Mod_Base;
	class SCT_ARMOR{
		author = "Sonic.T";
		picture = "\SCT\sonict.paa";
		logo = "\SCT\sonict.paa";
		logoOver = "\SCT\sonict.paa";
		logoSmall = "\SCT\sonict.paa";
		dlcColor[] = {0, 0, 0, 1};
		tooltip = "SCT Armor Plate";
		tooltipOwned = "Sonic.T";
		name = "Sonic.T and V. Berlioz's full-spectrum body armor overhaul";
		overview = "stuff hard armor plates in your vest, to ensure your safety";
		dir = "SCT";
	};
};

//making additional custom 'init' eventhandler.
class SCTEVTEX_base {
	init = "[_this select 0]execVM '\SCT\addons\SonicT_vest\scripts\fn_ManInit.sqf';";
};

class SCTEVENT : SCTEVTEX_base{};

class DefaultEventhandlers {
	class SCTEVENT : SCTEVTEX_base {};
};

class CfgFunctions{
	class SCT{
		class VestFnc {
			file = "SCT\addons\SonicT_vest\scripts";
			class SysPreInit{
				preInit = 1;
				description= "Sonict system initialization codes";
			};
			class SysPostInit{
				postInit = 1;
				description = "make settings bar on the map";
			};
			class ManInit{
				preInit = 1;
				description="Sonict vest initializing manbase units";
			};
			class Ragdoll{
				postInit = 1;
				description="Make people fall if hit too hard.";
			};
			
			class ChangeSettings {
				preInit = 1;
			};
			
			class OpenSettings {};
			
		};
	};
};

//to make option menus on the map, with CBA free.

class RscPicture;	// External class reference
class RscProgressBar;	// External class reference
class RscStructuredText;	// External class reference
class RscText;	// External class reference
class RscEdit;	// External class reference
class RscButton;	// External class reference
class RscListbox;	// External class reference
class RscObject;	// External class reference
class RscCombo;	// External class reference
class IGUIBack;	// External class reference
class RscSlider;	// External class reference
class RscCheckbox;	// External class reference

class SCT_PLATE_SETTINGS {
	idd = 5964;
	movingEnable = 1;
	enableSimulation = 1;
	onLoad = "uiNamespace setVariable ['SCT_plate_Settings', (_this select 0)]";
	
	class controls {
		class SCT_PLATE_menu_BackGround : IGUIBack {
			idc = -1;
			x = "0.396875 * safezoneW + safezoneX";
			y = "0.291 * safezoneH + safezoneY";
			w = "0.20625 * safezoneW";
			h = "0.242 * safezoneH";
			colorBackground[] = {0, 0, 0, 1};
			colorText[] = {1, 1, 1, 1};
		};
		
		class SCT_PLATE_menu__Header : RscText {
			idc = -1;
			text = "Sonic.T's Armor Plate Settings";
			x = "0.396875 * safezoneW + safezoneX";
			y = "0.291 * safezoneH + safezoneY";
			w = "0.20625 * safezoneW";
			h = "0.033 * safezoneH";
			colorBackground[] = {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.69])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.75])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.5])", 0.7};
			colorText[] = {1, 1, 1, 1};
		};
		
		class SCT_PLATE_menu_TRAUMAPAD : RscText {
			idc = -1;
			text = "PADdmg:";
			x = "0.428125 * safezoneW + safezoneX";
			y = "0.357 * safezoneH + safezoneY";
			w = "0.0567187 * safezoneW";
			h = "0.022 * safezoneH";
			colorText[] = {1, 1, 1, 1};
		};
		
		class SCT_PLATE_menu_RiflePenetDefault : RscText {
			idc = -1;
			text = "PnetDMG:";
			x = "0.428125 * safezoneW + safezoneX";
			y = "0.401 * safezoneH + safezoneY";
			w = "0.0567187 * safezoneW";
			h = "0.022 * safezoneH";
			colorText[] = {1, 1, 1, 1};
		};
		
		class SCT_PLATE_menu_DEBUG : RscText {
			idc = -1;
			text = "Indicators";
			x = "0.448438 * safezoneW + safezoneX";
			y = "0.445 * safezoneH + safezoneY";
			w = "0.0670312 * safezoneW";
			h = "0.022 * safezoneH";
			colorText[] = {1, 1, 1, 1};
		};
		
		class SCT_PLATE_menu_TRAUMAPAD_Edit : RscEdit {
			idc = 5965;
			text = 128;
			x = "0.494844 * safezoneW + safezoneX";
			y = "0.357 * safezoneH + safezoneY";
			w = "0.0567187 * safezoneW";
			h = "0.022 * safezoneH";
			tooltip = "damage divider for stopped bullet";
		};
		
		class SCT_PLATE_menu_RiflePenet_Edit : RscEdit {
			idc = 5966;
			text = 2;
			x = "0.494844 * safezoneW + safezoneX";
			y = "0.401 * safezoneH + safezoneY";
			w = "0.0567187 * safezoneW";
			h = "0.022 * safezoneH";
			tooltip = "FMJ penet multiplier";
		};
		
		class SCT_PLATE_menu_DEBUG_Checkbox : RscCheckbox {
			idc = 5967;
			x = "0.520625 * safezoneW + safezoneX";
			y = "0.445 * safezoneH + safezoneY";
			w = "0.0154688 * safezoneW";
			h = "0.022 * safezoneH";
			tooltip = "Apply settings";
		};
		
		class SCT_PLATE_menu_Apply : RscButton {
			idc = 5968;
			text = "Apply";
			x = "0.479375 * safezoneW + safezoneX";
			y = "0.489 * safezoneH + safezoneY";
			w = "0.0515625 * safezoneW";
			h = "0.033 * safezoneH";
			action = "call SCT_fnc_ChangeSettings; CloseDialog 0;";
			colorText[] = {1, 1, 1, 1};
			colorDisabled[] = {0, 0.6, 0, 1};
			colorBackground[] = {0, 0.6, 0, 1};
			colorBackgroundDisabled[] = {0, 0.6, 0, 1};
			colorBackgroundActive[] = {0, 0.5, 0, 1};
			colorFocused[] = {0, 0.5, 0, 1};
			colorShadow[] = {0, 0.3, 0, 1};
			colorBorder[] = {0, 0.3, 0, 1};
		};
		
		class SCT_PLATE_menu_Exit : RscButton {
			idc = -1;
			text = "X";
			x = "0.5825 * safezoneW + safezoneX";
			y = "0.291 * safezoneH + safezoneY";
			w = "0.020625 * safezoneW";
			h = "0.033 * safezoneH";
			action = "CloseDialog 0";
		};
	};
};




class CfgVehicles{
	class ContainerSupply;
//for basic init. reference : CBA
	class Land;
	/*class Man: Land{
		class EventHandlers{
			class SCTEVENT : SCTEVTEX_base {};
		};
	};*/ // involving this will cause super rabbit or something
//followed CBA config but found they are partially enabled, so looked up original

	class Supply5 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };

	class Supply10 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };

	class Supply20 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply30 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply40 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply50 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply60 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply70 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply80 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply90 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply100 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply110 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply120 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply130 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply140 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply150 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply160 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply170 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply180 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply190 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply200 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply210 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply220 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply230 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply240 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply250 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply260 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply270 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply280 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply290 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply300 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply310 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply320 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply330 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply340 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply350 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply360 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply370 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply380 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply390 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply400 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply650 : ContainerSupply {
        maximumLoad = 650;               // Replace XX with the desired capacity value.
    };
	
	class Supply780 : ContainerSupply {
        maximumLoad = 780;               // Replace XX with the desired capacity value.
    };
	
	class Supply1000 : ContainerSupply {
        maximumLoad = 1000;               // Replace XX with the desired capacity value.
    };
	
	class Supply1200 : ContainerSupply {
        maximumLoad = 1200;               // Replace XX with the desired capacity value.
    };
	
	class Supply1600 : ContainerSupply {
        maximumLoad = 1600;               // Replace XX with the desired capacity value.
    };
	
	class CAManBase {

		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	class Civilian_F;
	class SoldierGB;
	class B_Soldier_base_F;
	class B_Soldier_02_f; //extern
	class B_Soldier_03_f;
	class B_CTRG_Soldier_3_F;	// External class reference
	
	class C_man_1: Civilian_F {

		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_RangeMaster_F: B_Soldier_base_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	
	
	class B_Story_SF_Captain_F: B_Soldier_02_f{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_Story_Protagonist_F: B_Soldier_02_f{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_Story_Engineer_F: B_Soldier_base_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_Story_Pilot_F: B_Soldier_base_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_CTRG_soldier_GL_LAT_F: B_Soldier_base_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_CTRG_soldier_engineer_exp_F: B_Soldier_02_f{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	

	
	class B_CTRG_soldier_M_medic_F: B_Soldier_03_f{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_CTRG_soldier_AR_A_F: B_Soldier_03_f{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_CTRG_Miller_F : B_CTRG_Soldier_3_F {
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
		
	};
	
	class C_man_hunter_1_F: C_man_1{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class C_man_pilot_F: C_man_1{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class C_journalist_F : C_man_1 {
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
		
	};
	
	class C_Orestes; //Extern
	
	class C_Nikos: C_Orestes{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class I_G_Soldier_base_F: SoldierGB{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class B_G_Soldier_F;
	
	class I_G_Story_Protagonist_F: B_G_Soldier_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class I_G_Story_SF_Captain_F: B_G_Soldier_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class I_G_resistanceLeader_F: I_G_Story_Protagonist_F{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	
	class C_Soldier_VR_F: C_man_1{
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
	};
	

	class C_man_w_worker_F;	// External class reference
	
	class C_scientist_F : C_man_w_worker_F {
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
		
	};
	

	
	class C_Driver_1_F : C_man_1 {
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
		
	};

	
	class VirtualMan_F : Civilian_F {
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
		
	};
	
	class VirtualSpectator_F : VirtualMan_F {
		class EventHandlers {
			class SCTEVENT : SCTEVTEX_base {};
		};
		
	};
	
};

class CfgWeapons {
	
	class ItemCore;
	class InventoryItem_Base_F;

	class SonicT_Item_Base: ItemCore {
		scope = 1;
		displayName = "-";
		detectRange = -1;
		simulation = "ItemMineDetector";
		useAsBinocular = 0;
		type = 4096;
		picture = "";
		descriptionShort = "";

		class ItemInfo: InventoryItem_Base_F {
			mass = 1;
		};
	};
	
//override all vanilla body armor at most class iiia
	
	class CfgGlasses {
		class None;
	};
	
	class Vest_Camo_Base;
	class Vest_NoCamo_Base;
	class VestItem;
	class V_PlateCarrier1_rgr: Vest_NoCamo_Base { //NATO plate Carrier light.
		descriptionShort = "NIJ IIIA, plate attachable";
		class ItemInfo: VestItem {
			containerClass = "Supply780"; //vanilla 140. 2 sapi plates. 2* sapi is about 5.7kg. 2035 lightweight approx. 5kg
			mass = 20; //vanilla 60
			//armor = 100;
			class HitpointsProtectionInfo {

				
				class Chest {
					HitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = 0.150000;
				};
				
			};
		};
	};

	class V_PlateCarrier2_rgr: V_PlateCarrier1_rgr {
		scope = 2;
		descriptionShort = "NIJ IIIA, plate attachable";

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest01";
			containerClass = "Supply780"; //vanilla 140. - plate protection
			mass = 60; //vanilla 100

			class HitpointsProtectionInfo {

				class Chest {
					HitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_NIJIV_ARMOR;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD_LITE;
				};
				
			};
		};
	};

	class V_PlateCarrier2_blk;

	class V_PlateCarrier3_rgr: Vest_NoCamo_Base {
		descriptionShort = "NIJ IIIA, plate attachable";

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest01.p3d";
			containerClass = "Supply780"; //vanilla 140. - plate protection
			mass = 60; //vanilla 100

			class HitpointsProtectionInfo {

				class Chest {
					HitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD_LITE;
				};
				
			};
		};
	};

	class V_PlateCarrierGL_rgr: Vest_NoCamo_Base {
		descriptionShort = "NIJ IIIA + extended body part protection, explosive resistant";
		class ItemInfo: VestItem {
			containerClass = "Supply1600"; //vanilla 140. Juggernaut vest increase.
			mass = 170; //Added penalty to limit Jug mobility.

			class HitpointsProtectionInfo {

				class Neck {
					hitpointName = "HitNeck";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Arms {
					hitpointName = "HitArms";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Chest {
					hitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Pelvis {
					hitpointName = "HitPelvis";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = 0.600000;
				};
			};
		};
	};

	class V_PlateCarrier1_blk: Vest_Camo_Base {

		descriptionShort = "Plate attachable, No armor";

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_vest02.p3d";
			containerClass = "Supply780";
			mass = 15;

			class HitpointsProtectionInfo {

				class Chest {
					HitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD_LITE;
				};
			};
		};
	};

	class V_PlateCarrierSpec_rgr: Vest_NoCamo_Base {

		descriptionShort = "Heavy duty carrier, NIJ IIIA";

		class ItemInfo: VestItem {
			uniformModel = "\A3\Characters_F\BLUFOR\equip_b_carrier_spec_rig.p3d";
			containerClass = "Supply1200";
			mass = 100; //made it less heavier than gl rig because there is no pelvic armor

			class HitpointsProtectionInfo {

				class Neck {
					hitpointName = "HitNeck";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Arms {
					hitpointName = "HitArms";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Chest {
					hitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD;
				};
			};
		};
	};

	class V_PlateCarrierIA1_dgtl: Vest_NoCamo_Base { //greenback carrier GA lite

		descriptionShort = "NIJ IIIA, Plate attachable";
		class ItemInfo: VestItem {
			containerClass = "Supply780"; //vanilla 140. 2 sapi plates. 2* sapi is about 5.7kg. 2035 lightweight approx. 5kg
			mass = 15; //vanilla 60

			class HitpointsProtectionInfo {

				class Chest {
					HitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					HitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD;
				};
			};
		};
	};

	class V_PlateCarrierIA2_dgtl: V_PlateCarrierIA1_dgtl {
		descriptionShort = "NIJ IIIA, plate attachable";

		class ItemInfo: VestItem {
			uniformModel = "A3\Characters_F_Beta\INDEP\equip_ia_vest02";
			containerClass = "Supply780";
			mass = 55; //vanilla 80 - pelvic armors are heavy enough to protect your balls.

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Pelvis { //i really didn't know GA carrier rig have pelvic protection
					hitpointName = "HitPelvis";
					//armor = SCT_NIJIIIA_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD;
				};
			};
		};
	};

	class V_PlateCarrierIAGL_dgtl: V_PlateCarrierIA2_dgtl {
		descriptionShort = "NIJ IIIA + extended body part protection, explosive resistant";

		class ItemInfo: VestItem {
			containerClass = "Supply780";
			mass = 80;


			class HitpointsProtectionInfo {

				class Neck {
					hitpointName = "HitNeck";
					//armor = SCT_NIJIIIA_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Arms {
					hitpointName = "HitArms";
					//armor = SCT_NIJIIIA_ARMOR
					//passthrough = SCT_TRAUMAPAD_LITE;
				};

				class Chest {
					hitpointName = "HitChest";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Pelvis {
					hitpointName = "HitPelvis";
					//armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = 0.600000;
				};
			};
		};
	};

	class V_RebreatherB: Vest_Camo_Base {
		descriptionShort = "Rebreather with a little protection";

	};

	class V_Press_F: Vest_Camo_Base {

		descriptionShort = "NIJ IIIA, plate attachable"; // I really didn't like about this vest because it looked like plate armor but it was not.

		class ItemInfo: VestItem {
			containerClass = "Supply80"; //minimal weights for the armor plates
			mass = 45;

			class HitpointsProtectionInfo {

				class Chest {
					hitpointName = "HitChest";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Diaphragm {
					hitpointName = "HitDiaphragm";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Abdomen {
					hitpointName = "HitAbdomen";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Pelvis {
					hitpointName = "HitPelvis";
					armor = SCT_NIJIIIA_ARMOR;
					//passthrough = SCT_TRAUMAPAD;
				};

				class Body {
					hitpointName = "HitBody";
					//passthrough = SCT_TRAUMAPAD;
				};
			};
		};
	};

	//this is to make auto-equip CSAT Units with uniform bodywear(Oct 07)
	class Uniform_Base;
	class UniformItem;
	class U_O_CombatUniform_ocamo: Uniform_Base{
		descriptionShort="CSAT Hex camo GOST level 2";
		class ItemInfo: UniformItem
		{
			containerClass="Supply140";
			mass=80;
		};
	};
	class U_O_CombatUniform_oucamo: Uniform_Base{
		descriptionShort="CSAT Urban camo GOST level 2";
		class ItemInfo: UniformItem
		{
			containerClass="Supply140";
			mass=80;
		};
	};
	
	class U_O_GhillieSuit: Uniform_Base{
		class ItemInfo: UniformItem
		{
			containerClass="Supply140";
			mass=80;
		};
	};
	
	class U_O_PilotCoveralls: Uniform_Base{
		class ItemInfo: UniformItem
		{
			containerClass="Supply140";
			mass=80;
		};
	};
	
	class U_O_Wetsuit: Uniform_Base{
		class ItemInfo: UniformItem
		{
			containerClass="Supply140";
			mass=80;
		};
	};
	
	class U_O_V_Soldier_Viper_F: Uniform_Base
	{
		class ItemInfo: UniformItem
		{
			containerClass="Supply140";
			mass=80;
		};
	};
	class U_O_V_Soldier_Viper_hex_F: Uniform_Base{
		class ItemInfo: UniformItem
		{
			containerClass="Supply140";
			mass=80;
		};
	};
	
};

//magtype classes are for implement durability system.
//for user accessibility, item types are left - users can equip them easily by Virtual Arsenal.
//all magazine type set to 1, which means these magazines cannot access from Virtual Arsenal or 3den Editor(or Zeus).


class CfgMagazines {
	
	class CA_Magazine;
	class 30Rnd_556x45_Stanag;
	
	class BER_REPAIR: CA_Magazine {
	
		class BER_REPAIR_24 {
			scope = 2;
			allowedSlots[] = {701};
			displayName = "(Repair) Flex Tape x24";
			picture = "\SCT\addons\SonicT_vest\data\flextape.paa";
			model = "\SCT\addons\SonicT_vest\data\objects\24chargeflextape.p3d"
			descriptionShort = "24 Patches of Flex Tape<br />For when you've sawed this boat in half!";
			mass = 90;
			count = 24;

		};
	
		class BER_REPAIR_12 {
			scope = 2;
			allowedSlots[] = {701};
			displayName = "(Repair) Flex Tape x12";
			picture = "\SCT\addons\SonicT_vest\data\flextape.paa";
			model = "\SCT\addons\SonicT_vest\data\objects\24chargeflextape.p3d"
			descriptionShort = "12 Patches of Flex Tape<br />For when you need to fix a lotta damage!";
			mass = 62;
			count = 12;

		};
	
		class BER_REPAIR_6 {
			scope = 2;
			allowedSlots[] = {701};
			displayName = "(Repair) Flex Tape x6";
			picture = "\SCT\addons\SonicT_vest\data\flextape.paa";
			model = "\SCT\addons\SonicT_vest\data\objects\24chargeflextape.p3d"
			descriptionShort = "6 Patches of Flex Tape<br />Seal and repair!";
			mass = 31;
			count = 6;

		};
		
	};

	class AAPM_Item_Base_magtype: CA_Magazine {
		scope = 1;
		allowedSlots[] = {701};
		scopeArsenal = 2;
		displayName = "-";
		detectRange = -1;
		simulation = "ItemMineDetector";
		useAsBinocular = 0;
		type = 256;
		picture = "";
		descriptionShort = "";
		count = 6000;
		mass = 1;

	};
	
	//PL = NIJ Level III = 1. NIJ Level IV = 2. NIJ Level IV+ = 2.3. NIJ Level IV- = 1.75. NIJ Level III+ = 1.2. NIJ Level IIIA = 0.8. NIJ Level II = 0.7. Interpolate to determine other values as required. Military-issue plates are less vulnerable tO APs.
	//CMP = Divides PL. 1.2 for Boron Carbide, 1.0 for Alumina. 0.9 for SiC and 0.85 for B5C. 1.5 for UHMWPE and 2.0 for AR500. MIL-DTL-46100E and Armox get 1.5.

	class SCT_plate_ceramic_esapi1_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-IV ESAPI 10X12";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\ESAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-IV Ceramic, Boron Carbide<br />Introduced: 2005<br />Will withstand 30-06 M2AP";
		count = 68;
		mass = 156;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ESAPI MIL-IV ceramic ICW", 1};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.8,1.8,1.8,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4.5;
		};
	};
	
	class SCT_plate_ceramic_esapis1_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-IV ESAPI 8X10";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\ESAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-IV Ceramic, Boron Carbide<br />Introduced: 2005<br />Will withstand 30-06 M2AP";
		count = 62;
		mass = 121;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ESAPI MIL-IV ceramic ICW", 1};
			enableparts[] = {0,0,9,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.4,1.7,1.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4.5;
		};
	};
	
	class SCT_plate_ceramic_esapimc1_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-IV ESAPI 11X14";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\ESAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-IV Ceramic, Boron Carbide<br />Introduced: 2005<br />Will withstand 30-06 M2AP<br />Maximum Coverage";
		mass = 180;
		count = 74;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"ESAPI MIL-IV ceramic ICW, Maximum Coverage", 1};
			enableparts[] = {5,5,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0.4,0.4,1.85,1.85,1.85,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4.5;
		};
	};
	
	class SCT_plate_ceramic_isapi_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III+ ISAPI 10X12";
		picture = "\SCT\addons\SonicT_vest\data\isapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\ISAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III+ Ceramic, Boron Carbide<br />Introduced: 2001<br />Will withstand 7.62x39mm API";
		count = 58;
		mass = 152;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ISAPI MIL-III+ ceramic ICW", 1};
			enableparts[] = {0,0,12.5,12.5,12.5,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3.5;
		};
	};
	
	class SCT_plate_ceramic_isapih_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III+ ISAPI 11X14";
		picture = "\SCT\addons\SonicT_vest\data\isapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\ISAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III+ Ceramic, Boron Carbide<br />Introduced: 2001<br />Will withstand 7.62x39mm API";
		count = 64;
		mass = 175;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ISAPI MIL-III+ ceramic ICW", 1};
			enableparts[] = {5,5,13,13,13,0,0,0,0};
			blunttraumaPad[] = {0.5,0.5,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3.5;
		};
	};
	
	class SCT_plate_ceramic_isapis_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III+ ISAPI 8X10";
		picture = "\SCT\addons\SonicT_vest\data\isapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\ISAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III+ Ceramic, Boron Carbide<br />Introduced: 2001<br />Will withstand 7.62x39mm API";
		count = 58;
		mass = 114;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"ISAPI MIL-III+ ceramic ICW", 1};
			enableparts[] = {0,0,7,12.5,10,0,0,0,0};
			blunttraumaPad[] = {0,0,1.1,1.3,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3.5;
		};
	};
	
	class SCT_plate_ceramic_xsapi_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		PL = 4;
		displayName = "(Plate)MIL-V XSAPI/3 10X12";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\plateXSAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Silicon Carbide<br />Introduced: 2016<br />Will withstand M993, M995, or 7N39";
		mass = 159;
		count = 87;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2016 MIL-V Ceramic", 0.8};
			enableparts[] = {3,3,48,48,48,0,0,0,0};
			blunttraumaPad[] = {0.6,0.6,4,4,4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 8;
		};
	};
	
	class SCT_plate_ceramic_xsapis_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		PL = 4;
		displayName = "(Plate)MIL-V XSAPI/3 8X10";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\plateXSAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Silicon Carbide<br />Introduced: 2016<br />Will withstand M993, M995, or 7N39";
		mass = 125;
		count = 82;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2016 MIL-V Ceramic", 1};
			enableparts[] = {1,1,16,48,48,0,0,0,0};
			blunttraumaPad[] = {0.4,0.4,4,4,4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 8;
		};
	};
	
	class SCT_plate_ceramic_xsapimc_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		PL = 4;
		displayName = "(Plate)MIL-V XSAPI/3 11X14";
		picture = "\SCT\addons\SonicT_vest\data\xsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\plateXSAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Silicon Carbide<br />Introduced: 2016<br />Will withstand M993, M995, or 7N39<br />Maximum Coverage";
		mass = 182;
		count = 91;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2016", 1};
			enableparts[] = {4,2,48,48,48,0,0,0,0};
			blunttraumaPad[] = {1.2,1.4,4.5,4.5,4.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 8;
		};
	};
	
	class SCT_plate_ceramic_xsapi2009_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		PL = 4;
		displayName = "(Plate)MIL-V XSAPI/1 10X12";
		picture = "\SCT\addons\SonicT_vest\data\xsapiold.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\plateXSAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-VA Ceramic, Boron Carbide<br />Introduced: 2009<br />Will withstand M995";
		mass = 158;
		count = 76;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2009 MIL-VA", 1};
			enableparts[] = {0,0,25,25,25,0,0,0,0};
			blunttraumaPad[] = {0,0,1.9,1.9,1.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 8;
		};
	};
	
	class SCT_plate_ceramic_xsapi2011_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		PL = 4;
		displayName = "(Plate)MIL-V XSAPI/2 10X12";
		picture = "\SCT\addons\SonicT_vest\data\xsapiold.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\plateXSAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2011<br />Special Theater Contingency Plate";
		mass = 172;
		count = 94;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"XSAPI-2011 GEN2", 1};
			enableparts[] = {0,0,27,27,27,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 8;
		};
	};
	
	class SCT_plate_ceramic_hxsapi_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-VI H-XSAPI 10X12";
		picture = "\SCT\addons\SonicT_vest\data\hxsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\H-XSAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-VI Ceramic, Silicon Carbide<br />Introduced: 2018<br />Will withstand .338 Lapua";
		mass = 255;
		count = 110;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"HXSAPI-2016 MIL-V Ceramic", 1};
			enableparts[] = {11,11,66,66,66,0,0,0,0};
			blunttraumaPad[] = {1,1,6,6,6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 10;
		};
	};
	
	class SCT_plate_ceramic_hxsapih_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-VI H-XSAPI 11X14";
		picture = "\SCT\addons\SonicT_vest\data\hxsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\H-XSAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-VI Ceramic, Silicon Carbide<br />Introduced: 2018<br />Will withstand .338 Lapua";
		mass = 299;
		count = 125;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"HXSAPI-2016 MIL-V Ceramic", 1};
			enableparts[] = {14,14,66,66,66,0,0,0,0};
			blunttraumaPad[] = {1,1,6,6,6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 10;
		};
	};
	
	class SCT_plate_ceramic_hxsapiS_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-VI H-XSAPI 8X10";
		picture = "\SCT\addons\SonicT_vest\data\hxsapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\H-XSAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-VI Ceramic, Silicon Carbide<br />Introduced: 2018<br />Will withstand .338 Lapua";
		mass = 220;
		count = 104;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"HXSAPI-2016 MIL-V Ceramic", 1};
			enableparts[] = {4,4,21,44,44,0,0,0,0};
			blunttraumaPad[] = {0.9,0.9,6,6,6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 10;
		};
	};
	
	class SCT_plate_ceramic_VSPBZ_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III VS-PBZ 10X12";
		picture = "\SCT\addons\SonicT_vest\data\vspbz.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\LightSAPI.p3d"
		descriptionShort = "Used By: USSOCOM<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 2010<br />Multi-hit resistant from 5.56x45mm M855 and 7.62x39mm API";
		mass = 100;
		count = 58;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"VS-PBZ Light SAPI", 1};
			enableparts[] = {0,0,12.5,12.5,12.5,0,0,0,0};
			blunttraumaPad[] = {0,0,1.2,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	class SCT_plate_ceramic_VSPBZH_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III VS-PBZ 11X14";
		picture = "\SCT\addons\SonicT_vest\data\vspbz.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\LightSAPI.p3d"
		descriptionShort = "Used By: USSOCOM<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 2010<br />Multi-hit resistant from 5.56x45mm M855 and 7.62x39mm API";
		mass = 140;
		count = 62;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"VS-PBZ Light SAPI", 1};
			enableparts[] = {4,4,12.5,12.5,12.5,0,0,0,0};
			blunttraumaPad[] = {0.3,0.3,1.25,1.25,1.25,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	class SCT_plate_ceramic_VSPBZS_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III VS-PBZ 8X10";
		picture = "\SCT\addons\SonicT_vest\data\vspbz.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\LightSAPI.p3d"
		descriptionShort = "Used By: USSOCOM<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 2010<br />Multi-hit resistant from 5.56x45mm M855 and 7.62x39mm API";
		mass = 100;
		count = 50;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"VS-PBZ Light SAPI", 1};
			enableparts[] = {0,0,7,12.5,10.5,0,0,0,0};
			blunttraumaPad[] = {0,0,1,1.2,1.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	class SCT_plate_ceramic_ggap_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-III+ GGAP-31 10X12";
		picture = "\SCT\addons\SonicT_vest\data\greyghost.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Some Canadians<br />Rating: NIJ-III+ Ceramic, Silicon Carbide<br />Introduced: 2018<br />Six impacts of 7.62x51mm M80";
		mass = 132;
		count = 85;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"GGAP-31", 1};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3.5;
		};
	};
	
	class SCT_plate_ceramic_sapi_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III SAPI 10X12";
		picture = "\SCT\addons\SonicT_vest\data\sapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 1998<br />Multi-hit resistant";
		mass = 126;
		count = 54;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"SAPI MIL-III ICW", 1};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,0.94,0.94,0.95,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2.9;
		};
	};
	
	class SCT_plate_ceramic_sapih_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III SAPI 11X14";
		picture = "\SCT\addons\SonicT_vest\data\sapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 1998<br />Multi-hit resistant";
		mass = 161;
		count = 66;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"SAPI MIL-III ICW", 1};
			enableparts[] = {3,3,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0.4,0.4,0.95,0.95,0.95,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2.9;
		};
	};
	
	class SCT_plate_ceramic_sapiS_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III SAPI 8X10";
		picture = "\SCT\addons\SonicT_vest\data\sapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: MIL-III Ceramic, Boron Carbide<br />Introduced: 1998<br />Multi-hit resistant";
		mass = 103;
		count = 45;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"SAPI MIL-III ICW", 1};
			enableparts[] = {0,0,7,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,0.75,0.95,0.95,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2.9;
		};
	};
	
	class SCT_plate_ceramic_hesapi_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-IV+ H-ESAPI 10X12";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\H-ESAPI.p3d"
		descriptionShort = "Used By: US Air Force Pararescuemen<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2005<br />Rated to stop M993, M995, or 7N24";
		mass = 225;
		count = 115;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"H-ESAPI MIL-V", 1};
			enableparts[] = {4,4,28,26,26,0,0,0,0};
			blunttraumaPad[] = {0.8,0.8,2.6,2.6,2.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4.7;
		};
	};
	
	class SCT_plate_ceramic_hesapis_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-IV+ H-ESAPI 8X10";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\H-ESAPI.p3d"
		descriptionShort = "Used By: US Air Force Pararescuemen<br />Rating: MIL-V Ceramic, Boron Carbide<br />Introduced: 2005<br />Rated to stop M993, M995, or 7N24";
		mass = 184;
		count = 97;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"H-ESAPI MIL-V", 1};
			enableparts[] = {2,2,16,26,24,2,2,0,0};
			blunttraumaPad[] = {0.3,0.3,2,2,2,0.6,0.6,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4.7;
		};
	};
	
	class SCT_plate_ceramic_hesapimc_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-IV+ H-ESAPI 11X14";
		picture = "\SCT\addons\SonicT_vest\data\hesapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\H-ESAPI.p3d"
		descriptionShort = "Used By: US Air Force Pararescuemen<br />Rating: MIL-V Ceramic, Boron Carbide, Maximum Coverage<br />Introduced: 2005<br />Rated to stop M993, M995, or 7N24";
		mass = 273;
		count = 123;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"H-ESAPI MIL-V/MC", 1};
			enableparts[] = {4,4,26,26,26,12,6,0,0};
			blunttraumaPad[] = {0.4,0.4,2.8,2.8,2.8,1.5,0.9,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4.7;
		};
	};
	
	class SCT_plate_ceramic_socombackstop_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Trauma)SOCOM SAPI";
		picture = "\SCT\addons\SonicT_vest\data\backstop.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SOCOMSAPI.p3d"
		descriptionShort = "Used By: USSOCOM<br />Rating: Unrated, MIL-VII ICW ESAPI, Titanium<br />Introduced: 2007<br />Load behind ESAPI to reach extremely high levels of protection.";
		mass = 170;
		count = 152;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"SOCOM SAPI", 1};
			enableparts[] = {0,0,13,13,13,0,0,0,0};
			blunttraumaPad[] = {0,0,4.2,4.2,4.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2;
		};
	};
	
	class SCT_plate_ceramic_aufruest3_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)SK3 Aufruest 10X12";
		picture = "\SCT\addons\SonicT_vest\data\aufruest.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Bundeswehr<br />Rating: Schutzklasse 3 Ceramic, Boron Carbide<br />Introduced: 2010<br />Bewertet für 5.56x45mm und 7.62x51mm";
		mass = 132;
		count = 54;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"SK3", 1};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	class SCT_plate_ceramic_aufruest4_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)SK4 Aufruest 10X12";
		picture = "\SCT\addons\SonicT_vest\data\aufruest.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Bundeswehr<br />Rating: Schutzklasse 4 Ceramic, Boron Carbide<br />Introduced: 2010<br />bewertet für 7,62x51mm Stahlkern";
		mass = 162;
		count = 71;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"SK4", 1};
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4;
		};
	};
	
	class SCT_plate_ceramic_aufruest4P_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)SK4+ Aufruest 10X12";
		picture = "\SCT\addons\SonicT_vest\data\aufruest.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Bundeswehr<br />Rating: Schutzklasse 4+ Ceramic, Boron Carbide<br />Introduced: 2010<br />bewertet für mehrere Stahlkern 7.62x51mm";
		mass = 180;
		count = 90;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"SK4", 1};
			enableparts[] = {0,0,16,16,16,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4.5;
		};
	};
	
	class SCT_plate_ceramic_aufruest5_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)SK5 Aufruest 10X12";
		picture = "\SCT\addons\SonicT_vest\data\aufruest.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Bundeswehr<br />Rating: Schutzklasse 5 Ceramic, Boron Carbide<br />Introduced: 2010<br />bewertet für Wolfram 7.62x51mm";
		mass = 190;
		count = 90;

		
		class SCT_ITEMINFO{
			plateinfo[] = {"SK4", 1};
			enableparts[] = {0,0,24,24,24,0,0,0,0};
			blunttraumaPad[] = {0,0,2,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 5;
		};
	};
	
	class SCT_plate_ceramic_4sas7_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-IV Highcom 4SAS-7";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV Ceramic, Alumina<br />Introduced: 2000s<br />Rated against 30-06 M2AP";
		mass = 190;
		count = 56;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"4SAS-7 Level IV", 1};
			enableparts[] = {0,0,15,15,15,0,0,0,0};
			blunttraumaPad[] = {0,0,1.3,1.3,1.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4;
		};
	};

	class SCT_plate_steel_ar5001_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-III+ AR500 10X12";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III+<br />Introduced: 2000s<br />Will withstand repeat 5.56x45mm M193 impacts";
		mass = 250;
		count = 2000;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III+ ", 2};
			enableparts[] = {0,0,13,13,13,0,0,0,0};
			blunttraumaPad[] = {0,0,0.6,0.6,0.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2.8;
		};
	};
	
	class SCT_plate_steel_ar500C_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-III AR500 10X12";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";
		mass = 240;
		count = 2000;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III", 2};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0.55,0.55,0.55,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2.6;
		};
	};
	
	class SCT_plate_steel_ar500CS_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-III AR500 8X10";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III, Small-sized<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";
		mass = 150;
		count = 2000;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III, 8x10", 2};
			enableparts[] = {0,0,6,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0.3,0.45,0.45,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2.6;
		};
	};
	
	class SCT_plate_steel_ar500CT_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-III AR500 11X14";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III, Maximum Coverage<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm FMJ impacts";
		mass = 280;
		count = 2200;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level III/MC", 2};
			enableparts[] = {2,2,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0.1,0.2,0.57,0.57,0.57,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2.6;
		};
	};
	
	class SCT_plate_steel_ar5004_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-IV AR500 10X12";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV, Steel<br />Introduced: 2000s<br />Will withstand repeat 30-06 M2AP impacts";
		mass = 330;
		count = 2700;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IV", 2};
			enableparts[] = {0,0,13,13,13,0,0,0,0};
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2.9;
		};
	};
	
	class SCT_plate_steel_ar5004CAA_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-IV AR500-Ceramic";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV, Ceramic<br />Introduced: 2000s<br />Will withstand .22-250 Remington";
		mass = 150;
		count = 75;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IV, Ceramic", 1};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,1.13,1.13,1.13,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4;
		};
	};
	
	class SCT_plate_steel_ar5004MC_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-IV AR500 11X14";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV, Maximum Coverage<br />Introduced: 2000s<br />Will withstand repeat 30-06 M2AP impacts";
		mass = 380;
		count = 2750;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IV/MC", 2};
			enableparts[] = {4,5,13,13,13,0,0,0,0};
			blunttraumaPad[] = {0.1,0.2,0.72,0.72,0.72,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4;
		};
	};
	
	class SCT_plate_steel_arbudget_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-IIIA AR500";
		picture = "\SCT\addons\SonicT_vest\data\ar500.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IIIA, Steel<br />Introduced: 2000s<br />Will withstand repeat .44 Magnum impacts";
		mass = 120;
		count = 600;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"AR500 Level IIIA ", 2};
			enableparts[] = {0,0,8,8,8,0,0,0,0};
			blunttraumaPad[] = {0,0,0.6,0.6,0.6,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2;
		};
	};
	
	class SCT_plate_kevlar_3_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-IIIA Kevlar";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IIIA<br />Introduced: 1980s<br />Will withstand revolver impacts";
		mass = 40;
		count = 40;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Kevlar Level IIIA", 2};
			enableparts[] = {0,0,7,7,7,0,0,0,0};
			blunttraumaPad[] = {0,0,0.3,0.3,0.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2;
		};
	};
	
	class SCT_plate_kevlar_2_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-II Kevlar";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level II<br />Introduced: 1980s<br />Will withstand six 9x19mm JHP or six .357 Magnum JHP rounds";
		mass = 30;
		count = 25;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Kevlar Level II", 2};
			enableparts[] = {0,0,6,6,6,0,0,0,0};
			blunttraumaPad[] = {0,0,0.3,0.3,0.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 1.5;
		};
	};
	
	class SCT_plate_kevlar_1_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-I Kevlar";
		picture = "\SCT\addons\SonicT_vest\data\doron.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level I<br />Introduced: 1980s<br />Will withstand .22LR and .380 ACP";
		mass = 20;
		count = 14;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"Kevlar Level I", 2};
			enableparts[] = {0,0,2,3,2,0,0,0,0};
			blunttraumaPad[] = {0,0,0.2,0.2,0.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 1;
		};
	};
	
	class SCT_plate_steel_ar680_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-III+ AR680";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level III+<br />Introduced: 2010s<br />Will withstand repeat 7.62x51mm Ball";
		mass = 211;
		count = 1300;

		class SCT_ITEMINFO{
			plateinfo[] = {"AR680 Level III+", 2};
			enableparts[] = {0,0,11.5,11.5,11.5,0,0,0,0};
			blunttraumaPad[] = {0,0,0.64,0.64,0.64,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	class SCT_plate_steel_ar680b_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-IV AR680";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_steel_ar500_3p.p3d"
		descriptionShort = "Used By: Contractors, Civilians, PMCs<br />Rating: NIJ Level IV<br />Introduced: 2010s<br />Will withstand .30-06 M2AP";
		mass = 250;
		count = 1400;

		class SCT_ITEMINFO{
			plateinfo[] = {"AR680 Level IV", 2};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,0.68,0.68,0.68,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3.2;
		};
	};
	
	class SCT_plate_ceramic_SAIII_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-III BBA";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: NIJ Level III, Ceramic<br />Introduced: 2000s<br />Will withstand repeat 7.62x51mm Ball";
		mass = 122;
		count = 55;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"BBA III", 1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0.95,0.95,0.95,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	class SCT_plate_ceramic_SAIV_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-IV BBA";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Armed Forces of South Africa<br />Rating: NIJ Level IV, Ceramic<br />Introduced: 2000s<br />Will withstand 30-06 M2AP";
		mass = 144;
		count = 67;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"BBA IV", 1};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,0.98,0.98,0.98,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4;
		};
	};
	
	class SCT_plate_poly_DFNDR_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-III+ DFNDR";
		picture = "\SCT\addons\SonicT_vest\data\SCT_poly_dfndr_3p.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Civilians, Law Enforcement<br />Rating: NIJ Level III+<br />Introduced: 2000s<br />Rated for 7.62x51mm Ball impacts";
		mass = 80;
		count = 54;

		class SCT_ITEMINFO{
			plateinfo[] = {"DEFENDER Lightweight Level III+", 1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0.86,0.86,0.86,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3.2;
		};
	};
	
	class SCT_plate_poly_dragic_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-III MD Spectra";
		picture = "\SCT\addons\SonicT_vest\data\serb.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Serbian Armed Forces<br />Rating: NIJ Level III<br />Introduced: 2000s<br />Rated for M193 5.56x45mm";
		mass = 85;
		count = 52;

		class SCT_ITEMINFO{
			plateinfo[] = {"Mile Dragic Spectra III", 1};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0.76,0.76,0.76,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	class SCT_plate_trauma_AR500_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Trauma)AR500 Trauma Pad";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Civilians, SWAT<br />Rating: Non-ballistic<br />Introduced: 2010s<br />Increases chances of survival";
		mass = 15;
		count = 111;

		class SCT_ITEMINFO{
			plateinfo[] = {"Class 2 Trauma Pad", 2};
			enableparts[] = {0,0,1,1,1,0,0,0,0};
			blunttraumaPad[] = {0,0,2.2,2.2,2.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 0;
		};
	};
	
	class SCT_plate_trauma_Spartan_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Trauma)Spartan Trauma Pad";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Civilians, Survivalists<br />Rating: Non-ballistic<br />Introduced: 2010s<br />Absorbs impact force to aid in withstanding high-powered rounds";
		mass = 20;
		count = 111;

		class SCT_ITEMINFO{
			plateinfo[] = {"Class 3 Trauma Pad", 2};
			enableparts[] = {0,0,1,1,1,0,0,0,0};
			blunttraumaPad[] = {0,0,3.2,3.2,3.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 0;
		};
	};
	
	class SCT_plate_trauma_Spartanf_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Trauma)Heavy Trauma Pad";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Civilians, Survivalists<br />Rating: Non-ballistic<br />Introduced: 2010s<br />Absorbs impact force to aid in withstanding high-powered rounds";
		mass = 36;
		count = 133;

		class SCT_ITEMINFO{
			plateinfo[] = {"Class 5 Trauma Pad", 2};
			enableparts[] = {0,0,1,1,1,0,0,0,0};
			blunttraumaPad[] = {0,0,6.2,6.2,6.2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 0;
		};
	};
	
	class BER_Boost_Special_Doubler_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Special)Euro Extreme Mode";
		picture = "\SCT\addons\SonicT_vest\data\ocsk.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Switches AAPM into one-shot-kill mode<br />deducts fifty armor";
		mass = 1;
		count = 9999;

		class SCT_ITEMINFO{
			plateinfo[] = {"Euro Extreme Mode", 0};
			enableparts[] = {-50,-50,-50,-50,-50,-50,-50,-50,-50};
			blunttraumaPad[] = {1,1,1,1,1,1,1,1,1};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 0;
		};
	};
	
	class BER_Boost_Special_Infiltration_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Special)Old School Mode";
		picture = "\SCT\addons\SonicT_vest\data\ocsk.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Makes you feel like you're in the late 1990s again.<br />deducts twenty-five armor<br />Modeled after UT99 Infiltration.";
		mass = 1;
		count = 9999;

		class SCT_ITEMINFO{
			plateinfo[] = {"Old School Mode", 0};
			enableparts[] = {-25,-25,-25,-25,-25,-25,-25,-25,-25};
			blunttraumaPad[] = {1,1,1,1,1,1,1,1,1};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 0;
		};
	};
	
	class SCT_plate_poly_speedplate3_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-III SPEED-Plate";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: First Responders, Law Enforcement<br />Rating: NIJ Level III, Polyethylene<br />Introduced: 2010s<br />Rated for 5.56x45mm M193";
		mass = 110;
		count = 45;

		class SCT_ITEMINFO{
			plateinfo[] = {"SPEED-Plate Level III", 2};
			enableparts[] = {0,0,11,11,11,0,0,0,0};
			blunttraumaPad[] = {0,0,0.7,0.7,0.7,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2.8;
		};
	};
	
	class SCT_plate_poly_speedplate4_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-IV Paraclete #20015";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_poly_dfndr_3p.p3d"
		descriptionShort = "Used By: Civilians, Law Enforcement<br />Rating: NIJ Level IV, Aluminum Oxide<br />Introduced: 2010s<br />Rated for 30-06 M2AP";
		mass = 170;
		count = 68;

		class SCT_ITEMINFO{
			plateinfo[] = {"Paraclete Level IV", 1};
			enableparts[] = {0,0,14,14,14,0,0,0,0};
			blunttraumaPad[] = {0,0,0.98,0.98,0.98,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4;
		};
	};
	
	class SCT_plate_poly_PSAPI_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III SPEAR 10X12";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: NIJ Level III, Polyethylene<br />Introduced: 2010s<br />Rated for .308";
		mass = 75;
		count = 51;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"SPEAR MIL-III Polyethylene", 2};
			enableparts[] = {0,0,10,10,10,0,0,0,0};
			blunttraumaPad[] = {0,0,0.85,0.85,0.85,0,0,0,0};
			enablePlace[] = {"vest", "uniform", "backpack"};
			PL = 3;
		};
	};
	
	class SCT_plate_poly_PSAPI2_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III SPEAR 8X10";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: NIJ Level III, Polyethylene<br />Introduced: 2010s<br />Rated for .308";
		mass = 58;
		count = 50;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"SPEAR MIL-III Polyethylene", 2};
			enableparts[] = {0,0,2,10,8,0,0,0,0};
			blunttraumaPad[] = {0,0,0.82,0.85,0.78,0,0,0,0};
			enablePlace[] = {"vest", "uniform", "backpack"};
			PL = 3;
		};
	};
	
	class SCT_plate_poly_PSAPI3_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III SPEAR 11X14";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: United States Military<br />Rating: NIJ Level III, Polyethylene<br />Introduced: 2010s<br />Rated for .308";
		mass = 98;
		count = 60;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"SPEAR MIL-III Polyethylene", 2};
			enableparts[] = {3,3,10,10,10,0,0,0,0};
			blunttraumaPad[] = {0.33,0.33,0.89,0.89,0.89,0,0,0,0};
			enablePlace[] = {"vest", "uniform", "backpack"};
			PL = 3;
		};
	};
	
	class SCT_plate_ceramic_gamma_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-III TAP Gamma";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Law Enforcement<br />Rating: NIJ Level III, Aluminum Oxide<br />Introduced: 2003<br />Rated for multi-impact .308";
		mass = 128;
		count = 67;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"TAP Gamma NIJ-III", 1};
			enableparts[] = {0,0,12.3,12.3,12.3,0,0,0,0};
			blunttraumaPad[] = {0,0,1.1,1.1,1.1,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	class SCT_plate_ceramic_gamma2_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-III+ TAP Gamma";
		picture = "\SCT\addons\SonicT_vest\data\genbc.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Law Enforcement<br />Rating: NIJ Level III+, Aluminum Oxide<br />Introduced: 2003<br />Rated for M855 and M193";
		mass = 145;
		count = 69;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"TAP Gamma NIJ-III+", 1};
			enableparts[] = {0,0,13.4,13.4,13.4,0,0,0,0};
			blunttraumaPad[] = {0,0,1.15,1.15,1.15,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	class SCT_plate_poly_m1199_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-IV RMA M1199";
		picture = "\SCT\addons\SonicT_vest\data\rma.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV, Special Ceramic<br />Introduced: 2010s<br />Rated for six 30-06 M2AP - undersized 8X10 strike panel results in less overall coverage.";
		mass = 130;
		count = 90;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"RMA Level IV Ceramic panel", 1};
			enableparts[] = {1.2,1.2,30,30,30,1.2,1.2,0,0};
			blunttraumaPad[] = {0,0,1,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3.8;
		};
	};
	
	class SCT_plate_poly_m1189_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-IV RMA M1189";
		picture = "\SCT\addons\SonicT_vest\data\rma.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV, Special Ceramic<br />Introduced: 2010s<br />Rated for seven 30-06 M2AP - full sized strike panel";
		mass = 176;
		count = 98;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"RMA Level IV Ceramic panel", 1};
			enableparts[] = {3,3,36,36,36,8,3,0,0};
			blunttraumaPad[] = {0.2,0.2,1.5,2,2,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3.8;
		};
	};
	
	class SCT_plate_poly_m1155_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)NIJ-IV RMA M1155";
		picture = "\SCT\addons\SonicT_vest\data\rma.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Civilians<br />Rating: NIJ Level IV, Special Ceramic<br />Introduced: 2010s<br />Rated for five 30-06 M2AP - full sized strike panel";
		mass = 170;
		count = 83;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"RMA Level IV Ceramic panel", 1};
			enableparts[] = {1,1,29,29,29,1,1,0,0};
			blunttraumaPad[] = {0.2,0.2,1,2,2,0.5,0.5,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3.8;
		};
	};
	
	class SCT_uniform_underwear_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/U)NIJ-II Underwear";
		picture = "\SCT\addons\SonicT_vest\data\underwear.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level II Underwear";
		mass = 24;
		count = 60;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level II Underwear", 2};
			enableparts[] = {0,0,0,0,0,4,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.7,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 1.5;
		};
	};
	
	class SCT_uniform_underwear3_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/U)NIJ-IIIA Underwear";
		picture = "\SCT\addons\SonicT_vest\data\underwear.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level IIIA Underwear";
		mass = 32;
		count = 77;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 2};
			enableparts[] = {0,0,0,0,0,9,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.8,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2;
		};
	};
	
	class SCT_uniform_arms1_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/A)NIJ-II Arm Brace";
		picture = "\SCT\addons\SonicT_vest\data\arms.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level II Kevlar Arm Protection<br />9x19mm FMJ rated";
		mass = 39;
		count = 47;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level II Arm Armor", 2};
			enableparts[] = {0,7,0,0,0,0,0,0,0};
			blunttraumaPad[] = {0,0.53,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 1.5;
		};
	};
	
	class SCT_uniform_arms2_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/A)NIJ-IIIA Arm Brace";
		picture = "\SCT\addons\SonicT_vest\data\arms.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level IIIA Kevlar Arm Protection<br />.44 Magnum JHP rated";
		mass = 47;
		count = 53;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Arm Armor", 2};
			enableparts[] = {0,9.5,0,0,0,0,0,0,0};
			blunttraumaPad[] = {0,0.87,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2;
		};
	};
	
	class SCT_uniform_arms3_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/A)NIJ-III Arm Brace";
		picture = "\SCT\addons\SonicT_vest\data\arms.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level III Ceramic Arm Protection<br />7.62x51mm M80";
		mass = 56;
		count = 72;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Arm Armor", 1};
			enableparts[] = {0,11,0,0,0,0,0,0,0};
			blunttraumaPad[] = {0,1.3,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	class SCT_uniform_arms4_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/A)NIJ-IV Arm Brace";
		picture = "\SCT\addons\SonicT_vest\data\arms.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level IV Ceramic Arm Protection<br />30-06 M2AP";
		mass = 65;
		count = 82;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Arm Armor", 1};
			enableparts[] = {0,16,0,0,0,0,0,0,0};
			blunttraumaPad[] = {0,1.6,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4;
		};
	};
	
	class SCT_uniform_arms5_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/A)MIL-V Arm Brace";
		picture = "\SCT\addons\SonicT_vest\data\arms.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-V Ceramic Arm Protection<br />M995, M993, 7N37, 7N39";
		mass = 80;
		count = 95;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Arm Armor", 1};
			enableparts[] = {0,29,0,0,0,0,0,0,0};
			blunttraumaPad[] = {0,2,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 7;
		};
	};
	
	class SCT_uniform_arms6_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/A)MIL-VI Arm Brace";
		picture = "\SCT\addons\SonicT_vest\data\arms.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-VI Ceramic Arm Protection<br />.338 Lapua Magnum FMJ";
		mass = 105;
		count = 102;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Arm Armor", 1};
			enableparts[] = {0,55,0,0,0,0,0,0,0};
			blunttraumaPad[] = {0,3,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 9;
		};
	};
	
	class SCT_uniform_arms7_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/A)MIL-VII Arm Brace";
		picture = "\SCT\addons\SonicT_vest\data\arms.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-VII Ceramic Arm Protection<br />.338 Lapua Magnum API526";
		mass = 130;
		count = 142;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Arm Armor", 1};
			enableparts[] = {0,72,0,0,0,0,0,0,0};
			blunttraumaPad[] = {0,6,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 11;
		};
	};
	
	class SCT_uniform_arms8_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/A)MIL-VIII Arm Brace";
		picture = "\SCT\addons\SonicT_vest\data\arms.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-VIII Ceramic Arm Protection<br />.50 BMG Ball";
		mass = 150;
		count = 162;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Arm Armor", 1};
			enableparts[] = {0,111,0,0,0,0,0,0,0};
			blunttraumaPad[] = {0,8,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 15;
		};
	};
	
	class SCT_uniform_shirt1AD_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/S)NIJ-I Combat Shirt";
		picture = "\SCT\addons\SonicT_vest\data\uarm3.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level II Kevlar Combat Shirt<br />.22LR";
		mass = 24;
		count = 30;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 2};
			enableparts[] = {0,4,4,4,4,0,0,0,0};
			blunttraumaPad[] = {0,0.3,0.3,0.3,0.3,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 1;
		};
	};
	
	class SCT_uniform_shirt1A_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/S)NIJ-IIA Combat Shirt";
		picture = "\SCT\addons\SonicT_vest\data\uarm3.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level II Kevlar Combat Shirt<br />9x19mm JHP rated";
		mass = 34;
		count = 40;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 2};
			enableparts[] = {0,4,4,4,4,0,0,0,0};
			blunttraumaPad[] = {0,0.4,0.4,0.4,0.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 1.5;
		};
	};
	
	class SCT_uniform_shirt1_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/S)NIJ-II Combat Shirt";
		picture = "\SCT\addons\SonicT_vest\data\uarm3.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level II Kevlar Combat Shirt<br />9x19mm FMJ rated";
		mass = 56;
		count = 45;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 2};
			enableparts[] = {0,5,5,5,5,0,0,0,0};
			blunttraumaPad[] = {0,0.5,0.5,0.5,0.5,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 1.5;
		};
	};
	
	class SCT_uniform_shirt2_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/S)NIJ-IIIA Combat Shirt";
		picture = "\SCT\addons\SonicT_vest\data\uarm3.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level IIIA Kevlar Combat Shirt<br />.44 Magnum JHP rated";
		mass = 90;
		count = 47;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 2};
			enableparts[] = {0,9,9,9,9,0,0,0,0};
			blunttraumaPad[] = {0,0.85,0.85,0.85,0.85,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2;
		};
	};
	
	class SCT_uniform_neck2_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/N)NIJ-II Neck Guard";
		picture = "\SCT\addons\SonicT_vest\data\neck.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level II Kevlar Neck Guard<br />9x19mm FMJ and .357 Magnum JHP rated";
		mass = 28;
		count = 31;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 2};
			enableparts[] = {7,0,0,0,0,0,0,0,0};
			blunttraumaPad[] = {0.8,0,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 1.5;
		};
	};
	
	class SCT_uniform_neck3_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/N)NIJ-IIIA Neck Guard";
		picture = "\SCT\addons\SonicT_vest\data\neck.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level IIIA Kevlar Neck Guard<br />.44 Magnum JHP protection";
		mass = 35;
		count = 31;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 2};
			enableparts[] = {8,0,0,0,0,0,0,0,0};
			blunttraumaPad[] = {0.95,0,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2;
		};
	};
	
	class SCT_uniform_neck3d_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/N)NIJ-III Neck Guard";
		picture = "\SCT\addons\SonicT_vest\data\neck.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level III Ceramic Neck Guard<br />7.62x51mm NATO M80 Protection";
		mass = 53;
		count = 52;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 1};
			enableparts[] = {13,0,0,0,0,0,0,0,0};
			blunttraumaPad[] = {1.4,0,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	class SCT_uniform_neck4d_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/N)NIJ-IV Neck Guard";
		picture = "\SCT\addons\SonicT_vest\data\neck.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level IV Ceramic Neck Guard<br />30-06 M2AP Protection";
		mass = 71;
		count = 31;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 1};
			enableparts[] = {15,0,0,0,0,0,0,0,0};
			blunttraumaPad[] = {1.5,0,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4;
		};
	};
	
	class SCT_uniform_neck5mil_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/N)MIL-V Neck Guard";
		picture = "\SCT\addons\SonicT_vest\data\neck.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-V Ceramic Neck Guard<br />M995 / M993 Protection";
		mass = 82;
		count = 45;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 1};
			enableparts[] = {25,0,0,0,0,0,0,0,0};
			blunttraumaPad[] = {3,0,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 7;
		};
	};
	
	class SCT_uniform_neck6mil_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/N)MIL-VI Neck Guard";
		picture = "\SCT\addons\SonicT_vest\data\neck.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-VI Ceramic Neck Guard<br />.338 Lapua Magnum / 7N33 Protection";
		mass = 100;
		count = 67;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 1};
			enableparts[] = {45,0,0,0,0,0,0,0,0};
			blunttraumaPad[] = {5,0,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 9;
		};
	};
	
	class SCT_uniform_neck7mil_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/N)MIL-VII Neck Guard";
		picture = "\SCT\addons\SonicT_vest\data\neck.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-VII Ceramic Neck Guard<br />.338 Lapua Magnum API526 Protection";
		mass = 120;
		count = 82;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 1};
			enableparts[] = {72,0,0,0,0,0,0,0,0};
			blunttraumaPad[] = {6,0,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 11;
		};
	};
	
	class SCT_uniform_neck8mil_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/N)MIL-VIII Neck Guard";
		picture = "\SCT\addons\SonicT_vest\data\neck.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-VIII Ceramic Neck Guard<br />.50 BMG Ball Protection";
		mass = 140;
		count = 111;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 1};
			enableparts[] = {144,0,0,0,0,0,0,0,0};
			blunttraumaPad[] = {8,0,0,0,0,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 15;
		};
	};
	
	class SCT_uniform_pelvisa_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/P)NIJ-I Pelvis Guard";
		picture = "\SCT\addons\SonicT_vest\data\pelvis.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level I Kevlar Pelvis Guard<br />.22LR Rated";
		mass = 41;
		count = 31;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 2};
			enableparts[] = {0,0,0,0,0,3,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.4,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 1;
		};
	};
	
	class SCT_uniform_pelvis1a_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/P)NIJ-IIA Pelvis Guard";
		picture = "\SCT\addons\SonicT_vest\data\pelvis.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level IIA Kevlar Pelvis Guard<br />9x19mm JHP rated";
		mass = 45;
		count = 32;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 2};
			enableparts[] = {0,0,0,0,0,4,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.5,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 1.5;
		};
	};
	
	class SCT_uniform_pelvis1_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/P)NIJ-II Pelvis Guard";
		picture = "\SCT\addons\SonicT_vest\data\pelvis.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level II Kevlar Pelvis Guard<br />9x19mm FMJ rated";
		mass = 52;
		count = 52;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Underwear", 2};
			enableparts[] = {0,0,0,0,0,6,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.69,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 1.5;
		};
	};
	
	class SCT_uniform_pelvis2_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/P)NIJ-IIIA Pelvis Guard";
		picture = "\SCT\addons\SonicT_vest\data\pelvis.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level IIIA Kevlar Pelvis Guard<br />.44 Magnum JHP rated";
		mass = 60;
		count = 57;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Pelvis", 2};
			enableparts[] = {0,0,0,0,0,8,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.9,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2;
		};
	};
	
	class SCT_uniform_pelvis3_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/P)NIJ-III Pelvis Guard";
		picture = "\SCT\addons\SonicT_vest\data\pelvis.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level III Ceramic Pelvis Guard<br />7.62x51mm M80 Rated";
		mass = 78;
		count = 67;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ-III Cockblocker", 1};
			enableparts[] = {0,0,0,0,0,13,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,1.4,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	class SCT_uniform_pelvis4_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/P)NIJ-IV Pelvis Guard";
		picture = "\SCT\addons\SonicT_vest\data\pelvis.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level IV Ceramic Pelvis Guard<br />30-06 M2AP Rated";
		mass = 90;
		count = 87;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ-IV Cockblocker", 1};
			enableparts[] = {0,0,0,0,0,14,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,1.4,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4;
		};
	};
	
	class SCT_uniform_pelvis5_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/P)MIL-V Pelvis Guard";
		picture = "\SCT\addons\SonicT_vest\data\pelvis.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-V Ceramic Pelvis Guard<br />M995, M993, 7N37, 7N39 Rated";
		mass = 120;
		count = 100;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V Cockblocker", 1};
			enableparts[] = {0,0,0,0,0,29,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,2.5,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 7;
		};
	};
	
	class SCT_uniform_pelvis6_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/P)MIL-VI Pelvis Guard";
		picture = "\SCT\addons\SonicT_vest\data\pelvis.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-VI Ceramic Pelvis Guard<br />.338 Lapua Magnum FMJ rated";
		mass = 140;
		count = 111;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI Cockblocker", 1};
			enableparts[] = {0,0,0,0,0,55,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,4,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 9;
		};
	};
	
	class SCT_uniform_pelvis7_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/P)MIL-VII Pelvis Guard";
		picture = "\SCT\addons\SonicT_vest\data\pelvis.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-VII Ceramic Pelvis Guard<br />.338 Lapua Magnum API526 rated";
		mass = 170;
		count = 140;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII Cockblocker", 1};
			enableparts[] = {0,0,0,0,0,72,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,6,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 11;
		};
	};
	
	class SCT_uniform_pelvis8_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/P)MIL-VIII Pelvis Guard";
		picture = "\SCT\addons\SonicT_vest\data\pelvis.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-VIII Ceramic Pelvis Guard<br />.50 BMG Ball";
		mass = 180;
		count = 170;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII Cockblocker", 1};
			enableparts[] = {0,0,0,0,0,72,0,0,0};
			blunttraumaPad[] = {0,0,0,0,0,8,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 15;
		};
	};
	
	class SCT_uniform_leg1_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/L)NIJ-II Pants";
		picture = "\SCT\addons\SonicT_vest\data\mediumpants.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level II Kevlar Leg Armor<br />9x19mm FMJ rated";
		mass = 47;
		count = 57;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Pants", 2};
			enableparts[] = {0,0,0,0,0,3,6,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.4,0.69,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 1.5;
		};
	};
	
	class SCT_uniform_leg2_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/L)NIJ-IIIA Pants";
		picture = "\SCT\addons\SonicT_vest\data\mediumpants.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level IIIA Kevlar Leg Armor<br />.44 Magnum JHP rated";
		mass = 68;
		count = 63;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IIIA Pants", 2};
			enableparts[] = {0,0,0,0,0,4,8,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.5,0.92,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2;
		};
	};
	
	class SCT_uniform_leg3_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/L)NIJ-III Leg Armor";
		picture = "\SCT\addons\SonicT_vest\data\mediumpants.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level III Ceramic Leg Armor<br />7.62x51mm M80 Rated<br />Pelvis is IIIA Kevlar";
		mass = 90;
		count = 72;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level III Pants", 1};
			enableparts[] = {0,0,0,0,0,6,11,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.7,1.3,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	class SCT_uniform_leg4_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/L)NIJ-IV Leg Armor";
		picture = "\SCT\addons\SonicT_vest\data\mediumpants.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Level IV Ceramic Leg Armor<br />30-06 M2AP Rated<br />Pelvis is IIIA Kevlar";
		mass = 110;
		count = 82;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level IV Pants", 1};
			enableparts[] = {0,0,0,0,0,6,15,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.7,1.5,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4;
		};
	};
	
	class SCT_uniform_leg5_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/L)MIL-V Leg Armor";
		picture = "\SCT\addons\SonicT_vest\data\mediumpants.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-V Ceramic Leg Armor<br />M993, M995, 7N37, 7N39 Rated<br />Pelvis is IIIA Kevlar";
		mass = 170;
		count = 130;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level V Pants", 1};
			enableparts[] = {0,0,0,0,0,6,32,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.7,3,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 7;
		};
	};
	
	class SCT_uniform_leg6_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/L)MIL-VI Leg Armor";
		picture = "\SCT\addons\SonicT_vest\data\mediumpants.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-VI Ceramic Leg Armor<br />.338 Lapua Magnum FMJ<br />Pelvis is IIIA Kevlar";
		mass = 195;
		count = 150;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level VI Pants", 1};
			enableparts[] = {0,0,0,0,0,6,53,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.7,4,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 9;
		};
	};
	
	class SCT_uniform_leg7_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/L)MIL-VII Leg Armor";
		picture = "\SCT\addons\SonicT_vest\data\mediumpants.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-VII Ceramic Leg Armor<br />.338 Lapua Magnum API526<br />Pelvis is IIIA Kevlar";
		mass = 211;
		count = 183;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level VII Pants", 1};
			enableparts[] = {0,0,0,0,0,6,72,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.7,6,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 11;
		};
	};
	
	class SCT_uniform_leg8_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Uparmor/L)MIL-VIII Leg Armor";
		picture = "\SCT\addons\SonicT_vest\data\mediumpants.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "MIL-VIII Ceramic Leg Armor<br />.50 BMG<br />Pelvis is IIIA Kevlar";
		mass = 241;
		count = 220;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"Level VII Pants", 1};
			enableparts[] = {0,0,0,0,0,6,120,0,0};
			blunttraumaPad[] = {0,0,0,0,0,0.7,8,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 15;
		};
	};
	
	class SCT_booster_helmetface2_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Booster)NIJ-II Helmet Booster";
		picture = "\SCT\addons\SonicT_vest\data\ocsk.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Reinforcement for helmet";
		mass = 20;
		count = 25;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ II", 2};
			enableparts[] = {0,0,0,0,0,0,0,7,7};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0.6,0.6};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 1.5;
		};
	};
	
	class SCT_booster_helmetface3a_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Booster)NIJ-IIIA Helmet Booster";
		picture = "\SCT\addons\SonicT_vest\data\ocsk.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Reinforcement for helmet";
		mass = 35;
		count = 30;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IIIA", 2};
			enableparts[] = {0,0,0,0,0,0,0,8,8};
			blunttraumaPad[] = {0,0,0,0,0,0,0,0.7,0.7};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 2;
		};
	};
	
	class SCT_booster_helmetface3_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Booster)NIJ-III Helmet Booster";
		picture = "\SCT\addons\SonicT_vest\data\ocsk.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Helmet reinforcement";
		mass = 40;
		count = 53;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ III", 1};
			enableparts[] = {0,0,0,0,0,0,0,13,13};
			blunttraumaPad[] = {0,0,0,0,0,0,0,1,1};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 3;
		};
	};
	
	
	class SCT_booster_helmetface4_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Booster)NIJ-IV Helmet Booster";
		picture = "\SCT\addons\SonicT_vest\data\ocsk.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Heavy Helmet Reinforcement";
		mass = 57;
		count = 41;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"NIJ IV", 1};
			enableparts[] = {0,0,0,0,0,0,0,16,16};
			blunttraumaPad[] = {0,0,0,0,0,0,0,1.6,1.6};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 4;
		};
	};
	
	class SCT_booster_helmetface5_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Booster)MIL-V Helmet Booster";
		picture = "\SCT\addons\SonicT_vest\data\ocsk.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Super-heavy Helmet Reinforcement";
		mass = 70;
		count = 65;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-V", 1};
			enableparts[] = {0,0,0,0,0,0,0,22,22};
			blunttraumaPad[] = {0,0,0,0,0,0,0,2,2};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 8;
		};
	};
	
	class SCT_booster_helmetface6_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Booster)MIL-VI Helmet Booster";
		picture = "\SCT\addons\SonicT_vest\data\ocsk.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Juggernaut Helmet Reinforcement";
		mass = 90;
		count = 78;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VI", 1};
			enableparts[] = {0,0,0,0,0,0,0,30,30};
			blunttraumaPad[] = {0,0,0,0,0,0,0,2.7,2.7};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 9;
		};
	};
	
	class SCT_booster_helmetface7_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Booster)MIL-VII Helmet Booster";
		picture = "\SCT\addons\SonicT_vest\data\ocsk.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Assault Juggernaut Helmet Reinforcement";
		mass = 140;
		count = 155;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII", 1};
			enableparts[] = {0,0,0,0,0,0,0,90,90};
			blunttraumaPad[] = {0,0,0,0,0,0,0,3.7,3.7};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 11;
		};
	};
	
	class SCT_booster_helmetface8_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Booster)MIL-VIII Helmet Booster";
		picture = "\SCT\addons\SonicT_vest\data\ocsk.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Grognard Helmet Reinforcement";
		mass = 160;
		count = 200;
	
		class SCT_ITEMINFO{
			plateinfo[] = {"MIL-VII", 1};
			enableparts[] = {0,0,0,0,0,0,0,700,700};
			blunttraumaPad[] = {0,0,0,0,0,0,0,7,7};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
			PL = 15;
		};
	};
	
};

