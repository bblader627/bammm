/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *  Bradley Crusco
 * Description:
 * Inventory cpp file.
 *
 */

#include <iostream>
#include "../Resources/Constant.h"
#include "../Resources/DynamicArray.h"
#include "../Resources/Color.h"
#include "Item.h"
#include "Inventory.h"
using namespace std;

namespace bammm
{
	Inventory::Inventory()
	{
		_slots = 10;
	}

	Inventory::Inventory(uint slots)
	{
		_slots = slots;
	}

	bool Inventory::addItem(Item* item)
	{
		if(_inventory.getSize() >= _slots)
		{
			return false;
		}
		
		_inventory.add(item);
		return true;
	}

	Item* Inventory::removeItem(Item& item)
	{
		uint usedSlots = _inventory.getSize();
		for(uint i = 0; i < usedSlots; i++)
		{
			Item currentItem = *_inventory.get(i);
			if(currentItem == item)
			{
				return _inventory.remove(i);
			}
		}

		return NULL;
	}

	bool Inventory::contains(Item& item)
	{
		uint usedSlots = _inventory.getSize();
		
		for(uint i = 0; i < usedSlots; i++)
		{
			Item currentItem = *_inventory.get(i);
			if(currentItem == item)
			{
				return true;	
			}
		}

		return false;
	}

	bool Inventory::contains(Item& item, uint amount)
	{
		uint count = 0;

		for(uint i = 0; i < amount; i++)
		{
			if(contains(item))
			{
				count++;
			}
		}

		if(count >= amount)
		{
			return true;
		}

		return false;
	}

	void Inventory::setSlots(uint slots)
	{
		_slots = slots;
	}

	uint Inventory::getSlots()
	{
		return _slots;
	}

	uint Inventory::getUsedSlots()
	{
		return _inventory.getSize();
	}

	string Inventory::toString()
	{
		string inventory = "Inventory: ";
		uint usedSlots = getUsedSlots();
		for(uint i = 0; i < usedSlots; i++)
		{
			Item* item = _inventory.get(i);
			string itemName = item->getName();
			uint amount = _inventory.get(i)->getAmount();
			string trueName = itemName + " (" + to_string(amount) + ")";
			string coloredName = Color::colorText(trueName, item->getColor());
			inventory = inventory + coloredName;
			
			if(i < usedSlots - 1)
			{
				inventory = inventory + ", ";
			}
		}

		return inventory;
	}

	Inventory::~Inventory()
	{
	}
}
