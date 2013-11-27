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
 * InventoryObject header file.
 *
 */

#ifndef INVENTORYOBJECT_H_
#define INVENTORYOBJECT_H_

#include <iostream>

using namespace std;

namespace bammm
{
	class InventoryObject
	{
		public:
			string id;

			InventoryObject(string id);
	};
}

#endif

