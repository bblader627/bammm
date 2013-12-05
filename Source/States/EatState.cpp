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
 * EatState cpp file.
 *
 */

#include "EatState.h"

namespace bammm
{
	EatState::EatState(Actor& actor)
	{
		_actor = &actor;
	}

	EatState::EatState(Actor& actor, IStateCallback* stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	void EatState::setup()
	{
	}

	void EatState::breakdown()
	{
		cout << _actor->getName() << " is finished eating!" << endl;
	}

	void EatState::setAmount(int amount)
	{
		_amount = amount;
	}

	void EatState::setType(string type)
	{
		_food = type;
	}

	void EatState::tick(float deltaTime)
	{
		if (canEat())
		{
			if (_food == "fish")
			{
				Item iron("fish");
				Item* removedItem = _actor->getInventory().removeItem(iron);
				if (removedItem == NULL)
				{
					switchState("null");
					return;
				}
				else
				{
					_actor->increaseHealth(5);
					_actor->increaseStamina(5);
					cout << _actor->getName() << " takes a bite of " << _food << "! "
							<<  "His health and stamina increased by 5" << endl;

					if (_actor->getHealth() >= _actor->getMaximumHealth())
					{
						_actor->setHealth(_actor->getMaximumHealth());
						cout << _actor->getName() << " is too full to continue eating." << endl;
						switchState("null");
					}
				}
			}
		}
		else
		{
			cout << _actor->getName() << " doesn't have any " << _food << "!" << endl;
			switchState("null");
		}
	}

	void EatState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string EatState::toString()
	{
		return "eat";
	}

	bool EatState::canEat()
	{
		int canEat = 0;

		if (_amount > 0)
		{
			Item fish("fish");
			if(_actor->getInventory().contains(fish))
			{
				canEat++;
			}
		}

		return !!canEat;
	}
}
