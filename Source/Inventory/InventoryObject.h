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
		private:
			string _type;
			int _amount;
		public:
			InventoryObject(string id);

			/*
				
			*/
			void setType(string type);
			
			void setAmount(int amount);
			
			void increaseAmount(int amount);

			void decreaseAmount(int amount);

			string toString();
	};
}

#endif

