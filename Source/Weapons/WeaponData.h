/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *  Bradley Crusco
 * Description:
 * WeaponData header file.
 *
 */

#ifndef WEAPONDATA_H_
#define WEAPONDATA_H_

#ifndef UINT
#define UINT
typedef unsigned int uint;
#endif

#include <iostream>

using namespace std;

namespace bammm
{
	class WeaponData
	{
		private:
			int _range;
			int _clipCapacity;
			int _damage;
			float _reloadSpeed;
			int _ammoCount;
			uint _fireRate;
			string _model;
			string _type;

		public:
			WeaponData();
			WeaponData(int damage, uint fireRate, string model, string type);
			WeaponData(int range, int clipCapacity, int damage,
					float reloadSpeed, uint fireRate, string model,
					string type);

			/**
			 getType
			 @Pre-Condition- No input
			 @Post-Condition- Returns type
			 */
			string getType();

			/**
			 getRange
			 @Pre-Condition- No input
			 @Post-Condition- Returns range
			 */
			int getRange();

			/**
			 getClipCapacity
			 @Pre-Condition- No input
			 @Post-Condition- Returns clip capacity
			 */
			int getClipCapacity();

			/**
			 getDamage
			 @Pre-Condition- No input
			 @Post-Condition- Returns damage
			 */
			int getDamage();

			/**
			 getReloadSpeed
			 @Pre-Condition- No input
			 @Post-Condition- Returns reload speed
			 */
			float getReloadSpeed();

			/**
			 getAmmoCount
			 @Pre-Condition- No input
			 @Post-Condition- Returns ammo count
			 */
			int getAmmoCount();

			/**
			 getFireRate
			 @Pre-Condition- No input
			 @Post-Condition- Returns fire rate
			 */
			uint getFireRate();

			/**
			 getModel
			 @Pre-Condition- No input
			 @Post-Condition- Returns model
			 */
			string getModel();
	};
}

#endif
