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

	uint Inventory::addItem(Item* item, uint amount)
	{
		uint added = 0;

		for(uint i = 0; i < amount; i++)
		{
			if(!addItem(item))
			{
				break;
			}

			added++;
		}

		return added;
	}

	bool Inventory::removeItem(Item* item)
	{
		return _inventory.removeElement(item);
	}

	uint Inventory::removeItem(Item* item, uint amount)
	{
		uint removed = 0;

		for(uint i = 0; i < amount; i++)
		{
			if(!removeItem(item))
			{
				break;
			}

			removed++;
		}

		return removed;
	}

	bool Inventory::contains(Item* item)
	{
		return _inventory.contains(item);
	}

	bool Inventory::contains(Item* item, uint amount)
	{
		for(uint i = 0; i < amount; i++)
		{
			if(!contains(item))
			{
				return false;
			}
		}

		return true;
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
}
