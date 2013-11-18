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
 * Boomstick header file.
 *
 */

#ifndef BOOMSTICK_H_
#define BOOMSTICK_H_

#include "RangedWeapon.h"
#include "../Actors/Actor.h"
#include "../TestSuite/Time.h"

namespace bammm
{
	class Boomstick: RangedWeapon
	{
		private:
			WeaponData* _weaponData;
			float _timer;
			Time* _time;

		public:
			Boomstick();
			Boomstick(WeaponData* weaponData);
			~Boomstick();

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

			/**
			 getRange
			 @Pre-Condition- No input
			 @Post-Condition- Returns the distance between the weapon user and their target
			 */
			int getRange();
	};

	Boomstick::Boomstick()
	{
		_weaponData = new WeaponData(1, 10000, 1, 0.01, 1, "", "ranged");
		_timer = 0.0;
		_time = new Time();
	}

	Boomstick::Boomstick(WeaponData* weaponData)
	{
		_weaponData = weaponData;
		_timer = 0.0;
		_time = new Time();
	}

	Boomstick::~Boomstick()
	{
		delete _weaponData;
		delete _time;
	}

	int Boomstick::attack()
	{
		return _weaponData->getDamage();
	}

	bool Boomstick::canAttack()
	{
		if (_time->getSeconds() < _timer)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	int Boomstick::getRange()
	{
		return _weaponData->getRange();
	}
}

#endif
