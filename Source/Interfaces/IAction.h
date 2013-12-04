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
		public:
			virtual void action(Actor* target, int amount)=0;
	};
}

#endif
