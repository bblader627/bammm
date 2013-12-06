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
 * IAction header file.
 *
 */

#ifndef IACTION_H_
#define IACTION_H_

#include <iostream>

class Actor;

using namespace std;

namespace bammm
{
	class IAction
	{
		private:
			string _type;
			int _amount;

		public:
			/*
			 action
			 @Pre-Condition- Takes in an Actor* target, and an int amount
			 @Post-Condition- Returns void
			 */
			virtual void action(Actor* target, int amount)=0;

			/*
			 setType
			 @Pre-Condition- Takes in a string type
			 @Post-Condition- Returns void
			 */
			void setType(string type);

			/*
			 setAmount
			 @Pre-Condition- Takes in an int amount
			 @Post-Condition- Returns void
			 */
			void setAmount(int amount);

			/*
			 increaseAmount
			 @Pre-Condition- Takes in an int amount
			 @Post-Condition- Returns void
			 */
			void increaseAmount(int amount);

			/*
			 decreaseAmount
			 @Pre-Condition- Takes in an int amount
			 @Post-Condition- Returns void
			 */
			void decreaseAmount(int amount);

			/*
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string representation of the IAction
			 */
			string toString();
	};
}

#endif
