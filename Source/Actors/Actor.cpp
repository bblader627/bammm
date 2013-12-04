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
#include "../Inventory/Inventory.h"

namespace bammm
{
	Actor::Actor()
	{
		_rotation = 0;
		_velocity = new Vector3D();
		_location = new Vector3D();
		_collision = false;
		_stats = new ActorInfo();
	}

	Actor::Actor(ActorInfo* info)
	{
		_stats->setType(info->getType());
		_stats->setName(info->getName());
		_rotation = 0;
		_velocity = new Vector3D();
		_location = info->getLocation();

		_stats->setHealth(info->getHealth());
		_stats->setStamina(info->getStamina());
		_stats->setAttack(info->getAttack());
		_stats->setDefense(info->getDefense());

		_stats->setBehavior(info->getBehavior());
		_stats->setAlliance(info->getAlliance());
		_stats->setCollision(info->getCollision());
		_stats->setSymbol(info->getSymbol());
		_stats->setColor(info->getColor());
		_stats->setWood(info->getWood());
		_iron = info->getIron();
		_gold = info->getGold();
		_coal = info->getCoal();
		_BAC = 0;
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
		_stats->setName(name);
	}

	void Actor::setType(string type)
	{
		_stats->setType(type);
	}

	void Actor::setLocation(Vector3D* location)
	{
		_location = location;
	}

	void Actor::setSymbol(string symbol)
	{
		_stats->setSymbol(symbol);
	}

	void Actor::setColor(string color)
	{
		_stats->setColor(color);
	}

	void Actor::setGold(int gold)
	{
		_stats->setGold(gold);
	}

	void Actor::setIron(int iron)
	{
		_stats->setIron(iron);
	}

	void Actor::setCoal(int coal)
	{
		_stats->setCoal(coal);
	}

	void Actor::setWood(int wood)
	{
		_stats->setWood(wood);
	}

	void Actor::increaseHealth(int amount)
	{
		_stats->increaseHealth(amount);
	}

	void Actor::increaseStamina(int amount)
	{
		_stats->increaseStamina(amount);
	}

	void Actor::reduceHealth(int amount)
	{
		_stats->reduceHealth(amount);
	}

	void Actor::reduceStamina(int amount)
	{
		_stats->reduceStamina(amount);
	}

	bool Actor::isFullyRested()
	{
		return _stats->isFullyRested();
	}

	void Actor::incrementBAC()
	{
		_stats->incrementBAC();
	}

	int Actor::addGold(int amount)
	{
		return _stats->addGold(amount);
	}

	bool Actor::spendGold(int amount)
	{
		return _stats->spendGold(amount);
	}

	int Actor::getGold()
	{
		return _stats->getGold();
	}

	int Actor::getWood()
	{
		return _stats->getWood();
	}

	int Actor::getCoal()
	{
		return _stats->getCoal();
	}

	int Actor::getIron()
	{
		return _stats->getIron();
	}

	bool Actor::getCollision()
	{
		return _stats->getCollision();
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
		return _stats->getBAC();
	}

	float Actor::getRotation()
	{
		return _rotation;
	}

	string Actor::getName()
	{
		return _stats->getName();
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
		return _stats->getHealth();
	}

	void Actor::setHealth(int newHealth)
	{
		_stats->setHealth(newHealth);
	}

	int Actor::getStamina()
	{
		return _stats->getStamina();
	}

	int Actor::getMaximumHealth()
	{
		return _stats->getMaximumHealth();
	}

	int Actor::getMaximumStamina()
	{
		return _stats->getMaximumStamina();
	}

	void Actor::setMaximumHealth(int maximumHealth)
	{
		_stats->setMaximumHealth(maximumHealth);
	}

	void Actor::setMaximumStamina(int maximumStamina)
	{
		_stats->setMaximumStamina(maximumStamina);
	}

	int Actor::getAttack()
	{
		return _stats->getAttack();
	}

	void Actor::setAttack(int newAttack)
	{
		_stats->setAttack(newAttack);
	}

	int Actor::getDefense()
	{
		return _stats->getDefense();
	}

	void Actor::setDefense(int newDefense)
	{
		_stats->setDefense(newDefense);
	}

	string Actor::getType()
	{
		return _stats->getType();
	}

	DynamicArray<string>* Actor::getBaseBehaviors()
	{
		return _stats->getBaseBehaviors();
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

	AllianceType Actor::getAlliance()
	{
		return _stats->getAlliance();
	}

	string Actor::getSymbol()
	{
		return _stats->getSymbol();
	}

	string Actor::getColor()
	{
		return _stats->getColor();
	}

	int Actor::getEnemyAlliance()
	{
		return _stats->getEnemyAlliance();
	}
	
	Inventory& Actor::getInventory()
	{
		return _inventory;
	}

	void Actor::setLevel(int newLevel)
	{
		_stats->setLevel(newLevel);
	}

	int Actor::getExperience()
	{
		return _stats->getExperience();
	}

	void Actor::setExperience(int newExperience)
	{
		_stats->setExperience(newExperience);
	}

	int Actor::getTotalExperienceThisLevel()
	{
		return _stats->getTotalExperienceThisLevel();
	}

	void Actor::setTotalExperienceThisLevel(int newTotalExperienceThisLevel)
	{
		_stats->setTotalExperienceThisLevel(newTotalExperienceThisLevel);
	}

	string Actor::toString()
	{
		return _stats->getName();
	}
}
