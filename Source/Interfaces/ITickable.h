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

			/**
			 tick
			 @Pre-Condition- Takes a float deltaTime
			 @Post-Condition- Ticks for deltaTime
			 */
			virtual void tick(float deltaTime)=0;

			/**
			 canDelete
			 @Pre-Condition- Takes nothing
			 @Post-Condition- Returns a boolean representing if the tickable can be deleted or not.
			 */
			virtual bool canDelete();

			/**
			 toString
			 @Pre-Condition- Takes nothing
			 @Post-Condition- Returns a string representation of a tickable
			 */
			virtual string toString()=0;
	};
}

#endif
