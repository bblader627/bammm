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
 * PlayerController header file.
 *
 */


#ifndef PLAYERCONTROLLER_H_
#define PLAYERCONTROLLER_H_

#include "Controller.h"
#include "../Factories/Factory.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

using namespace std;

namespace bammm
{
    class PlayerController : public Controller
    {
        public:
			PlayerController();
			~PlayerController();

			/**
			 input
			 @Pre-Condition- Takes multiple commands and a deltaTime
			 @Post-Condition- The commands are executed.
			 */            
			void input(DynamicArray<string>* command, float deltaTime);

			/**
			 input
			 @Pre-Condition- Takes a single command and a deltaTime
			 @Post-Condition- The command is executed.
			 */            
			void input(string command, float deltaTime);
            
			/**
			 setup
			 @Pre-Condition- Takes an Actor, SceneManager, and MeleeCombat
			 @Post-Condition- Sets up the controller with the passed Actor, SceneManager, and MeleeCombat
			 */			
			void setup(Actor& actor, SceneManager& scene, MeleeCombat& meleeC);
            
			/**
			 printOptions
			 @Pre-Condition- Takes no arguments
			 @Post-Condition- Prints out control options to the screen
			 */
			void printOptions();

			/** 
			 canDelete
			 @Pre-Condition- Takes nothing
			 @Post-Condition- Returns a boolean representing if the Controller can be deleted or not.
			 */
			 virtual bool canDelete();
    };

	PlayerController::PlayerController()
	{
	}

    void PlayerController::setup(Actor& actor, SceneManager& scene, MeleeCombat& meleeCombat)
    {
		_sceneManager = &scene;
		_meleeCombat = &meleeCombat;
    	//Factory* actorFactory = new Factory();
    	//actorFactory->setup();();

        _actor = &actor;
        _stateMachine.setup(actor, _states);


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

    void PlayerController::input(DynamicArray<string>* multiInput, float deltaTime)
    {
    	//all currently running states
		//Danger
    	DynamicArray<State*>& currentStates = _stateMachine.getCurrentStates();

    	//newStates will have 1 state
		//DynamicArray<State*>* newStates = new DynamicArray<State*>();

		for(int i = 0; i < (int)multiInput->getSize(); i++)
		{
			//Check to see if state is already running
			//if so, break it down

			//!!!!!!!Danger!!!!!!!
			State* newState  = _states.getValue(multiInput->get(i));

			/********************************************
			 *This should be handled in the stateMachine
			 *This logic should be in statemachine->add()
			 * or switchState()
			 *******************************************/
			if (currentStates.contains(newState))
			{
				//switching newState with NULL calls breakdown on newState, the remove on currentStates
				
				//Do doTurn in MeleeCombat
				if (newState->toString() == "combat")
				{
					if (!_meleeCombat->fightHappening())
					{
						_stateMachine.removeState(newState);

					}
					else
					{
						_meleeCombat->useTurn();
					}
				}
				else
				{
					//breakdown and setup are not calling the correct functions
					_stateMachine.removeState(newState);
				}
			}
			else
			{
				//Special case for combat state
				if (newState->toString() == "combat")
				{
					Actor* closestEnemy = _sceneManager->getSceneGraph().getEnemy(_actor->getLocation(), _actor);
					if(closestEnemy)
					{
						_meleeCombat->setup(*_actor, *closestEnemy);
					}
				}
				_stateMachine.addState(newState);
			}
		}

		//Should input even call switchstate?
		//_stateMachine->switchState(newStates);
		_stateMachine.tick(deltaTime);
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
    	/*

    	}
    	*/
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
		if(_actor->getHealth() <= 0)
		{
			return true;
		}

		return false;
	}

    PlayerController::~PlayerController()
    {
    }


}
#endif
