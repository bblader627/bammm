#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../states/state.h"
#include "../resources/hashmap.h"
#include "../actors/actor.h"
#include <string>
#include "../statemachine.h"

using namespace std;

namespace bammm
{
    class Controller
    {
        private:
            HashMap<string, State>* _states;
            Actor* _actor;
            StateMachine* _stateMachine;

        public:
            void intialize(Actor* actor);
            ~Controller();
    };

    Controller::Controller()
    {
        _states = new HashMap<string, State>();
        _stateMachine = new StateMachine();
    }

    void Controller::initialize(Actor* actor)
    {
        _actor = actor;
    }

    virtual Controller::~Controller()
    {
        delete _states;
        delete _stateMachine;
    }
}
#endif
