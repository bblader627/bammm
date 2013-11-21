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
 * AiController header file.
 *
 * Last Modified: Matt Witkowski
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
using namespace bammm;

namespace bammm
{
    class AiController : public Controller
    {
		private:
			MeleeCombat* meleeCombat;
			RangedCombat* rangedCombat;
			SceneManager* sceneManager;
        public:
            void setup(Actor& actor, SceneManager& scene, MeleeCombat& meleeC);
			bool update(float dTime);
			AiController();
            ~AiController();
    };

	AiController::AiController()
	{
	}

    void AiController::setup(Actor& actor, SceneManager& scene, MeleeCombat& meleeC)
    {
		sceneManager = &scene;
		meleeCombat = &meleeC;
        _actor = &actor;
    	_stateMachine.setup(actor, _states);

		//Create the states
        //DO NOT DELETE THE REFERENCES TO STATEMACHINE.  THE CODE WILL SEG FAULT IF YOU DO
        DrinkState* drinkState = new DrinkState(actor, _stateMachine);
        MineState* mineState = new MineState(actor, _stateMachine);
        SingState* singState = new SingState(actor, _stateMachine);
        BrawlState* brawlState = new BrawlState(actor, _stateMachine);
        SleepState* sleepState = new SleepState(actor, _stateMachine);
        IdleState* idleState = new IdleState(actor, _stateMachine);
		CombatState* combatState = new CombatState(actor, _stateMachine);

        _states.add(idleState->to_string(), idleState);
        _states.add(mineState->to_string(), mineState);
        _states.add(drinkState->to_string(), drinkState);
        _states.add(singState->to_string(), singState);
        _states.add(brawlState->to_string(), brawlState);
        _states.add(sleepState->to_string(), sleepState);
       	_states.add(combatState->to_string(), combatState);
		
		//Put actor in idle state
		_stateMachine.initialState(_states.getValue(idleState->to_string()));
    }

    AiController::~AiController()
    {
    }

	bool AiController::update(float dTime)
	{
    	//all currently running states
		if(_actor->getHealth() <= 0)
		{
			sceneManager->getSceneGraph().remove(_actor->getLocation(), _actor);
			delete _actor;
			return true;
		}
		else
		{
			Vector3D* newLoc = new Vector3D(0,0,0);
			sceneManager->getSceneGraph().moveTowards(_actor, newLoc);
        	_stateMachine.tick(dTime);
		}

		return false;
    }
}
#endif
