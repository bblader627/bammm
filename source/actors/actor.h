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
using namespace bammm;

class Actor
{

	private:
		float rotation;
		string name;
		Vector3D *velocity;
		Vector3D *location;
		float healthBar;
		float staminaBar;
		float MAX_HEALTH;
		float MAX_STAMINA;
	public:
		//Constructors
		
		Actor(string myName)
		{
			name = myName;
			rotation = 0;
			velocity = new Vector3D();
			location = new Vector3D();

			MAX_HEALTH = 100;
			MAX_STAMINA = 50;
			healthBar = MAX_HEALTH;
			staminaBar = MAX_STAMINA;
		}
		Actor(string myName,float health,float stamina)
		{
			name = myName;
			rotation = 0;
			velocity = new Vector3D();
			location = new Vector3D();

			MAX_HEALTH = health;
			MAX_STAMINA = stamina;
			healthBar = MAX_HEALTH;
			staminaBar = MAX_STAMINA;
		}

		//Functions
		/*
			getRotation
			@Pre-Condition- takes no arguments
			@Post-Condition- returns rotation
		*/
		inline float getRotation()
		{
			return rotation;
		}

		/*
			getName
			@Pre-Condition- takes no arguments
			@Post-Condition- returns name
		*/
		inline string getName()
		{
			return name;
		}

		/*
			getVelocity
			@Pre-Condition- takes no arguments
			@Post-Condition- returns velocity vector representation
		*/
		inline string getVelocity()
		{
			return velocity->toString();
		}

		/*
			getLocation
			@Pre-Condition- takes no arguments
			@Post-Condition- returns velocity vector representation
		*/
		inline string getLocation()
		{
			return location->toString();
		}
		/*
			getHealth
			@Pre-Condition- takes no arguments
			@Post-Condition- returns healthBar
		*/
		inline float getHealth()
		{
			return healthBar;
		}
		/*
			getStamina
			@Pre-Condition- takes no arguments
			@Post-Condition- returns staminaBar
		*/
		inline float getStamina()
		{
			return staminaBar;
		}
		/*
			setRotation
			@Pre-Condition- takes no arguments
			@Post-Condition- returns rotation
		*/
		void setRotation(float myRotation)
		{
			rotation = myRotation;
		}

		/*
			setName
			@Pre-Condition- takes no arguments
			@Post-Condition- returns name
		*/
		void setName(string myName)
		{
			name = myName;
		}
		/*
			increaseHealth
			@Pre-Condition- Takes an float amount 
			@Post-Condition- Increases health by said amount
		*/
		void increaseHealth(float amount)
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
		/*
			increaseStamina
			@Pre-Condition- Takes an float amount 
			@Post-Condition- Increases stamina by said amount
		*/
		void increaseStamina(float amount)
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
		/*
			reduceHealth
			@Pre-Condition- Takes an float amount 
			@Post-Condition- Decreases health by said amount
		*/
		void reduceHealth(float amount)
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
		/*
			reduceHealth
			@Pre-Condition- Takes an float amount 
			@Post-Condition- Decreases stamina by said amount
		*/
		void reduceStamina(float amount)
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

		/*
		 	isFullyRested
		 	@Pre-Condition- no parameters
		 	@Post-Condition- returns true if healthBar and staminaBar are equal to MAX_HEALTH and MAX_STAMINA
		 					 returns false otherwise;
		 */
		boolean isFullyRested()
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
		
};
#endif
