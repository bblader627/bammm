/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *
 * Description:
 * InventoryObject header file.
 *
 * Last Modified: Alvaro Home
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

