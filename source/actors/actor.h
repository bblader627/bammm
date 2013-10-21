/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *
 * Description:
 * Actor header file.
 *
 * Last Modified: Alvaro Home
 *
 */
#ifndef ACTOR_H_
#define ACTOR_H_

#include <iostream>
#include "../resources/vector3d.h"
using namespace std;

namespace bammm
{
	class Actor
	{

		private:
			float _rotation;
			string _name;
			Vector3D *velocity;
			Vector3D *location;

			int _healthBar;
			int _staminaBar;
			int MAX_HEALTH;
			int MAX_STAMINA;

			int _attack;
			int _defense;

		public:
			//Constructors
			Actor(string myName);
			Actor(string myName,int health,int stamina,int atck, int def);

			//Functions
			/*
				setRotation
				@Pre-Condition- takes no arguments
				@Post-Condition- returns rotation
			*/
			void setRotation(float myRotation);
			/*
				setName
				@Pre-Condition- takes no arguments
				@Post-Condition- returns name
			*/
			void setName(string myName);
			/*
				increaseHealth
				@Pre-Condition- Takes an float amount 
				@Post-Condition- Increases health by said amount
			*/
			void increaseHealth(int amount);
			/*
				increaseStamina
				@Pre-Condition- Takes an float amount 
				@Post-Condition- Increases stamina by said amount
			*/
			void increaseStamina(int amount);
			/*
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
			/*
			 	isFullyRested
			 	@Pre-Condition- no parameters
			 	@Post-Condition- returns true if healthBar and staminaBar are equal to MAX_HEALTH and MAX_STAMINA
			 					 returns false otherwise;
			 */
			bool isFullyRested();

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
				return velocity->toString();
			}

			inline string getLocation()
			{
				return location->toString();
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


		
	};

	Actor::Actor(string myName)
	{
		_name = myName;
		_rotation = 0;
		velocity = new Vector3D();
		location = new Vector3D();

		MAX_HEALTH = 100;
		MAX_STAMINA = 50;
		_healthBar = MAX_HEALTH;
		_staminaBar = MAX_STAMINA;
		_healthBar = 100;
		_staminaBar = 50;
		_attack = 4;
		_defense = 2;
	}

	Actor::Actor(string myName,int health,int stamina,int atck, int def)
	{
		_name = myName;
		_rotation = 0;
		velocity = new Vector3D();
		location = new Vector3D();
	
		MAX_HEALTH = health;
		MAX_STAMINA = stamina;
		_healthBar = MAX_HEALTH;
		_staminaBar = MAX_STAMINA;
		_healthBar = health;
		_staminaBar = stamina;
		_attack = atck;
		_defense = def;
	}

	void Actor::setRotation(float myRotation)
	{
		_rotation = myRotation;
	}


	void Actor::setName(string myName)
	{
		_name = myName;
	}


	void Actor::increaseHealth(int amount)
	{
		if (_healthBar>=MAX_HEALTH)
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
		if (_staminaBar>=MAX_STAMINA)
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
			return;
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
}
#endif
