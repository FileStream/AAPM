//SonicT's armor overhaul script written in sept. 28th
//Rewritten by Sysroot 8/9/18

//Get penetrator lists
#include "SCT_PENETRATORS.hpp"
#include "SCT_LPENET.hpp"
#include "SCT_SPENET.hpp"
	
params ["_unit", "_ace"];

_lastPlateUpdate = 0; //Stores the last tick a plate was updated during, prevents plate duplication and a plethora of other bugs

FUNC_OVERHAULARMOR = { //Revise hitpoint values of armor
	params["_hitpoint"];
	_newhitpoint = 5;
	if(_hitpoint > 8) then{_newhitpoint = 8 + (_hitpoint /64)} else { _newhitpoint = _hitpoint};
	_newhitpoint
};

FUNC_forEachPlateDmg = { //Calculates damage absorbed by plate

	params["_plate", "_dmgleft", "_hitindex", "_padset", "_AP", "_PL"]; //Plate data (stored in the format of [name,hp]), damage taken, damaged hitpoint, padding, AP bonus.
	
	_AP = getNumber (configFile >> "cfgAmmo" >> _dmgfrom >> "AP");
	_PL = getNumber (configFile >> "cfgMagazines" >> _name >> "SCT_ITEMINFO" >> "PL");
	//_CMP = getNumber (configFile >> "cfgMagazines" >> _name >> "SCT_ITEMINFO" >> "CMP");
	//_Type = getNumber (configFile >> "cfgMagazines" >> _name >> "Type");
	_name = _plate select 0;
	_hp = _plate select 1;
	_platedmg = _hp; //Set platedamage to the current hp of the plate
	_protarr = getArray(configFile >>"CfgMagazines">> _name >> "SCT_ITEMINFO" >> "enableparts"); //Get an array containing the "enabled parts" of the plate
	_imarr = getArray(configFile >>"CfgMagazines">> _name >> "SCT_ITEMINFO" >> "blunttraumaPad"); //Get array containing trauma pad data
	
	if((count _protarr <(_hitindex + 1)) or (count _imarr < (_hitindex +1)))exitWith{ //If the damaged hitpoint isn't included in the "enabled parts" list, print an error message
		_cnt = count _protarr;
		if(!isNil("_hitindex") or (_hitindex < 9)) then {
			for [{_i=0}, {_i < (9 - _cnt)}, {_i = _i + 1}] do {_protarr pushBack 0;}; //Fill empty _protarr protection values with 0
			systemChat format ["AAPM error : Item %1 in config.cpp has a low number of protection values - it needs 9 but only has %2. Empty values have been set to 0 to ensure a stable system", _name, _cnt];
		}
		else{
			_hitindex = 4;
			systemChat format ["AAPM error : FUNC_forEachPlateDmg in fn_Vestinit.sqf somehow could not read variable 'hitindex' which means where the unit was hit. Value has been automatically set to 'abdomen', hitpoint 4."];
		};
	};
	_prot = _protarr select _hitindex; //Get the protection value of the hit part
	
	_impactabs = _imarr select _hitindex; //Get the protection value of the hit part (with trauma pad)
	_impactdam = (_dmgleft - _prot) max (_dmgleft/((_padset * _impactabs)+1)); //Calculate impact damage
	
	if(_impactdam > 0.001) then {
		_platedmg = floor(_hp - (_impactdam + _AP - (_PL * _PL) max 0)); //Calculate plate's new hp
	};

	_output = [_impactdam, _platedmg]; 
	
	_output //Return the total impact damage and the plate's new hp
};

