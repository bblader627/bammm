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
 * LevelingSystem header file.
 *
 */

#ifndef LEVELINGSYSTEM_H_
#define LEVELINGSYSTEM_H_

#include "../Actors/Actor.h"

namespace bammm
{
	class LevelingSystem
	{
		private:
			/**
			 levelUP
			 @Pre-Condition- Takes in an Actor* actor
			 @Post-Condition- Does all the required tasks for when an actor levels up, and returns the modified actor
			 */
			static Actor* levelUP(Actor* actor);

		public:
			LevelingSystem();
			virtual ~LevelingSystem();

			/**
			 gainExperience
			 @Pre-Condition- Takes in an Actor* actor
			 @Post-Condition- Increments the actors experience, and checks if it should level up. Returns modified actor
			 */
			static Actor* gainExperience(Actor* actor);
	};
}

#endif
