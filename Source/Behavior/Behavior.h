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
 * Behavior header file.
 *
 */

#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include <iostream>
#include "../Resources/HashMap.h"
#include "../Resources/DynamicArray.h"

using namespace std;

namespace bammm
{
	class Behavior
	{
		private:
			HashMap<int> _desireTable;
			DynamicArray<string> *_baseBehaviors;

		public:
			Behavior();
			Behavior(DynamicArray<string> *baseBehaviors,
					DynamicArray<int> *baseValues);

			/**
			 addBehavior
			 @Pre-Condition- Takes a behavior and a base desire level
			 @Post-Condition- returns nothing
			 */
			void addBehavior(string behavior, int desireLevel);

			/**
			 addBaseBehavior
			 @Pre-Condition- Takes a behavior and a base desire level
			 @Post-Condition- returns nothing but adds this behavior to baseBehvaiors array
			 */
			void addBaseBehavior(string behavior, int desireLevel);

			/**
			 printTable
			 @Pre-Condition- takes no arguments
			 @Post-Condition- prints the desire table
			 */
			void printTable();

			/**
			 getBaseBehaviors
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns DynamicArray of the Base behaviors
			 */
			DynamicArray<string>* getBaseBehaviors();
	};
}

#endif
