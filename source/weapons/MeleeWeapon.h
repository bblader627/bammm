#ifndef MELEEWEAPON_H_
#define MELEEWEAPON_H_

#include "IWeaponType.h"
//#include "weapondata.h"
//#include "../actors/actor.h"
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
}

#endif
