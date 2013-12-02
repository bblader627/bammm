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
 * SearchState cpp file.
 *
 */

#include "SearchState.h"

namespace bammm
{
	SearchState::SearchState(Actor& actor)
	{
		_actor = &actor;
	}

	SearchState::SearchState(Actor& actor, IStateCallback& stateMachine,
			Grid3D<Actor*>& sceneGraph)
	{
		_sceneGraph = &sceneGraph;
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	void SearchState::setTarget(string target)
	{
		_target = target;
		//_path = _sceneGraph->getPath(_actor, _target);
	}

	void SearchState::setDestState(State* goal)
	{
		_goalState = goal;
	}

	void SearchState::setup()
	{
	}

	void SearchState::breakdown()
	{
	}

	void SearchState::tick(float deltaTime)
	{
		cout << "Ticking search state!" << endl;
		if (_path->isEmpty())
		{
			switchState("null");

		}
		else
		{
			_sceneGraph->move(_actor, _path->pop());
		}
	}

	void SearchState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	void SearchState::switchState(State* nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string SearchState::toString()
	{
		return "search";
	}
}
