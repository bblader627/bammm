#ifndef SLEEPSTATE_H_
#define SLEEPSTATE_H_

#include <iostream>
#include "state.h"
#include "IStateCallback.h"
#include "IdleState.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

using namespace std;

namespace bammm
{
    class SleepState : public State
    {
        public:
            SleepState(Actor* actor);
            SleepState(Actor* actor, IStateCallback* statemachine);
            void setup();
            void breakdown();
            void tick(float dTime);
            void switchState(string nextState);
			string to_string();

        private:
            static const int hoursToSleep = 8;
            int timeSlept;
    };

	SleepState::SleepState(Actor* actor)
	{
		_actor = actor;
	}

	SleepState::SleepState(Actor* actor, IStateCallback* statemachine)
	{
		_actor = actor;
		registerTransitionCallback(statemachine);
	}

    void SleepState::setup()
    {
        timeSlept = 0;
    }

    void SleepState::breakdown()
    {
    }

    void SleepState::tick(float dTime)
    {
        string output = "";

        _actor->increaseHealth(2);
        _actor->increaseStamina(2);

        if (_actor->isFullyRested())
        {
        	switchState("idle");
        }

        if(timeSlept < hoursToSleep)
        {
            if(timeSlept == 0)
            {
                output = actor->getName() << " lays on the ground and begins to sleep.\n";
            }
            output + "zzzZZZ\n";
            timeSlept++;
        }
    }

    void SleepState::switchState(string nextState)
    {
    	_statemachine->switchState(this, nextState);
    }

	string SleepState::to_string()
	{
		return "sleep";
	}
}
#endif
