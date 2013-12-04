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
		_health = _maximumHealth;
		_stamina = _maximumStamina;
		_attack = 10;
		_defense = 10;
		_collision = true;
		_alliance = AllianceType::ally;
		_symbol = "?";
		_color = "white";
		_gold = 100;
		_iron = 100;
		_coal = 100;
		_wood = 100;
		_BAC = 0;
		_behaviors = new Behavior();
		_level = 1;
		_experience = 0;
		_totalExperienceThisLevel = 1;
	}

	ActorInfo::ActorInfo(string type, string name, int attack, int defense,
			Behavior *behaviors, bool collision, AllianceType alliance,
			string symbol, string color, int gold, int coal, int iron, int wood,
			float BAC)
	{
		_type = type;
		_name = name;
		_health = _maximumHealth;
		_stamina = _maximumStamina;
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
		_level = 1;
		_experience = 0;
		_totalExperienceThisLevel = 1;
	}

	string ActorInfo::getType()
	{
		return _type;
	}

	int ActorInfo::getHealth()
	{
		return _health;
	}

	int ActorInfo::getMaximumHealth()
	{
		return _maximumHealth;
	}

	int ActorInfo::getStamina()
	{
		return _stamina;
	}

	int ActorInfo::getMaximumStamina()
	{
		return _maximumStamina;
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

	void ActorInfo::setMaximumHealth(int maximumHealth)
	{
		_maximumHealth = maximumHealth;
	}

	void ActorInfo::setStamina(int stamina)
	{
		_stamina = stamina;
	}

	void ActorInfo::setMaximumStamina(int maximumStamina)
	{
		_maximumStamina = maximumStamina;
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

	void ActorInfo::setBAC(float BAC)
	{
		_BAC = BAC;
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
		if (_health >= _maximumHealth)
		{
			_health = _maximumHealth;
			return;
		}
		else
		{
			_health += amount;
		}
	}

	void ActorInfo::increaseStamina(int amount)
	{
		if (_stamina >= _maximumStamina)
		{
			_stamina = _maximumStamina;
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
		if (_health == _maximumHealth && _stamina == _maximumStamina)
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

	void ActorInfo::setBehavior(string behavior)
	{
		_behavior = behavior;
	}

	string ActorInfo::getBehavior()
	{
		return _behavior;
	}

	int ActorInfo::getLevel()
	{
		return _level;
	}

	void ActorInfo::setLevel(int newLevel)
	{
		_level = newLevel;
	}

	int ActorInfo::getExperience()
	{
		return _experience;
	}

	void ActorInfo::setExperience(int newExperience)
	{
		_experience = newExperience;
	}

	int ActorInfo::getTotalExperienceThisLevel()
	{
		return _totalExperienceThisLevel;
	}

	void ActorInfo::setTotalExperienceThisLevel(int newTotalExperienceThisLevel)
	{
		_totalExperienceThisLevel = newTotalExperienceThisLevel;
	}
}
