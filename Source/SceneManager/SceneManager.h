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

#include <random>
#include "Grid3D.h"
#include "../Actors/Actor.h"
#include "../Controllers/AiController.h"
#include "../Interfaces/ITickable.h"
#include "../Weapons/MeleeCombat.h"
#include "../Controllers/PlayerController.h"

using namespace std;

namespace bammm
{
	class SceneManager: public ITickable
	{
		private:
			DynamicArray<Actor*> _allActors;
			MeleeCombat* _meleeCombat;
			DynamicArray<ITickable*> _allTickables;
			static const int SCENE_X = 10;
			static const int SCENE_Y = 10;
			static const int SCENE_Z = 10;
			Grid3D<Actor*> _sceneGraph;

		public:
			SceneManager();
			virtual ~SceneManager();

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
			ITickable* removeTickable(ITickable* tickable);

			/**
			 setMeleeCombat
			 @Pre-Condition- Takes in an instance of MeleeCombat
			 @Post-Condition- Sets meleeCombat to the scene
			 */
			void setMeleeCombat(MeleeCombat& meleeCombat);

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns an empty string right now
			 */
			string toString();

			/**
			 getSceneGraph
			 @Pre-Condition- No input
			 @Post-Condition- Returns the Grid3D of the scene
			 */
			Grid3D<Actor*>& getSceneGraph();

			/**
			 tick
			 @Pre-Condition- Takes in a float deltaTime
			 @Post-Condition- Ticks the scene for the duration of deltaTime
			 */
			virtual void tick(float deltaTime);
	};
}

#endif
