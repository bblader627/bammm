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
 * AiController header file.
 *
 */


#ifndef AICONTROLLER_H_
#define AICONTROLLER_H_

#include "Controller.h"
#include <random>

#ifndef NULL
#define NULL ((void *)0)
#endif

using namespace std;

namespace bammm
{
    class AiController: public Controller, public ITickable
    {
        public:
			AiController();
            ~AiController();
			
			/**
			 setup
			 @Pre-Condition- Takes an Actor, MeleeCombat, and Grid3D as input
			 @Post-Condition- Sets up the controller with passed parameters
			 */            
			void setup(Actor& actor, MeleeCombat& meleeCombat, Grid3D<Actor*>& sceneGraph);
			
			/**
			 tick
			 @Pre-Condition- Takes a float delta time (change in time) as input
			 @Post-Condition- Updates are executed based on the deltaTime.
			 */		
			virtual void tick(float deltaTime);

			/**
			 canDelete
			 @Pre-Condition- Takes nothing
			 @Post-Condition- Returns a boolean representing if the Controller can be deleted or not.
			 */
			 virtual bool canDelete();
			
    };

	AiController::AiController()
	{
	}

    void AiController::setup(Actor& actor, MeleeCombat& meleeCombat, Grid3D<Actor*>& sceneGraph)
    {
		_sceneGraph = &sceneGraph;
		_meleeCombat = &meleeCombat;
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
		MovementState* movementState = new MovementState(actor, _stateMachine, sceneGraph);

        _states.add(idleState->toString(), idleState);
        _states.add(mineState->toString(), mineState);
        _states.add(drinkState->toString(), drinkState);
        _states.add(singState->toString(), singState);
        _states.add(brawlState->toString(), brawlState);
        _states.add(sleepState->toString(), sleepState);
       	_states.add(combatState->toString(), combatState);
       	_states.add(movementState->toString(), movementState);
		
		//Put actor in idle state
		_stateMachine.initialState(_states.getValue(idleState->toString()));
    }

    AiController::~AiController()
    {
		//Prevents deletion of dead units for now
		//SceneManager::getSceneGraph().remove(_actor->getLocation(), _actor);
		delete _actor;
    }

	bool AiController::canDelete()
	{
		if(_actor->getHealth() <= 0)
		{
			return true;
		}

		return false;
	}

	void AiController::tick(float deltaTime)
	{
		DynamicArray<State*>& currentStates = _stateMachine.getCurrentStates();
		State* newState = _states.getValue("movement");
    	//all currently running states
		if(!currentStates.contains(newState))
		{
			_stateMachine.addState(newState);	
		}
        _stateMachine.tick(deltaTime);
    }
}
#endif
