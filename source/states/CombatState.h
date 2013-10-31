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
    class CombatArray : public State
    {
        public:
            CombatArray(Actor* actor);
            void setup();
            void breakDown();
            void tick(float dTime);
			string to_string();

        private:
    };

	CombatArray::CombatArray(Actor* actor)
	{
		_actor = actor;
	}

    void CombatArray::setup()
    {
    }

    void CombatArray::breakDown()
    {
    }

    void CombatArray::tick(float dTime)
    {
    }

	string CombatArray::to_string()
	{
		return "Combat State";
	}
}
#endif
