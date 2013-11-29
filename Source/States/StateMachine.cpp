/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *	Bradley Crusco
 * Description:
 * StateMachine cpp file.
 *
 */

#include "StateMachine.h"


namespace bammm
{
	StateMachine::StateMachine()
	{
	}

	StateMachine::~StateMachine()
	{
	}

	StateMachine::StateMachine(Actor& actor, HashMap<State*>& allStates)
	{
		_actor = &actor;
		_allStates = &allStates;
	}

	void StateMachine::setup(Actor& actor, HashMap<State*>& allStates, MeleeCombat* meleeCombat)
	{
		_actor = &actor;
		_allStates = &allStates;
		_meleeCombat = meleeCombat;

	}

	void StateMachine::initialState(State* initial)
	{
		initial->setup(new DynamicArray<string>());
		currentStates.add(initial);
	}

	void StateMachine::tick(float dTime)
	{
		for (int i = 0; i < (int) currentStates.getSize(); i++)
		{
			currentStates.get(i)->tick(dTime);
		}
	}

	void StateMachine::switchState(State& current, State& newState)
	{
		removeState(&current);
		addState(&newState, new DynamicArray<string>());
	}

	void StateMachine::switchState(State& current, string newStateString)
	{
		if (newStateString == "null")
		{
			removeState(&current);
			return;
		}
		switchState(current, *_allStates->getValue(newStateString));
	}

	void StateMachine::addState(State* newState)
	{
		if (currentStates.contains(newState))
		{
			if (newState->toString() == "combat")
			{
				//test for fight hapening
				if (!_meleeCombat->fightHappening())
				{
					this->removeState(newState);

				}
				else
				{
					_meleeCombat->useTurn();
				}
			}
			else
			{
				//breakdown and setup are not calling the correct functions
				this->removeState(newState);
			}
		}
		else
		{
			//Special case for combat state
			if (newState->toString() == "combat")
			{
				/*Actor* closestEnemy = SceneManager::getSceneGraph().getEnemy(_actor->getLocation(), _actor);
				 if(closestEnemy)
				 {
				 _meleeCombat->setup(*_actor, *closestEnemy);
				 }*/
			}
			cout << "poop" << endl;
			newState->setup(new DynamicArray<string>());
			currentStates.add(newState);
		}
	}

	void StateMachine::addState(State* newState, DynamicArray<string>* args)
	{
		if (currentStates.contains(newState))
		{
			if (newState->toString() == "combat")
			{
				//test for fight hapening
				if (!_meleeCombat->fightHappening())
				{
					this->removeState(newState);

				}
				else
				{
					_meleeCombat->useTurn();
				}
			}
			else
			{
				//breakdown and setup are not calling the correct functions
				this->removeState(newState);
			}
		}
		else
		{
			//Special case for combat state
			if (newState->toString() == "combat")
			{
				/*Actor* closestEnemy = SceneManager::getSceneGraph().getEnemy(_actor->getLocation(), _actor);
				 if(closestEnemy)
				 {
				 _meleeCombat->setup(*_actor, *closestEnemy);
				 }*/
			}
			newState->setup(args);
			currentStates.add(newState);
		}
	}
	void StateMachine::removeState(State* oldState)
	{
		oldState->breakdown();
		currentStates.removeElement(oldState);
	}

	DynamicArray<State*>& StateMachine::getCurrentStates()
	{
		return currentStates;
	}

	string StateMachine::toString()
	{
		return "statemachine";
	}
}
