params["_unit","_amt"];

	_tapes = []; //Collection of all flex tape
	_inv = backpackContainer _unit; //Get backpack inventory

if(!(isNull _inv)) then { //Add all flex tape to _tapes
	{
	_name = _x select 0;
	_count = _x select 1;
	if(_name isKindOf ["BER_REPAIR", configFile >> "CfgMagazines"]) then {
		if (_amt==1) then {
			removeItemFromBackpack _name;
			if (_count>1) then {
				_inv addMagazineAmmoCargo [_x select 0, 1, (_count-1)];
			};
		};
	};
	if (_amt==1) exitWith {};
	else {
		_tapes pushBack [_name,_count];
	};
	}forEach (magazinesAmmoCargo _inv);
};

if (_amt==0) then {
count _tapes
};

