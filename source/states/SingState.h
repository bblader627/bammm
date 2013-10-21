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
    }

    void SingState::breakDown()
    {
    }

    void SingState::tick(float dTime)
    {
        int random = rand() % 100 + 1;
        
        cout << "The dwarf begins to sing. "
        if(random <= singPercentage)
        {
            cout << "\"Far over the misty mountains cold...\"";
        }
    }
}
#endif
