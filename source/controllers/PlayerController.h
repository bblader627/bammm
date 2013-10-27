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
            void printOptions();
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

        _states->add("idle", idleState);
        _states->add("mine", mineState);
        _states->add("drink", drinkState);
        _states->add("sing", singState);
        _states->add("brawl", brawlState);
        _states->add("sleep", sleepState);

    }


    void PlayerController::input(DynamicArray<string>* multiInput, float dTime)
    {
    	//all currently running states
    	DynamicArray<State*>* currentStates = _stateMachine->getCurrentStates();

    	//newStates will have 1 state
		//DynamicArray<State*>* newStates = new DynamicArray<State*>();

		for(int i = 0; i < (int)multiInput->getSize(); i++)
		{
			//newStates->add(_states->getValue(multiInput->get(i)));

			//Check to see if state is already running
			//if so, break it down

			State* newState = _states->getValue(multiInput->get(i));
			if (currentStates->contains(newState))
			{
				//switching newState with NULL calls breakdown on newState, the remove on currentStates
				//_stateMachine->switchState(newState, NULL);

				newState->breakdown();
				currentStates->removeElem(newState);
			}
			else
			{
				_stateMachine->addState(newState);
			}

		}

		//Should input even call switchstate?
		//_stateMachine->switchState(newStates);
        _stateMachine->tick(dTime);
    }

    void PlayerController::input(string command, float dTime)
    {
        DynamicArray<string>* passValue = new DynamicArray<string>();
        passValue->add(command);
        input(passValue, dTime);
		delete passValue;
    }

    void PlayerController::printOptions()
    {
    	DynamicArray<State*>* currentStates = _stateMachine->getCurrentStates();
    	/*

    	}
    	*/
    	//MAKE THIS SMARTER
    	cout << "Select an activity for your dwarf:" << endl;

		//Mining gold options
    	if (currentStates->contains(_states->getValue("mine")))
		{
			cout << "1. Stop mining gold" << endl;
		}
		else
		{
			cout << "1. Mine Gold" << endl;
		}

    	//Drinking options
    	if (currentStates->contains(_states->getValue("drink")))
		{
			cout << "2. Stop drinking ale" << endl;
		}
		else
		{
			cout << "2. Drink ale" << endl;
		}

    	//Singing options
    	if (currentStates->contains(_states->getValue("sing")))
    	{
    		cout << "3. Stop signing" << endl;
    	}
    	else
    	{
    		cout << "3. Sing a song" << endl;
    	}

    	//Fighting options
    	if (currentStates->contains(_states->getValue("brawl")))
    	{
    		cout << "4. Stop fighting" << endl;
    	}
    	else
    	{
    		cout << "4. Fight a dwarf" << endl;
    	}


    	//Fighting options
		if (currentStates->contains(_states->getValue("sleep")))
		{
			cout << "5. Wake up" << endl;
		}
		else
		{
			cout << "5. Go to sleep" << endl;
		}

    	cout << "0. Quit" << endl;
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
