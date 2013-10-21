#ifndef AICONTROLLER_H_
#define AI_CONTROLLER_H_
#include "Controller.h"
#include "../statemachine.h"
using namespace std;

namespace bammm
{
    class AiController : public Controller
    {
        private:

        public:
            AiController();
            void update();
            uint counter;
            void initialize(Actor* actor);
            virtual ~AiController();
    };

    AiController::AiController()
    {
    }

    void AiController::initialize(Actor* actor)
    {
        _actor = actor;
        counter = 0;

        DrinkState drinkState;
        MineState mineState;
        SingState singState;
        BrawlState brawlState;
        SleepState sleepState;
        IdleState idleState;

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
        DynamicArray<State> currentStates = stateMachine->getCurrentStates();
        int random;

        if(currentStates.size() > 1 && currentStates.get(0) != _states->getValue("idle"))
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
        //State* oldState = stateMachine->getCurrentState().get(0);
        //State* newAddState = _states->getValue(newState);
        //stateMachine->switchState(oldState, newAddState);
    }

    AiController::~AiController()
    {
    }
}
#endif
