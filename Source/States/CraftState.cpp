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
			switchState("idle");
		}
		else
		{
			craft();
		}

		cout << _craftableItem->getName()
				<< " has been added to the inventory of " << _actor->getName();
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

		JSON* ingredientMap = factory.getCraftables();
		for (int i = 0;
				i
						< ingredientMap->getChild(_craftableItem->getName())->getSize();
				i++)
		{
		ingredientMap->getChild(_craftableItem->getName())->get(i)->getChild->("name");
		ingredientMap->getChild(_craftableItem->getName())->get(i)->getChild->("amount");
	}
	//create new item
	//remove items from inventory
	//add new item to inventory
	//delete items
}

bool CraftState::canCraft()
{

	JSON* ingredientMap = factory.getCraftables();

	for (int i = 0; i < ingredientMap->get(i)->getSize(); i++)
	{
		if (_actor.getInventory.contains(_craftableItem->getName(),
				ingredientMap->getChild(_craftableItem->getName())->getValue(
						"amount")))
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
