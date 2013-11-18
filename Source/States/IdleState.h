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
 * IdleState header file.
 *
 */

#ifndef IDLESTATE_H_
#define IDLESTATE_H_

#include "State.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

namespace bammm
{
	class IdleState: public State
	{
		public:
			IdleState(Actor* actor);
			IdleState(Actor* actor, IStateCallback* stateMachine);

			/**
			 setup
			 @Pre-Condition- No input
			 @Post-Condition- Sets up the state
			 */
			void setup();

			/**
			 breakdown
			 @Pre-Condition- No input
			 @Post-Condition- Performs a breakdown on the state
			 */
			void breakdown();

			/**
			 tick
			 @Pre-Condition- Takes in a float deltaTime
			 @Post-Condition- Executes a tick of length deltaTime
			 */
			void tick(float deltaTime);

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string representation of the state
			 */
			string toString();
	};

	IdleState::IdleState(Actor* actor)
	{
		_actor = actor;
	}

	IdleState::IdleState(Actor* actor, IStateCallback* stateMachine)
	{
		_actor = actor;
		registerTransitionCallback(stateMachine);
	}

	void IdleState::setup()
	{
	}

	void IdleState::breakdown()
	{
	}

	void IdleState::tick(float deltaTime)
	{
	}

	string IdleState::toString()
	{
		return "idle";
	}
}

#endif

