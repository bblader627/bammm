#include "state.h"
#include "hashmap.h"
#include "actor.h"
#include <string>
#include "statemachine.h"

using namespace std;

namespace bammm
{
    class AiController
    {
        private:
            Hashmap<string, State>* _states;
            Actor* _actor;
            StateMachine* _stateMachine;
            DrinkState* drinkState;
            MineState* mineState;
            SingState* singState;
            BrawlState* brawlState;
            SleepState* sleepState;
            IdleState* idleState;

        public:
            AiController(Actor actor);
            void intialize();
            void update();
            uint counter = 0;
    };

    AiController::AiController()
    {
    }

    void AiController::initialize(Actor* actor)
    {
        _states = new Hashmap<string, State>();
        _stateMachine = new StateMachine();
        _actor = actor;
        
        drinkState = new DrinkState;
        mineState = new MineState;
        singState = new SingState;
        brawlState = new BrawlState;
        sleepState = new SleepState;
        idleState = new IdleState;

        _states.add("drink", *drinkState);
        _states.add("mine", *mineState);
        _states.add("sing", *singState);
        _states.add("brawl", *brawlState);
        _states.add("sleep", *sleepState);
        _states.add("idle", *idleState);
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
}
