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
 * SingState cpp file.
 *
 */

#include "SingState.h"

namespace bammm
{
	SingState::SingState(Actor& actor)
	{
		_actor = &actor;
	}

	SingState::SingState(Actor& actor, IStateCallback& stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	void SingState::setup(DynamicArray<string>* args)
	{
		_singLine = 0;
		cout << _actor->getName() << " begins to sing. ";
	}

	void SingState::setup()
	{

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
