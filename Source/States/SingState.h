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
 * SingState header file.
 *
 */

#ifndef SINGSTATE_H_
#define SINGSTATE_H_

#include <iostream>
#include "State.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

namespace bammm
{
	class SingState: public State
	{
		private:
			const static int _singPercentage = 75;
			int _singLine;

		public:
			SingState(Actor* actor);
			SingState(Actor* actor, IStateCallback* stateMachine);

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

	SingState::SingState(Actor* actor)
	{
		_actor = actor;
	}

	SingState::SingState(Actor* actor, IStateCallback* stateMachine)
	{
		_actor = actor;
		registerTransitionCallback(stateMachine);
	}

	void SingState::setup()
	{
		_singLine = 0;
		cout << _actor->getName() << " begins to sing. ";
	}

	void SingState::breakdown()
	{
	}

	void SingState::tick(float deltaTime)
	{
		_actor->reduceStamina(1);
		cout << _actor->getName() << " is singing the song of it's people.\n";
	}

	string SingState::toString()
	{
		return "sing";
	}
}

#endif
