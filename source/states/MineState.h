#ifndef MINESTATE_H_
#define MINESTATE_H_

#include "state.h"
#include <stdlib.h>

#ifndef UINT
#define UINT
typedef unsigned int UINT
#endif

namespace bammm
{
    class MineState : State
    {
        public:
            MineState();
            void setup();
            void breakDown();
            void tick(float dTime);

        private:
            int successChance = 30;
    };

    MineState::MineState()
    {
    }

    void MineState::setup(Actor* actor)
    {
        _actor = actor;
    }

    void MineState::breakDown()
    {
    }

    void MineState::tick(float dTime)
    {
        int random = rand() % 100 + 1;

        cout << "The dwarf lifts his pickaxe, and swings it at the rock. ";
        
        if(random <= successChance)
        {
            cout << "A chunk of runite falls from the rock.\n";
        }
        else
        {
            cout << "Nothing useful chips off from the rock.";
        }
    }
}
#endif
