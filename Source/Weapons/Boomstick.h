/*
 * Boomstick.h
 *
 *  Created on: Oct 27, 2013
 *      Author: michael
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

			WeaponData& weaponData;
			float timer;
			Time* time;

		public:

			Boomstick();
			Boomstick(WeaponData&);
			~Boomstick();
			int attack();
			bool canAttack();
			int getRange();

	};

	Boomstick::Boomstick()
	{
		weaponData = new WeaponData(1, 10000, 1, 0.01, 1, "", "ranged");
		timer = 0.0;
		time = new Time();
	}

	Boomstick::Boomstick(WeaponData& wd)
	{
		weaponData = &wd;
		timer = 0.0;
		time = new Time();
	}

	Boomstick::~Boomstick()
	{
		delete time;
	}

	int Boomstick::attack()
	{
		return weaponData->getDamage();
	}

	bool Boomstick::canAttack()
	{
		if (time->getSeconds() < timer)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	int Boomstick::getRange(){
		return weaponData->getRange();
	}

}

#endif /* BOOMSTICK_H_ */
