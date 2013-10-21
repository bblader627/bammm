#ifndef SLEEPSTATE_H_
#define SLEEPSTATE_H_

#include <iostream>
#include "state.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

using namespace std;

namespace bammm
{
    class SleepState : public State
    {
        public:
            SleepState(Actor* actor);
            void setup();
            void breakDown();
            void tick(float dTime);

        private:
            static const int hoursToSleep = 8;
            int timeSlept;
    };

    SleepState::SleepState()
    {
    }

    void SleepState::setup(Actor* actor)
    {
        _actor = actor;
        timeSlept = 0;
    }

    void SleepState::breakDown()
    {
    }

    void SleepState::tick(float dTime)
    {
        string output = "";

        _actor->increaseHealth(2);
        _actor->increaseStamina(2);

        if(timeSlept < hoursToSleep)
        {
            if(timeSlept == 0)
            {
                output = "The dwarf lays on the ground and begins to sleep.\n";
            }
            output + "zzzZZZ\n";
            timeSlept++;
        }
    }
}
#endif
