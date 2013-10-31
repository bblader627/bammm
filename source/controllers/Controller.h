/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski	
 *   Bradley Crusco
 * Description:
 * Controller header file.
 *
 * Last Modified: Matt Witkowski
 *
 */



#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../states/state.h"
#include "../states/IdleState.h"
#include "../states/DrinkState.h"
#include "../states/BrawlState.h"
#include "../states/SleepState.h"
#include "../states/SingState.h"
#include "../states/MineState.h"
#include "../states/CombatState.h"
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
            HashMap<State*>* _states;
            Actor* _actor;
            StateMachine* _stateMachine;

        public:
            Controller();
            void setup(Actor* actor);
            virtual ~Controller();
    };

    Controller::Controller()
    {
    }

    void Controller::setup(Actor* actor)
    {
    }

    Controller::~Controller()
    {
    }
}
#endif
