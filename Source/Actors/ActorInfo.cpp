#include <iostream>

using namespace std;

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
	}

	ActorInfo::ActorInfo(string type, string name, int health, int stamina, int attack, int defense, string behavior)
	{
		_type = type;
		_name = name;
		_health = health;
		_stamina = stamina;
		_attack = attack;
		_defense = defense;
		_behavior = behavior;
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
}
