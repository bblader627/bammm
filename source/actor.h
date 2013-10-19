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


class Actor
{

	private:
		float rotation;
		string name;
		float velocity
	public:
		//Constructors
		
		Actor(string name)
		{
			this.name = name;
			rotation = 0;
			velocity = 0;
		}

		//Functions
		/*
			rotation
			@Pre-Condition- takes no arguments
			@Post-Condition- returns rotation
		*/
		inline  float rotation()
		{
			return rotation;
		}
		/*
			name
			@Pre-Condition- takes no arguments
			@Post-Condition- returns name
		*/
		inline string name()
		{
			return name;
		}
		/*
			velocity
			@Pre-Condition- takes no arguments
			@Post-Condition- returns velocity
		*/
		inline float velocity()
		{
			return velocity;
		}

		
};
