#ifndef SCENEMANAGER_H_
#define SCENEMANAGER_H_

#include "Grid3D.h"
#include "../Actors/Actor.h"
#include "../Actors/OrcActor.h"
//#include "../Controllers/AiController.h"
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
			ITickable* removeTickable(ITickable* tickable);
			void setMeleeCombat(MeleeCombat& meleeCombat);
			string toString();
			Grid3D<Actor*>& getSceneGraph();
			virtual void tick(float deltaTime);

	};

	SceneManager::~SceneManager()
	{
	}

	SceneManager::SceneManager() : _sceneGraph(SCENE_X, SCENE_Y, SCENE_Z)
	{
	    Vector3D* temp;
	    //Random number generator
	    random_device rd;
	    mt19937 generator(rd());

	    //Pick random number of orcs
	    int minOrc = 1;
	    int maxOrc = 10;
	    uniform_int_distribution<int> orcDistribution (minOrc, maxOrc);
	    int orcCount = orcDistribution(generator);

	    //Create the orcs
	    uniform_int_distribution<int> xDistribution (0, getSceneGraph().getX() - 1);
	    uniform_int_distribution<int> yDistribution (0, getSceneGraph().getY() - 1);
	    for(int i = 0; i < orcCount; i++)
	    {
	        int randomX = xDistribution(generator);
	        int randomY = yDistribution(generator);
	        temp = new Vector3D(randomX, randomY, 0);

	        OrcActor* newOrc = new OrcActor();
	        addActor(newOrc);

	        //AiController* newAi = new AiController();
	        //newAi->setup(*_allActors.get(i), *this, *_meleeCombat);
	        getSceneGraph().add(temp, (_allActors.get(i)));
	        //addTickable(newAi);
	    }
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
		int size = _allTickables.getSize();
		for(int i = 0; i < size; i++)
		{
			_allTickables.get(i)->tick(deltaTime);
			if(_allTickables.get(i)->canDelete())
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
