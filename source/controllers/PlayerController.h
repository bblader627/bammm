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
            void input(DynamicArray<string>* command, float dTime);
            void input(string command, float dTime);
            PlayerController();
            void setup(Actor* actor);
            ~PlayerController();
    };

    PlayerController::PlayerController()
    {
    }

    void PlayerController::setup(Actor* actor)
    {
        cout << "Setup was called\n";
        _actor = actor;
        _states = new HashMap<State*>();
        _stateMachine = new StateMachine(_actor);

		//Create the states
        DrinkState* drinkState = new DrinkState();
        MineState* mineState = new MineState();
        SingState* singState = new SingState();
        BrawlState* brawlState = new BrawlState();
        SleepState* sleepState = new SleepState();
        IdleState* idleState = new IdleState();

		//Setup the states
		drinkState->setup(_actor);
		mineState->setup(_actor);
		singState->setup(_actor);
		brawlState->setup(_actor);
		sleepState->setup(_actor);
		idleState->setup(_actor);

        //Add states to _stateMachine to be ticked
        _stateMachine->addState(idleState);
		_stateMachine->addState(drinkState);
		_stateMachine->addState(mineState);
		_stateMachine->addState(singState);
		_stateMachine->addState(brawlState);
		_stateMachine->addState(sleepState);

		//Put actor in idle state
        _stateMachine->switchState(NULL, idleState);

        _states->add("drink", drinkState);
        _states->add("mine", mineState);
        _states->add("sing", singState);
        _states->add("brawl", brawlState);
        _states->add("sleep", sleepState);
        _states->add("idle", idleState);
    }


    void PlayerController::input(DynamicArray<string>* multiInput, float dTime)
    {
		State* newState = _states->getValue(multiInput->get(0));
		State* oldState = _stateMachine->getCurrentStates()->get(0);
		_stateMachine->switchState(oldState, newState);
        _stateMachine->tick(dTime);
    }

    void PlayerController::input(string command, float dTime)
    {
        DynamicArray<string>* passValue = new DynamicArray<string>();
        passValue->add(command);
        input(passValue, dTime);
		delete passValue;
    }

    PlayerController::~PlayerController()
    {
        DynamicArray<State*>* temp = _states->getAllValues();
        for(int i = 0; i < (int)temp->getSize(); i++)
        {
            delete temp->get(i);
        }

        //delete _states;
        delete _stateMachine;
    }
}
#endif
