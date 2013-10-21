#include "../states/state.h"
#include "resources/hashmap.h"
#include "../actors/actor.h"
#include <string>
#include "../statemachine.h"

using namespace std;

namespace bammm
{
    class Controller
    {
        private:
            Hashmap<string, State>* _states;
            Actor* _actor;
            StateMachine* _stateMachine;

        public:
            void intialize(Actor* actor);
            ~Controller();
    };

    Controller::Controller()
    {
        _states = new Hashmap<string, State>();
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
