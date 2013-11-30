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

			Actor* newOrc = new Actor("Mr. Orc", "orc");
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
		cout << "adding actor" << endl;
		_allActors.add(actor);
		cout << "actor successfully added" << endl;
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
