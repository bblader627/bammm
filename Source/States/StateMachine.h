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
#include "../Resources/DynamicArray.h"
#include "../Resources/HashMap.h"
#include "IStateCallback.h"
#include "State.h"

#ifndef NULL
#define NULL (void *)0
#endif

using namespace std;
using namespace bammm;


class StateMachine : public IStateCallback
{
	private:
		DynamicArray<State> currentStates;
		HashMap<State>* _allStates;
		Actor* _actor;
	public:
		/*
		 * Default Constructor
		 */
		StateMachine();
		StateMachine(Actor& actor, HashMap<State>& allStates);
		void initialState(State& initial);
		void tick(float dTime);
		void switchState(State& current, State& newState);
		void switchState(State& current, string newStateString);
		void addState(State& newState);
		void removeState(State& oldState);
		DynamicArray<State>& getCurrentStates();
		virtual ~StateMachine()
		{
		}
		string to_string();

};
		StateMachine::StateMachine()
		{
		}

		StateMachine::StateMachine(Actor& actor, HashMap<State>& allStates)
		{
			_actor = &actor;
			_allStates = &allStates;
		}

		void StateMachine::initialState(State& initial)
		{
			initial.setup();
			currentStates.add(initial);
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

			for(int i = 0; i < (int) currentStates.getSize(); i++)
			{
				currentStates.get(i).tick(0);
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
		void StateMachine::switchState(State& current, State& newState)
		{
			removeState(current);
			addState(newState);

		}

		void StateMachine::switchState(State& current, string newStateString)
		{
			if (newStateString=="null")
			{
				removeState(current);
				return;
			}
			switchState(current, _allStates->getValue(newStateString));
		}

		/*
		 * addState
		 * Pre-Condition- accepts pointer to state to be added
		 * Post-Condition-no return
		 *
		 * Called from a Controller
		 * Adds currently running states to array
		 */
		void StateMachine::addState(State& newState)
		{
			newState.setup();
			currentStates.add(newState);
		}

		/*
		 * removeState
		 * Pre-Condition- accepts pointer to state to be removed
		 * Post-Condition- breaks down states and removies it from array
		 */
		void StateMachine::removeState(State& oldState)
		{
			oldState.breakdown();
			currentStates.removeElem(oldState);
		}

		/**
		 * getCurrentStates
		 * Pre-Condition-
		 * Post-Condition-
		 *
		 * Called from Controller
		 * Returns currently running states
		 */
		DynamicArray<State>& StateMachine::getCurrentStates()
		{
			return currentStates;
		}


		string StateMachine::to_string()
		{
			return "statemachine";
		}
#endif
