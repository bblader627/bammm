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

		//Put actor in idle state
		_stateMachine.initialState(_states.getValue(idleState->toString()));
	}

	void PlayerController::input(DynamicArray<string>* commandString,
			float deltaTime)
	{
		string newState = commandString->get(0);
		//bool doTick = true;

		DynamicArray<string>* oreType = new DynamicArray<string>();
		oreType->add("iron");
		oreType->add("coal");
		oreType->add("gold");


		if (newState == "mine")
		{
			//mine [#] [ore-type]
			int numOre;
			string type;

			if (commandString->getSize() == 3)
			{
				string number_str = commandString->get(1);

				numOre = atoi(number_str.c_str());
				if (numOre == 0)
				{
					cout << "Invalid argument\n";
					//doTick = false;
				}
				numOre = 0;
				type = commandString->get(2);
				if (!(oreType->contains(type)))
				{
					cout << type << " is not a valid ore type\n";
					//doTick = false;
				}
				//Add to controllerinput

			}
			else
			{
				cout << "Invalid input\n";
				//doTick = false;
			}

			Vector3D* oreLocation = _sceneGraph->findInGrid(type);
			State* stateToAdd = _states.getValue(newState);

			if (_actor->getLocation() == oreLocation)
			{
				_stateMachine.addState(stateToAdd);
			}
			else
			{

				SearchState* search = static_cast<SearchState*>(_states.getValue("search"));
				search->setTarget(type);
				search->setDestState(stateToAdd);
				_stateMachine.addState(search);

			}


			//_stateMachine.tick(deltaTime);
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
		}*/
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
		/*
		_stateMachine.tick(deltaTime);
		Actor* enemy = _sceneGraph->getEnemy(_actor->getLocation(), _actor);
		DynamicArray<State*>& currentStates = _stateMachine.getCurrentStates();
		if (enemy)
		{
			State* tempState = _states.getValue("damage");

			if (!currentStates.contains(tempState))
			{
				_stateMachine.addState(tempState);
			}
			DamageState* castedState = static_cast<DamageState*>(tempState);
			castedState->setTarget(*enemy);
		}
		else
		{

			State* newState = _states.getValue("movement");

			//all currently running states
			if (!currentStates.contains(newState))
			{
				_stateMachine.addState(newState);
			}

			//Random number generator
			random_device rd;
			mt19937 generator(rd());

			uniform_int_distribution<int> randomDistribution(0, 3);

			//Pick a random direction
			int random = randomDistribution(generator);
			Vector3D newLocation(0, 0, 0);
			if (random == 0)
			{
				newLocation.set(1, 0, 0);
			}
			else if (random == 1)
			{
				newLocation.set(-1, 0, 0);
			}
			else if (random == 2)
			{
				newLocation.set(0, 1, 0);
			}
			else if (random == 3)
			{
				newLocation.set(0, -1, 0);
			}
			MoveState* castedState = static_cast<MoveState*>(newState);
			castedState->setDirection(newLocation);
		 	newState = _states.getValue("movement");
		}
		*/

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
