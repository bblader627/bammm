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
 * IStateCallback header file.
 *
 */

#ifndef ISTATECALLBACK_H_
#define ISTATECALLBACK_H_

#include <iostream>
#include "../Actors/Actor.h"

using namespace std;

namespace bammm
{
	//Forward declaration of class State;
	class State;

	class IStateCallback
	{
		public:
			IStateCallback();
			virtual ~IStateCallback();

			/**
			 switchState
			 @Pre-Condition- Takes in two pointers to States, the current state and the newState
			 @Post-Condition- The current state is switched to the given newState
			 */
			virtual void switchState(State* current, State* newState);

			/**
			 switchState
			 @Pre-Condition- Takes in a pointer to the current State and a string representing new state
			 @Post-Condition- The current state is switched to the state specified by the string newStateString
			 */
			virtual void switchState(State* current, string newStateString);
	};
}

#endif
