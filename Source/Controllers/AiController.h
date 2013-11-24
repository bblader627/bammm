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
#include "../States/StateMachine.h"
#include "../SceneManager/SceneManager.h"
#include "../Weapons/MeleeCombat.h"
#include "../Weapons/RangedCombat.h"
#include <random>

#ifndef NULL
#define NULL ((void *)0)
#endif

using namespace std;

namespace bammm
{
    class AiController : public Controller
    {
        public:
			AiController();
            ~AiController();
			
			/**
			 setup
			 @Pre-Condition- Takes an Actor, SceneManager, MeleeCombat as input
			 @Post-Condition- Sets up the controller with passed parameters
			 */            
			void setup(Actor& actor, SceneManager& scene, MeleeCombat& meleeCombat);
			
			/**
			 update
			 @Pre-Condition- Takes a float delta time (change in time) as input
			 @Post-Condition- Updates are executed based on the deltaTime. Returns true when controller should be deleted.
			 */		
			bool update(float dTime);
			
    };

	AiController::AiController()
	{
	}

    void AiController::setup(Actor& actor, SceneManager& scene, MeleeCombat& meleeCombat)
    {
		_sceneManager = &scene;
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

    AiController::~AiController()
    {
    }

	bool AiController::update(float dTime)
	{
    	//all currently running states
		if(_actor->getHealth() <= 0)
		{
			_sceneManager->getSceneGraph().remove(_actor->getLocation(), _actor);
			delete _actor;
			return true;
		}
		else
		{
			Vector3D* newLoc = new Vector3D(0,0,0);
			_sceneManager->getSceneGraph().moveTowards(_actor, newLoc);
        	_stateMachine.tick(dTime);
		}

		return false;
    }
}
#endif
