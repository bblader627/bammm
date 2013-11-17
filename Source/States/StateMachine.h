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
 * StateMachine header file.
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

namespace bammm
{
	class StateMachine: public IStateCallback
	{
		private:
			DynamicArray<State*>* currentStates;
			HashMap<State*>* _allStates;
			Actor* _actor;

		public:
			StateMachine(Actor* actor, HashMap<State*>* allStates);
			virtual ~StateMachine();

			/**
			 setup
			 @Pre-Condition- Takes in a State* initial
			 @Post-Condition- Sets the initial state of the state machine as the given initial
			 */
			void initialState(State* initial);

			/**
			 tick
			 @Pre-Condition- Takes in a float deltaTime
			 @Post-Condition- Executes a tick of length deltaTime
			 */
			void tick(float deltaTime);

			/**
			 switchState
			 @Pre-Condition- Takes in two pointers to States, the current state and the newState
			 @Post-Condition- The current state is switched to the given newState
			 */
			void switchState(State* current, State* newState);

			/**
			 switchState
			 @Pre-Condition- Takes in a pointer to the current State and a string representing new state
			 @Post-Condition- The current state is switched to the state specified by the string newStateString
			 */
			void switchState(State* current, string newStateString);

			/**
			 addState
			 @Pre-Condition- Takes in a pointer to a State state
			 @Post-Condition- Adds the given State state to the state machine
			 */
			void addState(State* state);

			/**
			 removeState
			 @Pre-Condition- Takes in a pointer to a State state
			 @Post-Condition- Removes the given State state from the state machine
			 */
			void removeState(State* state);

			/**
			 getCurrentStates
			 @Pre-Condition- No input
			 @Post-Condition- Returns all the current states in the state machine
			 */
			DynamicArray<State*>* getCurrentStates();
			string toString();
	};

	StateMachine::StateMachine(Actor* actor, HashMap<State*>* allStates)
	{
		_actor = actor;
		currentStates = new DynamicArray<State*>();
		_allStates = allStates;
	}

	virtual StateMachine::~StateMachine()
	{
		delete _actor;
	}

	void StateMachine::initialState(State* initial)
	{
		initial->setup();
		currentStates->add(initial);
	}

	void StateMachine::tick(float deltaTime)
	{

		for (int i = 0; i < (int) currentStates->getSize(); i++)
		{
			State* thisState = currentStates->get(i);
			thisState->tick(0);
		}
	}

	void StateMachine::switchState(State* current, State* newState)
	{
		removeState(current);
		addState(newState);

	}

	void StateMachine::switchState(State* current, string newStateString)
	{
		if (newStateString == "null")
		{
			removeState(current);
			return;
		}
		State* newState = _allStates->getValue(newStateString);
		if (newState != NULL)
		{
			switchState(current, newState);
		}
	}

	void StateMachine::addState(State* state)
	{
		state->setup();
		currentStates->add(state);
	}

	void StateMachine::removeState(State* state)
	{
		state->breakdown();
		currentStates->removeElement(state);
	}

	DynamicArray<State*>* StateMachine::getCurrentStates()
	{
		return currentStates;
	}

	string StateMachine::toString()
	{
		return "statemachine";
	}
}

#endif
