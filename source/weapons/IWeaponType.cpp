#ifndef IWEAPONTYPE_H_
#define IWEAPONTYPE_H_

#include "weapondata.h"
namespace bammm
{
	class IWeaponType
	{
		protected:
			WeaponData weaponData;
		public:
			IWeaponType();
			virtual ~IWeaponType();
			virtual void attack()=0;
			virtual bool canAttack()=0;
			virtual void reload()=0;
	};
}
#endif
