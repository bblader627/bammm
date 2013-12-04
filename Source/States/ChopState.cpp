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
				bool canPickup = true;
				string treeName = _tree->getName();
				Item* removedItem;

				if(treeName.find("redwood") != string::npos)
				{
					Item redwood("Redwood logs");
					removedItem = _tree->getInventory().removeItem(redwood);
				}
				else if(treeName.find("oak") != string::npos)
				{
					Item oak("Oak logs");
					removedItem = _tree->getInventory().removeItem(oak);
				}
				else if(treeName.find("birch") != string::npos)
				{
					Item birch("Birch logs");
					removedItem = _tree->getInventory().removeItem(birch);
				}
				else if(treeName.find("cedar") != string::npos)
				{
					Item cedar("Cedar logs");
					removedItem = _tree->getInventory().removeItem(cedar);
				}
				_actor->reduceStamina(1);
				
				string coloredName = Color::colorText(removedItem->getName(), removedItem->getColor());

				cout << _actor->getName()
						<< " lifts his hatchet, and swings it at the tree. " << "\n";
				cout << _actor->getName() 
						<< " successfully chops some " << coloredName << "\n";
				
				canPickup = _actor->getInventory().addItem(removedItem);
				if(!canPickup)
				{
					delete removedItem;
					cout << _actor->getName()
						<< " has a full inventory, and drops " << coloredName
						<< " on the ground.\n";
				}

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
			Item redwood("Redwood logs");
			if(_tree->getInventory().contains(redwood))
			{
				canChop++;
			}

			Item birch("Birch logs");
			if(_tree->getInventory().contains(birch))
			{
				canChop++;
			}

			Item oak("Oak logs");
			if(_tree->getInventory().contains(oak))
			{
				canChop++;
			}

			Item cedar("Cedar logs");
			if(_tree->getInventory().contains(cedar))
			{
				canChop++;
			}
		}

		return !!canChop;
	}
}
