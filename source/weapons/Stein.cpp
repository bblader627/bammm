#ifndef STEIN
#define STEIN_H_

#include "IWeaponType.h"
using namespace bammm
{
	class Stein : public IWeaponType
	{
		private:
			WeaponData* weaponData;
			float timer;

		public:
			Stein();
			Stein(WeaponData* wd);
			~Stein();
			void attack();
			bool canAttack();
	};

	Stein::Stein()
	{
		weaponData = new WeaponData(1, 1, "", "melee");
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

	void Stein::attack()
	{
		if(canAttack())
		{
			//Add a damage state to the target?
		}
		timer = weaponData->getFireRate();
	}

	bool canAttack()
	{
		if(timer > 0)
		{
			return false;
		}

		return true;
	}
}
#endif
