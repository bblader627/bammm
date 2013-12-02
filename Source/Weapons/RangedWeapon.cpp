/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *  Bradley Crusco
 * Description:
 * RangedWeapon cpp file.
 *
 */

#include "RangedWeapon.h"

namespace bammm
{
	RangedWeapon::RangedWeapon(WeaponData weaponData)
	{
		_weaponData = weaponData;
	}

	RangedWeapon::RangedWeapon()
	{
	}
	
	RangedWeapon::~RangedWeapon()
	{
	}

	int RangedWeapon::attack()
	{
		return 0;
	}

	bool RangedWeapon::canAttack()
	{
		return true;
	}

	int RangedWeapon::getRange()
	{
		return 0;
	}
}
