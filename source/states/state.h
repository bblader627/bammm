/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *	Bradley Crusco
 *
 * Description:
 * Drinking state header file.
 *
 * Last Modified: Matthew Konstantinou
 *
 */

#ifndef STATE_H_
#define STATE_H_

#include <iostream>
#include "../resources/dynamicarray.h"
#include "../states/IStateCallback.h"
#include "../actors/actor.h"

#ifndef NULL
#define NULL (void *)0
#endif

using namespace std;

namespace bammm
{
    class State
    {
		protected:
			Actor* _actor;

        public:
			State()
			{
				//do nothing
			}

			/*
			* setup
			* Pre-Condition- no parameters
			* Post-Condition- no return value
			*
			* Sets actor's necessary attributes for beginning a state
			*/
			void setup(Actor* actor)
			{
				_actor = actor;
			}

			/*
			* breakDown
			* Pre-Condition- no parameters
			* Post-Condition- no return value
			*
			* Returns Actor to old state
			*/
			void breakdown()
			{

			}

			/*
			* tick
			*
			* Pre-Condition- time as recorded since beginning state
			* Post-Condition- no return value
			*
			* Process state updates based on passed time
			*/
			void tick(float dTime);

			/*
			 * registerTransitionCallback
			 * Pre-Condition- accepts pointer to IStateCallback
			 * Post-Condition- calls onTransition to swap states in callback
			 */
			void registerTransitionCallback(IStateCallback* callback)
			{
				callback->onTransition();
			}

			string to_string()
			{
				cout << "State" << endl;
                return "State";
			}

			bool operator==(State* s)
			{
				//bad - to_string overloader?
				//if (_actor == s)
				//{

				//}
				return false;
			}
    };
}
#endif
