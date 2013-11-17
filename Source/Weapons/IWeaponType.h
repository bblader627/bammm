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
 * IWeaponType header file.
 *
 */

#ifndef IWEAPONTYPE_H_
#define IWEAPONTYPE_H_

#include "WeaponData.h"

namespace bammm
{
	class Actor;

	class IWeaponType
	{
		protected:
			WeaponData* _weaponData;

		public:
			IWeaponType();
			virtual ~IWeaponType();

			/**
			 attack
			 @Pre-Condition- No input
			 @Post-Condition- Attack is executed
			 */
			int attack();

			/**
			 canAttack
			 @Pre-Condition- No input
			 @Post-Condition- Returns true if weapon can attack
			 */
			virtual bool canAttack();
	};
}

#endif
