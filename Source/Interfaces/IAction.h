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
			virtual void action(Actor* target, int amount)=0;

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
