#include "state.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT
#endif

namespace bammm
{
    class SleepState : State
    {
        public:
            SleepState();
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

    void SleepState::setup()
    {
        timeSlept = 0;
    }

    void SleepState::breakDown()
    {
    }

    void SleepState::tick(float dTime)
    {
        string output = "";
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


