	/*
 * CS585
 *
 * Team BAMMM
 * 	Alvaro Home
 * 	Matt Konstantino
 * 	Michael Abramo
 *
 * Description:
 * 	Vector3D Header Class
 *
 * Last Modified: Alvaro Home
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
			//Constant Variables
			/*static const Vector3D *UP;
			static const Vector3D *DOWN;
			static const Vector3D *LEFT;
			static const Vector3D *RIGHT;
			static const Vector3D *ZERO;*/

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
			 @Post-Condition- returns nothing, just normalizea this Vector
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
			 sqrMagnitude
			 @Pre-Condition-Takes no arguments
			 @Post-Condition- returns sqaured length of vector
			 |a| = sx^2 + y^2 + z^2
			 */	
			float sqrMagnitude();
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
			void divideVector(int n);
			/**
			 multiplyVector
			 @Pre-Condition- Takes in scalar value
			 @Post-Condition- returns a Vector with representing the multiplication
			 Vector Multiplication
			 A*n = {Ax*n,Ay*n,Az*n}  n = scalar value
			 */
			void multiplyVector(int n);
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
			 Overload ==
			 @Pre-Condition-Takes a vector
			 @Post-Condition- compares the equality of the vectors
			 */
			bool operator==(const Vector3D &vector);
			/**
			 Overload !=
			 @Pre-Condition-Takes a vector
			 @Post-Condition- compares the equality of the vectors
			 */
			bool operator!=(const Vector3D &vector);
			/**
			 Overload +
			 @Pre-Condition-Takes a vector
			 @Post-Condition- adds two vectors
			 */
			Vector3D operator+(const Vector3D &vector);
			/**
			 Overload +=
			 @Pre-Condition-Takes a vector
			 @Post-Condition- adds two vectors together stores it in original
			 */
			Vector3D& operator+=(const Vector3D &vector);
			/**
			 Overload -
			 @Pre-Condition-Takes a vector
			 @Post-Condition- subtracts two vectors
			 */
			Vector3D operator-(const Vector3D &vector);
			/**
			 Overload -=
			 @Pre-Condition-Takes a vector
			 @Post-Condition- subtracts two vectors together stores it in original
			 */
			Vector3D& operator-=(const Vector3D &vector);

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
		 { 0, 0, 0 };*/
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
		 { 0, 0, 0 };*/
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


	float Vector3D::sqrMagnitude()
	{
		return (_x * _x) + (_y * _y) + (_z * _z);
	}


	float Vector3D::dotProduct(Vector3D &vect)
	{
		return (_x * vect.x()) + (_y * vect.y()) + (_z * vect.z());
	}


	void Vector3D::divideVector(int n)
	{
		_x = _x / n;
		_y = _y / n;
		_z = _z / n;
	}


	void Vector3D::multiplyVector(int n)
	{
		_x = _x * n;
		_y = _y * n;
		_z = _z * n;
	}


	Vector3D Vector3D::crossProduct(Vector3D &vector)
	{
		return Vector3D((_y * vector.z()) - (_z - vector.y()),
				(_x * vector.z()) - (_z - vector.x()),
				(_x * vector.y()) - (_y - vector.x()));

	}


	string Vector3D::toString()
	{
		/*string output;
		output.append("<");
		output.append(output.to_string(x));
		output.append(",");
		output.append(output.to_string(y));
		output.append(",");
		output.append(output.to_string(z));
		output.append(">");
		return "<" + to_string(x) + "," + to_string(y) + "," + to_string(z) + ">";*/
        return "";
	}


	bool Vector3D::operator==(const Vector3D &vector)
	{
		if ((_x == vector.x()) && (_y == vector.y()) && (_z == vector.z()))
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
		if ((_x == vector.x()) && (_y == vector.y()) && (_z == vector.z()))
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
		return Vector3D(_x + vector.x(), _y + vector.y(), _z + vector.z());
	}


	Vector3D& Vector3D::operator+=(const Vector3D &vector)
	{
		_x += vector.x();
		_y += vector.y();
		_z += vector.z();
		return *this;
	}


	Vector3D Vector3D::operator-(const Vector3D &vector)
	{
		return Vector3D(_x - vector.x(), _y - vector.y(), _z - vector.z());
	}


	Vector3D& Vector3D::operator-=(const Vector3D &vector)
	{
		_x -= vector.x();
		_y -= vector.y();
		_z -= vector.z();
		return *this;
	}





}
#endif

