#include "BIS_AddonInfo.hpp"
#define _ARMA_
class CfgPatches
 {
 	class FinalSolution //thanks to Improved Ammo mod A3 for providing working examples and configuration.
 	{
 		units[] = {};
 		weapons[] = {};
 		requiredVersion = 1.00;
 		requiredAddons[] = {"A3_Weapons_F","A3_Weapons_F_Mark"};
 	};
 };
 //In this version the hit-value of all handgun bullets is taken by [2]
 class CfgAmmo
 {
	class BulletBase;
	class SubmunitionBullet;
	class ShotgunBase;
	
	class B_556x45_Ball: BulletBase
	{
		hit = 15;
		caliber = 1.3;
	};
	
	class B_556x45_Ball_Tracer_Green : BulletBase {
		hit = 15;
		caliber = 1.3;
	};
	
	class B_56x15_dual: BulletBase
	{
		hit = 13;
		caliber = 1.2;
	};
	class B_65x39_Caseless: BulletBase
	{
		hit = 22;
		caliber = 1.7;
	};
	class B_65x39_Minigun_Caseless: SubmunitionBullet
	{
		hit = 22;
		caliber = 1.9;
	};
	class B_762x51_Ball: BulletBase
	{
		hit = 27;
		caliber = 2.2;
	};
	class B_762x51_Tracer_Red: BulletBase
	{
		hit = 27;
		caliber = 2.2;
	};
	class B_762x51_Minigun_Tracer_Red: SubmunitionBullet
	{
		hit = 27;
		caliber = 2.2;
	};
	class B_12Gauge_Slug: BulletBase
	{
		hit = 20;
		caliber = 0.4;
	};
	class B_12Gauge_Pellets: ShotgunBase
	{
		hit = 4;
		caliber = 0.8;
	};
	class B_408_Ball: BulletBase
	{
		hit = 80;
		caliber = 4.5;
	};
	class B_127x33_Ball: BulletBase
	{
		hit = 18;
		caliber = 2.2;
	};
	class B_127x99_Ball: BulletBase
	{
		hit = 100;
		caliber = 4.5;
	};
	class B_127x99_SLAP: B_127x99_Ball
	{
		hit = 109;
		caliber = 5;
	};
	class B_127x108_Ball: BulletBase
	{
		hit = 105;
		caliber = 4.3;
	};
	class B_127x108_APDS: B_127x108_Ball
	{
		hit = 112;
		caliber = 4.6;
	};

	class B_338_Ball : BulletBase
	{
		hit = 54;
		caliber = 3;
	};
	
	class B_338_NM_Ball : BulletBase
	{
		hit = 51;
		caliber = 2.8;
	};
	class B_127x54_Ball : BulletBase
	{
		hit = 48;
		caliber = 2.4;
	};
	class B_93x64_Ball : BulletBase
	{
		hit = 46;
		caliber = 2.8;
	};
	class B_50BW_Ball_F: BulletBase
	{
		hit = 23;
		caliber = 1.9;
	};
	class B_545x39_Ball_F: BulletBase
	{
		hit = 13;
		caliber = 1.5;
	};
	class B_580x42_Ball_F: BulletBase
	{
		hit = 17;
	};
	class B_762x39_Ball_F: BulletBase
	{
		hit = 19;
		caliber = 1.4;
	};
	//Pistols
	class B_45ACP_Ball: BulletBase
	{
		hit = 10;
		caliber = 0.7;
	};
	
	class B_9x21_Ball: BulletBase
	{
		hit = 8;
		caliber = 0.9;
	};

	class GrenadeBase;
	class Grenade;
	/*class G_20mm_HE : GrenadeBase 
	{
		hit = 80;
		indirectHit = 80;
	};
	class G_40mm_HE : GrenadeBase 
	{
		hit = 100;
		indirectHit = 100;
	};*/
	class GrenadeHand : Grenade 
	{
		hit = 22;
		indirectHit = 33;
		indirectHitRange = 5;
		caliber = 2;
		explosionTime = 3;
	};
	class mini_Grenade : GrenadeHand
	{
		hit = 12;
		indirectHit = 12;
		caliber = 2;
		explosionTime = 4;
	};
	//rpg
	class RocketBase;
	class R_PG32V_F : RocketBase
	{
		hit = 1200;
	};
	//attack chopper gatling
	class B_30mm_AP : BulletBase
	{
		hit = 120;
	};
	class B_30mm_HE : BulletBase
	{
		hit = 140;
		indirectHit = 40;
		indirectHitRange = 7;
	};
	class B_20mm : BulletBase
	{
		hit = 140;
		indirectHit = 35;
		indirectHitRange = 4;
	};
 };