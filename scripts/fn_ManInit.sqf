_unit = _this select 0;


if(isNil {_unit getVariable "Init"}) then {

	if(_unit isKindOf "CAManBase") then {
		if(isClass (configFile >> "CfgPatches" >> "ace_medical")) then { //Check whether ace medical is enabled
			[_unit] spawn {
				params["_this"];
				sleep 2;
				_this removeAllEventHandlers "HandleDamage"; //Disable ace medical damage handling
				[_this, 1] execVM "\SCT\addons\SonicT_vest\scripts\fn_Vestinit.sqf"; //Add AAPM damage handling
			};
		}else{
			[_unit, 0] execVM "\SCT\addons\SonicT_vest\scripts\fn_Vestinit.sqf"; //Add AAPM damage handling
			
		};
		
		
	};
	
	
} else{
	
};