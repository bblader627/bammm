#ifndef IDLESTATE_H_
#define IDLESTATE_H_

#include "State.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

namespace bammm
{
    class IdleState : public State
    {
        public:
            IdleState(Actor* actor);
            IdleState(Actor* actor, IStateCallback& statemachine);
            void setup();
            void breakdown();
            void tick(float dTime);
			string to_string();

        private:
    };

	IdleState::IdleState(Actor* actor)
	{
		_actor = actor;
	}

	IdleState::IdleState(Actor* actor, IStateCallback& statemachine)
	{
		_actor = actor;
		registerTransitionCallback(statemachine);
	}

    void IdleState::setup()
    {
    }

    void IdleState::breakdown()
    {
    }

    void IdleState::tick(float dTime)
    {
    }

	string IdleState::to_string()
	{
		return "idle";
	}
}
#endif

