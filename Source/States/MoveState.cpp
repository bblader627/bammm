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
 * MoveState cpp file.
 *
 */

#include "MoveState.h"

namespace bammm
{
	MoveState::MoveState(Actor& actor)
	{
		_actor = &actor;
	}

	MoveState::MoveState(Actor& actor, IStateCallback& stateMachine,
			Grid3D<Actor*>& sceneGraph)
	{
		_sceneGraph = &sceneGraph;
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	void MoveState::setup(Vector3D direction)
	{
		_direction = direction;
	}

	void MoveState::setup()
	{
	}

	void MoveState::breakdown()
	{
	}

	void MoveState::tick(float deltaTime)
	{
		Vector3D temp(0,0,0);
		temp += *_actor->getLocation();
		temp += _direction;
		float x = temp.getX();
		float y = temp.getY();
		float z = temp.getZ();
		Vector3D* newLoc = new Vector3D(x, y, z);
		
		_sceneGraph->move(_actor, newLoc);
		switchState("null");
	}

	void MoveState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string MoveState::toString()
	{
		return "movement";
	}
}
