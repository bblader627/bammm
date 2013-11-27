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

#ifndef DWARFACTOR_H_
#define DWARFACTOR_H_

#include <iostream>
#include "../SceneManager/Vector3D.h"
#include "../Weapons/Stein.h"
#include "Actor.h"

namespace bammm
{
	class DwarfActor: public Actor
	{
		private:
			//TODO: Why do we need additional private members specifying bloodAlcoholContent and goldCount when Actor already has _BAC and _gold?
			float _bloodAlcoholContent;
			int _goldCount;

		public:
			DwarfActor();
			DwarfActor(float BAC, int gold);

			/**
			 getBAC
			 @Pre-Condition- No input
			 @Post-Condition- Returns _BAC
			 */
			float getBAC();

			/**
			 increaseBAC
			 @Pre-Condition- No input
			 @Post-Condition- increments BAC by .05
			 */
			float incrementBAC();

			/**
			 increaseBAC
			 @Pre-Condition- Takes in a float representing the amount to increment
			 @Post-Condition- increments BAC by amount
			 */
			float incrementBAC(float amount);

			/**
			 decrementBAC
			 @Pre-Condition- No input
			 @Post-Condition- Decrements BAC by .05;
			 */
			float decrementBAC();

			/*
			 resetBAC
			 @Pre-Condition- No input
			 @Post-Condition- sets BAC back to 0
			 */
			float resetBAC();

			/**
			 getGold
			 @Pre-Condition- No input
			 @Post-Condition- Returns _gold
			 */
			int getGold();

			/**
			 addGold
			 @Pre-Condition- No input
			 @Post-Condition- Increments amount of gold by 1
			 */
			int addGold();

			/**
			 addGold
			 @Pre-Condition- takes amount of gold to add
			 @Post-Condition- returns total amount of gold
			 */
			int addGold(int amount);
	};
}

#endif
