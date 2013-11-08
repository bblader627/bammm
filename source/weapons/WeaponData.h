/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski	
 *   Bradley Crusco
 * Description:
 * WeaponData Class header file.
 *
 * Last Modified: Alvaro Home
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
			//Constructors
			WeaponData();
			WeaponData(int damage, uint fireRate, string model, string type);
			WeaponData(int range, int clipCapacity, int damage, float reloadSpeed, uint fireRate, string model, string type);

			//Functions
	

			inline string getType()
			{
				return _type;
			}

			inline int getRange()
			{
				return _range;
			}
		
			inline int getClipCapacity()
			{
				return _clipCapacity;
			}

			inline int getDamage()
			{
				return _damage;
			}

			inline float getReloadSpeed()
			{
				return _reloadSpeed;
			}

			inline int getAmmoCount()
			{
				return _ammoCount;
			}
			
			inline uint getFireRate()
			{
				return _fireRate;
			}

			inline string getModel()
			{
				return _model;
			}
			

	};

	WeaponData::WeaponData()
	{
	}

	WeaponData::WeaponData(int damage, uint fireRate, string model, string type)
	{
		_range = 0;
		_damage = damage;
		_fireRate = fireRate;
		_model = model;
		_type = type;

	}

	WeaponData::WeaponData(int range, int clipCapacity, int damage, float reloadSpeed, uint fireRate, string model, string type)
	{
		_range = range;
		_clipCapacity = clipCapacity;
		_reloadSpeed = reloadSpeed;
		_damage = damage;
		_fireRate = fireRate;
		_model = model;
		_type = type;
	}

}
#endif
