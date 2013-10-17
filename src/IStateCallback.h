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

#ifndef HEAP_H_
#define HEAP_H_
#endif

#include <iostream>
#include "state.h"
using namespace std;

class IStateCallback: public IStateCallback
{
public:
	//In (State.)registerTransitionCallback, pass "IStateCallback.onTransition(oldState, newState)" with function in that file?
	virtual void onTransition(State oldState, State newState);
	virtual ~IStateCallback();
};
