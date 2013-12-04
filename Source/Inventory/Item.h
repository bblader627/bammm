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
 * Item header file.
 *
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <iostream>
#include "../Resources/Constant.h"
#include "IAction.h"
class Actor;
using namespace std;

namespace bammm
{
	class Item
	{
		private:
			string _name;
			IAction* _action;
			uint _amount;


		public:
			Item();
			Item(string name);
			Item(string name, int amount);
			void action(Actor* target, int amount);
			uint getAmount();
			void setAmount(uint amount);
			string getName();
			void setName(string name);

	};
}

#endif
