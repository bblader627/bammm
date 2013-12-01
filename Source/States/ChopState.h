/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *	Bradley Crusco
 * Description:
 * ChopState header file.
 *
 */

#ifndef CHOPSTATE_H_
#define CHOPSTATE_H_

#include <iostream>
#include "State.h"

namespace bammm
{
	class ChopState: public State
	{
		private:
			int _successChance;
			int _maximumWood;
			int _amountToChop;
			string _treeType;

		public:
			ChopState(Actor& actor);
			ChopState(Actor& actor, IStateCallback& stateMachine);

			/**
			 setup
			 @Pre-Condition- No input
			 @Post-Condition- Sets up the state
			 */
			//virtual void setup(DynamicArray<string>* args);
			void setup();


			/**
			 setup
			 @Pre-Condition- No input
			 @Post-Condition- Sets up the state
			 */
			 void setAmount(int amountToChop);

			/**
			 setup
			 @Pre-Condition- No input
			 @Post-Condition- Sets up the state
			 */
			 void setTreeType(string treeType);
			
			/**
			 breakdown
			 @Pre-Condition- No input
			 @Post-Condition- Performs a breakdown on the state
			 */
			void breakdown();

			/**
			 tick
			 @Pre-Condition- Takes in a float deltaTime
			 @Post-Condition- Executes a tick of length deltaTime
			 */
			virtual void tick(float deltaTime);

			/**
			 switchState
			 @Pre-Condition- Takes in a string nextState
			 @Post-Condition- The current state is switched to the given nextState
			 */
			void switchState(string nextState);

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string representation of the state
			 */
			string toString();
	};
}

#endif
