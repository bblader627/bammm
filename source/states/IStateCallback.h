/*
 * CS585
 *
 * Team MMA
 *  Alvaro Home
 *  Matt Konstantinou
 *  Michael Abramo
 *
 * Description:
 * Heap template header file.
 *
 * Last Modified: Matthew Konstantinou
 *
 */

#ifndef ISTATECALLBACK_H_
#define ISTATECALLBACK_H_

#include <iostream>
#include "../actors/actor.h"

using namespace std;



namespace bammm
{
	//Forward declaration of class State;
	class State;

	class IStateCallback
	{
		public:
			virtual void switchState(State* current, State* newState);
			virtual void switchState(State* current, string newStateString);
	};

}

#endif
