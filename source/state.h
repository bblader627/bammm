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

	/*
	 * setup
	 * Pre-Condition- no parameters
	 * Post-Condition- no return value
	 *
	 * Sets actor values for beginning the state
	 */
	void setup();

	/*
	 * breakDown
	 * Pre-Condition- no parameters
	 * Post-Condition- no return value
	 *
	 * Returns Actor to old state
	 */
	void breakDown();

	/*
	 * tick
	 *
	 * Pre-Condition- time as recorded since beginning state
	 * Post-Condition- no return value
	 *
	 * Process state updates based on passed time
	 */
	void tick(float dTime);

	//void registerTransitionCallback(IStateCallback callback);
private:
	//Actor actor;
};
