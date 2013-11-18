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
 * Stein header file.
 *
 */

#ifndef STEIN_H_
#define STEIN_H_

#include "MeleeWeapon.h"
#include "../TestSuite/Time.h"

#ifndef UNIT
#define UINT
typedef unsigned int uint;
#endif

namespace bammm
{
	class Stein: public MeleeWeapon
	{
		private:
			WeaponData* _weaponData;
			uint _timer;
			Time _time;

		public:
			Stein();
			Stein(WeaponData* weaponData);
			~Stein();

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

	Stein::Stein()
	{
		int damage = 10;
		int cooldown = 2;

		_weaponData = new WeaponData(damage, cooldown, "", "melee");
		_timer = 0;
	}

	Stein::Stein(WeaponData* weaponData)
	{
		_weaponData = weaponData;
		_timer = 0;
	}

	Stein::~Stein()
	{
		delete _weaponData;
	}

	int Stein::attack()
	{
		_time = _time.current();
		if (canAttack())
		{
			_timer = _time.getSeconds() + _weaponData->getFireRate();
			return _weaponData->getDamage();
		}

		return 0;
	}

	bool Stein::canAttack()
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
