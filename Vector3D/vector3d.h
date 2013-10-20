/*
 * CS585
 *
 * Team BAMMM
 * 	Alvaro Home
 * 	Matt Konstantino
 * 	Michael Abramo
 *
 * Description:
 * 	Vector3d Header Class
 *
 * Last Modified: Alvaro Home
 *
 */

#ifndef VECTOR3D_H_
#define VECTOR3D_H_

#include <math.h>
#include <iostream>
#include <string>
using namespace std;

#ifndef NULL
#define NULL (void *)0
#endif

class Vector3d
{
	private:
		float x;
		float y;
		float z;

	public:
		//Constant Variables
		const Vector3d UP;
		const Vector3d DOWN;
		const Vector3d LEFT;
		const Vector3d RIGHT;
		const Vector3d ZERO;

		//Constructors		
		Vector3d();
		Vector3d(float x, float y, float z);

		//Destructor
		~Vector3d();

		//Operator Overloads
		/*
		 Overload ==
		 @Pre-Condition-Takes a vector
		 @Post-Condition- compares the equality of the vectors
		 */
		bool operator==(const Vector3d *vect);
		/*
		 Overload !=
		 @Pre-Condition-Takes a vector
		 @Post-Condition- compares the equality of the vectors
		 */
		bool operator!=(const Vector3d *vect);
		/*
		 Overload +
		 @Pre-Condition-Takes a vector
		 @Post-Condition- adds two vectors
		 */
		bool operator+(const Vector3d *vect);
		/*
		 Overload +=
		 @Pre-Condition-Takes a vector
		 @Post-Condition- adds two vectors together stores it in original
		 */
		bool operator+=(const Vector3d *vect);
		/*
		 Overload -
		 @Pre-Condition-Takes a vector
		 @Post-Condition- subtracts two vectors
		 */
		bool operator-(const Vector3d *vect);
		/*
		 Overload -=
		 @Pre-Condition-Takes a vector
		 @Post-Condition- subtracts two vectors together stores it in original
		 */
		bool operator-=(const Vector3d *vect);

		//Functions
		/*
		 normalize
		 @Pre-Condition-Takes no arguments
		 @Post-Condition- returns nothing, just normalizea this Vector
		 Normal
		 A = {x,y,z} / |a| |a| = magnitude
		 */
		void normalize();

		/*
		 magnitude
		 @Pre-Condition-Takes no arguments
		 @Post-Condition- returns vectors length
		 |a| = sqrt( x^2 + y^2 + z^2)
		 */
		float magnitude();

		/*
		 set
		 @Pre-Condition- Takes in new values for x,y,z components
		 @Post-Condition- Returns nothing but sets x,y,z components to new values
		 */
		void set(float a, float b, float c);
		/*
		 Accessors/Mutators
		 Easier than using set and get Functions
		 Vector require multiple acces to these variables.
		 */
		inline float x() const
		{
			return _x;
		}

		inline float y() const
		{
			return _y;
		}

		inline float z() const
		{
			return _z;
		}

		inline float& x()
		{
			return _x;
		}

		inline float& y()
		{
			return _y;
		}

		inline float& z()
		{
			return _z;
		}
		/*
		 dotProduct
		 @Pre-Condition-Takes a Vector and will perform a Dot Product
		 @Post-Condition- It will return the resulting int
		 Dot Product
		 A*B = Ax*Bx + Ay*By + Az*Bz
		 */
		float dotProduct(Vector3d *vect);
		/*
		 divideVector
		 @Pre-Condition- Takes in scalar value
		 @Post-Condition- returns a Vector with representing the division
		 Vector Division
		 A/n = {Ax/n,Ay/n,Az/n}  n = scalar value
		 */
		void divideVector(int n);

		/*
		 multiplyVector
		 @Pre-Condition- Takes in scalar value
		 @Post-Condition- returns a Vector with representing the multiplication
		 Vector Multiplication
		 A*n = {Ax*n,Ay*n,Az*n}  n = scalar value
		 */
		void multiplyVector(int n);

		/*
		 crossProduct
		 @Pre-Condition- Takes a Vector and performs a Cross Product
		 @Post-Condition- returns a vector representing the result
		 Cross Product
		 AxB = [(Ay * Bz) - (Az - By), (Ax * Bz) - (Az - Bx), (Ax * By) - (Ay -Bx)]
		 */
		Vector3d* crossProduct(Vector3d *vect);

		/*
		 toString
		 @Pre-Condition- Takes no parameters
		 @Post-Condition- returns a String representing a vector
		 */
		string toString();
};

#endif

