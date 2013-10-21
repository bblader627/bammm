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
			healthBar += amount;
		}
		/*
			increaseStamina
			@Pre-Condition- Takes an float amount 
			@Post-Condition- Increases stamina by said amount
		*/
		void increaseStamina(int amount)
		{
			staminaBar += amount;
		}
		/*
			reduceHealth
			@Pre-Condition- Takes an float amount 
			@Post-Condition- Decreases health by said amount
		*/
		void reduceHealth(int amount)
		{
			healthBar -= amount;
		}
		/*
			reduceHealth
			@Pre-Condition- Takes an float amount 
			@Post-Condition- Decreases stamina by said amount
		*/
		void reduceStamina(int amount)
		{
			staminaBar += amount;
		}


		
};
#endif
