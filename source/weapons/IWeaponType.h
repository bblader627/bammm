#ifndef IWEAPONTYPE_H_
#define IWEAPONTYPE_H_

#include "weapondata.h"
//#include "../states/AttackState.h"
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
			int attack();
			virtual bool canAttack();
	};
}
#endif
