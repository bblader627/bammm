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

		int healthBar;
		int staminaBar;
		int MAX_HEALTH;
		int MAX_STAMINA;

		int attack;
		int defense;

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
			healthBar = 100;
			staminaBar = 50;
			attack = 4;
			defense = 2;
		}
		
		Actor(string myName,int health,int stamina,int atck, int def)
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
		inline int getHealth()
		{
			return healthBar;
		}
		
		/*
			getStamina
			@Pre-Condition- takes no arguments
			@Post-Condition- returns staminaBar
		*/
		inline int getStamina()
		{
			return staminaBar;
		}
		/*
			getAttack
			@Pre-Condition- takes no arguments
			@Post-Condition- returns healthBar
		*/
		inline int getAttack()
		{
			return attack;
		}
		/*
			getDefense
			@Pre-Condition- takes no arguments
			@Post-Condition- returns defense
		*/
		inline int getDefense()
		{
			return defense;
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
		void increaseHealth(int amount)
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
		void increaseStamina(int amount)
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
		void reduceHealth(int amount)
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
		void reduceStamina(int amount)
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
		bool isFullyRested()
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
