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
#include "../Resources/DynamicArray.h"
#include "IStateCallback.h"
#include "../Actors/Actor.h"

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
			IStateCallback* _statemachine;
        public:
			State();
			State(Actor* actor);
			State(Actor* actor, IStateCallback& stateMachine);
			virtual void setup();
			virtual void breakdown();
			virtual void tick(float dTime);
			virtual void registerTransitionCallback(IStateCallback& statemachine);
			virtual void switchState(string nextState);
			virtual string to_string();
			virtual bool operator==(State* s);
			virtual ~State();
	};

	State::State()
	{
	}

	State::State(Actor* actor)
	{
		_actor = actor;
	}

	State::State(Actor* actor, IStateCallback& stateMachine)
	{
		_actor = actor;
		_statemachine = &stateMachine;
	}

	/*
	* setup
	* Pre-Condition- no parameters
	* Post-Condition- no return value
	*
	* Sets actor's necessary attributes for beginning a state
	*/
	void State::setup()
	{
		cout << "wrong setup" << endl;
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
		cout << "wrong breakdown" << endl;
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
	* Post-Condition- calls switchState to swap states in callback
	*/
	void State::registerTransitionCallback(IStateCallback& statemachine)
	{
		_statemachine = &statemachine;
	}

	/*
	* switchState
	* Pre-Condition- accepts next state as text
	* Post-Condition- returns void, calls switchState on _statemachine
	*/
	void State::switchState(string nextState)
	{
		//_statemachine->switchState(this, nextState);
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
