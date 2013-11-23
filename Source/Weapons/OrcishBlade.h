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
 * OrcishBlade header file.
 *
 */

#ifndef ORCISHBLADE_H_
#define ORCISHBLADE_H_

#include "MeleeWeapon.h"
#include "../TestSuite/Time.h"

#ifndef UNIT
#define UINT
typedef unsigned int uint;
#endif

namespace bammm
{
	class OrcishBlade: public MeleeWeapon
	{
		private:
			WeaponData* _weaponData;
			uint _timer;
			Time _time;

		public:
			OrcishBlade();
			OrcishBlade(WeaponData& weaponData);
			~OrcishBlade();

			/**
			 attack
			 @Pre-Condition- No input
			 @Post-Condition- Attack is executed
			 */
			int attack();

			/**
			 canAttack
			 @Pre-Condition- No input
			 @Post-Condition- Returns true if weapon can attack
			 */
			bool canAttack();
	};

	OrcishBlade::OrcishBlade()
	{
		int damage = 6;
		int cooldown = 2;

		_weaponData = new WeaponData(damage, cooldown, "", "melee");
		_timer = 0;
	}

	OrcishBlade::OrcishBlade(WeaponData& weaponData)
	{
		_weaponData = &weaponData;
		_timer = 0;
	}

	OrcishBlade::~OrcishBlade()
	{
		delete _weaponData;
	}

	int OrcishBlade::attack()
	{
		_time = _time.current();
		if (canAttack())
		{
			_timer = _time.getSeconds() + _weaponData->getFireRate();
			return _weaponData->getDamage();
		}

		return 0;
	}

	bool OrcishBlade::canAttack()
	{
		_time = _time.current();
		if (_time.getSeconds() < _timer)
		{
			return false;
		}

		return true;
	}
}

#endif
