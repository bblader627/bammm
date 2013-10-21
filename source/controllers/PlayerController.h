#ifndef PLAYERCONTROLLER_H_
#define PLAYERCONTROLLER_H_

#include "Controller.h"
#include "../states/statemachine.h"
using namespace std;
using namespace bammm;

namespace bammm
{
    class PlayerController : public Controller
    {
        public:
            void input(DynamicArray<string> command);
            void input(string command);
            PlayerController();
            void setup(Actor* actor);
            virtual ~PlayerController();
    };

    PlayerController::PlayerController()
    {
    }

    void PlayerController::setup(Actor* actor)
    {
        _actor = actor;
        _states = new HashMap<State>();
        _stateMachine = new StateMachine(_actor);

        DrinkState drinkState;
        MineState mineState;
        SingState singState;
        BrawlState brawlState;
        SleepState sleepState;
        IdleState idleState;

        //_actor begins in idleState
        _stateMachine->addState(&idleState);

        _states->add("drink", drinkState);
        _states->add("mine", mineState);
        _states->add("sing", singState);
        _states->add("brawl", brawlState);
        _states->add("sleep", sleepState);
        _states->add("idle", idleState);
    }


    void PlayerController::input(DynamicArray<string> multiInput)
    {
		State temp1 = _states->getValue(multiInput.get(0));
		State temp2 = _stateMachine->getCurrentStates().get(0);
		State* newState = &temp1;
		State* oldState = &temp2;
		_stateMachine->switchState(oldState, newState);
    }

    void PlayerController::input(string command)
    {
        DynamicArray<string> passValue;
        passValue.add(command);
        input(passValue);    
    }

    PlayerController::~PlayerController()
    {
        delete _states;
        delete _stateMachine;
    }
}
#endif
