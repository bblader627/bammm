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
		return true;
	}

	bool Inventory::addItem(Item* item, uint amount)
	{
		return true;
	}

	bool Inventory::removeItem(Item* item)
	{
		return true;
	}

	bool Inventory::removeItem(Item* item, uint amount)
	{
		return true;
	}

	bool Inventory::contains(Item* item)
	{
		return true;
	}

	bool Inventory::contains(Item* item, uint amount)
	{
		return true;
	}
}
