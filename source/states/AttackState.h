#ifndef ATTACKSTATE_H_
#define ATTACKSTATE_H_

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
    class AttackState : public State
    {
        public:
            AttackState(Actor* actor);
            void setup();
            void breakDown();
            void tick(float dTime);
			string to_string();

        private:
    };

	AttackState::AttackState(Actor* actor)
	{
		_actor = actor;
	}

    void AttackState::setup()
    {
    }

    void AttackState::breakDown()
    {
    }

    void AttackState::tick(float dTime)
    {
    }

	string AttackState::to_string()
	{
		return "Attack State";
	}
}
#endif
