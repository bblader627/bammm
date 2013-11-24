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
 * State header file.
 *
 */

#ifndef STATE_H_
#define STATE_H_

#include <iostream>
#include "../Resources/DynamicArray.h"
#include "../Interfaces/IStateCallback.h"
#include "../Interfaces/ITickable.h"
#include "../Actors/Actor.h"

#ifndef NULL
#define NULL (void *)0
#endif

using namespace std;

namespace bammm
{
	class State: public ITickable
	{
		protected:
			Actor* _actor;
			IStateCallback* _stateMachine;

		public:
			State();
			State(Actor& actor);
			virtual ~State();

			/**
			 setup
			 @Pre-Condition- No input
			 @Post-Condition- Sets up the state
			 */
			virtual void setup();

			/**
			 breakdown
			 @Pre-Condition- No input
			 @Post-Condition- Performs a breakdown on the state
			 */
			virtual void breakdown();

			/**
			 tick
			 @Pre-Condition- Takes in a float deltaTime
			 @Post-Condition- Executes a tick of length deltaTime
			 */
			virtual void tick(float deltaTime);

			/**
			 registerTransitionCallback
			 @Pre-Condition- Takes in a IStateCallback& state machine
			 @Post-Condition- A transition callback is registered
			 */
			virtual void registerTransitionCallback(IStateCallback& stateMachine);

			/**
			 switchState
			 @Pre-Condition- Takes in a string nextState
			 @Post-Condition- The current state is switched to the given nextState
			 */
			virtual void switchState(string nextState);

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string representation of the state
			 */
			virtual string toString();

			/**
			 operator==
			 @Pre-Condition- Takes in a State*
			 @Post-Condition- Returns a boolean of the comparison between two states
			 */
			virtual bool operator==(State* state);
	};

	State::State()
	{
	}

	State::State(Actor& actor)
	{
		_actor = &actor;
	}

	State::~State()
	{

	}

	void State::setup()
	{
		cout << "wrong setup" << "\n";
	}

	void State::breakdown()
	{
		cout << "wrong breakdown" << "\n";
	}

	void State::tick(float deltaTime)
	{
		cout << "In parent state\n";
	}

	void State::registerTransitionCallback(IStateCallback& stateMachine)
	{
		_stateMachine = &stateMachine;
	}

	void State::switchState(string nextState)
	{
		//_statemachine->switchState(this, nextState);
	}

	string State::toString()
	{
		return "State";
	}

	bool State::operator==(State* state)
	{
		return false;
	}
}

#endif
