class CfgPatches {
	class Mercenary
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.62;
		requiredAddons[] = {};
		magazines[] = {};
		ammo[] = {};
	};
};

class CfgAILevelPresets {
	
	class AILevelSuper {
		displayName = "Super";
		skillAI = 1;
		precisionAI = 3;
	};
};

class CfgMagazines {
	class AAPM_Item_Base_magtype;
	
	class SCT_plate_steel_confed_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-I CSA Insert";
		picture = "\SCT\addons\SonicT_vest\data\civilwar.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Confederate Soldiers<br />Rating: MIL Level I<br />Introduced: 1863<br />Rated for Powder and Ball from several dozen yards";
		mass = 150;
		count = 43;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"M1", 2};
			enableparts[] = {0,0,4,4,4,0,0,0,0};
			blunttraumaPad[] = {0,0,0.4,0.4,0.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class SCT_plate_steel_union_magtype: AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-I Union Insert";
		picture = "\SCT\addons\SonicT_vest\data\civilwar.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Union Soldiers<br />Rating: MIL Level I<br />Introduced: 1863<br />Rated for Powder and Ball from several dozen yards";
		mass = 150;
		count = 43;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"M1", 2};
			enableparts[] = {0,0,4,4,4,0,0,0,0};
			blunttraumaPad[] = {0,0,0.4,0.4,0.4,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class easter_CercommultiH_magtype : AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III ENSAPI 11X14";
		picture = "\SCT\addons\SonicT_vest\data\cercom.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Prototype<br />Rating: MIL-III Multi-Hit, Boron Carbide. Enhanced design results in improved multi-hit capacity<br />Introduced: 2003<br />Rated for several impacts of 7.62x51mm M80<br />Prototype multi-hit SAPI insert designed by CERCOM in 2002-2003 that provided enhanced protection.";
		mass = 176;
		count = 81;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"sigma", 1};
			enableparts[] = {4,4,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0.55,0.55,1.14,1.14,1.14,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class easter_Cercommultil_magtype : AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III ENSAPI 10X12";
		picture = "\SCT\addons\SonicT_vest\data\cercom.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Prototype<br />Rating: MIL-III Multi-Hit, Boron Carbide. Enhanced design results in improved multi-hit capacity<br />Introduced: 2003<br />Rated for several impacts of 7.62x51mm M80<br />Prototype multi-hit SAPI insert designed by CERCOM in 2002-2003 that provided enhanced protection.";
		mass = 161;
		count = 78;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"sigma", 1};
			enableparts[] = {0,0,12,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,1.12,1.12,1.12,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
	
	class easter_CercommultiS_magtype : AAPM_Item_Base_magtype {
		scope = 2;
		displayName = "(Plate)MIL-III ENSAPI 8X10";
		picture = "\SCT\addons\SonicT_vest\data\cercom.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SAPI.p3d"
		descriptionShort = "Used By: Prototype<br />Rating: MIL-III Multi-Hit, Boron Carbide. Enhanced design results in improved multi-hit capacity<br />Introduced: 2003<br />Rated for several impacts of 7.62x51mm M80<br />Prototype multi-hit SAPI insert designed by CERCOM in 2002-2003 that provided enhanced protection.";
		mass = 146;
		count = 69;
		
		class SCT_ITEMINFO{
			plateinfo[] = {"sigma", 1};
			enableparts[] = {0,0,8,12,12,0,0,0,0};
			blunttraumaPad[] = {0,0,0.9,1.12,1.12,0,0,0,0};
			enablePlace[] = {"Vest", "Uniform", "Backpack"};
		};
	};
};
		

class CfgDifficultyPresets {
	
	class Recruit
	{
		displayName = $STR_Difficulty0;
        optionDescription = "";
		optionPicture = "";
        levelAI = "AILevelLow";

		class Options
		{
			reducedDamage = 1;

			groupIndicators = 2;
			friendlyTags = 2;
			enemyTags = 0;
			detectedMines = 2;
			commands = 2;
			waypoints = 2;
                        tacticalPing = 1;

