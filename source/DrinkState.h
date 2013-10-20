#include "state.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT
#endif

namespace bammm
{
    class DrinkState : State
    {
        public:
            DrinkState();
            void setup();
            void breakDown();
            void tick(float dTime);

        private:
            uint stoutSize;
    };

    DrinkState::DrinkState()
    {
    }

    void DrinkState::setup()
    {
        stoutSize = 5;
    }

    void DrinkState::breakDown()
    {
    }

    void DrinkState::tick(float dTime)
    {
        
    }
}


