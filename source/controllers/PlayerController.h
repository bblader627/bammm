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
            void initialize(Actor* actor);
            virtual ~PlayerController();
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

        _states->add("drink", drinkState);
        _states->add("mine", mineState);
        _states->add("sing", singState);
        _states->add("brawl", brawlState);
        _states->add("sleep", sleepState);
        _states->add("idle", idleState);
    }


    void PlayerController::input(DynamicArray<string> multiInput)
    {
        //State* newState = &_states->get(multiInput.get(0));
        //State* oldState = &_stateMachine->getCurrentStates().get(0);
        //_stateMachine->switchState(oldState, newState);
    }
    PlayerController::~PlayerController()
    {
    }
}
#endif
