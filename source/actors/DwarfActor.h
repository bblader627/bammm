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
#include "../resources/vector3d.h"
#include "actor.h"

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
			bloodAlcoholContent = 0.00;
			goldCount = 0;
		}

		DwarfActor(float BAC, int gold)
		{
			bloodAlcoholContent = BAC;
			goldCount = gold;
		}

		inline float getBAC()
		{
			return bloodAlcoholContent;
		}

		inline float incrementBAC()
		{
			bloodAlcoholContent += 0.001;
			this->velocity -= 0.01;
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
