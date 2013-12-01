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
 * Behavior cpp file.
 *
 */

#include "Behavior.h"
using namespace std;

namespace bammm
{
	Behavior::Behavior(DynamicArray<string> *baseBehaviors,DynamicArray<string> *baseValues)
	{
		int i;
		_baseBehaviors = baseBehaviors;
		
		for(i = 0; i < baseBehaviors->getSize(); i++)
		{
			
		}
	}

	void Behavior::addBehavior(string behavior, int baseDesire)
	{
		_desireTable.add(behavior,baseDesire);
	}

	void Behavior::printTable()
	{
		cout << _currentDesireTable.getAllKeys()->toString() << endl;
		cout << _currentDesireTable.getAllValues()->toString() << endl;
	}
}
