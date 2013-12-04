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
//#include "../Interfaces/IAction.h"
//#include "../Actors/Actor.h"
using namespace std;

namespace bammm
{
	class Item
	{
		private:
			string _name;
			string _color;
			string _description;
			//IAction* _action;
			uint _amount;

		public:
			Item();
			Item(string name);
			Item(string name, string color);
			Item(string name, int amount, string color);
			Item(string name, int amount);
			virtual ~Item();

			/**
			 action
			 Pre-Condition- A pointer to an Actor, and an int amount
			 Post-Condition- Uses the item's action
			 */
			//void action(Actor* target, int amount);

			/**
			 getAmount
			 Pre-Condition- None
			 Post-Condition- Gets the amount of the item
			 */
			uint getAmount();

			/**
			 setAmount
			 Pre-Condition- A uint to set the amount of the item
			 Post-Condition- Sets the amount of the item
			 */
			void setAmount(uint amount);

			/**
			 getName
			 Pre-Condition- None
			 Post-Condition- Gets the name of the item
			 */
			string getName();

			/**
			 setName
			 Pre-Condition- A string for the new name
			 Post-Condition- Sets the name of the item
			 */
			void setName(string name);

			/**
			 setColor
			 Pre-Condition- A string for the new color
			 Post-Condition- Sets the color of the item
			 */
			void setColor(string color);
			
			/**
			 getColor
			 Pre-Condition- None
			 Post-Condition- Gets the color of the item
			 */
			string getColor();
			
			/**
			 setDescription
			 Pre-Condition- A string for the new description
			 Post-Condition- Sets the description of the item
			 */
			void setDescription(string description);
			
			/**
			 getDescription
			 Pre-Condition- None
			 Post-Condition- Gets the description of the item
			 */
			string getDescription();
			
			/**
			 operator==
			 Pre-Condition- A reference to an Item
			 Post-Condition- Returns true if two items have same name
			 */
			bool operator==(const Item& item2);

	};
}

#endif
