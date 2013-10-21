#ifndef AICONTROLLER_H_
#define AI_CONTROLLER_H_

#include "Controller.h"
using namespace std;

namespace bammm
{
    class AiController : Controller
    {
        private:

        public:
            AiController();
            void update();
            uint counter = 0;
            ~AiController();
    };

    AiController::AiController()
    {
    }

    void AiController::initialize(Actor* actor)
    {
        _actor = actor;
        
        DrinkState drinkState;
        MineState mineState;
        SingState singState;
        BrawlState brawlState;
        SleepState sleepState;
        IdleState idleState;

        _states.add("drink", drinkState);
        _states.add("mine", mineState);
        _states.add("sing", singState);
        _states.add("brawl", brawlState);
        _states.add("sleep", sleepState);
        _states.add("idle", idleState);
    }


    void AiController::update()
    {
        string newState;
        int random;

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
            random = rand() % 100 + 1;
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

        stateMachine->switchState(stateMachine->getCurrentState(), 
                                 _states->get(newState));
    }

    virtual AiController::~AiController()
    {
    }
}
#endif
