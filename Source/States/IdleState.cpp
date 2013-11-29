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
 * IdleState cpp file.
 *
 */

#include "IdleState.h"

namespace bammm
{
	IdleState::IdleState(Actor& actor)
	{
		_actor = &actor;
	}

	IdleState::IdleState(Actor& actor, IStateCallback& stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	void IdleState::setup(DynamicArray<string>* args)
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
