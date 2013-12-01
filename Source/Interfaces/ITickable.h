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
 * ITickable header file.
 *
 */

#include <string>

#ifndef ITICKABLE_H_
#define ITICKABLE_H_

using namespace std;

namespace bammm
{
	class ITickable
	{
		public:
			virtual ~ITickable();

			//TODO: Add doc style comment
			virtual void tick(float deltaTime)=0;

			//TODO: Add doc style comment
			virtual bool canDelete();

			virtual string toString()=0;
	};
}

#endif
