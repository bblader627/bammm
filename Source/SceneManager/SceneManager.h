#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "Grid3D.h"
#include "../Actors/Actor.h"
#include "ITickable.h"
using namespace std;

namespace bammm
{
	class SceneManager
	{
		private:
			DynamicArray<Actor*> _allActors;
			DynamicArray<ITickable*> _allTickables;
			Grid3d<Actor*> _sceneGraph;

		public:
			~SceneManager();
			SceneManager();
			SceneManager(Grid3d<Actor*> grid);
			void addActor(Actor* actor);
			void removeActor(Actor* actor);
			void addTickable(ITickable* tickable);
			void removeTickable(ITickable* tickable);
			string to_string();
	};

	SceneManager::~SceneManager()
	{
	}

	SceneManager::SceneManager()
	{
	}

	SceneManager::SceneManager(Grid3d<Actor*> grid)
	{
	}

	void SceneManager::addActor(Actor* actor)
	{
		_allActors.add(actor);
	}


	void SceneManager::removeActor(Actor* actor)
	{
		_allActors.removeElem(actor);
	}

	void SceneManager::addTickable(ITickable* tickable)
	{
		_allTickables.add(tickable);
	}

	void SceneManager::removeTickable(ITickable* tickable)
	{
		_allTickables.removeElem(tickable);
	}

	string SceneManager::to_string()
	{
		return "";
	}
}
#endif
