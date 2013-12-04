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
		_type = "none";
		_name = "n/a";
		_health = 10;
		_stamina = 5;
		_attack = 10;
		_defense = 10;
		_behavior = "drink";
		_collision = true;
		_alliance = AllianceType::ally;
		_symbol = "?";
		_color = "white";
		_gold = 100;
		_iron = 100;
		_coal = 100;
		_wood = 100;
	}

	ActorInfo::ActorInfo(string type, string name, int health, int stamina,
			int attack, int defense, string behavior, bool collision,
			AllianceType alliance, string symbol, string color, int gold, int coal, int iron, int wood)
	{
		_type = type;
		_name = name;
		_health = health;
		_stamina = stamina;
		_attack = attack;
		_defense = defense;
		_behavior = behavior;
		_collision = collision;
		_alliance = alliance;
		_symbol = symbol;
		_color = color;
		_gold = gold;
		_coal = coal;
		_iron = iron;
		_wood = wood;
	}

	string ActorInfo::getType()
	{
		return _type;
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

	string ActorInfo::getBehavior()
	{
		return _behavior;
	}

	Vector3D* ActorInfo::getLocation()
	{
		return _location;
	}

	bool ActorInfo::getCollision()
	{
		return _collision;
	}

	AllianceType ActorInfo::getAlliance()
	{
		return _alliance;
	}

	string ActorInfo::getSymbol()
	{
		return _symbol;
	}

	string ActorInfo::getColor()
	{
		return _color;
	}

	int ActorInfo::getGold()
	{
		return _gold;
	}

	int ActorInfo::getWood()
	{
		return _wood;
	}

	int ActorInfo::getCoal()
	{
		return _coal;
	}

	int ActorInfo::getIron()
	{
		return _iron;
	}

	void ActorInfo::setType(string type)
	{
		_type = type;
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

	void ActorInfo::setBehavior(string behavior)
	{
		_behavior = behavior;
	}

	void ActorInfo::setLocation(Vector3D* location)
	{
		_location = location;
	}

	void ActorInfo::setCollision(bool collision)
	{
		_collision = collision;
	}

	void ActorInfo::setAlliance(AllianceType alliance)
	{
		_alliance = alliance;
	}

	void ActorInfo::setSymbol(string symbol)
	{
		_symbol = symbol;
	}
}
