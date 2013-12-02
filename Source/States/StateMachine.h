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
#include "../Interfaces/IStateCallback.h"
#include "../Interfaces/ITickable.h"
#include "State.h"
#include "../Weapons/MeleeCombat.h"
#include "../Resources/Constant.h"

using namespace std;

namespace bammm
{
	class StateMachine: public IStateCallback
	{
		private:
			DynamicArray<State*> currentStates;
			HashMap<State*>* _allStates;
			MeleeCombat* _meleeCombat;
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
			void tick(float deltaTime);

			/**
			 switchState
			 @Pre-Condition- Takes in two State references, the current state and the newState
			 @Post-Condition- The current state is switched to the given newState
			 */
			void switchState(State* current, State* newState);

			/**
			 switchState
			 @Pre-Condition- Takes in a reference to the current State and a string representing new state
			 @Post-Condition- The current state is switched to the state specified by the string newStateString
			 */
			void switchState(State* current, string newStateString);

			/**
			 addState
			 @Pre-Condition- Takes in a pointer to a State state
			 @Post-Condition- Adds the given State state to the state machine
			 */
			void addState(State* newState);

			/**
			 addState
			 @Pre-Condition- Takes in a pointer to a State state
			 @Post-Condition- Adds the given State state to the state machine
			 */
			//void addState(State* newState);

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

			/**
			 setup
			 @Pre-Condition- Takes in Actor&, HashMap<State*>& of all the states, and MeleeCombat*
			 @Post-Condition- Sets up the state machine
			 */
			void setup(Actor& actor, HashMap<State*>& allStates,
					MeleeCombat* meleeCombat);

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string representation of the state machine
			 */
			string toString();
	};
}
#endif
