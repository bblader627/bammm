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
 * BrawlState cpp file.
 *
 */

#include "BrawlState.h"

namespace bammm
{
	BrawlState::BrawlState(Actor& actor)
	{
		_actor = &actor;
	}

	BrawlState::BrawlState(Actor& actor, IStateCallback& stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	/*void BrawlState::setup(DynamicArray<string>* args)
	 {
	 }*/

	void BrawlState::setup()
	{
	}

	void BrawlState::breakdown()
	{
	}

	void BrawlState::tick(float deltaTime)
	{
		cout << _actor->getName()
				<< " pulls his right arm back and then thrusts his arm forward by twisting his core. \"DWARF PUNCHHHH!\"\n";
	}

	string BrawlState::toString()
	{
		return "brawl";
	}
}
