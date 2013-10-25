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
			State();
			virtual void setup(Actor* actor);
			virtual void breakdown();
			virtual void tick(float dTime);
			virtual void registerTransitionCallback(IStateCallback* callback);
			virtual string to_string();
			virtual bool operator==(State* s);
			virtual ~State();
	};

	State::State()
	{
	}

	/*
	* setup
	* Pre-Condition- no parameters
	* Post-Condition- no return value
	*
	* Sets actor's necessary attributes for beginning a state
	*/
	void State::setup(Actor* actor)
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
	void State::breakdown()
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
	void State::tick(float dTime)
	{
		cout << "In parent state\n";
	}

	/*
	* registerTransitionCallback
	* Pre-Condition- accepts pointer to IStateCallback
	* Post-Condition- calls onTransition to swap states in callback
	*/
	void State::registerTransitionCallback(IStateCallback* callback)
	{
		callback->onTransition();
	}

	string State::to_string()
	{
		return "State";
	}

	bool State::operator==(State* s)
	{
		//bad - to_string overloader?
		//if (_actor == s)
		//{

		//}
		return false;
	}

	State::~State()
	{
	}
}
#endif
