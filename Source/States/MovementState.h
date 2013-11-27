/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *	Bradley Crusco
 * Description:
 * MovementState header file.
 *
 */

#ifndef MOVEMENTSTATE_H_
#define MOVEMENTSTATE_H_

#include <iostream>
#include "State.h"
#include "../SceneManager/Grid3D.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

using namespace std;

namespace bammm
{
	class MovementState: public State
	{
		private:
			Vector3D* _direction;
			Grid3D<Actor*>* _sceneGraph;

		public:
			MovementState(Actor& actor);
			MovementState(Actor& actor, IStateCallback& stateMachine, Grid3D<Actor*>& sceneGraph);

			/**
			 Update this to take a Vector3D once we get rid of circular
			 setup
			 @Pre-Condition- Takes nothing
			 @Post-Condition- Sets up the state
			 */
			virtual void setup();

			/**
			 breakdown
			 @Pre-Condition- No input
			 @Post-Condition- Performs a breakdown on the state
			 */
			void breakdown();

			/**
			 tick
			 @Pre-Condition- Takes in a float deltaTime
			 @Post-Condition- Executes a tick of length deltaTime
			 */
			virtual void tick(float deltaTime);

			/**
			 switchState
			 @Pre-Condition- Takes in a string nextState
			 @Post-Condition- The current state is switched to the given nextState
			 */
			void switchState(string nextState);

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string representation of the state
			 */
			string toString();
	};
}

#endif
