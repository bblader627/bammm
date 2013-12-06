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
 * Craft State source file.
 *
 */

#include "CraftState.h"
#include "../JSON/JSON.h"
#include <string>
#include "../Factories/Factory.h"

namespace bammm
{

	CraftState::CraftState(Actor& actor)
	{
		_actor = &actor;
	}

	CraftState::CraftState(Actor& actor, IStateCallback* stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	void CraftState::setup()
	{
		cout << "crafting..." << endl;
	}

	void CraftState::breakdown()
	{

	}

	void CraftState::tick(float deltaTime)
	{
		cout << _actor->getName() << " is beginning to craft. \n";

		if (canCraft() == false)
		{
			cout << _actor->getName() << " cannot craft "
					<< _craftableItem->getName() << ". \n";
			switchState("null");
			return;
		}
		else
		{
			craft();
		}

		cout << _craftableItem->getName()
				<< " has been added to the inventory of " << _actor->getName() << endl;
	}

	void CraftState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string CraftState::toString()
	{
		return "craft";
	}

	void CraftState::setCraftable(Item& craftableItem)
	{
		_craftableItem = &craftableItem;
	}

	void CraftState::setAmount(int craftableAmount)
	{
		_craftableAmount = craftableAmount;
	}

	void CraftState::craft()
	{
		extern Factory* factory;

		JSON* ingredientMap = factory->getCraftables();
		JSON* child = ingredientMap->getChild(_craftableItem->getName());

		//All required items
		DynamicArray<JSON*>* allChildren =
				child->getAllChildren()->getAllValues();

		for (unsigned int i = 0; i < allChildren->getSize(); i++)
		{
			string name = allChildren->get(i)->getChild("name")->getStringValue();
			int amount = allChildren->get(i)->getChild("amount")->getIntValue();

			Item item(name, true);
			while (amount > 0)
			{
				_actor->getInventory().removeItem(item);
				amount--;
			}
		}

		_actor->getInventory().addItem(_craftableItem);
	}

	bool CraftState::canCraft()
	{
		extern Factory* factory;

		JSON* ingredientMap = factory->getCraftables();
		JSON* child = ingredientMap->getChild(_craftableItem->getName());
		DynamicArray<JSON*>* allChildren =
				child->getAllChildren()->getAllValues();

		string craftableItemName = _craftableItem->getName();

		for (unsigned int i = 0; i < allChildren->getSize(); i++)
		{
			Item item(allChildren->get(i)->getChild("name")->getStringValue(), true);
			int amount = allChildren->get(i)->getChild("amount")->getIntValue();
			if (_actor->getInventory().contains(item, amount))
			{
				continue;
			}
			else
			{
				return false;
			}
		}

		return true;
	}
}

