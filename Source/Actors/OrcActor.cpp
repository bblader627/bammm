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
 * OrcActor cpp file.
 *
 */

#include "OrcActor.h"

namespace bammm
{
	OrcActor::OrcActor()
	{
		_name = "Orc";
		_alliance = enemy;
		_goldCount = rand() % 6;
		setMeleeWeapon(new OrcishBlade());
	}

	OrcActor::OrcActor(int gold)
	{
		_name = "Orc";
		_alliance = enemy;
		_goldCount = gold;
		setMeleeWeapon(new OrcishBlade());
	}

	int OrcActor::getGold()
	{
		return _goldCount;
	}
}
