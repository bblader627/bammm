#ifndef MINESTATE_H_
#define MINESTATE_H_

#include "state.h"
#include <iostream>

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

namespace bammm
{
    class MineState : public State
    {
		private:
			int successChance;
			int maxGold;
        public:
            MineState(Actor* actor);
            MineState(Actor* actor, IStateCallback* statemachine);
            void setup();
            void breakdown();
            void tick(float dTime);
            void switchState(string nextState);
            string to_string();
    };

	MineState::MineState(Actor* actor)
	{
		_actor = actor;
		maxGold = 15;
	}
	MineState::MineState(Actor* actor, IStateCallback* statemachine)
	{
		_actor = actor;
		maxGold = 15;
		registerTransitionCallback(statemachine);
	}
    /*
     * setup
     * Pre-Condition- no parameters
     * Post-Condition- sets _actor's member variables necessary for beginning a state
     */
    void MineState::setup()
    {

    	successChance = 30;
    	maxGold = 100;

    }

    void MineState::breakdown()
    {
    }

    void MineState::tick(float dTime)
    {
    	if (_actor->getBAC() > 0.4)
    	{
    		cout << _actor->getName() << " drunkenly swings the pickaxe, hits himself in the foot, and decides not to do that anymore." << endl;
    		switchState("null"); //ends this state;
    		return;
    	}

        //int random = rand() % 100 + 1;
    	_actor->reduceStamina(1);
    	_actor->addGold(1);
        cout << _actor->getName() << " lifts his pickaxe, and swings it at the rock. " << endl;
        cout << _actor->getGold() << endl;
        if (_actor->getGold() > maxGold)
        {
        	cout << _actor->getName() << "'s purse is full!" << endl;
        	switchState("drink");
        }

        /*
        if(random <= successChance)
        {
            cout << "A chunk of runite falls from the rock.\n";
        }
        else
        {
            cout << "Nothing useful chips off from the rock.";
        }
        */
    }

    /* switchState
	* Pre-Condition- accepts next state as text
	* Post-Condition- returns void, calls switchState on _statemachine
	*/
	void MineState::switchState(string nextState)
	{
		_statemachine->switchState(this, nextState);
	}

	string MineState::to_string()
	{
		return "mine";
	}

}
#endif
