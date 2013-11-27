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
 * MovementState cpp file.
 *
 */

#include "MovementState.h"

namespace bammm
{
	MovementState::MovementState(Actor& actor)
	{
		_actor = &actor;
	}

	MovementState::MovementState(Actor& actor, IStateCallback& stateMachine,
			Grid3D<Actor*>& sceneGraph)
	{
		_sceneGraph = &sceneGraph;
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	void MovementState::setup()
	{
		//_direction = &direction;
	}

	void MovementState::breakdown()
	{
	}

	void MovementState::tick(float deltaTime)
	{
		Vector3D* newLoc = new Vector3D(0, 0, 0);
		_sceneGraph->moveTowards(_actor, newLoc);
		//SceneManager::getSceneGraph().moveTowards(_actor, newLoc);
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
