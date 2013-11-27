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
 * ActorInfo cpp file.
 *
 */

#include "ActorInfo.h"

namespace bammm
{
	ActorInfo::ActorInfo()
	{
		_name = "n/a";
		_health = 10;
		_stamina = 5;
		_attack = 10;
		_defense = 10;

	}

	ActorInfo::ActorInfo(string name, int health, int stamina, int attack,
			int defense)
	{
		_name = name;
		_health = health;
		_stamina = stamina;
		_attack = attack;
		_defense = defense;
	}

	int ActorInfo::getHealth()
	{
		return _health;
	}

	int ActorInfo::getStamina()
	{
		return _stamina;
	}

	int ActorInfo::getAttack()
	{
		return _attack;
	}

	int ActorInfo::getDefense()
	{
		return _defense;
	}

	string ActorInfo::getName()
	{
		return _name;
	}

	void ActorInfo::setName(string name)
	{
		_name = name;
	}

	void ActorInfo::setHealth(int health)
	{
		_health = health;
	}

	void ActorInfo::setStamina(int stamina)
	{
		_stamina = stamina;
	}

	void ActorInfo::setAttack(int attack)
	{
		_attack = attack;
	}

	void ActorInfo::setDefense(int defense)
	{
		_defense = defense;
	}
}
