/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *
 * Description:
 * Actor header file.
 *
 * Last Modified: Michael Abramo
 *
 */

#include "../resources/vector3d.h"
#include "actor.h"
#include "../weapons/OrcishBlade.h"
#include <cmath>

namespace bammm
{

	class OrcActor: public Actor
	{

		private:

			int goldCount;

		public:

			OrcActor()
			{
				goldCount = rand() % 6;
				this->setMeleeWeapon(new OrcishBlade());
			}

			OrcActor(int gold)
			{
				goldCount = gold;
				this->setMeleeWeapon(new OrcishBlade());
			}

			inline int getGold()
			{
				return goldCount;
			}

	};

}
