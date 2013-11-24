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
#include "../Weapons/MeleeCombat.h"
#include "../Weapons/RangedCombat.h"
#include "../SceneManager/SceneManager.h"

using namespace std;

namespace bammm
{
    class Controller
    {
        protected:
            HashMap<State*> _states;
            Actor* _actor;
            StateMachine _stateMachine;
			MeleeCombat* _meleeCombat;
			RangedCombat* _rangedCombat;
			SceneManager* _sceneManager;

        public:
            Controller();
			virtual ~Controller();
			
			/**Fix
			 setup
			 @Pre-Condition- Takes an Actor, SceneManager, and MeleeCombat as input
			 @Post-Condition - Sets up the controller with the passed Actor.
			 */            
			virtual void setup(Actor& actor, SceneManager& scene, MeleeCombat& meleeCombat)=0;
			/**
			 canDelete
			 @Pre-Condition- Takes nothing
			 @Post-Condition- Returns a boolean representing fi the Controller can be deleted or not.
			 */
			virtual bool canDelete()=0;
    };

    Controller::Controller()
    {
    }

    Controller::~Controller()
    {
		DynamicArray<string>* keys = _states.getAllKeys();
		int size = keys->getSize();
		for(int i = 0; i < size; i++)
		{
			delete _states.getValue(keys->get(i));
		}
		
		delete keys;
    }
}
#endif
