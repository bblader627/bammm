#ifndef IDLESTATE_H_
#define IDLESTATE_H_

#include "state.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT;
#endif

namespace bammm
{
    class IdleState : public State
    {
        public:
            IdleState(Actor* actor);
            void setup();
            void breakDown();
            void tick(float dTime);

        private:
    };

    IdleState::IdleState(Actor* actor)
    {
    	_actor = actor;
    }

    void IdleState::setup()
    {

    }

    void IdleState::breakDown()
    {
    }

    void IdleState::tick(float dTime)
    {
    }
}
#endif

