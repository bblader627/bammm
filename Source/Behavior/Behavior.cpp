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

namespace bammm
{
	Behavior::Behavior()
	{
		_baseBehaviors = new DynamicArray<string>();
	}

	Behavior::Behavior(DynamicArray<string> *baseBehaviors,
			DynamicArray<string> *baseValues)
	{
		int i;
		_baseBehaviors = baseBehaviors;

		for (i = 0; i < baseBehaviors->getSize(); i++)
		{
			addBehavior(_baseBehaviors->get(i), baseValues->get(i));
		}
	}

	void Behavior::addBehavior(string behavior, int baseDesire)
	{
		_desireTable.add(behavior, baseDesire);
	}

	void Behavior::addBaseBehavior(string behavior, int baseDesire)
	{
		_desireTable.add(behavior, baseDesire);
		_baseBehaviors->add(behavior);
	}

	void Behavior::printTable()
	{
		cout << _desireTable.getAllKeys()->toString() << endl;
		cout << _desireTable.getAllValues()->toString() << endl;
	}

	DynamicArray<string>* Behavior::getBaseBehaviors()
	{
		return _baseBasehaviors;
	}

}
