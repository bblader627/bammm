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
 * ActorInfo header file.
 *
 */
#ifndef ACTORINFO_H_
#define ACTORINFO_H_

#include <iostream>

using namespace std;

namespace bammm
{
	class ActorInfo
	{
		private:
			string _name;
			int _health;
			int _stamina;
			int _attack;
			int _defense;

		public:
			ActorInfo(string name, int health, int stamina, int attack,
					int defense);

			/**
			 getName
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns name
			 */
			string getName();

			/**
			 getHealth
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns health
			 */
			int getHealth();

			/**
			 getStamina
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns stamina
			 */
			int getStamina();

			/**
			 getAttack
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns attack
			 */
			int getAttack();

			/**
			 getDefense
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns defense
			 */
			int getDefense();

			/**
			 setName
			 @Pre-Condition- takes in name to set
			 @Post-Condition- returns void
			 */
			void setName(string name);

			/**
			 setHealth
			 @Pre-Condition- takes in health to set
			 @Post-Condition- returns void
			 */
			void setHealth(int health);

			/**
			 setStamina
			 @Pre-Condition- takes in stamina to set
			 @Post-Condition- returns void
			 */
			void setStamina(int stamina);

			/**
			 setAttack
			 @Pre-Condition- takes in attack
			 @Post-Condition- returns void
			 */
			void setAttack(int attack);

			/**
			 setDefense
			 @Pre-Condition- takes in defense
			 @Post-Condition- returns void
			 */
			void setDefense(int defense);
	};

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

#endif