			weaponInfo = 2;
			stanceIndicator = 2;
			staminaBar = 1;
			weaponCrosshair = 1;
			visionAid = 1;

			thirdPersonView = 1;
			cameraShake = 1;

			scoreTable = 1;
			deathMessages = 1;
			vonID = 1;

			mapContent = 1;
			autoReport = 1;
			multipleSaves = 1;
		};
	};

	class Regular
	{
		displayName = $STR_Difficulty1;
                optionDescription = "";
		optionPicture = "\A3\Ui_f\data\Logos\arma3_white_ca.paa";
                levelAI = "AILevelMedium";

		class Options
		{
			reducedDamage = 0;

			groupIndicators = 1;
			friendlyTags = 1;
			enemyTags = 0;
			detectedMines = 1;
			commands = 1;
			waypoints = 2;
                        tacticalPing = 1;


			weaponInfo = 2;
			stanceIndicator = 2;
			staminaBar = 1;
			weaponCrosshair = 1;
			visionAid = 0;

			thirdPersonView = 1;
			cameraShake = 1;

			scoreTable = 1;
			deathMessages = 1;
			vonID = 1;

			mapContent = 1;
			autoReport = 1;
			multipleSaves = 1;
		};
	};

	class Veteran
	{
		displayName = $STR_Difficulty2;
                optionDescription = "";
		optionPicture = "\A3\Ui_f\data\Logos\arma3_white_ca.paa";
                levelAI = "AILevelHigh";

		class Options
		{
			reducedDamage = 0;

			groupIndicators = 0;
			friendlyTags = 0;
			enemyTags = 0;
			detectedMines = 0;
			commands = 1;
			waypoints = 1;
                        tacticalPing = 0;

			weaponInfo = 1;
			stanceIndicator = 1;
			staminaBar = 0;
			weaponCrosshair = 0;
			visionAid = 0;

			thirdPersonView = 0;
			cameraShake = 1;

			scoreTable = 1;
			deathMessages = 1;
			vonID = 1;

			mapContent = 0;
			autoReport = 0;
			multipleSaves = 0;
		};
	};

	class Custom
	{
		displayName = $STR_Difficulty_Custom;
                optionDescription = "";
		optionPicture = "\A3\Ui_f\data\Logos\arma3_white_ca.paa";
                levelAI = "AILevelMedium";

               
		class Options
		{
			reducedDamage = 0;    

			groupIndicators = 0;
			friendlyTags = 0;
			enemyTags = 0;
			detectedMines = 0;
			commands = 0;
			waypoints = 0;
            tacticalPing = 0;       

			
			weaponInfo = 1;
			stanceIndicator = 0;
			staminaBar = 0;
			weaponCrosshair = 0;
			visionAid = 0;

			thirdPersonView = 0;
			cameraShake = 0;

			scoreTable = 0;
			deathMessages = 0;
			vonID = 0

			mapContent = 0;
			autoReport = 0;
			multipleSaves = 0;
		};
	};
	
	class Merc {
		displayName = "Mercenary";
		levelAI = "AILevelSuper";
		description = "hehehe";
		optionDescription = "";
		animSpeedCoef = 1;
		autoAimAngle = 0;
		autoAimDistance = 0;
		autoAimSizeFactor = 0;
		BleedingRate = 0.011;
		myArmorCoef = 1;
		
		class Options
		{
			reducedDamage = 0;

			groupIndicators = 0;
			friendlyTags = 0;
			enemyTags = 0;
			detectedMines = 0;
			commands = 0;
			waypoints = 0;
            tacticalPing = 0;

			weaponInfo = 1;
			stanceIndicator = 0;
			staminaBar = 0;
			weaponCrosshair = 0;
			visionAid = 0;

			thirdPersonView = 0;
			cameraShake = 1;

			scoreTable = 0;
			deathMessages = 0;
			vonID = 0;

			mapContent = 0;
			autoReport = 0;
			multipleSaves = 0;
		};
	};
};