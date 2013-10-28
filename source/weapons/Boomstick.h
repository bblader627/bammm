/*
 * Boomstick.h
 *
 *  Created on: Oct 27, 2013
 *      Author: michael
 */

#ifndef BOOMSTICK_H_
#define BOOMSTICK_H_

#include "RangedWeapon.h"
#include "../actors/actor.h"
#include "../TestSuite/time.h"

namespace bammm
{

	class Boomstick: RangedWeapon
	{

		private:

			WeaponData * weaponData;
			float timer;
			Time* time;

		public:

			Boomstick();
			Boomstick(WeaponData *);
			~Boomstick();
			void attack(Actor *);
			bool canAttack();
			int getRange();

	};

	Boomstick::Boomstick()
	{
		weaponData = new WeaponData(3, 10000, 1, 0.01, 1, "", "ranged");
		timer = 0.0;
		time = new Time();
	}

	Boomstick::Boomstick(WeaponData * wd)
	{
		weaponData = wd;
		timer = 0.0;
		time = new Time();
	}

	Boomstick::~Boomstick()
	{
		delete weaponData;
		delete time;
	}

	void Boomstick::attack(Actor* actor)
	{
		int damage = weaponData->getDamage();

		if (actor == NULL)
		{
			return;
		}

		if (canAttack())
		{
			actor->reduceHealth(damage);
			timer = time->getSeconds() + weaponData->getFireRate();
		}
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
