#include "state.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT
#endif

namespace bammm
{
    class IdleState : State
    {
        public:
            IdleState();
            void setup();
            void breakDown();
            void tick(float dTime);

        private:
    };

    IdleState::IdleState()
    {
    }

    void IdleState::setup()
    {
        stoutLife = stoutSize;
    }

    void IdleState::breakDown()
    {
    }

    void IdleState::tick(float dTime)
    {
    }
}


