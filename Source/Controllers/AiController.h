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
 * AiController header file.
 *
 */

#ifndef AICONTROLLER_H_
#define AICONTROLLER_H_

#include <random>
#include "Controller.h"
#include "../States/StateMachine.h"
#include "../SceneManager/SceneManager.h"
#include "../Weapons/MeleeCombat.h"
#include "../Weapons/RangedCombat.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

using namespace std;

namespace bammm
{
	class AiController: public Controller
	{
		private:
			MeleeCombat* _meleeCombat;
			RangedCombat* _rangedCombat;
			SceneManager* _sceneManager;

		public:
			AiController(SceneManager* scene, MeleeCombat* meleeCombat);
			~AiController();

			/**
			 setup
			 @Pre-Condition- Takes an actor as input
			 @Post-Condition- Actor passed as argument is setup for use
			 */
			void setup(Actor* actor);

			/**
			 update
			 @Pre-Condition- Takes a float delta time (change in time) as input
			 @Post-Condition- Updates are executed based on the deltaTime
			 */
			bool update(float deltaTime);
	};

	AiController::AiController(SceneManager* scene, MeleeCombat* meleeCombat)
	{
		_sceneManager = scene;
		_meleeCombat = meleeCombat;
	}

	AiController::~AiController()
	{
		DynamicArray<State*>* temp = _states->getAllValues();
		for (int i = 0; i < (int) temp->getSize(); i++)
		{
			delete temp->get(i);
		}

		delete _states;
		delete _stateMachine;
	}

	void AiController::setup(Actor* actor)
	{
		_actor = actor;
		_states = new HashMap<State*>();
		_stateMachine = new StateMachine(_actor, _states);

		//Create the states
		//DO NOT DELETE THE REFERENCES TO STATEMACHINE. THE CODE WILL SEG FAULT IF YOU DO
		DrinkState* drinkState = new DrinkState(_actor, _stateMachine);
		MineState* mineState = new MineState(_actor, _stateMachine);
		SingState* singState = new SingState(_actor, _stateMachine);
		BrawlState* brawlState = new BrawlState(_actor, _stateMachine);
		SleepState* sleepState = new SleepState(_actor, _stateMachine);
		IdleState* idleState = new IdleState(_actor, _stateMachine);
		CombatState* combatState = new CombatState(_actor, _stateMachine);

		//Put actor in idle state
		_stateMachine->initialState(idleState);

		_states->add(idleState->to_string(), idleState);
		_states->add(mineState->to_string(), mineState);
		_states->add(drinkState->to_string(), drinkState);
		_states->add(singState->to_string(), singState);
		_states->add(brawlState->to_string(), brawlState);
		_states->add(sleepState->to_string(), sleepState);
		_states->add(combatState->to_string(), combatState);
	}

	bool AiController::update(float deltaTime)
	{
		//All currently running states
		if (_actor->getHealth() <= 0)
		{
			_sceneManager->getSceneGraph()->remove(_actor->getLocation(),
					_actor);
			delete _actor;
			return true;
		}
		else
		{
			Vector3D* newLoc = new Vector3D(0, 0, 0);
			cout << "Before Graph\n";
			_sceneManager->getSceneGraph()->moveTowards(_actor, newLoc);
			cout << "After Graph\n";
			_stateMachine->tick(deltaTime);
		}

		return false;
	}
}

#endif
