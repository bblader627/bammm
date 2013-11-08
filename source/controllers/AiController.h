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
#include "../states/StateMachine.h"
#include "../resources/Grid3D.h"
#include "../weapons/MeleeCombat.h"
#include "../weapons/RangedCombat.h"
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
			Grid3d<Actor*>* grid;
        public:
            AiController(Grid3d<Actor*>* theGrid, MeleeCombat* meleeC);
            void setup(Actor* actor);
			bool update(float dTime);
            ~AiController();
    };

    AiController::AiController(Grid3d<Actor*>* theGrid, MeleeCombat* meleeC)
    {
		grid = theGrid;
		meleeCombat = meleeC;
    }

    void AiController::setup(Actor* actor)
    {
        _actor = actor;
        _states = new HashMap<State*>();
        _stateMachine = new StateMachine(_actor, _states);

		//Create the states
        //DO NOT DELETE THE REFERENCES TO STATEMACHINE.  THE CODE WILL SEG FAULT IF YOU DO
        DrinkState* drinkState = new DrinkState(_actor, _stateMachine);
        MineState* mineState = new MineState(_actor, _stateMachine);
        SingState* singState = new SingState(_actor, _stateMachine);
        BrawlState* brawlState = new BrawlState(_actor, _stateMachine);
        SleepState* sleepState = new SleepState(_actor, _stateMachine);
        IdleState* idleState = new IdleState(_actor, _stateMachine);
		CombatState* combatState = new CombatState(_actor, _stateMachine);

		//Put actor in idle state
		_stateMachine->initialState(idleState);

        _states->add(idleState->to_string(), idleState);
        _states->add(mineState->to_string(), mineState);
        _states->add(drinkState->to_string(), drinkState);
        _states->add(singState->to_string(), singState);
        _states->add(brawlState->to_string(), brawlState);
        _states->add(sleepState->to_string(), sleepState);
       	_states->add(combatState->to_string(), combatState);
    }

    AiController::~AiController()
    {
        DynamicArray<State*>* temp = _states->getAllValues();
        for(int i = 0; i < (int)temp->getSize(); i++)
        {
            delete temp->get(i);
        }

        delete _states;
        delete _stateMachine;
    }

	bool AiController::update(float dTime)
	{
    	//all currently running states
		if(_actor->getHealth() <= 0)
		{
			grid->remove(_actor->getLocation(), _actor);
			delete _actor;
			return true;
		}
		else
		{
			Vector3D* newLoc = new Vector3D(0,0,0);
			grid->moveTowards(_actor, newLoc);
        	_stateMachine->tick(dTime);
		}

		return false;
    }
}
#endif
