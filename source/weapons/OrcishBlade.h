#ifndef ORCISHBLADE_H_
#define ORCISHBLADE_H_

#include "MeleeWeapon.h"
#include "../TestSuite/time.h"

#ifndef UNIT
#define UINT
typedef unsigned int uint;
#endif

namespace bammm
{
	class OrcishBlade : public MeleeWeapon
	{
		private:
			WeaponData* weaponData;
			uint timer;
			Time time;

		public:
			OrcishBlade();
			OrcishBlade(WeaponData* wd);
			~OrcishBlade();
			int attack();
			bool canAttack();
	};

	OrcishBlade::OrcishBlade()
	{
		int damage = 6;
		int cooldown = 2;

		weaponData = new WeaponData(damage, cooldown, "", "melee");
		timer = 0;
	}

	OrcishBlade::OrcishBlade(WeaponData* wd)
	{
		weaponData = wd;
		timer = 0;
	}

	OrcishBlade::~OrcishBlade()
	{
		delete weaponData;
	}

	int OrcishBlade::attack()
	{
		time = time.current();
		if (canAttack())
		{
			timer = time.getSeconds() + weaponData->getFireRate();
			return weaponData->getDamage();
		}
		return 0;
	}

	bool OrcishBlade::canAttack()
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
