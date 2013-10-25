#ifndef BRAWLSTATE_H_
#define DEFINE BRAWLSTATE_H_

#include "state.h"

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
            void setup();
            void breakDown();
            void tick(float dTime);
			string to_string();

        private:
    };

    BrawlState::BrawlState(Actor* actor)
    {
		_actor = actor;
    }

    void BrawlState::setup()
    {
    }

    void BrawlState::breakDown()
    {
    }

    void BrawlState::tick(float dTime)
    {
        cout << "The dwarf pulls his right arm back and then thrusts his arm forward by twisting his core. \"DWARF PUNCHHHH!\"";
    }

	string BrawlState::to_string()
	{
		return "Brawl State";
	}
}
#endif

