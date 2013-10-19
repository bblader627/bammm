/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *
 * Description:
 * State header file.
 *
 * Last Modified: Matthew Konstantinou
 *
 */

#ifndef STATE_H_
#define STATE_H_
#endif

#include <iostream>
#include "array.h"
#include "IStateCallback.h"


#ifndef NULL
#define NULL (void *)0
#endif

using namespace std;

class State
{
public:
	State();

	void setup()
	{
		//Check actor's performableActions?
		//Get actor's details
		//Set values to begin state?
	}
	void tick(float dTime)
	{
		//Update
		//If updating calls for a state change, create IStateCallback and call IStateCallback.onTransition
	}
	void breakDown();
	void registerTransitionCallback(IStateCallback callback);
private:
	//Actor actor;
};
