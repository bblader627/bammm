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

#include "Inventory.h"

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

	Inventory::~Inventory()
	{
	}

	bool Inventory::addItem(Item* item)
	{
		bool canAdd = false;
		bool isStackable = item->getStackable();
		bool containsNewItem = contains(*item);
		bool canStore = _inventory.getSize() < _slots;

		if (canStore && !isStackable)
		{
			_inventory.add(item);
			canAdd = true;
		}
		else if (isStackable && !containsNewItem && canStore)
		{
			_inventory.add(item);
			canAdd = true;
		}
		else if (isStackable && containsNewItem)
		{
			int index = getInventoryIndex(*item);
			Item* foundItem = _inventory.get(index);

			foundItem->setAmount(foundItem->getAmount() + item->getAmount());
			delete item;
			canAdd = true;
		}

		return canAdd;
	}

	Item* Inventory::removeItem(Item& item)
	{
		uint usedSlots = _inventory.getSize();

		for (uint i = 0; i < usedSlots; i++)
		{
			Item* currentItem = _inventory.get(i);

			if (*currentItem == item)
			{
				if (currentItem->getAmount() == 1)
				{
					return _inventory.remove(i);
				}
				else
				{
					int currentAmount = currentItem->getAmount();
					currentItem->setAmount(currentAmount - 1);
					return currentItem->getStackableCopy();
				}
			}
		}

		return NULL ;
	}

	string Inventory::removeItem(string item)
	{
		uint usedSlots = _inventory.getSize();

		for (uint i = 0; i < usedSlots; i++)
		{
			Item currentItem = *_inventory.get(i);

			if (currentItem.getName() == item)
			{
				if (currentItem.getAmount() == 1)
				{
					return _inventory.remove(i)->getName();
				}
				else
				{
					currentItem.setAmount(currentItem.getAmount() - 1);

					return currentItem.getStackableCopy()->getName();
				}
			}
		}

		return "No item removed";
	}

	bool Inventory::contains(Item& item)
	{
		uint usedSlots = _inventory.getSize();

		for (uint i = 0; i < usedSlots; i++)
		{
			Item currentItem = *_inventory.get(i);
			if (currentItem == item)
			{
				return true;
			}
		}

		return false;
	}

	int Inventory::getInventoryIndex(Item& item)
	{
		uint usedSlots = _inventory.getSize();

		for (uint i = 0; i < usedSlots; i++)
		{
			Item currentItem = *_inventory.get(i);

			if (currentItem == item)
			{
				return i;
			}
		}

		return -1;
	}

	bool Inventory::contains(Item& item, uint amount)
	{
		uint count = 0;

		for (uint i = 0; i < amount; i++)
		{
			if (contains(item))
			{
				int index = getInventoryIndex(item);

				count += _inventory.get(index)->getAmount();
			}
		}

		if (count >= amount)
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

	Item* Inventory::getIndex(uint index)
	{
		return _inventory[index];
	}

	string Inventory::toString()
	{
		string inventory = "Inventory: ";
		uint usedSlots = getUsedSlots();

		for (uint i = 0; i < usedSlots; i++)
		{
			Item* item = _inventory.get(i);
			string itemName = item->getName();
			uint amount = _inventory.get(i)->getAmount();
			string trueName = itemName + " (" + to_string(amount) + ")";
			string coloredName = Color::colorText(trueName, item->getColor());

			inventory = inventory + coloredName;

			if (i < usedSlots - 1)
			{
				inventory = inventory + ", ";
			}
		}

		return inventory;
	}
}
