#ifndef MELEEWEAPON_H_
#define MELEEWEAPON_H_

#include "IWeaponType.h"
//#include "WeaponData.h"
//#include "../Actors/Actor.h"
namespace bammm
{
	class Actor;

	//This needs to implement IWeaponType
	class MeleeWeapon
	{
		protected:
			WeaponData* weaponData;
	
		public:
			MeleeWeapon();
			virtual ~MeleeWeapon();
			virtual int attack();
			virtual bool canAttack();
	};

	MeleeWeapon::MeleeWeapon()
	{
	}

	MeleeWeapon::~MeleeWeapon()
	{
	}

	int MeleeWeapon::attack()
	{
		return 0;
	}

	bool MeleeWeapon::canAttack()
	{
		return true;
	}
}

#endif