FUNC_DAMAGEMODULE = { //To be run every time a unit takes damage, accounts for armor and plating
	params ["_impact","_unit", "_basearmor","_penet", "_hitindex", "_caliber"];
	
	[_lastPlateUpdate] spawn {waitUntil{diag_tickTime - (_this select 0) >= 1};}; //THIS STOPS PLATE DUPLICATION. NOBODY KNOWS WHY IT WORKS BUT DONT FUCKING CHANGE IT LEST YOU LONG FOR DEATH!
	
	_traumapadedit = missionNameSpace getVariable ["SCT_PLATE_menu_TRAUMAPAD",16]; //Get trauma pad protection from mission data, defaults to 16 if nothing is found
	_debug = missionNameSpace getVariable ["SCT_PLATE_menu_DEBUG_Checkbox",false]; //Checks whether debug is enabled or not
	_humandam = 4+ (3.48*_penet* _penet); //Accounts for the penetration resistance of human flesh
	
	_impactdam = ((_impact - _basearmor)/_humandam)max (_impact/(_traumapadedit+1)); //Calculate impact damage

	_penetval = ((_penet*_impact) -(_basearmor))max 0; //Calculate penetration value, cannot be negative
	_penetdam = ((_penetval/(_humandam)) max 0) * _caliber; //Internal penetration damage
	
	_fdam = _impactdam + _penetdam; //Calculate total damage
	
	
	_vplates = []; //Collection of all vest plates
	_uplates = []; //Collection of all uniform plates
	_vcon = vestContainer _unit; //Get vest inventory
	_ucon = uniformContainer _unit; //Get uniform inventory

	if(!(isNull _vcon)) then { //Add all "magazines" (plates) in the vest to the _vplates array
		{
			_name = _x select 0;
			_magcount = _x select 1;
			if(_name isKindOf ["AAPM_Item_Base_magtype", configFile >> "CfgMagazines"]) then{
				_vplates pushBack [_name, _magcount];
			};
		}forEach (magazinesAmmoCargo _vcon);
	};
	
	if(!(isNull _ucon)) then { //Add all "magazines" (plates) in the uniform to the _uplates array
		{
			_name = _x select 0;
			_magcount = _x select 1;
			if(_name isKindOf ["AAPM_Item_Base_magtype", configFile >> "CfgMagazines"]) then{
				_uplates pushBack [_name, _magcount];
			};
		}forEach (magazinesAmmoCargo _ucon);
	};
	
	{
		_name = _x select 0;
		_arr = [_x, _fdam, _hitindex, _traumapadedit] call FUNC_forEachPlateDmg; //Calculate damage absorbed by the plate
		_hp = _arr select 1; //Plate's remaining health
		_fdam = _arr select 0; //Damage not absorbed by the plate
		_vplates set [_forEachIndex, [_name, _hp]]; //Set plate's new health
		
	}forEach _vplates;
	
	// This might be used later, who knows?
	//{
		//_unit globalChat format ["damagemodule call plate %1, dmg : %2, where : %3", _x, _impact, _hitindex];
		//_arr = [_x, _fdam, _hitindex, _traumapadedit] call FUNC_forEachPlateDmg;
		//_hp = _arr select 1;
		//_fdam = _arr select 0;
		//_uplates set [_forEachIndex, [(_x select 0), _hp]];
		
	//}forEach _uplates;
	
	{
		_unit removeItemFromVest (_x select 0); //Remove outdated plate from vest
	}forEach _vplates;
	
	{
		_vcon addMagazineAmmoCargo [_x select 0, 1, _x select 1]; //Add updated plate to vest
		
	}forEach _vplates;
	
	{
		_unit removeItemFromUniform (_x select 0); //Remove outdated plate from uniform
	}forEach _uplates;	
	{
		_ucon addMagazineAmmoCargo [_x select 0, 1, _x select 1]; //Add updated plate to uniform
	}forEach _uplates;
	
	_lastPlateUpdate = diag_tickTime; //Set the current tick value to ensure a delay to prevent plate duplication
	
	_fdam //Return damage not absorbed by plate
};

