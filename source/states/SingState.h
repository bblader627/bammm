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
    class SingState : public State
    {
        public:
            SingState();
            void setup(Actor* actor);
            void breakDown();
            void tick(float dTime);

        private:
            const static int singPercentage = 75;
            int singLine;
    };

    SingState::SingState()
    {
    }

    void SingState::setup(Actor* actor)
    {
        _actor = actor;
        singLine = 0;
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
