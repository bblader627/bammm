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
            BrawlState(Actor* actor, IStateCallback* stateMachine);
            void setup();
            void breakdown();
            void tick(float deltaTime);
			string toString();

        private:
    };

    BrawlState::BrawlState(Actor* actor)
    {
		_actor = actor;
    }

    BrawlState::BrawlState(Actor* actor, IStateCallback* stateMachine)
	{
		_actor = actor;
		registerTransitionCallback(stateMachine);
	}

    void BrawlState::setup()
    {
    }

    void BrawlState::breakdown()
    {
    }

    void BrawlState::tick(float deltaTime)
    {
        cout << _actor->getName() << " pulls his right arm back and then thrusts his arm forward by twisting his core. \"DWARF PUNCHHHH!\"\n";
    }

	string BrawlState::toString()
	{
		return "brawl";
	}
}
#endif

