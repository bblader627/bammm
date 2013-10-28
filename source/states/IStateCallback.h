/*
 * CS585
 *
 * Team MMA
 *  Alvaro Home
 *  Matt Konstantinou
 *  Michael Abramo
 *
 * Description:
 * Heap template header file.
 *
 * Last Modified: Matthew Konstantinou
 *
 */

#ifndef ISTATECALLBACK_H_
#define ISTATECALLBACK_H_

#include <iostream>
#include "../actors/actor.h"

using namespace std;



namespace bammm
{
//Forward declaration of class State;
class State;

	class IStateCallback
	{
		private:
			State* currentState;
			State* newState;
			Actor* _actor;

		public:
			IStateCallback(State* current, State* next, Actor* actor)
			{
				currentState = current;
				newState = next;
				_actor = actor;
			}

			void onTransition()
			{

			}
			/*
			{
				currentState->breakdown();
				currentState = newState;
				currentState->setup(_actor);
			}
			*/
	};

}

#endif
