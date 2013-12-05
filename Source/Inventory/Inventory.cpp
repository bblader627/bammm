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
		bool isStackable = item->getStackable();
		bool containsNewItem = contains(*item);
		bool canStore = _inventory.getSize() < _slots;

		//Can put new item
		if(canStore && !isStackable)
		{
			_inventory.add(item);
			return true;
		}
		//Can put new stackable
		else if(isStackable && !containsNewItem && canStore)
		{
			_inventory.add(item);
			return true;
		}
		else if(isStackable && containsNewItem)
		{
			int index = _inventory.getInventoryIndex(item);
			cout << "addItem: " << index << "\n";
			Item* foundItem = _inventory.get(index);
			foundItem->setAmount(foundItem->getAmount() + item->getAmount());
			delete item;
		}
		
		return false;
	}

	Item* Inventory::removeItem(Item& item)
	{
		uint usedSlots = _inventory.getSize();
		for(uint i = 0; i < usedSlots; i++)
		{
			cout << "removeItem: " << i << "\n";
			Item currentItem = *_inventory.get(i);
			if(currentItem == item)
			{
				//Return last stackable/item
				if(currentItem.getAmount() == 1)
				{
					return _inventory.remove(i);
				}
				else
				{
					currentItem.setAmount(currentItem.getAmount() - 1);
					return currentItem.getStackableCopy();
				}
			}
		}

		return NULL;
	}

	bool Inventory::contains(Item& item)
	{
		uint usedSlots = _inventory.getSize();
		
		for(uint i = 0; i < usedSlots; i++)
		{
			cout << "contains: " << i << "\n";
			Item currentItem = *_inventory.get(i);
			if(currentItem == item)
			{
				return true;	
			}
		}

		return false;
	}
	
	int Inventory::getInventoryIndex(Item& item)
	{
		uint usedSlots = _inventory.getSize();
		
		for(uint i = 0; i < usedSlots; i++)
		{
			cout << "inventoryIndex: " << i << "\n";
			Item currentItem = *_inventory.get(i);
			if(currentItem == item)
			{
				return i;	
			}
		}
		cout << "Does not contain: " << item.getName() << "\n";
		return -1;
	}

	bool Inventory::contains(Item& item, uint amount)
	{
		uint count = 0;

		for(uint i = 0; i < amount; i++)
		{
			if(contains(item))
			{
				int index = getInventoryIndex(item);
				count += _inventory.get(index)->getAmount();
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
