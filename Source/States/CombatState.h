#ifndef ATTACKSTATE_H_
#define ATTACKSTATE_H_

#include <iostream>
#include "State.h"
#include "IStateCallback.h"
#include "IdleState.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

using namespace std;

namespace bammm
{
    class CombatState : public State
    {
        public:
            CombatState(Actor& actor);
            CombatState(Actor& actor, IStateCallback& statemachine);
            void setup();
            void breakdown();
            void tick(float dTime);
			string to_string();

        private:
    };

	CombatState::CombatState(Actor& actor)
	{
		_actor = &actor;
	}

	CombatState::CombatState(Actor& actor, IStateCallback& statemachine)
	{
		_actor = &actor;

		registerTransitionCallback(statemachine);
	}

    void CombatState::setup()
    {
    }

    void CombatState::breakdown()
    {
    }

    void CombatState::tick(float dTime)
    {
    }

	string CombatState::to_string()
	{
		return "combat";
	}
}
#endif
