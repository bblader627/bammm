/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *   Bradley Crusco
 * Description:
 * Actor header file.
 *
 * Last Modified: Alvaro Home
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
		//string myName, int health, int stamina, int atck, int def
		private:
			string _name;
			int _health;
			int _stamina;
			int _attack;
			int _defense;
		public:
			ActorInfo(string myName, int health, int stamina, int atck, int def);
			string getName();
			int getHealth();
			int getStamina();
			int getAttack();
			int getDefense();

			//void setName();
			void setHealth(int health);
			void setStamina(int stamina);
			void setAttack(int attack);
			void setDefense(int defense);
	};

	ActorInfo::ActorInfo(string myName, int health, int stamina, int atck, int def)
	{
		_name = myName;
		_health = health;
		_stamina = stamina;
		_attack = atck;
		_defense = def;
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
