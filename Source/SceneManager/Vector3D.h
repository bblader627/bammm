/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *  Bradley Crusco
 * Description:
 * Vector3D header file.
 *
 */

#ifndef VECTOR3D_H_
#define VECTOR3D_H_

#include <math.h>
#include <iostream>
#include <string>
#include "../Resources/Constant.h"

using namespace std;

namespace bammm
{
	class Vector3D
	{
		private:
			float _x;
			float _y;
			float _z;

		public:
			Vector3D();
			Vector3D(float x, float y, float z);
			~Vector3D();

			/**
			 set
			 @Pre-Condition- Takes in new values for x,y,z components
			 @Post-Condition- Returns nothing but sets x,y,z components to new values
			 */
			void set(float a, float b, float c);

			/**
			 normalize
			 @Pre-Condition-Takes no arguments
			 @Post-Condition- returns nothing, just normalizes this vector
			 Normal
			 A = {x,y,z} / |a| |a| = magnitude
			 */
			void normalize();

			/**
			 magnitude
			 @Pre-Condition-Takes no arguments
			 @Post-Condition- returns vectors length
			 |a| = sqrt( x^2 + y^2 + z^2)
			 */
			float magnitude();

			/*
			 squareMagnitude
			 @Pre-Condition-Takes no arguments
			 @Post-Condition- returns sqaured length of vector
			 |a| = sx^2 + y^2 + z^2
			 */
			float squareMagnitude();

			/**
			 dotProduct
			 @Pre-Condition-Takes a Vector and will perform a Dot Product
			 @Post-Condition- It will return the resulting int
			 Dot Product
			 A*B = Ax*Bx + Ay*By + Az*Bz
			 */
			float dotProduct(Vector3D &vector);

			/**
			 divideVector
			 @Pre-Condition- Takes in scalar value
			 @Post-Condition- returns a Vector with representing the division
			 Vector Division
			 A/n = {Ax/n,Ay/n,Az/n}  n = scalar value
			 */
			void divideVector(int scalar);

			/**
			 multiplyVector
			 @Pre-Condition- Takes in scalar value
			 @Post-Condition- returns a Vector with representing the multiplication
			 Vector Multiplication
			 A*n = {Ax*n,Ay*n,Az*n}  n = scalar value
			 */
			void multiplyVector(int scalar);

			/**
			 crossProduct
			 @Pre-Condition- Takes a Vector and performs a Cross Product
			 @Post-Condition- returns a vector representing the result
			 Cross Product
			 AxB = [(Ay * Bz) - (Az - By), (Ax * Bz) - (Az - Bx), (Ax * By) - (Ay -Bx)]
			 */
			Vector3D crossProduct(Vector3D &vector);

			/**
			 toString
			 @Pre-Condition- Takes no parameters
			 @Post-Condition- returns a String representing a vector
			 */
			string toString();

			/**
			 operator==
			 @Pre-Condition-Takes a vector
			 @Post-Condition- compares the equality of the vectors
			 */
			bool operator==(const Vector3D &vector);

			/**
			 operator!=
			 @Pre-Condition-Takes a vector
			 @Post-Condition- compares the equality of the vectors
			 */
			bool operator!=(const Vector3D &vector);

			/**
			 operator+
			 @Pre-Condition-Takes a vector
			 @Post-Condition- adds two vectors
			 */
			Vector3D operator+(const Vector3D &vector);

			/**
			 operator+=
			 @Pre-Condition-Takes a vector
			 @Post-Condition- adds two vectors together stores it in original
			 */
			Vector3D& operator+=(const Vector3D &vector);

			/**
			 operator-
			 @Pre-Condition-Takes a vector
			 @Post-Condition- subtracts two vectors
			 */
			Vector3D operator-(const Vector3D &vector);

			/**
			 operator-=
			 @Pre-Condition-Takes a vector
			 @Post-Condition- subtracts two vectors together stores it in original
			 */
			Vector3D& operator-=(const Vector3D &vector);

			/**
			 getX
			 @Pre-Condition- No input
			 @Post-Condition- Returns _x
			 */
			float getX() const;

			/**
			 getY
			 @Pre-Condition- No input
			 @Post-Condition- Returns _y
			 */
			float getY() const;

			/**
			 getZ
			 @Pre-Condition- No input
			 @Post-Condition- Returns _z
			 */
			float getZ() const;

			/**
			 getX
			 @Pre-Condition- No input
			 @Post-Condition- Returns _x
			 */
			float& getX();

			/**
			 getY
			 @Pre-Condition- No input
			 @Post-Condition- Returns _y
			 */
			float& getY();

			/**
			 getZ
			 @Pre-Condition- No input
			 @Post-Condition- Returns _z
			 */
			float& getZ();
	};
}

#endif
