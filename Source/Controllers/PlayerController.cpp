/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *   Bradley Crusco
 * Description:
 * PlayerController cpp file.
 *
 */

#include "PlayerController.h"

namespace bammm
{
	PlayerController::PlayerController()
	{
	}

	PlayerController::~PlayerController()
	{
	}

	void PlayerController::setup(Actor& actor, MeleeCombat& meleeCombat,
			Grid3D<Actor*>& sceneGraph)
	{
		_meleeCombat = &meleeCombat;
		_sceneGraph = &sceneGraph;

		_actor = &actor;
		_stateMachine.setup(actor, _states, _meleeCombat);

		//Create the states
		DrinkState* drinkState = new DrinkState(actor, &_stateMachine);
		MineState* mineState = new MineState(actor, &_stateMachine);
		SingState* singState = new SingState(actor, &_stateMachine);
		BrawlState* brawlState = new BrawlState(actor, &_stateMachine);
		SleepState* sleepState = new SleepState(actor, &_stateMachine);
		IdleState* idleState = new IdleState(actor, &_stateMachine);
		CombatState* combatState = new CombatState(actor, &_stateMachine);
		SearchState* searchState = new SearchState(actor, &_stateMachine, *_sceneGraph);
		DamageState* damageState = new DamageState(actor, &_stateMachine);
		MoveState* moveState = new MoveState(actor, &_stateMachine, sceneGraph);
		ChopState* chopState = new ChopState(actor, &_stateMachine);

		_states.add(idleState->toString(), idleState);
		_states.add(mineState->toString(), mineState);
		_states.add(drinkState->toString(), drinkState);
		_states.add(singState->toString(), singState);
		_states.add(brawlState->toString(), brawlState);
		_states.add(sleepState->toString(), sleepState);
		_states.add(combatState->toString(), combatState);
		_states.add(searchState->toString(), searchState);
		_states.add(damageState->toString(), damageState);
		_states.add(moveState->toString(), moveState);
		_states.add(chopState->toString(), chopState);

		//Put actor in default behavior state
		_stateMachine.initialState(_states.getValue(searchState->toString()));
	}

	void PlayerController::input(DynamicArray<string>* commandString,
			float deltaTime)
	{
		string newState = commandString->get(0);
		//bool doTick = true;
		State* stateToAdd;

		DynamicArray<string>* oreType = new DynamicArray<string>();
		oreType->add("iron");
		oreType->add("coal");
		oreType->add("gold");

		DynamicArray<string>* woodType = new DynamicArray<string>();
		woodType->add("redwood");
		woodType->add("birch");
		woodType->add("oak");
		woodType->add("cedar");


		if (newState == "mine")
		{
			//mine [#] [ore-type]
			int numOre;
			string type;
			_states.getValue(newState);

			if (commandString->getSize() == 3)
			{
				string number_str = commandString->get(1);

				numOre = atoi(number_str.c_str());
				if (numOre == 0)
				{
					cout << "Invalid argument number\n";
					return;
					//doTick = false;
				}
				//numOre = 0;
				type = commandString->get(2);
				if (!(oreType->contains(type)))
				{
					cout << type << " is not a valid ore type\n";
					return;
					//doTick = false;
				}
				//Add to controllerinput
				Actor* ore = _sceneGraph->findClosestInGrid(_actor, type);
				stateToAdd = _states.getValue(newState);
				MineState* tempState = static_cast<MineState*>(stateToAdd);
				tempState->setAmount(numOre);
				tempState->setOre(ore);

				cout << _actor->getName() << " has been sent to mine " << type << "!" << endl;
				SearchState* search = static_cast<SearchState*>(_states.getValue("search"));
				search->setTarget(type);
				search->setDestState(tempState);
				_stateMachine.addState(search);

			}
			else
			{
				cout << "Invalid input\n";
				//doTick = false;
			}

		}
		else if (newState == "chop")
		{
			//mine [#] [ore-type]
			int numWood;
			string type;
			_states.getValue(newState);

			if (commandString->getSize() == 3)
			{
				string number_str = commandString->get(1);

				numWood = atoi(number_str.c_str());
				if (numWood == 0)
				{
					cout << "Invalid argument number\n";
					return;
					//doTick = false;
				}

				type = commandString->get(2);
				if (!(woodType->contains(type)))
				{
					cout << type << " is not a valid ore type\n";
					return;
					//doTick = false;
				}
				//Add to controllerinput
				Actor* ore = _sceneGraph->findClosestInGrid(_actor, type);
				stateToAdd = _states.getValue(newState);
				ChopState* tempState = static_cast<ChopState*>(stateToAdd);
				tempState->setAmount(numWood);
				tempState->setTree(ore);

				cout << _actor->getName() << " has been sent to chop " << type << "!" << endl;
				SearchState* search = static_cast<SearchState*>(_states.getValue("search"));
				search->setTarget(type);
				search->setDestState(tempState);
				_stateMachine.addState(search);

			}
			else
			{
				cout << "Invalid input\n";
			}
		}
		else if (newState == "drink")
		{
			cout << _actor->getName() << " has been sent to drink at the Pub!" << endl;

			stateToAdd = _states.getValue(newState);
			SearchState* search = static_cast<SearchState*>(_states.getValue("search"));
			search->setTarget("Pub");
			search->setDestState(stateToAdd);
			_stateMachine.addState(search);
		}

	}

	void PlayerController::input(string command, float deltaTime)
	{
		DynamicArray<string>* passValue = new DynamicArray<string>();
		passValue->add(command);
		input(passValue, deltaTime);
		delete passValue;
	}

	void PlayerController::printOptions()
	{
		//DynamicArray<State*>& currentStates = _stateMachine.getCurrentStates();
		cout << "What would you like your villagers to do?\n  To run the simulation, enter \"wait [number of iterations]\"." << endl;

	}

	bool PlayerController::canDelete()
	{
		if (_actor->getHealth() <= 0)
		{
			return true;
		}

		return false;
	}

	void PlayerController::tick(float deltaTime)
	{
		Actor* enemy = _sceneGraph->getEnemy(_actor->getLocation(), _actor);
		DynamicArray<State*>& currentStates = _stateMachine.getCurrentStates();
		State* newState;

		if (enemy)
		{
			newState = _states.getValue("damage");

			if(!currentStates.contains(newState))
			{
				_stateMachine.addState(newState);
				DamageState* castedState = static_cast<DamageState*>(newState);
				castedState->setTarget(*enemy);
			}
		}

		_stateMachine.tick(deltaTime);
	}

	string PlayerController::toString()
	{
		return "PlayerController";
	}

	int PlayerController::numberOfStates()
	{
		return _stateMachine.getCurrentStates().getSize();
	}

	DynamicArray<State*>& PlayerController::runningStates()
	{
		return _stateMachine.getCurrentStates();
	}

	HashMap<State*>& PlayerController::allStates()
	{
		return _states;
	}

}
