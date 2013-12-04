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
#include "../Inventory/Inventory.h"
#include "../Inventory/Item.h"

namespace bammm
{
	MineState::MineState(Actor& actor)
	{
		_actor = &actor;
	}

	MineState::MineState(Actor& actor, IStateCallback* stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	MineState::~MineState()
	{
	}

	/*void MineState::setup(DynamicArray<string>* args)
	 {
	 _successChance = 30;
	 _maximumGold = 100;
	 _amountToMine = atoi(args->get(1).c_str());
	 _oreType = args->get(2);
	 }*/

	void MineState::setup()
	{
		_successChance = 30;
	}

	void MineState::setAmount(int amountToMine)
	{
		_amountToMine = amountToMine;
	}

	void MineState::setOre(Actor* ore)
	{
		_ore = ore;
	}

	void MineState::breakdown()
	{
	}

	void MineState::tick(float deltaTime)
	{
		if (canMine())
		{
			if (_actor->getBAC() > .4)
			{
				cout << _actor->getName()
						<< " drunkenly swings the pickaxe, hits himself in the foot, and decides not to do that anymore."
						<< "\n";
				switchState("null"); //Ends this state;
			}
			else
			{
				bool canPickup = true;
				string oreName = _ore->getName();
				Item* removedItem;
				if (oreName.find("gold") != string::npos)
				{
					Item gold("Gold");
					removedItem = _ore->getInventory().removeItem(gold);
				}
				else if (oreName.find("iron") != string::npos)
				{
					Item iron("Iron ore");
					removedItem = _ore->getInventory().removeItem(iron);
				}
				else if (oreName.find("coal") != string::npos)
				{
					Item coal("Coal");
					removedItem = _ore->getInventory().removeItem(coal);
				}
				_actor->reduceStamina(1);

				string coloredName = Color::colorText(removedItem->getName(), removedItem->getColor());
				cout << _actor->getName()
						<< " lifts his pickaxe, and swings it at the rock. " << "\n";
				cout << _actor->getName() 
						<< " successfully mines some " << coloredName << "\n";

				canPickup = _actor->getInventory().addItem(removedItem);
				if(!canPickup)
				{
					delete removedItem;
					cout << _actor->getName()
						<< " has a full inventory, and drops " << coloredName 
						<< " on the ground.\n";
				}

				_amountToMine--;
			}
		}
		else
		{
			cout << _actor->getName() << " is finished mining!" << "\n";
			_amountToMine = 0;
			switchState("null");
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

	bool MineState::canMine()
	{
		int canMine = 0;
			
		if(_amountToMine > 0)
		{
			Item gold("Gold");
			if(_ore->getInventory().contains(gold))
			{
				canMine++;
			}
			
			Item iron("Iron ore");
			if(_ore->getInventory().contains(iron))
			{
				canMine++;
			}
			
			Item coal("Coal");
			if(_ore->getInventory().contains(coal))
			{
				canMine++;
			}
		}

		return !!canMine;
	}
}
