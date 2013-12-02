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
		_collision = true;
		_alliance = AllianceType::ally;
		_symbol = "?";
		_color = "white";
		_gold = 0;
		_iron = 0;
		_coal = 0;
		_wood = 0;
		_BAC = 0;
	}

	ActorInfo::ActorInfo(string type, string name, int health, int stamina,
			int attack, int defense, Behavior behaviors, bool collision,
			AllianceType alliance, string symbol, string color, int gold, int coal, int iron, int wood, float BAC)
	{
		_type = type;
		_name = name;
		_health = health;
		_stamina = stamina;
		_attack = attack;
		_defense = defense;
		_behaviors = behaviors;
		_collision = collision;
		_alliance = alliance;
		_symbol = symbol;
		_color = color;
		_gold = gold;
		_coal = coal;
		_iron = iron;
		_wood = wood;
		_BAC = BAC;
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

	DynamicArray<string>* ActorInfo::getBaseBehaviors()
	{
		return _behaviors.getBaseBehaviors();
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

	float ActorInfo::getBAC()
	{
		return _BAC;
	}

	void ActorInfo::incrementBAC()
	{
		_BAC += .01;
	}

	void ActorInfo::resetBAC();
	{
		_BAC = 0;
	}

	void ActorInfo::increaseHealth(int amount)
	{
		if (_healthBar >= MAX_HEALTH)
		{
			_healthBar = MAX_HEALTH;
			return;
		}
		else
		{
			_healthBar += amount;
		}
	}

	void ActorInfo::increaseStamina(int amount)
	{
		if (_staminaBar >= MAX_STAMINA)
		{
			_staminaBar = MAX_STAMINA;
			return;
		}
		else
		{
			_staminaBar += amount;
		}
	}

	void ActorInfo::reduceHealth(int amount)
	{
		if (_healthBar > 0)
		{
			_healthBar -= amount;
		}
		else
		{
			_healthBar = 0;
			return;
		}
	}

	void ActorInfo::reduceStamina(int amount)
	{
		if (_staminaBar > 0)
		{
			_staminaBar -= amount;
		}
		else
		{
			_staminaBar = 0;
		}
	}

	bool ActorInfo::isFullyRested()
	{
		if (_healthBar == MAX_HEALTH && _staminaBar == MAX_STAMINA)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}
