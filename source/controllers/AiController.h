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
            void update();
            void setup(Actor* actor);
            virtual ~AiController();
    };

    AiController::AiController()
    {
    }

    void AiController::setup(Actor* actor)
    {
        _stateMachine = new StateMachine(actor);
        _states = new HashMap<State*>();
        _actor = actor;
        counter = 0;

        DrinkState* drinkState = new DrinkState();
        MineState* mineState = new MineState();
        SingState* singState = new SingState();
        BrawlState* brawlState = new BrawlState();
        SleepState* sleepState = new SleepState();
        IdleState* idleState = new IdleState();

        _states->add("drink", drinkState);
        _states->add("mine", mineState);
        _states->add("sing", singState);
        _states->add("brawl", brawlState);
        _states->add("sleep", sleepState);
        _states->add("idle", idleState);
    }


    void AiController::update()
    {
        string newState;
        DynamicArray<State*>* currentStates = _stateMachine->getCurrentStates();

        if(currentStates->getSize() > 1 && currentStates->get(0) != _states->getValue("idle"))
        {
            return;
        }

        if(counter == 0)
        {
            newState = "idle";
            counter = 1;
        }
        else if(counter == 1 || counter == 3)
        {
           newState = "drink"; 
           counter++;
        }
        else if(counter == 2)
        {
            newState = "mine";
            counter++;
        }
        else if(counter == 3)
        {
            int random = rand() % 100 + 1;
            if(random <= 33)
            {
                newState = "sleep";
                counter = 0;
            }
            else
            {
                if(random <= 66)
                {
                    newState = "brawl";
                }
                else
                {
                    newState = "sing";
                }
                counter = 2;
            }
        }
        State* newAddState = _stateMachine->getCurrentStates()->get(0);
        State* oldState = _states->getValue(newState);
        _stateMachine->switchState(oldState, newAddState);
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
