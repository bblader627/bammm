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
 * Actor cpp file.
 *
 */

#include "Actor.h"
#include "../SceneManager/Vector3D.h"

using namespace std;

namespace bammm
{
	Actor::Actor()
	{
		_type = "dwarf";
		_name = "DefaultName";
		_rotation = 0;

		_velocity = new Vector3D();
		_location = new Vector3D();
		_collision = false;

		MAX_HEALTH = 100;
		MAX_STAMINA = 50;
		_healthBar = MAX_HEALTH;
		_staminaBar = MAX_STAMINA;
		_healthBar = 100;
		_staminaBar = 50;
		_attack = 4;
		_defense = 2;
		_symbol = "D";
		_color = "white";
	}

	Actor::Actor(string name, string type, AllianceType alliance)
	{
		_collision = false;
		_name = name;
		_type = type;
		_rotation = 0;
		_velocity = new Vector3D();
		_location = new Vector3D();

		MAX_HEALTH = 100;
		MAX_STAMINA = 50;
		_healthBar = MAX_HEALTH;
		_staminaBar = MAX_STAMINA;
		_healthBar = 100;
		_staminaBar = 50;
		_attack = 4;
		_defense = 2;
		_alliance = alliance;
	}

	Actor::Actor(string type, string name, int health, int stamina, int attack,
			int defense, string behavior, AllianceType alliance)
	{
		_type = type;
		_name = name;

		_rotation = 0;
		_velocity = new Vector3D();
		_location = new Vector3D();

		MAX_HEALTH = health;
		MAX_STAMINA = stamina;
		_healthBar = MAX_HEALTH;
		_staminaBar = MAX_STAMINA;
		_healthBar = health;
		_staminaBar = stamina;
		_attack = attack;
		_defense = defense;

		_behavior = behavior;
		_collision = false;
		_alliance = alliance;
	}

	Actor::Actor(ActorInfo* info)
	{
		_type = info->getType();
		_name = info->getName();
		_rotation = 0;
		_velocity = new Vector3D();
		_location = info->getLocation();

		MAX_HEALTH = info->getHealth();
		MAX_STAMINA = info->getStamina();
		_healthBar = MAX_HEALTH;
		_staminaBar = MAX_STAMINA;
		_healthBar = info->getHealth();
		_staminaBar = info->getStamina();
		_attack = info->getAttack();
		_defense = info->getDefense();

		_behavior = info->getBehavior();
		_alliance = info->getAlliance();
		_collision = info->getCollision();
		_symbol = info->getSymbol();
		_color = info->getColor();
	}

	void Actor::setMeleeWeapon(MeleeWeapon* weapon)
	{
		_meleeWeapon = weapon;
	}

	void Actor::setRangedWeapon(RangedWeapon* weapon)
	{
		_rangedWeapon = weapon;
	}

	void Actor::setRotation(float myRotation)
	{
		_rotation = myRotation;
	}

	void Actor::setName(string name)
	{
		_name = name;
	}

	void Actor::setType(string type)
	{
		_type = type;
	}

	void Actor::setBehavior(string behavior)
	{
		_behavior = behavior;
	}

	void Actor::setLocation(Vector3D* location)
	{
		_location = location;
	}

	void Actor::setSymbol(string symbol)
	{
		_symbol = symbol;
	}

	void Actor::setColor(string color)
	{
		_color = color;
	}

	void Actor::increaseHealth(int amount)
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

	void Actor::increaseStamina(int amount)
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

	void Actor::reduceHealth(int amount)
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

	void Actor::reduceStamina(int amount)
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

	bool Actor::isFullyRested()
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

	void Actor::incrementBAC()
	{
		_BAC += .01;
		return;
	}

	int Actor::addGold(int amount)
	{
		_gold += amount;
		return _gold;
	}

	bool Actor::spendGold(int amount)
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

	int Actor::getGold()
	{
		return _gold;
	}

	bool Actor::getCollision()
	{
		return _collision;
	}

	MeleeWeapon* Actor::getMeleeWeapon()
	{
		return _meleeWeapon;
	}

	RangedWeapon* Actor::getRangedWeapon()
	{
		return _rangedWeapon;
	}

	float Actor::getBAC()
	{
		return _BAC;
	}

	float Actor::getRotation()
	{
		return _rotation;
	}

	string Actor::getName()
	{
		return _name;
	}

	string Actor::getVelocity()
	{
		return _velocity->toString();
	}

	Vector3D* Actor::getLocation()
	{
		return _location;
	}

	int Actor::getHealth()
	{
		return _healthBar;
	}

	int Actor::getStamina()
	{
		return _staminaBar;
	}

	int Actor::getAttack()
	{
		return _attack;
	}

	int Actor::getDefense()
	{
		return _defense;
	}

	string Actor::getType()
	{
		return _type;
	}

	string Actor::getBehavior()
	{
		return _behavior;
	}

	int Actor::getX()
	{
		return _location->getX();
	}

	int Actor::getY()
	{
		return _location->getY();
	}

	int Actor::getZ()
	{
		return _location->getZ();
	}

	Vector3D * Actor::getVectorLocation()
	{
		return _location;
	}

	int Actor::getAlliance()
	{
		return _alliance;
	}

	string Actor::getSymbol()
	{
		return _symbol;
	}

	string Actor::getColor()
	{
		return _color;
	}

	int Actor::getEnemyAlliance()
	{
		return _alliance * -1;
	}

	string Actor::toString()
	{
		return _name;
	}
}
