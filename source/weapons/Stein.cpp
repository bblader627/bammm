#ifndef STEIN
#define STEIN_H_

#include "IWeaponType.h"
#include "../TestSuite/time.h"
#include "../actor/actor.h"
namespace bammm
{
	class Stein: public IWeaponType
	{
		private:
			WeaponData* weaponData;
			float timer;
			Time* time;

		public:
			Stein();
			Stein(WeaponData* wd);
			~Stein();
			void attack(Actor* actor);
			bool canAttack();
	};

	Stein::Stein()
	{
		weaponData = new WeaponData(1, 1, "", "melee");
		timer = 0;
		time = new Time();
	}

	Stein::Stein(WeaponData* wd)
	{
		weaponData = wd;
		timer = 0;
		time = new Time();
	}

	Stein::~Stein()
	{
		delete weaponData;
		delete time;
	}

	void Stein::attack(Actor* actor)
	{
		int damage = weaponData->getDamage();

		if (actor == NULL)
		{
			return;
		}

		if (canAttack())
		{
			actor->reduceHealth(damage);
			time = timer->getSeconds + weaponData->getFireRate();
		}
	}

	bool canAttack()
	{
		if (time->getSeconds() < timer)
		{
			return false;
		}

		return true;
	}
}
#endif
