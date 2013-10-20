#include "state.h"
#include "resources/hashmap.h"
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
        public:
            AiController(Actor actor);
            void intialize();
            void update();
    };

    AiController::AiController()
    {
    }

    void AiController::initialize(Actor* actor)
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


    void AiController::update()
    {
        stateMachine->switchState(stateMachine->getCurrentState(), 
                                 _states->get(multiInput.get(i)));
    }
}
