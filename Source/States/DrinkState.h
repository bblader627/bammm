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
 * DrinkState header file.
 *
 */

#ifndef DRINKSTATE_H_
#define DRINKSTATE_H_

#include "State.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

using namespace std;

namespace bammm
{
	class DrinkState: public State
	{
		private:
			static const uint stoutSize = 5;
			uint _stoutLife;

		public:
			DrinkState(Actor& actor);
			DrinkState(Actor& actor, IStateCallback& stateMachine);

			/**
			 setup
			 @Pre-Condition- No input
			 @Post-Condition- Sets up the state
			 */
			virtual void setup();

			/**
			 breakdown
			 @Pre-Condition- No input
			 @Post-Condition- Performs a breakdown on the state
			 */
			void breakdown();

			/**
			 tick
			 @Pre-Condition- Takes in a float deltaTime
			 @Post-Condition- Executes a tick of length deltaTime
			 */
			virtual void tick(float deltaTime);

			/**
			 switchState
			 @Pre-Condition- Takes in a string nextState
			 @Post-Condition- The current state is switched to the given nextState
			 */
			void switchState(string nextState);

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string representation of the state
			 */
			string toString();
	};

	DrinkState::DrinkState(Actor& actor)
	{
		_actor = &actor;

	}

	DrinkState::DrinkState(Actor& actor, IStateCallback& stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	void DrinkState::setup()
	{
		_stoutLife = stoutSize;
	}

	void DrinkState::breakdown()
	{
		double BAC = _actor->getBAC();
		if (BAC < 0.1)
		{
			//Do nothing
		}
		else if (BAC < 0.25)
		{
			cout << _actor->getName()
					<< " puts down his drink.  He's slightly tipsy, but is ready to get back to work!"
					<< endl;
		}
		else if (BAC < 0.35)
		{
			_actor->incrementBAC();
			cout << _actor->getName()
					<< " finishes his sloppily drink and slams it down on the counter, ready to go out and explore the village."
					<< endl;
		}
		else if (BAC < 0.5)
		{
			_actor->reduceHealth(2);
			cout << _actor->getName()
					<< " is very drunk.  He gets up to leave and falls over a table before making his way out the door."
					<< endl;
		}
	}

	void DrinkState::tick(float deltaTime)
	{
		string name = _actor->getName();
		if (_stoutLife == 0)
		{
			_stoutLife = 5;
			if (!(_actor->spendGold(3)))
			{
				cout << _actor->getName()
						<< " does not have enough gold to buy alcohol." << endl;
				return;
			}
		}

		_stoutLife--;
		_actor->reduceStamina(1);
		_actor->incrementBAC();

		if (_actor->getBAC() >= 0.5)
		{
			cout << name
					<< " is too drunk to continue.  He drops his glass and passes out on the floor."
					<< endl;
			switchState("sleep");
		}
		else if (_stoutLife < 1)
		{
			cout << name
					<< " finishes his drink. \"There's nothin' like a Dwarveren Ale from Ironforge.\""
					<< "\n";
		}
		else
		{
			cout << name << " takes a sip of the Dwarven Ale." << "\n";
		}
	}

	void DrinkState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string DrinkState::toString()
	{
		return "drink";
	}
}

#endif
