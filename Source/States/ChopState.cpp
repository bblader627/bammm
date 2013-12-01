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
 * ChopState cpp file.
 *
 */

#include "ChopState.h"

namespace bammm
{
	ChopState::ChopState(Actor& actor)
	{
		_actor = &actor;
		_maximumWood = 15;
	}
	ChopState::ChopState(Actor& actor, IStateCallback& stateMachine)
	{
		_actor = &actor;
		_maximumWood = 15;
		registerTransitionCallback(stateMachine);
	}

	/*void ChopState::setup(DynamicArray<string>* args)
	 {
	 _successChance = 30;
	 _maximumWood = 100;
	 _amountToChop = atoi(args->get(1).c_str());
	 _treeType = args->get(2);
	 }*/

	void ChopState::setup()
	{
		_successChance = 30;
		_maximumWood = 100;
	}

	void ChopState::setAmount(int amountToChop)
	{
		_amountToChop = amountToChop;
	}

	void ChopState::setTreeType(string treeType)
	{
		_treeType = treeType;
	}

	void ChopState::breakdown()
	{
	}

	void ChopState::tick(float deltaTime)
	{
		if (_actor->getGold() > _maximumWood || _amountToChop <= 0)
		{

			cout << _actor->getName() << " is finished chopping!" << "\n";
			_amountToChop = 0;
			switchState("null");
			return;
		}

		if (_actor->getBAC() > 0.4)
		{
			cout << _actor->getName()
					<< " drunkenly swings the hatchet, hits a squirrel, and decides not to do that anymore."
					<< "\n";
			switchState("null"); //Ends this state;
			return;
		}

		_actor->reduceStamina(1);
		//_actor->addGold(1);

		cout << _actor->getName()
				<< " lifts his hatchet, and swings it at the tree. " << "\n";
		//cout << _actor->getGold() << "\n";

	}

	void ChopState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string ChopState::toString()
	{
		return "chop";
	}
}
