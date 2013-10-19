/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 * 	Bradley Crusco
 * 	Matt Witkowski
 *
 * Description:
 * StateMachine header file.
 *
 * Last Modified: Matthew Konstantinou
 *
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_
#endif

#include <iostream>
#include "dynamicarray.h"
#include "state.h"


#ifndef NULL
#define NULL (void *)0
#endif

using namespace std;

class StateMachine
{
public:
	StateMachine();

	/*
	 * tick
	 * Pre-Condition-
	 * Post-Condition-
	 *
	 * Calls currentStates[i].setup() on every state in the array
	 * setup() updates states
	 */
	void tick(float dTime)
	{
		for(int i = 0; i < currentStates->size(); i++)
		{
			State * thisState = currentStates[i];
			thisState -> tick(time(NULL));
		}
	}

	/*
	 * switchState
	 *
	 * Pre-Condition-
	 * Post-Condition-
	 *
	 *PlayerController will be calling switchState
	 */
	void switchState(State oldState, State newState)
	{

	}

	/*
	 * addState
	 * Pre-Condition-
	 * Post-Condition-
	 *
	 * Called from a Controller
	 * Adds currently running states to array
	 */
	void addState(State newState)
	{
		currentStates->push_back(newState);
	}

private:
	DynamicArray<State>* currentStates;

}
