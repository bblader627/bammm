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
#include "Item.h"
#include "Inventory.h"
#include "Item.h"
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

	Inventory::~Inventory()
	{
	}
}
