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
		_health = MAX_HEALTH;
		_stamina = MAX_STAMINA;
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
		_behaviors = new Behavior();
	}

	ActorInfo::ActorInfo(string type, string name,
			int attack, int defense, Behavior *behaviors, bool collision,
			AllianceType alliance, string symbol, string color, int gold, int coal, int iron, int wood, float BAC)
	{
		_type = type;
		_name = name;
		_health = MAX_HEALTH;
		_stamina = MAX_STAMINA;
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
		return _behaviors->getBaseBehaviors();
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

	void ActorInfo::resetBAC()
	{
		_BAC = 0;
	}

	void ActorInfo::increaseHealth(int amount)
	{
		if (_health >= MAX_HEALTH)
		{
			_health = MAX_HEALTH;
			return;
		}
		else
		{
			_health += amount;
		}
	}

	void ActorInfo::increaseStamina(int amount)
	{
		if (_stamina >= MAX_STAMINA)
		{
			_stamina = MAX_STAMINA;
			return;
		}
		else
		{
			_stamina += amount;
		}
	}

	void ActorInfo::reduceHealth(int amount)
	{
		if (_health > 0)
		{
			_health -= amount;
		}
		else
		{
			_health = 0;
			return;
		}
	}

	void ActorInfo::reduceStamina(int amount)
	{
		if (_stamina > 0)
		{
			_stamina -= amount;
		}
		else
		{
			_stamina = 0;
		}
	}

	bool ActorInfo::isFullyRested()
	{
		if (_health == MAX_HEALTH && _stamina == MAX_STAMINA)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void ActorInfo::setColor(string color)
	{
		_color = color;
	}

	void ActorInfo::setGold(int gold)
	{
		_gold = gold;
	}

	void ActorInfo::setIron(int iron)
	{
		_iron = iron;
	}

	void ActorInfo::setCoal(int coal)
	{
		_coal = coal;
	}

	void ActorInfo::setWood(int wood)
	{
		_wood = wood;
	}

	int ActorInfo::addGold(int amount)
	{
		_gold += amount;
		return _gold;
	}

	bool ActorInfo::spendGold(int amount)
	{
		if (_gold < amount)
		{
			return false;
		}
		else
		{
			_gold -= amount;
			return true;
		}
	}

	int ActorInfo::getEnemyAlliance()
	{
		return _alliance * -1;
	}
	
	void ActorInfo::setBehavior(Behavior *behaviors)
	{
		_behaviors = behaviors;
	}

	Behavior* ActorInfo::getBehavior()
	{
		return _behaviors;
	}


}
