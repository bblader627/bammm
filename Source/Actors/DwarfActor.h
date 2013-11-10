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
 * Last Modified: Alvaro Home
 *
 */

#include <iostream>
#include "../SceneManager/Vector3D.h"
#include "../Weapons/Stein.h"
#include "Actor.h"

using namespace bammm;

namespace bammm
{
	class DwarfActor:public Actor
	{
		//using Actor::velocity;
	private:
		float bloodAlcoholContent;
		int goldCount;

	public:
		DwarfActor()
		{
			_name = "Dwarf";
			_alliance = ally;
			bloodAlcoholContent = 0.00;
			setMeleeWeapon(new Stein());
			goldCount = 0;
		}

		DwarfActor(float BAC, int gold)
		{
			_name = "Dwarf";
			_alliance = ally;
			bloodAlcoholContent = BAC;
			setMeleeWeapon(new Stein());
			goldCount = gold;
		}

		inline float getBAC()
		{
			return bloodAlcoholContent;
		}

		inline float incrementBAC()
		{
			bloodAlcoholContent += 0.001;
			//this->velocity -= 0.01;
			return bloodAlcoholContent;

		}

		inline float incrementBAC(float amount)
		{
			bloodAlcoholContent += amount;
			return bloodAlcoholContent;
		}

		inline float decrementBAC()
		{
			bloodAlcoholContent -= 0.001;
			return bloodAlcoholContent;
		}

		inline float resetBAC()
		{
			// "Sleep it off"
			bloodAlcoholContent = 0.00;
			return bloodAlcoholContent;
		}

		inline int getGold()
		{
			return goldCount;
		}

		inline int addGold()
		{
			goldCount++;
			return goldCount;
		}

		inline int addGold(int amount)
		{
			goldCount += amount;
			return goldCount;
		}




	};
}
