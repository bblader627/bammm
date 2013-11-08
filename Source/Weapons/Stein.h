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
	class Stein : public MeleeWeapon
	{
		private:
			WeaponData* weaponData;
			uint timer;
			Time time;

		public:
			Stein();
			Stein(WeaponData* wd);
			~Stein();
			int attack();
			bool canAttack();
	};

	Stein::Stein()
	{
		int damage = 10;
		int cooldown = 2;

		weaponData = new WeaponData(damage, cooldown, "", "melee");
		timer = 0;
	}

	Stein::Stein(WeaponData* wd)
	{
		weaponData = wd;
		timer = 0;
	}

	Stein::~Stein()
	{
		delete weaponData;
	}

	int Stein::attack()
	{
		time = time.current();
		if (canAttack())
		{
			timer = time.getSeconds() + weaponData->getFireRate();
			return weaponData->getDamage();
		}
		return 0;
	}

	bool Stein::canAttack()
	{
		time = time.current();
		if (time.getSeconds() < timer)
		{
			return false;
		}

		return true;
	}
}
#endif
