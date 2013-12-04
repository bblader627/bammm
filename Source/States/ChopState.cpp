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
	}
	ChopState::ChopState(Actor& actor, IStateCallback* stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	/*void ChopState::setup(DynamicArray<string>* args)
	 {
	 _successChance = 30;
	 _maximumGold = 100;
	 _amountToChop = atoi(args->get(1).c_str());
	 _treeType = args->get(2);
	 }*/

	void ChopState::setup()
	{
		_successChance = 30;
	}

	void ChopState::setAmount(int amountToChop)
	{
		_amountToChop = amountToChop;
	}

	void ChopState::setTree(Actor* tree)
	{
		_tree = tree;
	}

	void ChopState::breakdown()
	{
	}

	void ChopState::tick(float deltaTime)
	{
		if (canChop())
		{
			if (_actor->getBAC() > .4)
			{
				cout << _actor->getName()
						<< " drunkenly swings the hatchet, hits himself in the foot, and decides not to do that anymtree."
						<< "\n";
				switchState("null"); //Ends this state;
			}
			else
			{
				string treeName = _tree->getName();
				_actor->setWood(_actor->getWood() + 1);
				_tree->setWood(_tree->getWood() - 1);
				_actor->reduceStamina(1);

				cout << _actor->getName()
						<< " lifts his hatchet, and swings it at the rock. " << "\n";
				cout << _actor->getName() 
						<< " successfully chops a piece of " << _tree->getName() << "\n";
				_amountToChop--;
			}
		}
		else
		{
			cout << _actor->getName() << " is finished chopping!" << "\n";
			_amountToChop = 0;
			switchState("null");
		}
	}

	void ChopState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string ChopState::toString()
	{
		return "chop";
	}

	bool ChopState::canChop()
	{
		int canChop = 0;
		
		if(_amountToChop > 0)
		{
			if(_tree->getWood() > 0)
			{
				canChop++;
			}
		}

		return !!canChop;
	}
}
