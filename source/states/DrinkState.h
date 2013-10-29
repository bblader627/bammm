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
    		IStateCallback* _statemachine;
			void registerTransitionCallback(string newStateString);

        public:
            DrinkState(Actor* actor);
            void setup();
            void breakDown();
            void tick(float dTime);
			string to_string();

        private:
            static const uint stoutSize = 5;
            uint stoutLife;
    };

	DrinkState::DrinkState(Actor* actor)
	{
		_actor = actor;

	}

    void DrinkState::setup()
    {
        stoutLife = stoutSize;
    }

    void DrinkState::breakDown()
    {
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
			this->registerTransitionCallback("sleep");
			//switchState(this, SleepState);
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

	string DrinkState::to_string()
	{
		return "Drink State";
	}

	void DrinkState::registerTransitionCallback(string newStateString)
	{
		_statemachine->onTransition(this, newStateString);
	}
}
#endif
