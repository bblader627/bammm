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
 * SceneManager header file.
 *
 */

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
			Grid3D<Actor*> _sceneGraph;
			static const int SCENE_X = 10;
			static const int SCENE_Y = 10;
			static const int SCENE_Z = 10;

		public:
			SceneManager();
			~SceneManager();

			/**
			 addActor
			 @Pre-Condition- Takes in an actor
			 @Post-Condition- Adds the actor to the scene
			 */
			void addActor(Actor* actor);

			/**
			 removeActor
			 @Pre-Condition- Takes in an actor
			 @Post-Condition- Removes the given actor from the scene
			 */
			void removeActor(Actor* actor);

			/**
			 addTickable
			 @Pre-Condition- Takes in a tickable
			 @Post-Condition- Adds the given tickable to the scene
			 */
			void addTickable(ITickable* tickable);

			/**
			 removeTickable
			 @Pre-Condition- Takes in a tickable
			 @Post-Condition- Removes the given tickable from the scene
			 */
			void removeTickable(ITickable* tickable);

			/**
			 getSceneGraph
			 @Pre-Condition- No input
			 @Post-Condition- Returns the Grid3D of the scene
			 */
			Grid3D<Actor*>& getSceneGraph();

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns an empty string right now
			 */
			string toString();
	};

	SceneManager::SceneManager()
	{
		_sceneGraph = new Grid3D<Actor*>(SCENE_X, SCENE_Y, SCENE_Z);
	}

	SceneManager::~SceneManager()
	{
	}

	void SceneManager::addActor(Actor* actor)
	{
		_allActors->add(actor);
	}

	void SceneManager::removeActor(Actor* actor)
	{
		_allActors->removeElement(actor);
	}

	void SceneManager::addTickable(ITickable* tickable)
	{
		_allTickables->add(tickable);
	}

	void SceneManager::removeTickable(ITickable* tickable)
	{
		_allTickables->removeElement(tickable);
	}

	Grid3D<Actor*>* SceneManager::getSceneGraph()
	{
		return _sceneGraph;
	}

	string SceneManager::toString()
	{
		return "";
	}
}

#endif
