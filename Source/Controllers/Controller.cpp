/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *  Bradley Crusco
 * Description:
 * Controller cpp file.
 *
 */

#include "Controller.h"

namespace bammm
{
	Controller::Controller()
	{
	}

	Controller::~Controller()
	{
		DynamicArray<string>* keys = _states.getAllKeys();
		int size = keys->getSize();

		for (int i = 0; i < size; i++)
		{
			delete _states.getValue(keys->get(i));
		}

		delete keys;
	}
}
