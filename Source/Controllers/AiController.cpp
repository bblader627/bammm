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
 * AiController cpp file.
 *
 */

#include "AiController.h"

namespace bammm
{
	AiController::AiController()
	{
	}

	void AiController::setup(Actor& actor, MeleeCombat& meleeCombat,
			Grid3D<Actor*>& sceneGraph)
	{
		_sceneGraph = &sceneGraph;
		_meleeCombat = &meleeCombat;
		_actor = &actor;
		_stateMachine.setup(actor, _states);

		//Create the states
		DrinkState* drinkState = new DrinkState(actor, _stateMachine);
		MineState* mineState = new MineState(actor, _stateMachine);
		SingState* singState = new SingState(actor, _stateMachine);
		BrawlState* brawlState = new BrawlState(actor, _stateMachine);
		SleepState* sleepState = new SleepState(actor, _stateMachine);
		IdleState* idleState = new IdleState(actor, _stateMachine);
		CombatState* combatState = new CombatState(actor, _stateMachine);
		MoveState* moveState = new MoveState(actor, _stateMachine,
				sceneGraph);

		_states.add(idleState->toString(), idleState);
		_states.add(mineState->toString(), mineState);
		_states.add(drinkState->toString(), drinkState);
		_states.add(singState->toString(), singState);
		_states.add(brawlState->toString(), brawlState);
		_states.add(sleepState->toString(), sleepState);
		_states.add(combatState->toString(), combatState);
		_states.add(moveState->toString(), moveState);

		//Put actor in idle state
		_stateMachine.initialState(_states.getValue(idleState->toString()));
	}

	AiController::~AiController()
	{
		//Prevents deletion of dead units for now
		//SceneManager::getSceneGraph().remove(_actor->getLocation(), _actor);
		delete _actor;
	}

	bool AiController::canDelete()
	{
		if (_actor->getHealth() <= 0)
		{
			return true;
		}

		return false;
	}

	void AiController::tick(float deltaTime)
	{
		DynamicArray<State*>& currentStates = _stateMachine.getCurrentStates();
		State* newState = _states.getValue("movement");
		
		//all currently running states
		if (!currentStates.contains(newState))
		{
			_stateMachine.addState(newState);
		}
		else
		{
			//Random number generator
			random_device rd;
			mt19937 generator(rd());

			uniform_int_distribution<int> randomDistribution(0,4);

			//Pick a random direction
			int random = randomDistribution(generator);
			Vector3D newLoc(0,0,0);
			if(random == 0)
			{
				newLoc.set(1,0,0);
			}
			else if(random == 1)
			{
				newLoc.set(-1,0,0);
			}
			else if(random == 2)
			{
				newLoc.set(0,1,0);
			}
			else if(random == 3)
			{
				newLoc.set(0,-1,0);
			}
			newState->setup(newLoc);
		}
		_stateMachine.tick(deltaTime);
	}
}
