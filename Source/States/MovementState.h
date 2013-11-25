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
#include "../SceneManager/SceneManager.h"

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
			SceneManager* _sceneManager;
			Vector3D* _direction;

		public:
			MovementState(Actor& actor);
			MovementState(Actor& actor, IStateCallback& stateMachine);

			/**
			 Update this to take a Vector3D once we get rid of circular
			 setup
			 @Pre-Condition- Takes a SceneManager and a Vector3D
			 @Post-Condition- Sets up the state
			 */
			virtual void setup(SceneManager& sceneManager);

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

	MovementState::MovementState(Actor& actor)
	{
		_actor = &actor;
	}

	MovementState::MovementState(Actor& actor, IStateCallback& stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	void MovementState::setup(SceneManager& sceneManager)
	{
		_sceneManager = &sceneManager;
		//_direction = &direction;
	}

	void MovementState::breakdown()
	{
	}

	void MovementState::tick(float deltaTime)
	{
		Vector3D* newLoc = new Vector3D(0,0,0);
		_sceneManager->getSceneGraph().moveTowards(_actor, newLoc);
		//switchState("idle");
	}

	void MovementState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string MovementState::toString()
	{
		return "movement";
	}
}

#endif
