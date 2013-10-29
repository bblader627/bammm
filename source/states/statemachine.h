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

#include <iostream>
#include "../resources/dynamicarray.h"
#include "../resources/hashmap.h"
#include "state.h"

#include "../states/state.h"


#ifndef NULL
#define NULL (void *)0
#endif

using namespace std;
using namespace bammm;


class StateMachine : IStateCallback
{
	private:
		DynamicArray<State*>* currentStates;
		HashMap<State*>* _allStates;
		Actor* _actor;
	public:
		/*
		 * Default Constructor
		 */
		StateMachine(Actor* actor, State* initialState, HashMap<State*>* allStates)
		{
			_actor = actor;
			currentStates = new DynamicArray<State*>();
			currentStates->add(initialState);
			_allStates = allStates;
		}

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

			for(int i = 0; i < (int) currentStates->getSize(); i++)
			{
				State* thisState = currentStates->get(i);
				thisState->tick(0);
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
		void switchState(State* current, State* newState)
		{
			if (newState == NULL)
			{
				current->breakdown();
				currentStates->removeElem(current);
			}
			else
			{
				current->breakdown();
				current = newState;
				current->setup();
			}
		}

		void switchState(State* current, string newStateString)
		{
			State* newState = _allStates->getValue(newStateString);
			if (newState != NULL)
			{
				switchState(current, newState);
			}
		}

		/*
		 * addState
		 * Pre-Condition-
		 * Post-Condition-
		 *
		 * Called from a Controller
		 * Adds currently running states to array
		 */
		void addState(State* newState)
		{
			currentStates->add(newState);
		}

		/**
		 * getCurrentStates
		 * Pre-Condition-
		 * Post-Condition-
		 *
		 * Called from Controller
		 * Returns currently running states
		 */
		DynamicArray<State*>* getCurrentStates()
		{
			return currentStates;
		}

};
#endif
