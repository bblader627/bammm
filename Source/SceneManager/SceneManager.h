#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "Grid3D.h"
#include "../Actors/Actor.h"
#include "../Interfaces/ITickable.h"
using namespace std;

namespace bammm
{
	class SceneManager: ITickable
	{
		private:
			DynamicArray<Actor*> _allActors;
			DynamicArray<ITickable*> _allTickables;
			Grid3D<Actor*> _sceneGraph;
			static const int SCENE_X = 10;
			static const int SCENE_Y = 10;
			static const int SCENE_Z = 10;

		public:
			virtual ~SceneManager();
			SceneManager();

			void addActor(Actor* actor);
			void removeActor(Actor* actor);
			void addTickable(ITickable* tickable);
			void removeTickable(ITickable* tickable);
			string toString();
			Grid3D<Actor*>& getSceneGraph();
			virtual void tick(float deltaTime);

	};

	SceneManager::~SceneManager()
	{
	}

	SceneManager::SceneManager() : _sceneGraph(SCENE_X, SCENE_Y, SCENE_Z)
	{
	}

	void SceneManager::addActor(Actor* actor)
	{
		_allActors.add(actor);
	}

	void SceneManager::removeActor(Actor* actor)
	{
		_allActors.removeElement(actor);
	}

	void SceneManager::addTickable(ITickable* tickable)
	{
		_allTickables.add(tickable);
	}

	void SceneManager::removeTickable(ITickable* tickable)
	{
		_allTickables.removeElement(tickable);
	}

	Grid3D<Actor*>& SceneManager::getSceneGraph()
	{
		return _sceneGraph;
	}

	void SceneManager::tick(float deltaTime)
	{
		int size = _allTickables.getSize();
		for(int i = 0; i < size; i++)
		{
			_allTickables.get(i)->tick(deltaTime);
		}
	}

	string SceneManager::toString()
	{
		return "";
	}
}

#endif
