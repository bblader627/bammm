/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *	Bradley Crusco
 * Description:
 * IStateCallback cpp file.
 *
 */

#include "IStateCallback.h"

namespace bammm
{
	IStateCallback::IStateCallback()
	{

	}

	IStateCallback::~IStateCallback()
	{

	}

	void IStateCallback::switchState(State* current, State* newState)
	{
		cout << "wrong switch" << "\n";
	}

	void IStateCallback::switchState(State* current, string newStateString)
	{
		cout << "Wrong switch string" << "\n";
	}
}
