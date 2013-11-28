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
 * MineState cpp file.
 *
 */

#include "MineState.h"

namespace bammm
{
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
