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
			int attack();
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

	int Stein::attack()
	{
		if (canAttack())
		{
			timer = time->getSeconds() + weaponData->getFireRate();
			return weaponData->getDamage();
		}

		return 0;
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
