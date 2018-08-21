params["_unit"];

		_tapes = []; //Collection of all vest plates
	_vcon = vestContainer _unit; //Get vest inventory

	if(!(isNull _vcon)) then { //Add all "magazines" (plates) in the vest to the _vplates array
		{
			_name = _x select 0;
			_magcount = _x select 1;
			if(_name isKindOf ["AAPM_Item_Base_magtype", configFile >> "CfgMagazines"]) then{
				_vplates pushBack [_name, _magcount];
			};
		}forEach (magazinesAmmoCargo _vcon);
	};
