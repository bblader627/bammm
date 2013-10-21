#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../states/state.h"
#include "../states/IdleState.h"
#include "../states/DrinkState.h"
#include "../states/BrawlState.h"
#include "../states/SleepState.h"
#include "../states/SingState.h"
#include "../states/MineState.h"
#include "../resources/hashmap.h"
#include "../actors/actor.h"
#include <string>
#include "../states/statemachine.h"

using namespace std;

namespace bammm
{
    class Controller
    {
        protected:
            HashMap<State>* _states;
            Actor* _actor;
            StateMachine* _stateMachine;

        public:
            Controller();
            void initialize(Actor* actor);
            virtual ~Controller();
    };

    Controller::Controller()
    {
        _states = new HashMap<State>();
    }

    void Controller::initialize(Actor* actor)
    {
        _actor = actor;
        _stateMachine = new StateMachine(_actor);
    }

    Controller::~Controller()
    {
        delete _states;
        delete _stateMachine;
    }
}
#endif
