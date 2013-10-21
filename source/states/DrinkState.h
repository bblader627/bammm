#ifndef DRINKSTATE_H_
#define DRINKSTATE_H_
#include "state.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

namespace bammm
{
    class DrinkState : public State
    {
        public:
            DrinkState(Actor* actor);
            void setup();
            void breakDown();
            void tick(float dTime);

        private:
            static const uint stoutSize = 5;
            uint stoutLife;
    };

    DrinkState::DrinkState(Actor* actor)
    {
    	_actor = actor;
    }

    void DrinkState::setup()
    {
        stoutLife = stoutSize;
    }

    void DrinkState::breakDown()
    {
    }

    void DrinkState::tick(float dTime)
    {
        stoutLife--;
        _actor->reduceStamina(1);
        if(stoutLife < 1)
        {
            cout << "The dwarf finishes his drink. \"There's nothin' like a Dwarveren Ale from Ironforge.\"" << "\n";
        }
        else
        {
            cout << "The dwarf takes a sip of the Dwarven Ale." << "\n";
        }
    }
}
#endif
