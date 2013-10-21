#ifndef PLAYERCONTROLLER_H_
#define PLAYERCONTROLLER_H_

#include "Controller.h"
using namespace std;

namespace bammm
{
    class PlayerController : Controller
    {
        private:
            
        public:
            void input(DynamicArray<string> command);
            PlayerController();
            ~PlayerController();
    };

    PlayerController::PlayerController()
    {
    }

    void PlayerController::initialize(Actor* actor)
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


    void PlayerController::input(DynamicArray<string> multiInput)
    {
        for(uint i = 0; i < multiInput.getSize(); i++)
        {
            stateMachine->switchState(stateMachine->getCurrentStates(), 
                                        _states->get(multiInput.get(i)));
        }
    }

    virtual PlayerController::~PlayerController()
    {
    }
}
#endif
