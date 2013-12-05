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
 * GatherState cpp file.
 *
 */

#include "GatherState.h"
#include "../Inventory/Inventory.h"
#include "../Inventory/Item.h"

namespace bammm
{
	GatherState::GatherState(Actor& actor)
	{
		_actor = &actor;
	}

	GatherState::GatherState(Actor& actor, IStateCallback* stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	GatherState::~GatherState()
	{
	}

	/*void GatherState::setup(DynamicArray<string>* args)
	 {
	 _successChance = 30;
	 _maximumGold = 100;
	 _amount = atoi(args->get(1).c_str());
	 _targetType = args->get(2);
	 }*/

	void GatherState::setup()
	{
		_successChance = 30;
	}

	void GatherState::setAmount(int amount)
	{
		_amount = amount;
	}

	void GatherState::setTarget(Actor* target)
	{
		_target = target;
	}

	void GatherState::breakdown()
	{
	}

	void GatherState::tick(float deltaTime)
	{
		if (canGather())
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
				string typeName = _target->getName();
				Item* removedItem;
				if (typeName == "gold")
				{
					Item item("Gold");
					removedItem = _target->getInventory().removeItem(item);
					canPickup = _actor->getInventory().addItem(removedItem);
				}
				else if (typeName == "iron")
				{
					Item item("Iron ore");
					removedItem = _target->getInventory().removeItem(item);
					canPickup = _actor->getInventory().addItem(removedItem);
				}
				else if (typeName == "coal")
				{
					Item item("Coal");
					removedItem = _target->getInventory().removeItem(item);
					canPickup = _actor->getInventory().addItem(removedItem);
				}
				else if (typeName == "birch" || typeName == "oak" || typeName == "redwood")
				{
					Item item("Wood");
					removedItem = _target->getInventory().removeItem(item);
					canPickup = _actor->getInventory().addItem(removedItem);
				}
				else if (typeName == "shore")		//Fishing state will send dwarves to shore blocks to fish
				{
					Item item("Fish");
					removedItem = _target->getInventory().removeItem(item);
					canPickup = _actor->getInventory().addItem(removedItem);
				}


				_actor->reduceStamina(1);

				cout << _actor->getName()
						<< " lifts his pickaxe, and swings it at the rock. " << "\n";
				cout << _actor->getName()
						<< " successfully mines some " << removedItem->getName() << "\n";

				if(!canPickup)
				{
					delete removedItem;
					cout << _actor->getName()
						<< " has a full inventory, and drops it on the ground.\n";
				}
				_amount--;
			}
		}
		else
		{
			cout << _actor->getName() << " is finished mining!" << "\n";
			_amount = 0;
			switchState("null");
		}
	}

	void GatherState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string GatherState::toString()
	{
		return "mine";
	}

	bool GatherState::canGather()
	{
		int canGather = 0;

		if(_amount > 0)
		{
			Item item(_target->getName());

		}

		return !!canGather;
	}
}
