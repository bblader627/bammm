#ifndef IWEAPONTYPE_H_
#define IWEAPONTYPE_H_

#include "weapondata.h"
#include "../actors/actor.h"

namespace bammm
{
	class Actor;
	class IWeaponType
	{
		protected:
			WeaponData* weaponData;
		public:
			IWeaponType();
			virtual ~IWeaponType();
			virtual void attack(Actor* target);
			virtual bool canAttack();
	};
}
#endif
