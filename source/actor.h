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

using namespace std;

class Actor
{

	private:
		float rotation;
		string name;
		float velocity;
		float healthBar;
		float staminaBar;
	public:
		//Constructors
		
		Actor(string myName)
		{
			name = myName;
			rotation = 0;
			velocity = 0;
		}

		//Functions
		/*
			rotation
			@Pre-Condition- takes no arguments
			@Post-Condition- returns rotation
		*/
		inline float getRotation()
		{
			return rotation;
		}

		/*
			name
			@Pre-Condition- takes no arguments
			@Post-Condition- returns name
		*/
		inline string getName()
		{
			return name;
		}

		/*
			velocity
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
			@Post-Condition- returns healthBar
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
			setVelocity
			@Pre-Condition- takes no arguments
			@Post-Condition- returns velocity
		*/
		void setVelocity(float myVelocity)
		{
			velocity = myVelocity;
		}


		
};
