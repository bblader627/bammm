#ifndef IDLESTATE_H_
#define IDLESTATE_H_

#include "state.h"

#ifndef UINT
#define UINT
typedef unsigned int UINT
#endif

namespace bammm
{
    class IdleState : public State
    {
        public:
            IdleState();
            void setup(Actor* actor);
            void breakDown();
            void tick(float dTime);

        private:
    };

    IdleState::IdleState()
    {
    }

    void IdleState::setup(Actor* actor)
    {
        _actor = actor;
    }

    void IdleState::breakDown()
    {
    }

    void IdleState::tick(float dTime)
    {
    }
}
#endif

