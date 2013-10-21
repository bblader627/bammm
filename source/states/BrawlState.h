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

        private:
    };

    BrawlState::BrawlState()
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
}
#endif

