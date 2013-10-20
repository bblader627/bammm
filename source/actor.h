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

		
};
