CUSTOM PLATE ADDING REFERENCE

class SCT_plate_ceramic_esapi: SonicT_Item_Base {
		scope = 2;
		displayName = "ESAPI plate";
		picture = "\SCT\addons\SonicT_vest\data\esapi.paa";
		model = "\SCT\addons\SonicT_vest\data\objects\SCT_ceramic_esapi.p3d"
		descriptionShort = "NIJ level IV ceramic plate, ICW IIIA vest.";

		class ItemInfo: ItemInfo {
			mass = 56;
		};

		class SCT_ITEMINFO{
			plateinfo[] = {128, 28 , "ESAPI NIJ IV ceramic ICW soft body armor", 0};
		};
};


let's add more info, in additional class SCT_ITEMINFO! like this : 

class SCT_ITEMINFO{
	plateinfo[] = {128, 28 , "ESAPI NIJ IV ceramic ICW soft body armor", 0};
};

ELEMENT INFORMATION OF PLATEINFO

	select 0 : 