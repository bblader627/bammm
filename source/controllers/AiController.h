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
 * AIController header file.
 *
 * Last Modified: Matt Witkowski
 *
 */


#ifndef AICONTROLLER_H_
#define AI_CONTROLLER_H_
#include "Controller.h"
#include "../states/statemachine.h"
using namespace std;

namespace bammm
{
    class AiController : public Controller
    {
        private:
            uint counter;

        public:
            AiController();
            void update(float dTime);
            void setup(Actor* actor);
            virtual ~AiController();
    };

    AiController::AiController()
    {
    }

    void AiController::setup(Actor* actor)
    {
        //_stateMachine = new StateMachine(actor);
        _states = new HashMap<State*>();
        _actor = actor;
        counter = 0;
		
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
		//_stateMachine->switchState(NULL, idleState);

		//Add states to hashMap
        _states->add("drink", drinkState);
        _states->add("mine", mineState);
        _states->add("sing", singState);
        _states->add("brawl", brawlState);
        _states->add("sleep", sleepState);
        _states->add("idle", idleState);
    }


    void AiController::update(float dTime)
    {
        /*string newStateStr;
        DynamicArray<State*>* currentStates = _stateMachine->getCurrentStates();

        if(currentStates->getSize() > 1 && currentStates->get(0) != _states->getValue("idle"))
        {
            return;
        }

        if(counter == 0)
        {
            newStateStr = "idle";
            counter = 1;
        }
        else if(counter == 1 || counter == 3)
        {
           newStateStr = "drink"; 
           counter++;
        }
        else if(counter == 2)
        {
            newStateStr = "mine";
            counter++;
        }
        else if(counter == 3)
        {
            int random = rand() % 100 + 1;
            if(random <= 33)
            {
                newStateStr = "sleep";
                counter = 0;
            }
            else
            {
                if(random <= 66)
                {
                    newStateStr = "brawl";
                }
                else
                {
                    newStateStr = "sing";
                }
                counter = 2;
            }
        }
        State* newState = _stateMachine->getCurrentStates()->get(0);
        State* oldState = _states->getValue(newStateStr);
        _stateMachine->switchState(oldState, newState);
		_stateMachine->tick(dTime);*/
    }

    AiController::~AiController()
    {
        DynamicArray<State*>* temp = _states->getAllValues();
        for(int i = 0; i < (int) temp->getSize(); i++)
        {
            delete temp->get(i);
        }
        delete _states;
        delete _stateMachine;
    }
}
#endif
