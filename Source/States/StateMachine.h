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

namespace bammm
{
	class StateMachine: public IStateCallback
	{
		private:
			DynamicArray<State*> currentStates;
			HashMap<State*>* _allStates;
			Actor* _actor;
		public:
			StateMachine();
			StateMachine(Actor& actor, HashMap<State*>& allStates);
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
			void tick(float dTime);
		
			/**
			 switchState
			 @Pre-Condition- Takes in two State references, the current state and the newState
			 @Post-Condition- The current state is switched to the given newState
			 */
			void switchState(State& current, State& newState);
		
			/**
			 switchState
			 @Pre-Condition- Takes in a reference to the current State and a string representing new state
			 @Post-Condition- The current state is switched to the state specified by the string newStateString
			 */
			void switchState(State& current, string newStateString);
		
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
			DynamicArray<State*>& getCurrentStates();
			void setup(Actor&, HashMap<State*>&);
			string toString();

	};
	
	StateMachine::StateMachine()
	{
	}

	StateMachine::~StateMachine()
	{
	}

	StateMachine::StateMachine(Actor& actor, HashMap<State*>& allStates)
	{
		_actor = &actor;
		_allStates = &allStates;
	}

	void StateMachine::setup(Actor& actor, HashMap<State*>& allStates)
	{
		_actor = &actor;
		_allStates = &allStates;
	}

	void StateMachine::initialState(State* initial)
	{
		initial->setup();
		currentStates.add(initial);
	}

	void StateMachine::tick(float dTime)
	{
		for(int i = 0; i < (int) currentStates.getSize(); i++)
		{
			currentStates.get(i)->tick(dTime);
		}
	}

	void StateMachine::switchState(State& current, State& newState)
	{
		removeState(&current);
		addState(&newState);
	}

	void StateMachine::switchState(State& current, string newStateString)
	{
		if (newStateString=="null")
		{
			removeState(&current);
			return;
		}
		switchState(current, *_allStates->getValue(newStateString));
	}

	void StateMachine::addState(State* newState)
	{
		newState->setup();
		currentStates.add(newState);
	}

	void StateMachine::removeState(State* oldState)
	{
		oldState->breakdown();
		currentStates.removeElement(oldState);
	}

	DynamicArray<State*>& StateMachine::getCurrentStates()
	{
		return currentStates;
	}


	string StateMachine::toString()
	{
		return "statemachine";
	}
}
#endif
