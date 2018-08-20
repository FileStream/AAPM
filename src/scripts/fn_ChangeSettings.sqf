_traumapadedit = ctrlText ((uiNamespace getVariable 'SCT_plate_Settings')displayCtrl 5965);
_rifledmgedit = ctrlText ((uiNamespace getVariable 'SCT_plate_Settings')displayCtrl 5966);
_debug = cbChecked ((uiNamespace getVariable 'SCT_plate_Settings')displayCtrl 5967);
_traumapad = parseNumber _traumapadedit;
_rifledmg = parseNumber _rifledmgedit;

if(_traumapad <= 0) then{
	_traumapad = 4.2;
};

if(_rifledmg <= 0 ) then {
	_rifledmg = 1.375;
};

profileNameSpace setVariable ["SCT_PLATE_menu_TRAUMAPAD",_traumapad];
profileNameSpace setVariable ["SCT_PLATE_menu_RiflePenet", _rifledmg];
profileNameSpace setVariable ["SCT_PLATE_menu_DEBUG_Checkbox",_debug];
saveProfileNameSpace;


//Save these in the mission namespace too, in order to make it globally broadcast.
missionNameSpace setVariable ["SCT_PLATE_menu_TRAUMAPAD",_traumapad];
missionNameSpace setVariable ["SCT_PLATE_menu_RiflePenet", _rifledmg];
missionNameSpace setVariable ["SCT_PLATE_menu_DEBUG_Checkbox",_debug];
