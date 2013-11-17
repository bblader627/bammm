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
 * Actor header file.
 *
 */
#ifndef ACTOR_H_
#define ACTOR_H_

#include <iostream>
#include "../SceneManager/Vector3D.h"
#include "../Weapons/MeleeWeapon.h"
#include "../Weapons/RangedWeapon.h"
#include "ActorInfo.h"

using namespace std;

namespace bammm
{
	class MeleeWeapon;

	class Actor
	{
		protected:
			float _rotation;
			string _name;
			Vector3D *_velocity;
			Vector3D *_location;

			int _healthBar;
			int _staminaBar;
			int MAX_HEALTH;
			int MAX_STAMINA;

			int _attack;
			int _defense;

			int _gold;
			float _BAC;

			enum AllianceType
			{
				enemy = -1, neutral = 0, ally = 1
			};
			AllianceType _alliance;

			MeleeWeapon *_meleeWeapon;
			RangedWeapon *_rangedWeapon;

		public:
			Actor();
			Actor(string name);
			Actor(string name, int health, int stamina, int attack, int defense);
			Actor(ActorInfo* info);

			/**
			 setMeleeWeapon
			 @Pre-Condition- takes no arguments
			 @Post-Condition- sets the weapon to w
			 */
			void setMeleeWeapon(MeleeWeapon* weapon);

			/**
			 setRangedWeapon
			 @Pre-Condition- takes no arguments
			 @Post-Condition- sets the weapon to w
			 */
			void setRangedWeapon(RangedWeapon* weapon);

			/**
			 setRotation
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns rotation
			 */
			void setRotation(float myRotation);

			/**
			 setName
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns name
			 */
			void setName(string name);

			/**
			 setLocation
			 @Pre-Condition- takes the location to set
			 @Post-Condition- returns nothing
			 */
			void setLocation(Vector3D* location);

			/**
			 increaseHealth
			 @Pre-Condition- Takes an float amount
			 @Post-Condition- Increases health by said amount
			 */
			void increaseHealth(int amount);

			/**
			 increaseStamina
			 @Pre-Condition- Takes an float amount
			 @Post-Condition- Increases stamina by said amount
			 */
			void increaseStamina(int amount);

			/**
			 reduceHealth
			 @Pre-Condition- Takes an float amount
			 @Post-Condition- Decreases health by said amount
			 */
			void reduceHealth(int amount);

			/*
			 reduceHealth
			 @Pre-Condition- Takes an float amount
			 @Post-Condition- Decreases stamina by said amount
			 */
			void reduceStamina(int amount);

			/**
			 isFullyRested
			 @Pre-Condition- no parameters
			 @Post-Condition- returns true if healthBar and staminaBar are equal to 								MAX_HEALTH and MAX_STAMINA
			 returns false otherwise;
			 */
			bool isFullyRested();

			/**
			 increaseBAC
			 @Pre-Condition- no parameters;
			 @Post-Condition- increments BAC by .05;
			 */
			void incrementBAC();

			/*
			 resetBAC
			 @Pre-Condition- no parameters;
			 @Post-Condition- sets BAC back to 0
			 */
			void resetBAC();

			/**
			 addGold
			 @Pre-Condition- takes amount of gold to add
			 @Post-Condition- returns total amount of gold
			 */
			int addGold(int amount);

			/**
			 resetBAC
			 @Pre-Condition- takes amount of gold to spend;
			 @Post-Condition- decrements gold and returns true if there is enough, returns false if not
			 */
			bool spendGold(int amount);

			inline int getGold()
			{
				return _gold;
			}

			inline MeleeWeapon* getMeleeWeapon()
			{
				return _meleeWeapon;
			}

			inline RangedWeapon* getRangedWeapon()
			{
				return _rangedWeapon;
			}

			inline float getBAC()
			{
				return _BAC;
			}

			inline float getRotation()
			{
				return _rotation;
			}

			inline string getName()
			{
				return _name;
			}

			inline string getVelocity()
			{
				return _velocity->toString();
			}

			inline Vector3D* getLocation()
			{
				return _location;
			}

			inline int getHealth()
			{
				return _healthBar;
			}

			inline int getStamina()
			{
				return _staminaBar;
			}

			inline int getAttack()
			{
				return _attack;
			}

			inline int getDefense()
			{
				return _defense;
			}

			inline int getX()
			{
				return _location->x();
			}

			inline int getY()
			{
				return _location->y();
			}

			inline int getZ()
			{
				return _location->z();
			}

			inline Vector3D * getVectorLocation()
			{
				return _location;
			}

			inline int getAlliance()
			{
				return _alliance;
			}

			inline int getEnemyAlliance()
			{
				return _alliance * -1;
			}

	};

	Actor::Actor()
	{
		_name = "DefaultName";
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
	}

	Actor::Actor(string name)
	{
		_name = name;
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
	}

	Actor::Actor(string name, int health, int stamina, int attack, int defense)
	{
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
	}

	Actor::Actor(ActorInfo* info)
	{
		_name = info->getName();
		_rotation = 0;
		_velocity = new Vector3D();
		_location = new Vector3D();

		MAX_HEALTH = info->getHealth();
		MAX_STAMINA = info->getStamina();
		_healthBar = MAX_HEALTH;
		_staminaBar = MAX_STAMINA;
		_healthBar = info->getHealth();
		_staminaBar = info->getStamina();
		_attack = info->getAttack();
		_defense = info->getDefense();
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

	void Actor::setLocation(Vector3D* location)
	{
		_location = location;
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
}
#endif
