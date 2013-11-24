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
 * MineState header file.
 *
 */

#ifndef MINESTATE_H_
#define MINESTATE_H_

#include <iostream>
#include "State.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

namespace bammm
{
	class MineState: public State
	{
		private:
			int _successChance;
			int _maximumGold;

		public:
			MineState(Actor& actor);
			MineState(Actor& actor, IStateCallback& stateMachine);

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

	MineState::MineState(Actor& actor)
	{
		_actor = &actor;
		_maximumGold = 15;
	}
	MineState::MineState(Actor& actor, IStateCallback& stateMachine)
	{
		_actor = &actor;
		_maximumGold = 15;
		registerTransitionCallback(stateMachine);
	}

	void MineState::setup()
	{
		_successChance = 30;
		_maximumGold = 100;
	}

	void MineState::breakdown()
	{
	}

	void MineState::tick(float deltaTime)
	{
		if (_actor->getBAC() > 0.4)
		{
			cout << _actor->getName()
					<< " drunkenly swings the pickaxe, hits himself in the foot, and decides not to do that anymore."
					<< "\n";
			switchState("null"); //Ends this state;
			return;
		}

		_actor->reduceStamina(1);
		_actor->addGold(1);
		cout << _actor->getName()
				<< " lifts his pickaxe, and swings it at the rock. " << "\n";
		cout << _actor->getGold() << "\n";
		if (_actor->getGold() > _maximumGold)
		{
			cout << _actor->getName() << "'s purse is full!" << "\n";
			switchState("drink");
		}
	}

	void MineState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string MineState::toString()
	{
		return "mine";
	}
}

#endif
