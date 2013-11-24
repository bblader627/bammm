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
 * BrawlState header file.
 *
 */

#ifndef BRAWLSTATE_H_
#define DEFINE BRAWLSTATE_H_

#include "State.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

namespace bammm
{
	class BrawlState: public State
	{
		public:
			BrawlState(Actor& actor);
			BrawlState(Actor& actor, IStateCallback& stateMachine);

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
			virtual void tick(float deltaTime);

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string representation of the state
			 */
			string toString();
	};

	BrawlState::BrawlState(Actor& actor)
	{
		_actor = &actor;
	}

	BrawlState::BrawlState(Actor& actor, IStateCallback& stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

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
#endif
