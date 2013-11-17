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
 * OrcActor header file.
 *
 */
#ifndef ORCACTOR_H_
#define ORCACTOR_H_

#include <cmath>
#include "../SceneManager/Vector3D.h"
#include "Actor.h"
#include "../Weapons/OrcishBlade.h"

namespace bammm
{
	class OrcActor: public Actor
	{
		private:
			//TODO: Why do we need additional private members specifying goldCount when actor already has _gold?
			int _goldCount;

		public:
			OrcActor()
			{
				_name = "Orc";
				_alliance = enemy;
				_goldCount = rand() % 6;
				setMeleeWeapon(new OrcishBlade());
			}

			OrcActor(int gold)
			{
				_name = "Orc";
				_alliance = enemy;
				_goldCount = gold;
				setMeleeWeapon(new OrcishBlade());
			}

			inline int getGold()
			{
				return _goldCount;
			}
	};
}

#endif
