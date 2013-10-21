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
#include "states/state.h"

using namespace std;
//using namespace bammm;

class IStateCallback
{
	public:
		//In (State.)registerTransitionCallback, pass "IStateCallback.onTransition(oldState, newState)" with function in that file?

		//virtual void onTransition(State* currentState, State* newState)
		//{
			//currentState->breakdown();
			//currentState = newState;
			//currentState->setup();
		//}

		//virtual ~IStateCallback();
};

#endif
