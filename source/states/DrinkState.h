#ifndef DRINKSTATE_H_
#define DRINKSTATE_H_

#include "state.h"
#include "SleepState.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

using namespace std;

namespace bammm
{

    class DrinkState : public State
    {
    	private:
    		//IStateCallback* _statemachine;
    		static const uint stoutSize = 5;
			uint stoutLife;

        public:
            DrinkState(Actor* actor);
            DrinkState(Actor* actor, IStateCallback* statemachine);
            void setup();
            void breakdown();
            void tick(float dTime);
            void switchState(string nextState);
			string to_string();

    };

	DrinkState::DrinkState(Actor* actor)
	{
		_actor = actor;

	}

	DrinkState::DrinkState(Actor* actor, IStateCallback* statemachine)
	{
		_actor = actor;
		registerTransitionCallback(statemachine);
	}

    void DrinkState::setup()
    {
        stoutLife = stoutSize;
    }

    void DrinkState::breakdown()
    {
    	double bac = _actor->getBAC();
    	if (bac < 0.1)
    	{
    		//Do nothing
    	}
    	else if (bac < 0.25)
    	{
    		cout << _actor->getName() << " puts down his drink.  He's slightly tipsy, but is ready to get back to work!" << endl;
    	}
    	else if (bac < 0.35)
		{
    		_actor->incrementBAC();
			cout << _actor->getName() << " finishes his sloppily drink and slams it down on the counter, ready to go out and explore the village." << endl;
		}
    	else if (bac < 0.5)
		{
    		_actor->reduceHealth(2);
    		cout << _actor->getName() << " is very drunk.  He gets up to leave and falls over a table before making his way out the door." << endl;
		}
    }

    void DrinkState::tick(float dTime)
    {
    	string name = _actor->getName();
    	if (stoutLife==0)
    	{
    		stoutLife=5;
    		if (!(_actor->spendGold(3)))
			{
				cout << _actor->getName() << " does not have enough gold to buy alcohol." << endl;
				return;
			}
    	}

		stoutLife--;
		_actor->reduceStamina(1);
		_actor->incrementBAC();

		if (_actor->getBAC() >= 0.5)
		{
			cout << name << " is too drunk to continue.  He drops his glass and passes out on the floor." << endl;
			switchState("sleep");
		}
		else if(stoutLife < 1)
		{
			cout << name <<  " finishes his drink. \"There's nothin' like a Dwarveren Ale from Ironforge.\"" << "\n";
		}
		else
		{
			cout << "The dwarf takes a sip of the Dwarven Ale." << "\n";
		}
    }

    void DrinkState::switchState(string nextState)
    {
    	_statemachine->switchState(this, nextState);
    }

	string DrinkState::to_string()
	{
		return "drink";
	}

}
#endif
