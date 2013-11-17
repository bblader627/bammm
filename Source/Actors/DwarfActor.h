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
 * DwarfActor header file.
 *
 */

#include <iostream>
#include "../SceneManager/Vector3D.h"
#include "../Weapons/Stein.h"
#include "Actor.h"

using namespace bammm;

namespace bammm
{
	class DwarfActor: public Actor
	{
		private:
			//TODO: Why do we need additional private members specifying bloodAlcoholContent and goldCount when Actor already has _BAC and _gold?
			float _bloodAlcoholContent;
			int _goldCount;

		public:
			DwarfActor()
			{
				_name = "Dwarf";
				_alliance = ally;
				_bloodAlcoholContent = 0.00;
				setMeleeWeapon(new Stein());
				_goldCount = 0;
				_bloodAlcoholContent = _BAC;
			}

			DwarfActor(float BAC, int gold)
			{
				_name = "Dwarf";
				_alliance = ally;
				_bloodAlcoholContent = BAC;
				setMeleeWeapon(new Stein());
				_goldCount = gold;
			}

			inline float getBAC()
			{
				return _bloodAlcoholContent;
			}

			inline float incrementBAC()
			{
				_bloodAlcoholContent += 0.001;
				return _bloodAlcoholContent;

			}

			inline float incrementBAC(float amount)
			{
				_bloodAlcoholContent += amount;
				return _bloodAlcoholContent;
			}

			inline float decrementBAC()
			{
				_bloodAlcoholContent -= 0.001;
				return _bloodAlcoholContent;
			}

			inline float resetBAC()
			{
				_bloodAlcoholContent = 0.00;
				return _bloodAlcoholContent;
			}

			inline int getGold()
			{
				return _goldCount;
			}

			inline int addGold()
			{
				_goldCount++;
				return _goldCount;
			}

			inline int addGold(int amount)
			{
				_goldCount += amount;
				return _goldCount;
			}
	};
}
