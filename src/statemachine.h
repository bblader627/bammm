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
#include "array.h"
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
			thisState -> setup();
		}
	}

	/*
	 * switchState
	 *
	 * Pre-Condition-
	 * Post-Condition-
	 *
	 *PlayerController will be calling switchState
	 *Game loop will be calling PlayerController.update
	 *G
	 */

	void switchState(State oldState, State newState)
	{

	}

	void addState(State newState)
	{
		currentStates->push_back(newState);
	}
private:
	Array<State>* currentStates;

}
