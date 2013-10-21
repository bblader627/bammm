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
			float rotation;
			string name;
			Vector3D *velocity;
			Vector3D *location;

			int healthBar;
			int staminaBar;
			int MAX_HEALTH;
			int MAX_STAMINA;

			int attack;
			int defense;

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
				return rotation;
			}

			inline string getName()
			{
				return name;
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
				return healthBar;
			}

			inline int getStamina()
			{
				return staminaBar;
			}

			inline int getAttack()
			{
				return attack;
			}

			inline int getDefense()
			{
				return defense;
			}


		
	};

	Actor::Actor(string myName)
	{
		name = myName;
		rotation = 0;
		velocity = new Vector3D();
		location = new Vector3D();

		MAX_HEALTH = 100;
		MAX_STAMINA = 50;
		healthBar = MAX_HEALTH;
		staminaBar = MAX_STAMINA;
		healthBar = 100;
		staminaBar = 50;
		attack = 4;
		defense = 2;
	}

	Actor::Actor(string myName,int health,int stamina,int atck, int def)
	{
		name = myName;
		rotation = 0;
		velocity = new Vector3D();
		location = new Vector3D();
	
		MAX_HEALTH = health;
		MAX_STAMINA = stamina;
		healthBar = MAX_HEALTH;
		staminaBar = MAX_STAMINA;
		healthBar = health;
		staminaBar = stamina;
		attack = atck;
		defense = def;
	}

	void Actor::setRotation(float myRotation)
	{
		rotation = myRotation;
	}


	void Actor::setName(string myName)
	{
		name = myName;
	}


	void Actor::increaseHealth(int amount)
	{
		if (healthBar>=MAX_HEALTH)
		{
			healthBar = MAX_HEALTH;
			return;
		}
		else
		{
			healthBar += amount;
		}
	}


	void Actor::increaseStamina(int amount)
	{
		if (staminaBar>=MAX_STAMINA)
		{
			staminaBar = MAX_STAMINA;
			return;
		}
		else
		{
			staminaBar += amount;
		}
	}


	void Actor::reduceHealth(int amount)
	{
		if (healthBar > 0)
		{
			healthBar -= amount;
		}
		else
		{
			healthBar = 0;
			return;
		}
	}


	void Actor::reduceStamina(int amount)
	{
		if (staminaBar > 0)
		{
			staminaBar -= amount;
		}
		else
		{
			staminaBar = 0;
			return;
		}
	}


	bool Actor::isFullyRested()
	{
		if (healthBar == MAX_HEALTH && staminaBar == MAX_STAMINA)
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
