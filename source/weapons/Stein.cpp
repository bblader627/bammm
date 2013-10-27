#ifndef STEIN
#define STEIN_H_

#include "IWeaponType.h"
using namespace bammm
{
	class Stein : public IWeaponType
	{
		private:
			WeaponData weaponData;

		public:
			Stein();
			~Stein();
			void attack();
			bool canAttack();
			void reload();
	};
}
#endif
