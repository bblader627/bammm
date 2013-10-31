#ifndef COMBATSTATE_H_
#define COMBATSTATE_H_

#include "state.h"

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
            CombatState(Actor* actor);
            void setup();
            void breakDown();
            void tick(float dTime);
			string to_string();

        private:
            uint stoutLife;
    };

	CombatState::CombatState(Actor* actor)
	{
		_actor = actor;

	}

    void CombatState::setup()
    {
    }

    void CombatState::breakDown()
    {
    }

    void CombatState::tick(float dTime)
    {
    	//string name = _actor->getName();
    }

	string CombatState::to_string()
	{
		return "Combat State";
	}
}
#endif