FUNC_CHECKPLATE = { //Run once, checks armor values in cfg file
	params["_unit"];
	_debug = missionNameSpace getVariable ["SCT_PLATE_menu_DEBUG_Checkbox",false]; //Check whether or not debug is enabled
	_uniform = uniform _unit; //Get the unit's uniform
	_uniformdata = getText(configFile>> "cfgWeapons" >> _uniform >> "ItemInfo" >> "uniformClass"); //Get the unit's "uniform class" from the cfg
	_vest = vest _unit; //Get unit's vest

	_hGear = headgear _unit; //Get unit's current headgear
	
	_armorfull = getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"armor"); //Get full armor values
	
	if((isNil "_armorfull") or (_armorfull ==0)) then {_armorfull = 2}; //If no armorfull value is found default to 2
	
	_bodyParts = ["HitNeck","HitArms","HitChest","HitDiaphragm","HitAbdomen","HitPelvis","HitLegs","HitHead","HitFace"]; //Array of possible hitpoints, used for hitpoint initialization
	
	_armoruniformhitpoint = []; //Collection of uniform hitpoint armor values
	{
		_armoruniformhitpoint pushBack getNumber (configFile>>"cfgVehicles">>"CAManBase" >>"Hitpoints">>_x>>"armor"); //Get armor value of all uniform hitpoints
	}forEach _bodyParts;
	
	_armorvesthitpoint = [0,0,0,0,0,0,0,0,0]; //Default vest hitpoint armor to 0
		
		
	//Vanilla vest protection only cares about neck, arms, chest, diaphragm, abdomen and pelvis
	if(_vest isEqualTo "") then {_vest = "empty";} //If no vest is found set value to "empty"
	else{
		{
			if (_forEachIndex>=7 || (_hGear isEqualTo "")) then {_hGear = "empty";} //If no headgear is found for hitpoints 7+ then set value to "empty"
			else{
				_armorvesthitpoint set [_forEachIndex, getNumber (configFile>>"cfgWeapons">>_vest>>"ItemInfo">>"HitpointsProtectionInfo">>_x>>"armor")]; //Get armor value of all vest hitpoints
			};
		}forEach _bodyParts;
	};
		
	if(_uniform isEqualTo "") then {_uniform = "empty";} //If no uniform is found set uniform value to "empty"
	else{
		{
			_armorfull = getNumber (configFile>>"cfgVehicles">>_uniformdata >>"armor");
			_armoruniformhitpoint set [_forEachIndex, getNumber (configFile>>"cfgVehicles">>_uniformdata >>"Hitpoints">>_x>>"armor")]; //Get armor value of all uniform hitpoints but from "cfgVehicles"
		}forEach _bodyParts;
	};
	
	//Calculate total hit protection of uniform and vest together
	_hitprotection = [_armorfull*(_armoruniformhitpoint select 0) + (_armorvesthitpoint select 0), _armorfull*(_armoruniformhitpoint select 1) + (_armorvesthitpoint select 1),
		_armorfull*(_armoruniformhitpoint select 2) + (_armorvesthitpoint select 2),_armorfull*(_armoruniformhitpoint select 3) + (_armorvesthitpoint select 3),
		_armorfull*(_armoruniformhitpoint select 4) + (_armorvesthitpoint select 4), _armorfull*(_armoruniformhitpoint select 5) + (_armorvesthitpoint select 5),
		_armorfull*(_armoruniformhitpoint select 6) + (_armorvesthitpoint select 6), _armorfull*(_armoruniformhitpoint select 7) + (_armorvesthitpoint select 7),
		_armorfull*(_armoruniformhitpoint select 8) + (_armorvesthitpoint select 8)];
	
	/* THIS BLOCK CURRENTLY DOES NOTHING, SAVING IT FOR LATER
	{    
		if(_x isKindof ["SonicT_Item_Base", configFile >> "cfgWeapons"]) then{    
			_infoarr = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "plateinfo");
			_infoprot = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enableparts");
			_cnt = count _infoprot;
			_canAdd = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enableplace");

		};
		
	}forEach (vestitems _unit);
	
	{    
		if(_x isKindof ["SonicT_Item_Base", configFile >> "cfgWeapons"]) then{    
			_infoarr = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "plateinfo");
			_infoprot = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enableparts");
			_cnt = count _infoprot;
			_canAdd = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enableplace");
			
		};
		
	}forEach (uniformitems _unit);
	
	{    
		if(_x isKindof ["SonicT_Item_Base", configFile >> "cfgWeapons"]) then{    
			_infoarr = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "plateinfo");
			_infoprot = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enableparts");
			_cnt = count _infoprot;
			_canAdd = getArray(configFile >>"CfgWeapons">> _x >> "SCT_ITEMINFO" >> "enableplace");
		};
		
	}forEach (backpackitems _unit);
	*/
	
	//Make overhauled armor.
	_overhaularmor = _hitprotection apply {[_x] call FUNC_OVERHAULARMOR};

	_unit setVariable ["SCT_BaseArmor", _hitprotection];
	_unit setVariable["SCT_newArmor", _overhaularmor];
	
};
   
    
    
