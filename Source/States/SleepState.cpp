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
 * SleepState cpp file.
 *
 */

#include "SleepState.h"

namespace bammm
{
	SleepState::SleepState(Actor& actor)
	{
		_actor = &actor;
	}

	SleepState::SleepState(Actor& actor, IStateCallback& stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	void SleepState::setup(DynamicArray<string>* args)
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
