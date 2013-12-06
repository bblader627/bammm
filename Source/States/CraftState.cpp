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
		}
		else
		{
			craft();
		}

		cout << _craftableItem->getName()
				<< " has been added to the inventory of " << _actor->getName();
		switchState("null");
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
		DynamicArray<JSON*>* allChildren = child->getAllChildren()->getAllValues();

		for (unsigned int i = 0;
				i < allChildren->getSize();
				i++)
		{
			allChildren->get(i)->getChild("name");
			allChildren->get(i)->getChild("amount");

		}
		//create new item
		//remove items from inventory
		//add new item to inventory
		//delete items
	}

	bool CraftState::canCraft()
	{
		extern Factory* factory;

		JSON* ingredientMap = factory->getCraftables();
		JSON* child = ingredientMap->getChild(_craftableItem->getName());
		DynamicArray<JSON*>* allChildren = child->getAllChildren()->getAllValues();

		string craftableItemName = _craftableItem->getName();

		for (unsigned int i = 0; i < allChildren->getSize(); i++)
		{
			if (_actor->getInventory().contains(*_craftableItem))
					//, child->getChild("amount")))
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

