#ifndef SINGSTATE_H_
#define SINGSTATE_H_

#include "state.h"
#include <stdlib.h>

#ifndef UINT
#define UINT
typedef unsigned int UINT
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
    }

    void SingState::breakDown()
    {
    }

    void SingState::tick(float dTime)
    {
        int random = rand() % 100 + 1;
        
        cout << "The dwarf begins to sing. ";
        if(random <= singPercentage)
        {
            cout << "\"Far over the misty mountains cold...\"";
        }
    }
}
#endif
