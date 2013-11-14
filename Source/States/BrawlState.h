#ifndef BRAWLSTATE_H_
#define DEFINE BRAWLSTATE_H_

#include "State.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

namespace bammm
{
    class BrawlState : public State
    {
        public:
            BrawlState(Actor* actor);
            BrawlState(Actor* actor, IStateCallback& statemachine);
            void setup();
            void breakdown();
            void tick(float dTime);
			string to_string();

        private:
    };

    BrawlState::BrawlState(Actor* actor)
    {
		_actor = actor;
    }

    BrawlState::BrawlState(Actor* actor, IStateCallback& statemachine)
	{
		_actor = actor;
		registerTransitionCallback(statemachine);
	}

    void BrawlState::setup()
    {
    }

    void BrawlState::breakdown()
    {
    }

    void BrawlState::tick(float dTime)
    {
        cout << _actor->getName() << " pulls his right arm back and then thrusts his arm forward by twisting his core. \"DWARF PUNCHHHH!\"\n";
    }

	string BrawlState::to_string()
	{
		return "brawl";
	}
}
#endif

