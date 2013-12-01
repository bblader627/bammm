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

using namespace std;
#include <iostream>
#include "../Resources/HashMap.h"
#include "../Resources/DynamicArray.h"

namespace bammm
{
	class Behavior
	{
		private:
			HashMap<int> _baseDesireTable;
			HashMap<int> _currentDesireTable;
			DynamicArray<string> *_baseBehaviors;

		public:
			Behavior(DynamicArray<string> *baseBehaviors);

			/**
			 addBehavior
			 @Pre-Condition- Takes a behavior and a base desire level
			 @Post-Condition- returns nothing
			 */
			void addBehavior(string behavior, int baseDesire);

			/**
			 printTable
			 @Pre-Condition- takes no arguments
			 @Post-Condition- prints the desire table
			 */
			void printTable();	
			
	};
}

#endif
