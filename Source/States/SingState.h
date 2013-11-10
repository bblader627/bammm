#ifndef SINGSTATE_H_
#define SINGSTATE_H_

#include "State.h"
#include <iostream>

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

namespace bammm
{
    class SingState : public State
    {
        public:
            SingState(Actor* actor);
            SingState(Actor* actor, IStateCallback* statemachine);
            void setup();
            void breakdown();
            void tick(float dTime);
			string to_string();

        private:
            const static int singPercentage = 75;
            int singLine;
    };

	SingState::SingState(Actor* actor)
	{
		_actor = actor;
	}

	SingState::SingState(Actor* actor, IStateCallback* statemachine)
	{
		_actor = actor;
		registerTransitionCallback(statemachine);
	}

    void SingState::setup()
    {
        singLine = 0;
    	cout << _actor->getName() << " begins to sing. ";
    }

    void SingState::breakdown()
    {
    }

    void SingState::tick(float dTime)
    {
        _actor->reduceStamina(1);
        cout << _actor->getName() << " is singing the song of it's people.\n";
    }

	string SingState::to_string()
	{
		return "sing";
	}
}
#endif
