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
        _actor = actor;
        _states = new HashMap<State*>();

		//Create the states
        DrinkState* drinkState = new DrinkState(_actor);
        MineState* mineState = new MineState(_actor);
        SingState* singState = new SingState(_actor);
        BrawlState* brawlState = new BrawlState(_actor);
        SleepState* sleepState = new SleepState(_actor);
        IdleState* idleState = new IdleState(_actor);

		//Put actor in idle state
        _stateMachine = new StateMachine(_actor, idleState);

        _states->add("drink", drinkState);
        _states->add("mine", mineState);
        _states->add("sing", singState);
        _states->add("brawl", brawlState);
        _states->add("sleep", sleepState);
        _states->add("idle", idleState);
    }


    void PlayerController::input(DynamicArray<string>* multiInput, float dTime)
    {
		DynamicArray<State*>* newStates = new DynamicArray<State*>();
		for(int i = 0; i < (int)multiInput->getSize(); i++)
		{
			newStates->add(_states->getValue(multiInput->get(i)));
		}
		_stateMachine->switchState(newStates);
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

        delete _states;
        delete _stateMachine;
    }
}
#endif
