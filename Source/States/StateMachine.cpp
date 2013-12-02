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
		initial->setup();
		currentStates.add(initial);
	}

	void StateMachine::tick(float dTime)
	{
		cout << "In StateMachine's tick;" << endl;
		for (int i = 0; i < (int) currentStates.getSize(); i++)
		{
			cout << "tick " << currentStates.get(i)->toString() << endl;
			currentStates.get(i)->tick(dTime);
			cout << "End tick" << endl;
		}
	}

	void StateMachine::switchState(State& current, State& newState)
	{
		removeState(&current);
		addState(&newState);
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
			newState->setup();
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