FUNC_EVENTDMGHANDLE = { //Runs every time unit takes damage

	_rifledmg = missionNameSpace getVariable ["SCT_PLATE_menu_RiflePenet",1.375]; //Get mission's rifle penetration value, defaults to 1.375
	_debug = missionNameSpace getVariable ["SCT_PLATE_menu_DEBUG_Checkbox",false]; //Check whether debug is enabled
		 
	_unit = _this select 0; //Get unit who took damage
	_cancallhitback = false;


	_basearmor = _unit getVariable "SCT_BaseArmor"; //Get base armor values
	_newarmor = _unit getVariable "SCT_newArmor"; //Get overhauled armor values

	if(isNil "_basearmor") then {_basearmor = [1,5,1,1,1,6,5];}; //If basearmor is Nil return to vanilla civilian default.
	
	_highspeed = 0;     
	
	/* None of these are used, leaving them in for later
	_endurance = _armorstat select 0;
	_platetype = ((_armorstat select 1) select 0) select 1;
	_tPad = _armorstat select 2; */
	
	_shooter = _this select 3; //Person who caused the damage
	_dmg = _this select 2; //Amount of health the unit has after the hit
	_hitnum = _this select 5; //Stores the values of the "hit"
	//infantry hitselection number 0 : face_hub, 1: neck, 2 : head, 3 : pelvis, 4 : spine1, 5 : spine2, 6 : spine3, 7 : body, 8 : arms, 9: hands, 10 : legs
	_dmgfrom = _this select 4; //The weapon that caused the damage
	_hitpoint = _this select 7; //Get the hitpoint that was damaged
	_prevdmg = _unit getHitIndex _hitnum; //Get the amount of damage the hit did

	_selectionarmor = 1;
	_currarmor = _newarmor select 2;
	
	_hitnow = _dmg - _prevdmg; //know current damage
	_originalhit = _hitnow;
	_caliber = getNumber (configFile >> "cfgAmmo" >> _dmgfrom >> "caliber");
	if(getNumber (configFile >> "cfgAmmo" >> _dmgfrom >> "typicalSpeed") < 360) then {_highspeed = _rifledmg*0.5;}; // Subsonic armor performance penalty.
	if(getNumber (configFile >> "cfgAmmo" >> _dmgfrom >> "typicalSpeed") > 880) then {_highspeed = _rifledmg*0.8;}; // penetrates soft armor, multiplying dmg
	if(getNumber (configFile >> "cfgAmmo" >> _dmgfrom >> "typicalSpeed") > 980) then {_highspeed = _rifledmg*1.3;}; // Better simulation of higher-velocity cartridges like M193.
	if(getNumber (configFile >> "cfgAmmo" >> _dmgfrom >> "typicalSpeed") > 1040) then {_highspeed = _rifledmg*1.5;}; // Better simulation of higher-velocity cartridges like M193.
	if(getNumber (configFile >> "cfgAmmo" >> _dmgfrom >> "typicalSpeed") > 1200) then {_highspeed = _rifledmg*1.8;}; // Better simulation of extremely high velocity projectiles.
	if(_dmgfrom in SCT_PENETRATORS) then {_highspeed = _rifledmg*1.3; }; //Basic AP rounds. Believed to be not effective on flesh targets. Also used for high-caliber ammunition from Project Pitman that should absolutely ignore unpowered infantry armor.
	if(_dmgfrom in SCT_SPENET) then {_highspeed = _rifledmg*2.2; }; //Exotic AP rounds. Barely effective on flesh targets but brutally good against armor.
	if(_dmgfrom in SCT_LPENET) then {_highspeed = _rifledmg*0.75;}; // less penetratable rounds - Believed to be effective on flesh targets, but not effective to other materials.
		//implement new damage model

    //Commando950's Bugfix(6/13/2018)
    //Hitpoints are now lowercase.
    //Example: HitNeck became hitneck
    //Armor begins to work again as soon as I did this.
	switch (_hitpoint) do {
			
		case "hitneck" : {
			_selectionarmor = _basearmor select 0;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 0, _caliber] call FUNC_DAMAGEMODULE;
						
		};
		case "hitarms" : {
			_selectionarmor = _basearmor select 1;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 1, _caliber] call FUNC_DAMAGEMODULE;
							
		};
		case "hitchest" : {
			_selectionarmor = _basearmor select 2;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 2, _caliber] call FUNC_DAMAGEMODULE;
				
		};
		case "hitdiaphragm" : {
			_selectionarmor = _basearmor select 3;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 3, _caliber] call FUNC_DAMAGEMODULE;
		};
		case "hitabdomen" : {
			_selectionarmor = _basearmor select 4;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 4, _caliber] call FUNC_DAMAGEMODULE;
		};
		case "hitpelvis": {
			_selectionarmor = _basearmor select 5;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 5, _caliber] call FUNC_DAMAGEMODULE;
		};
		case "hitlegs" : {
			_selectionarmor = _basearmor select 6;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 6, _caliber] call FUNC_DAMAGEMODULE;
		};
		case "hitbody" : {
			
		};
			
		case "hithead" : {
			_selectionarmor = _basearmor select 7;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 7, _caliber] call FUNC_DAMAGEMODULE;
			
		};
		case "hitface" : {
			_selectionarmor = _basearmor select 8;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 8, _caliber] call FUNC_DAMAGEMODULE;
			
		};
		
		case "hitleftarm" : {
			_selectionarmor = _basearmor select 1;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 1, _caliber] call FUNC_DAMAGEMODULE;
		};
		
		case "hitrightarm" : {
			_selectionarmor = _basearmor select 1;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 1, _caliber] call FUNC_DAMAGEMODULE;
		};
		
		case "hitleftleg" : {
			_selectionarmor = _basearmor select 6;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 6, _caliber] call FUNC_DAMAGEMODULE;
		};
		
		case "hitrightleg" : {
			_selectionarmor = _basearmor select 6;
			_originalhit = _hitnow * _selectionarmor; //revert to original bullet damage, not divided by armor protection
			_hitnow = [_originalhit, _unit, _selectionarmor, _highspeed, 6, _caliber] call FUNC_DAMAGEMODULE;
		};
		
		case "" : {
			_cancallhitback = true;
			_hitnow = 0;
			_hmul = 1;
			if(_dmgfrom isKindOf "BulletBase") then {
				
				if(isNil{_unit getHitPointDamage "leg_l"}) then {
					if(((_unit getHitPointDamage "HitArms") > 0.99) or ((_unit getHitPointDamage "HitLegs") >0.99)) then {
						_hmul = 1;
					}else{
						_hmul = 0;
					};
					_hitnow = _hitnow * _hmul;
				} else{
					if(((_unit getHitPointDamage "leg_l") > 0.99) or ((_unit getHitPointDamage "leg_r") >0.99)
					or ((_unit getHitPointDamage "hand_r") >0.99)or ((_unit getHitPointDamage "hand_r") >0.99)) then {
						_hmul = 1;
						
					} else{
						_hmul = 0;
					};
					_hitnow = _hitnow * _hmul;
				};
				
			}
		};
		default {
			
		};
	};		
	_dmg = _hitnow + _prevdmg;
	
	//with some experiments this code seems to be obsolete
	/*
	if((_dmg < 0.02) and (_dmgfrom isKindOf "BulletBase")) then {
		_bullet = getPos _unit nearestObject _dmgfrom;
		deleteVehicle _bullet;
	};
	*/	
	//backblast effect.
	
	_dir = (getPosASL (_shooter))vectorFromTo (getPosASL (_unit));
	
	_originalhitclamp = [_unit, _originalhit] call {params ["_unit", "_originalhit"]; _goback = 0; 
	if(_originalhit > 80) then {_goback = 80 + (_originalhit * 0.01);} else {_goback = _originalhit}; _goback}; //Limit magnitude of backblast to around 80 or less
	
	_force = _dir vectorMultiply (_originalhitclamp/16);
	_vel = velocity _unit;
	if((_dmgfrom isKindOf "TimeBombCore") or (_dmgfrom isKindOf "GrenadeCore")or (_dmgfrom isKindOf "FuelExplosion")) then {
		_force set [2, abs(_force select 2) * 3];
		_dir set [2, 3 * abs(_dir select 2) +3];
	}else {
	};
	_nvel = [(_vel select 0) + ((_force select 0)/(1 + abs(_vel select 0))), (_vel select 1) + ((_force select 1)/(1 + abs(_vel select 1))), (_vel select 2) + (2*(_force select 2)/(1 + abs(_vel select 2)))];
	
	
	if(alive _unit) then {
		_unit setVelocity _nvel;
	};
	
	_dmg  
}; 

