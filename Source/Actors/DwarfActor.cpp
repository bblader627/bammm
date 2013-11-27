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
 * DwarfActor cpp file.
 *
 */

#include "DwarfActor.h"

namespace bammm
{
	DwarfActor::DwarfActor()
	{
		_name = "Dwarf";
		_alliance = ally;
		_bloodAlcoholContent = 0.00;
		setMeleeWeapon(new Stein());
		_goldCount = 0;
		_bloodAlcoholContent = _BAC;
	}

	DwarfActor::DwarfActor(float BAC, int gold)
	{
		_name = "Dwarf";
		_alliance = ally;
		_bloodAlcoholContent = BAC;
		setMeleeWeapon(new Stein());
		_goldCount = gold;
	}

	float DwarfActor::getBAC()
	{
		return _bloodAlcoholContent;
	}

	float DwarfActor::incrementBAC()
	{
		_bloodAlcoholContent += 0.001;
		return _bloodAlcoholContent;

	}

	inline float DwarfActor::incrementBAC(float amount)
	{
		_bloodAlcoholContent += amount;
		return _bloodAlcoholContent;
	}

	float DwarfActor::decrementBAC()
	{
		_bloodAlcoholContent -= 0.001;
		return _bloodAlcoholContent;
	}

	float DwarfActor::resetBAC()
	{
		_bloodAlcoholContent = 0.00;
		return _bloodAlcoholContent;
	}

	int DwarfActor::getGold()
	{
		return _goldCount;
	}

	int DwarfActor::addGold()
	{
		_goldCount++;
		return _goldCount;
	}

	int DwarfActor::addGold(int amount)
	{
		_goldCount += amount;
		return _goldCount;
	}
}
