#ifndef SINGSTATE_H_
#define SINGSTATE_H_

#include "state.h"
#include <iostream>

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

namespace bammm
{
    class SingState : State
    {
        public:
            SingState();
            void setup();
            void breakDown();
            void tick(float dTime);

        private:
            int singPercentage = 75;
            int singLine = 0;
    };

    SingState::SingState()
    {
    }

    void SingState::setup()
    {
    	cout << "The dwarf begins to sing. "
    }

    void SingState::breakDown()
    {
    }

    void SingState::tick(float dTime)
    {
        _actor->reduceStamina(1);
        cout << "The dwarf is singing the song of it's people. ";
        
    }
}
#endif
