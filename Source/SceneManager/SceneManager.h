#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "Grid3D.h"
#include "../Actors/Actor.h"
#include "../Controllers/AiController.h"
#include "../Interfaces/ITickable.h"
#include "../Weapons/MeleeCombat.h"
#include <random>
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
			 @Pre-Condition- Takes in MeleeCombat
			 @Post-Condition- Sets the MeleeCombat arguement to the scene
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
			 @Pre-Condition- Takes in float deltaTime
			 @Post-Condition- The scene ticks for the duration of the deltaTime
			 */
			virtual void tick(float deltaTime);
	};

	SceneManager::SceneManager() :
			_sceneGraph(SCENE_X, SCENE_Y, SCENE_Z)
	{
		Vector3D* temp;
		//Random number generator
		random_device rd;
		mt19937 generator(rd());

		//Pick random number of orcs
		int minOrc = 1;
		int maxOrc = 10;
		uniform_int_distribution<int> orcDistribution(minOrc, maxOrc);
		int orcCount = orcDistribution(generator);

		//Create the orcs
		uniform_int_distribution<int> xDistribution(0,
				getSceneGraph().getX() - 1);
		uniform_int_distribution<int> yDistribution(0,
				getSceneGraph().getY() - 1);
		for (int i = 0; i < orcCount; i++)
		{
			int randomX = xDistribution(generator);
			int randomY = yDistribution(generator);
			temp = new Vector3D(randomX, randomY, 0);

			Actor* newOrc = new Actor("orc");
			addActor(newOrc);

			AiController* newAi = new AiController();
			newAi->setup(*_allActors.get(i), *_meleeCombat, _sceneGraph);
			getSceneGraph().add(temp, (_allActors.get(i)));
			addTickable(newAi);
		}
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
	}

	void SceneManager::removeActor(Actor* actor)
	{
		_allActors.removeElement(actor);
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

#endif
