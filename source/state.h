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
#include "dynamicarray.h"
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
	}
	void tick(float dTime);
	void breakDown();
	void registerTransitionCallback(IStateCallback callback);
private:
	//Actor actor;
};
