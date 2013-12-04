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

#include <string>
#include "SceneManager.h"
#include "../Controllers/PlayerController.h"

using namespace std;

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
			this->addPlayerController(controller);
		}
		else if (actor->getType() == "orc")
		{
			AiController* controller = new AiController();
			controller->setup(*actor, *_meleeCombat, _sceneGraph);
			this->addTickable(controller);
			this->addAiController(controller);
		}

	}

	Actor* SceneManager::removeActor(Actor* actor)
	{
		_allActors.removeElement(actor);
		_sceneGraph.remove(actor->getLocation(), actor);
		return actor;
	}

	void SceneManager::addTickable(ITickable* tickable)
	{
		_allTickables.add(tickable);
	}

	void SceneManager::addPlayerController(PlayerController* controller)
	{
		_allPlayerControllers.add(controller);
	}

	void SceneManager::addAiController(AiController* controller)
	{
		_allAiControllers.add(controller);
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
		for (int i = 0; i < size; i++)
		{
			ITickable* tickable = _allTickables.get(i);
			if (tickable->canDelete())
			{
				PlayerController* playerController = static_cast<PlayerController*>(tickable);
				AiController* aiController = static_cast<AiController*>(tickable);
				size--;
				_allPlayerControllers.removeElement(playerController);
				_allAiControllers.removeElement(aiController);
				removeActor(_allActors.get(i));
				removeTickable(tickable);
				i--;
			}
			else
			{
				tickable->tick(deltaTime);
			}
		}
	}

	void SceneManager::input(DynamicArray<string>* args, float deltaTime)
	{
		string newState = args->get(0);
		//bool doTick = true;


		DynamicArray<string> oreType = *(new DynamicArray<string>());
		oreType.add("iron");
		oreType.add("coal");
		oreType.add("gold");


		PlayerController* controller = this->findController(newState);
		if (controller == NULL)
		{
			return;
		}

		if (newState == "mine")
		{
			controller->input(args, deltaTime);

		}
		/*
		else if (newState == "sing")
		{
			//sing [songname]
			string songname;
			if (commandString->getSize() >= 2)
			{
				for (unsigned int i = 1; i < commandString->getSize(); i++)
				{
					songname += commandString->get(i);
				}
			}
			else
			{
				cout << "Invalid input\n";
				doTick = false;
			}
		}
		else if (newState == "brawl")
		{
			//how even

		}
		else if (newState == "attack")
		{
			//attack [actor name]

		}
		else if (newState == "drink")
		{
			//drink [beverage name]
			string beverage;
			try
			{
				beverage = commandString->get(1);
			}
			catch (exception& e)
			{
				cout << "Invalid beverage name.\n";
			}
		}
		else
		{
			cout << "Invalid input\n";
			doTick = false;
		}


		if (doTick)
		{
			State* stateToAdd = _states.getValue(newState);
			_stateMachine.addState(stateToAdd, commandString);
			_stateMachine.tick(deltaTime);
		}
		*/
	}

	string SceneManager::toString()
	{
		return "";
	}

	PlayerController* SceneManager::findController(string command)
	{
		PlayerController* current;

		for (unsigned int i = 0; i < _allPlayerControllers.getSize(); i++)
		{
			current = _allPlayerControllers.get(i);
			DynamicArray<State*>& runningStates = current->runningStates();
			HashMap<State*>& allStates = current->allStates();

			if (current->numberOfStates()==0)  //return *current
			{
				return current;
			}
			else if (runningStates.contains(allStates.getValue(command)))
			{
				return current;
			}
			else if ((runningStates.contains(allStates.getValue("drink"))) ||
						(runningStates.contains(allStates.getValue("sing"))) ||
						(runningStates.contains(allStates.getValue("sleep"))) ||
						(runningStates.contains(allStates.getValue("idle")))
					)
			{
				return current;
			}

		}

		return NULL;
	}

}
