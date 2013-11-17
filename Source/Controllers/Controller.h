/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski	
 *  Bradley Crusco
 * Description:
 * Controller header file.
 *
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <string>
#include "../States/State.h"
#include "../States/IdleState.h"
#include "../States/DrinkState.h"
#include "../States/BrawlState.h"
#include "../States/SleepState.h"
#include "../States/SingState.h"
#include "../States/MineState.h"
#include "../States/CombatState.h"
#include "../Resources/HashMap.h"
#include "../Actors/Actor.h"
#include "../States/StateMachine.h"

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
			virtual ~Controller();

			/**
			 setup
			 @Pre-Condition- Takes an actor as input
			 @Post-Condition- Actor passed as argument is setup for use
			 */
			void setup(Actor* actor);
	};

	Controller::Controller()
	{
	}

	Controller::~Controller()
	{
	}

	void Controller::setup(Actor* actor)
	{
	}
}

#endif
