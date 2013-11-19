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

#ifndef NULL
#define NULL (void *)0
#endif

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
			/*
			 static const Vector3D *UP;
			 static const Vector3D *DOWN;
			 static const Vector3D *LEFT;
			 static const Vector3D *RIGHT;
			 static const Vector3D *ZERO;
			 */

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

	Vector3D::Vector3D()
	{
		_x = 0;
		_y = 0;
		_z = 0;

		/*
		 const Vector3D Vector3D::UP =
		 { 0, 1, 0 };
		 const Vector3D Vector3D::DOWN =
		 { 0, -1, 0 };
		 const Vector3D Vector3D::LEFT =
		 { -1, 0, };
		 const Vector3D Vector3D::RIGHT =
		 { 1, 0, 0 };
		 const Vector3D Vector3D::ZERO =
		 { 0, 0, 0 };
		 */
	}

	Vector3D::Vector3D(float x, float y, float z)
	{
		_x = x;
		_y = y;
		_z = z;

		/*
		 const Vector3D Vector3D::UP =
		 { 0, 1, 0 };
		 const Vector3D Vector3D::DOWN =
		 { 0, -1, 0 };
		 const Vector3D Vector3D::LEFT =
		 { -1, 0, };
		 const Vector3D Vector3D::RIGHT =
		 { 1, 0, 0 };
		 const Vector3D Vector3D::ZERO =
		 { 0, 0, 0 };
		 */
	}

	Vector3D::~Vector3D()
	{
	}

	void Vector3D::set(float x, float y, float z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	void Vector3D::normalize()
	{
		float normal = magnitude();
		_x = _x / normal;
		_y = _y / normal;
		_z = _z / normal;
	}

	float Vector3D::magnitude()
	{
		return sqrt((_x * _x) + (_y * _y) + (_z * _z));
	}

	float Vector3D::squareMagnitude()
	{
		return (_x * _x) + (_y * _y) + (_z * _z);
	}

	float Vector3D::dotProduct(Vector3D &vect)
	{
		return (_x * vect.getX()) + (_y * vect.getY()) + (_z * vect.getZ());
	}

	void Vector3D::divideVector(int scalar)
	{
		_x = _x / scalar;
		_y = _y / scalar;
		_z = _z / scalar;
	}

	void Vector3D::multiplyVector(int scalar)
	{
		_x = _x * scalar;
		_y = _y * scalar;
		_z = _z * scalar;
	}

	Vector3D Vector3D::crossProduct(Vector3D &vector)
	{
		return Vector3D((_y * vector.getZ()) - (_z - vector.getY()),
				(_x * vector.getZ()) - (_z - vector.getX()),
				(_x * vector.getY()) - (_y - vector.getX()));

	}

	string Vector3D::toString()
	{
		return "";
	}

	bool Vector3D::operator==(const Vector3D &vector)
	{
		if ((_x == vector.getX()) && (_y == vector.getY())
				&& (_z == vector.getZ()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Vector3D::operator!=(const Vector3D &vector)
	{
		if ((_x == vector.getX()) && (_y == vector.getY())
				&& (_z == vector.getZ()))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	Vector3D Vector3D::operator+(const Vector3D &vector)
	{
		return Vector3D(_x + vector.getX(), _y + vector.getY(),
				_z + vector.getZ());
	}

	Vector3D& Vector3D::operator+=(const Vector3D &vector)
	{
		_x += vector.getX();
		_y += vector.getY();
		_z += vector.getZ();
		return *this;
	}

	Vector3D Vector3D::operator-(const Vector3D &vector)
	{
		return Vector3D(_x - vector.getX(), _y - vector.getY(),
				_z - vector.getZ());
	}

	Vector3D& Vector3D::operator-=(const Vector3D &vector)
	{
		_x -= vector.getX();
		_y -= vector.getY();
		_z -= vector.getZ();
		return *this;
	}

	float Vector3D::getX() const
	{
		return _x;
	}

	float Vector3D::getY() const
	{
		return _y;
	}

	float Vector3D::getZ() const
	{
		return _z;
	}

	float& Vector3D::getX()
	{
		return _x;
	}

	float& Vector3D::getY()
	{
		return _y;
	}

	float& Vector3D::getZ()
	{
		return _z;
	}
}

#endif
