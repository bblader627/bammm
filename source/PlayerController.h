#include "state.h"
#include "hashmap.h"
#include "actor.h"
#include <string>
#include "statemachine.h"

using namespace std;

namespace bammm
{
    class PlayerController
    {
        private:
            Hashmap<string, State>* _states;
            Actor* _actor;
            StateMachine* _stateMachine;
        public:
            PlayerController(Actor actor);
            void input(DynamicArray<string> command);
            void intialize();
    };

    PlayerController::PlayerController()
    {
    }

    void PlayerController::initialize(Actor* actor)
    {
        _states = new Hashmap<string, State>();
        _stateMachine = new StateMachine();
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
}
