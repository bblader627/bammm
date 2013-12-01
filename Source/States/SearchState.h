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
 * SearchState header file.
 *
 */

#ifndef SEARCHSTATE_H_
#define SEARCHSTATE_H_

#include <iostream>
#include "State.h"
#include "../SceneManager/Grid3D.h"
#include "../Resources/Stack.h"
#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

using namespace std;

namespace bammm
{
	class SearchState: public State
	{
		private:
			string _target;
			Grid3D<Actor*>* _sceneGraph;
			Stack<Vector3D*>* _path;

		public:
			SearchState(Actor& actor);
			SearchState(Actor& actor, IStateCallback& stateMachine, Grid3D<Actor*>& sceneGraph);

			/**
			 Update this to take a Vector3D once we get rid of circular
			 setup
			 @Pre-Condition- Takes nothing
			 @Post-Condition- Sets up the state
			 */
			virtual void setup();

			/**
			 setup
			 @Pre-Condition- Takes a target to search for
			 @Post-Condition- Sets up the state with a string target
			 */
			virtual void setTarget(string target);
			
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
			virtual void switchState(string nextState);

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string representation of the state
			 */
			string toString();
	};
}

#endif
