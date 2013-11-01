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
#include "IStateCallback.h"
#include "state.h"

#include "../states/state.h"


#ifndef NULL
#define NULL (void *)0
#endif

using namespace std;
using namespace bammm;


class StateMachine : public IStateCallback
{
	private:
		DynamicArray<State*>* currentStates;
		HashMap<State*>* _allStates;
		Actor* _actor;
	public:
		/*
		 * Default Constructor
		 */
		StateMachine(Actor* actor, HashMap<State*>* allStates);
		void initialState(State* initial);
		void tick(float dTime);
		void switchState(State* current, State* newState);
		void switchState(State* current, string newStateString);
		void addState(State* newState);
		DynamicArray<State*>* getCurrentStates();
		virtual ~StateMachine()
		{
			delete _actor;
		}
		string to_string();

};
		StateMachine::StateMachine(Actor* actor, HashMap<State*>* allStates)
		{
			_actor = actor;
			currentStates = new DynamicArray<State*>();
			_allStates = allStates;
		}

		void StateMachine::initialState(State* initial)
		{
			currentStates->add(initial);
		}

		/*
		 * tick
		 * Pre-Condition-
		 * Post-Condition-
		 *
		 * Calls currentStates[i].setup() on every state in the array
		 * setup() updates states
		 */
		void StateMachine::tick(float dTime)
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
		void StateMachine::switchState(State* current, State* newState)
		{
			current->breakdown();
			currentStates->removeElem(current);
			currentStates->add(newState);
			newState->setup();

		}

		void StateMachine::switchState(State* current, string newStateString)
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
		void StateMachine::addState(State* newState)
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
		DynamicArray<State*>* StateMachine::getCurrentStates()
		{
			return currentStates;
		}


		string StateMachine::to_string()
		{
			return "statemachine";
		}
#endif
