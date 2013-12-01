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
		DrinkState* drinkState = new DrinkState(actor, _stateMachine);
		MineState* mineState = new MineState(actor, _stateMachine);
		SingState* singState = new SingState(actor, _stateMachine);
		BrawlState* brawlState = new BrawlState(actor, _stateMachine);
		SleepState* sleepState = new SleepState(actor, _stateMachine);
		IdleState* idleState = new IdleState(actor, _stateMachine);
		CombatState* combatState = new CombatState(actor, _stateMachine);

		_states.add(idleState->toString(), idleState);
		_states.add(mineState->toString(), mineState);
		_states.add(drinkState->toString(), drinkState);
		_states.add(singState->toString(), singState);
		_states.add(brawlState->toString(), brawlState);
		_states.add(sleepState->toString(), sleepState);
		_states.add(combatState->toString(), combatState);

		//Put actor in idle state
		_stateMachine.initialState(_states.getValue(idleState->toString()));
	}

	void PlayerController::input(DynamicArray<string>* commandString,
			float deltaTime)
	{
		string newState = commandString->get(0);
		bool doTick = true;

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
					doTick = false;
				}
				numOre = 0;
				type = commandString->get(2);
				if (!(oreType->contains(type)))
				{
					cout << type << " is not a valid ore type\n";
					doTick = false;
				}
				//Add to controllerinput

			}
			else
			{
				cout << "Invalid input\n";
				doTick = false;
			}

		}
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
		DynamicArray<State*>& currentStates = _stateMachine.getCurrentStates();
		//cout << "What would you like your villagers to do?\n  To run the simulation, enter \"wait [number of iterations]\"." << endl;


		//MAKE THIS SMARTER
		cout << "Select an activity for your dwarf:" << "\n";

		//Mining gold options
		if (currentStates.contains(_states.getValue("mine")))
		{
			cout << "1. Stop mining gold" << "\n";
		}
		else
		{
			cout << "1. Mine Gold" << "\n";
		}

		//Drinking options
		if (currentStates.contains(_states.getValue("drink")))
		{
			cout << "2. Stop drinking ale" << "\n";
		}
		else
		{
			cout << "2. Drink ale" << "\n";
		}

		//Singing options
		if (currentStates.contains(_states.getValue("sing")))
		{
			cout << "3. Stop singing" << "\n";
		}
		else
		{
			cout << "3. Sing a song" << "\n";
		}

		//Fighting options
		if (currentStates.contains(_states.getValue("brawl")))
		{
			cout << "4. Stop fighting" << "\n";
		}
		else
		{
			cout << "4. Fight a dwarf" << "\n";
		}

		//Sleeping options
		if (currentStates.contains(_states.getValue("sleep")))
		{
			cout << "5. Wake up" << "\n";
		}
		else
		{
			cout << "5. Go to sleep" << "\n";
		}

		//Combat options
		if (currentStates.contains(_states.getValue("combat")))
		{
			cout << "6. Attack" << "\n";
		}
		else
		{
			cout << "6. Fight Orc" << "\n";
		}

		cout << "7. Continue" << "\n";

		cout << "0. Quit" << "\n";

	}

	bool PlayerController::canDelete()
	{
		if (_actor->getHealth() <= 0)
		{
			return true;
		}

		return false;
	}
}
