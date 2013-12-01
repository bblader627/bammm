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
 * SceneManager cpp file.
 *
 */

#include "SceneManager.h"

namespace bammm
{
	SceneManager::SceneManager() :
			_sceneGraph(SCENE_X, SCENE_Y, SCENE_Z)
	{

	}

	SceneManager::~SceneManager()
	{
	}

	void SceneManager::setMeleeCombat(MeleeCombat& meleeCombat)
	{
		_meleeCombat = &meleeCombat;
	}

	void SceneManager::addActor(Actor* actor)
	{
		_allActors.add(actor);
		_sceneGraph.add(actor->getLocation(), actor);

		if (actor->getType() == "dwarf")
		{
			PlayerController* controller = new PlayerController();
			controller->setup(*actor, *_meleeCombat, _sceneGraph);
			this->addTickable(controller);
		}
		else if (actor->getType() == "orc")
		{
			AiController* controller = new AiController();
			controller->setup(*actor, *_meleeCombat, _sceneGraph);
			this->addTickable(controller);
		}

	}

	void SceneManager::removeActor(Actor* actor)
	{
		_allActors.removeElement(actor);
		_sceneGraph.remove(actor->getLocation(), actor);
	}

	void SceneManager::addTickable(ITickable* tickable)
	{
		_allTickables.add(tickable);
	}

	ITickable* SceneManager::removeTickable(ITickable* tickable)
	{
		_allTickables.removeElement(tickable);
		return tickable;
	}

	Grid3D<Actor*>& SceneManager::getSceneGraph()
	{
		return _sceneGraph;
	}

	void SceneManager::tick(float deltaTime)
	{
		cout << "I was ticked\n";
		int size = _allTickables.getSize();
		for (int i = 0; i < size; i++)
		{
			_allTickables.get(i)->tick(deltaTime);
			if (_allTickables.get(i)->canDelete())
			{
				delete removeTickable(_allTickables.get(i));
			}
		}
	}

	string SceneManager::toString()
	{
		return "";
	}
}
