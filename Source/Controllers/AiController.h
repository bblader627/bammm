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
 * AiController header file.
 *
 */

#ifndef AICONTROLLER_H_
#define AICONTROLLER_H_

#include "Controller.h"
#include <random>
#include "../Interfaces/ITickable.h"
#include "../Resources/Constant.h"

using namespace std;

namespace bammm
{
	class AiController: public Controller
	{
		public:
			AiController();
			~AiController();

			/**
			 setup
			 @Pre-Condition- Takes an Actor, MeleeCombat, and Grid3D as input
			 @Post-Condition- Sets up the controller with passed parameters
			 */
			void setup(Actor& actor, MeleeCombat& meleeCombat,
					Grid3D<Actor*>& sceneGraph);

			/**
			 tick
			 @Pre-Condition- Takes a float delta time (change in time) as input
			 @Post-Condition- Updates are executed based on the deltaTime.
			 */
			virtual void tick(float deltaTime);

			/**
			 canDelete
			 @Pre-Condition- Takes nothing
			 @Post-Condition- Returns a boolean representing if the Controller can be deleted or not.
			 */
			virtual bool canDelete();

			virtual string toString();

	};
}

#endif
