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
 * EatState header file.
 *
 */

#ifndef EATSTATE_H_
#define EATSTATE_H_

#include "State.h"

using namespace std;

namespace bammm
{
	class EatState: public State
	{
		private:
			int _amount;
			string _food;

		public:
			EatState(Actor& actor);
			EatState(Actor& actor, IStateCallback* stateMachine);

			/**
			 setup
			 @Pre-Condition- No input
			 @Post-Condition- Sets up the state
			 */
			//void setup(DynamicArray<string>* args);
			void setup();

			/**
			 setAmount
			 @Pre-Condition- takes int
			 @Post-Condition- sets _amount
			 */
			 void setAmount(int amount);

			 /**
			 setFood
			 @Pre-Condition- takes string
			 @Post-Condition- sets _food
			 */
			 void setType(string type);

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

			/*
			 canEat
			 @Pre-Condition- No input
			 @Post-Condition- returns true if player has food and health is not max
			 */
			bool canEat();
	};
}

#endif
