#ifndef STEIN
#define STEIN_H_

#include "IWeaponType.h"
#include "../"
using namespace bammm
{
	class Stein : public IWeaponType
	{
		private:
			WeaponData* weaponData;
			float timer;
			Time* time;

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

	void Stein::attack()
	{
		if(canAttack())
		{

			time = timer->getSeconds + weaponData->getFireRate();
		}
	}

	bool canAttack()
	{
		if(time->getSeconds() > timer)
		{
			return false;
		}

		return true;
	}
}
#endif
