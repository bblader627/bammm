#include "state.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT
#endif

namespace bammm
{
    class BrawlState : State
    {
        public:
            BrawlState();
            void setup(Actor* actor);
            void breakDown();
            void tick(float dTime);

        private:
    };

    BrawlState::BrawlState()
    {
    }

    void BrawlState::setup(Actor* actor)
    {
        _actor = actor;
    }

    void BrawlState::breakDown()
    {
    }

    void BrawlState::tick(float dTime)
    {
        cout << "The dwarf pulls his right arm back and then thrusts his arm forward by twisting his core. \"DWARF PUNCHHHH!\"";
    }
}


