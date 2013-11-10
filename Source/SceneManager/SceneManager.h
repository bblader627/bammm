#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "Grid3D.h"
#include "../Actors/Actor.h"
using namespace std;

namespace bammm
{
	class SceneManager
	{
		private:
			DynamicArray<Actor*> _allActors;
			DynamicArray<Actor*> _allTickables;
			Grid3d<Actor*> _sceneGraph;

		public:
			~SceneManager();
			SceneManager();
			SceneManager(Grid3d<Actor*> grid);
			void addActor(Actor* actor);
			void removeActor(Actor* actor);
			void addTickable();
			void removeTickable();
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
	}


	void SceneManager::removeActor(Actor* actor)
	{
	}

	void SceneManager::addTickable()
	{
	}

	void SceneManager::removeTickable()
	{
	}

	string SceneManager::to_string()
	{
		return "";
	}
}
#endif
