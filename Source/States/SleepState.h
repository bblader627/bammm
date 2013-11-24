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
 * SleepState header file.
 *
 */

#ifndef SLEEPSTATE_H_
#define SLEEPSTATE_H_

#include <iostream>
#include "State.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

using namespace std;

namespace bammm
{
	class SleepState: public State
	{
		private:
			static const int _hoursToSleep = 8;
			int _timeSlept;

		public:
			SleepState(Actor& actor);
			SleepState(Actor& actor, IStateCallback& stateMachine);

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
			void breakdown();

			/**
			 tick
			 @Pre-Condition- Takes in a float deltaTime
			 @Post-Condition- Executes a tick of length deltaTime
			 */
			virtual void tick(float deltaTime);

			/**
			 switchState
			 @Pre-Condition- Takes in a string nextState
			 @Post-Condition- The current state is switched to the given nextState
			 */
			void switchState(string nextState);

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string representation of the state
			 */
			string toString();
	};

	SleepState::SleepState(Actor& actor)
	{
		_actor = &actor;
	}

	SleepState::SleepState(Actor& actor, IStateCallback& stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	void SleepState::setup()
	{
		_timeSlept = 0;
	}

	void SleepState::breakdown()
	{
	}

	void SleepState::tick(float deltaTime)
	{
		string output = "";

		_actor->increaseHealth(2);
		_actor->increaseStamina(2);

		if (_actor->isFullyRested())
		{
			switchState("idle");
		}

		if (_timeSlept < _hoursToSleep)
		{
			if (_timeSlept == 0)
			{
				output = _actor->getName()
						+ " lays on the ground and begins to sleep.\n";
			}
			output + "zzzZZZ\n";
			_timeSlept++;
		}
	}

	void SleepState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string SleepState::toString()
	{
		return "sleep";
	}
}

#endif
