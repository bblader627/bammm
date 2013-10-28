#ifndef STEIN_H_
#define STEIN_H_

#include "MeleeWeapon.h"
#include "../DebugTools/time.h"

namespace bammm
{
	class Stein : public MeleeWeapon
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
		if (actor == NULL)
		{
			return;
		}

		if (canAttack())
		{
			actor->reduceHealth(weaponData->getDamage());
			timer = time->getSeconds() + weaponData->getFireRate();
			//return new AttackState(actor);
		}
	}

	bool Stein::canAttack()
	{
		if (time->getSeconds() < timer)
		{
			return false;
		}

		return true;
	}
}
#endif
