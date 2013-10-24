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
 * Last Modified: Matt Witkowski
 *
 */


#ifndef PLAYERCONTROLLER_H_
#define PLAYERCONTROLLER_H_

#include "Controller.h"
#include "../states/statemachine.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

using namespace std;
using namespace bammm;

namespace bammm
{
    class PlayerController : public Controller
    {
        public:
            void input(DynamicArray<string> command);
            void input(string command);
            PlayerController();
            void setup(Actor* actor);
            virtual ~PlayerController();
    };

    PlayerController::PlayerController()
    {
    }

    void PlayerController::setup(Actor* actor)
    {
        _actor = actor;
        _states = new HashMap<State*>();
        _stateMachine = new StateMachine(_actor);

        DrinkState* drinkState = new DrinkState();
        MineState* mineState = new MineState();
        SingState* singState = new SingState();
        BrawlState* brawlState = new BrawlState();
        SleepState* sleepState = new SleepState();
        IdleState* idleState = new IdleState();

        //_actor begins in idleState
        //addState causes seg fault
        _stateMachine->addState(idleState);
        _stateMachine->switchState(NULL, idleState);

        _states->add("drink", drinkState);
        _states->add("mine", mineState);
        _states->add("sing", singState);
        _states->add("brawl", brawlState);
        _states->add("sleep", sleepState);
        _states->add("idle", idleState);
    }


    void PlayerController::input(DynamicArray<string> multiInput)
    {
		State* newState = _states->getValue(multiInput.get(0));
		State* oldState = _stateMachine->getCurrentStates()->get(0);

		_stateMachine->switchState(oldState, newState);
    }

    void PlayerController::input(string command)
    {
        DynamicArray<string> passValue;
        passValue.add(command);
        input(passValue);
    }

    PlayerController::~PlayerController()
    {
        DynamicArray<State*>* temp = _states->getAllValues();
        for(int i = 0; i < (int)temp->getSize(); i++)
        {
            delete temp->get(i);
        }

        delete _states;
        delete _stateMachine;
    }
}
#endif
