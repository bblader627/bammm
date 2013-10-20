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

#include <iostream>
#include "vector3d.h"
using namespace std;

class Actor
{

	private:
		float rotation;
		string name;
		Vector3D velocity;
		Vector3D location;
		float healthBar;
		float staminaBar;
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
		}
		Actor(string myName,float health,float stamina)
		{
			name = myName;
			rotation = 0;
			velocity = new Vector3D();
			location = new Vector3D();
			healthBar = health;
			staminaBar = stamina;
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
			@Post-Condition- returns velocity
		*/
		inline float getVelocity()
		{
			return velocity;
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
			return staminahBar;
		}
		/*
			setRotation
			@Pre-Condition- takes no arguments
			@Post-Condition- returns rotation
		*/
		void setRotation(float myRotation)
		{
			rotation = MyRotation;
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
			healthBar += amount;
		}
		/*
			increaseStamina
			@Pre-Condition- Takes an float amount 
			@Post-Condition- Increases stamina by said amount
		*/
		void increaseStamina(float amount)
		{
			staminaBar += amount;
		}
		/*
			reduceHealth
			@Pre-Condition- Takes an float amount 
			@Post-Condition- Decreases health by said amount
		*/
		void reduceHealth(float amount)
		{
			healthBar -= amount;
		}
		/*
			reduceHealth
			@Pre-Condition- Takes an float amount 
			@Post-Condition- Decreases stamina by said amount
		*/
		void reduceStamina(float amount)
		{
			staminahBar += amount;
		}


		
};
