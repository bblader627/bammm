#include "weapondata.h"

class IWeaponType
{
	protected:
		WeaponData weaponData;
	public:
		IWeaponType();
		virtual ~IWeaponType();
		virtual void attack();
		virtual bool canAttack();
		virtual void reload();
};
