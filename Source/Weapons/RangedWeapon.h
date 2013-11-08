/*
 * RangedWeapon.h
 *
 *  Created on: Oct 27, 2013
 *      Author: michael
 */

#ifndef RANGEDWEAPON_H_
#define RANGEDWEAPON_H_

#include "IWeaponType.h"
//#include "../Actors/Actor.h"

namespace bammm{

	class Actor;

	class RangedWeapon
	{
		private:

		WeaponData* weaponData;

		public:

		RangedWeapon();
		~RangedWeapon();
		virtual int attack();
		virtual bool canAttack();
		virtual int getRange();

	};

}




#endif /* RANGEDWEAPON_H_ */