FUNC_FLEXMENU = {
params["_unit"];
_amount = [_unit,0] execVM "fn_Flextape.sqf";
_tapeAction = _unit addAction [format ["<t color='#efd615'>Use Flex-Tape (x%1)</t>",_amount], {[_unit,1] execVM "fn_Flextape.sqf"; _unit removeAction _tapeAction; [_unit] call FUNC_FLEXMENU}];
};


[_unit] call FUNC_CHECKPLATE;

_tapeAction = 0;

[_unit] call FUNC_FLEXMENU;

if(_ace == 1) then {
_unit addEventHandler["HandleDamage", {[_this select 0, _this select 1, _this call FUNC_EVENTDMGHANDLE, _this select 3, _this select 4, _this select 5, _this select 6] call ACE_medical_fnc_handleDamage;}];

}
else{
	_unit addEventHandler["HandleDamage", {[_this select 0, _this select 1, _this select 2, _this select 3, _this select 4, _this select 5, _this select 6, _this select 7] call FUNC_EVENTDMGHANDLE;}];

};
_unit addEventHandler["Respawn", {[_this select 0] call FUNC_CHECKPLATE;}]; //Run checkplate on every respawn
[_unit] spawn {
	params["_unit"];
	_tems = Items _unit;
	_dduk = headgear _unit;
	_ve = vest _unit;
	while{alive _unit} do {
		
		waitUntil{!(_tems isEqualTo (Items _unit)) or !(_dduk isEqualTo (headgear _unit)) or !(_ve isEqualTo (vest _unit))};
		[_unit] call FUNC_CHECKPLATE;
		_tems = Items _unit;
		_dduk = headgear _unit;
		_ve = vest _unit;
	};
	

	
};
