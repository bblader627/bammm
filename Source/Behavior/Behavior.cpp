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
	Behavior::Behavior()
	{
	}

	void Behavior::addBehavior(string behavior, int baseDesire)
	{
		_desireTable.add(behavior,baseDesire);
	}

	void Behavior::printTable()
	{
		cout << _desireTable.getAllKeys()->toString() << endl;
		cout << _desireTable.getAllValues()->toString() << endl;
	}
}
