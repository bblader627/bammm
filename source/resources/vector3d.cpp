/**
 * CS585
 *
 * Team MMA
 * 	Alvaro Home
 * 	Matt Konstantino
 * 	Michael Abramo
 *
 * Description:
 * 	Vector3d Template Class
 *
 * Last Modified: Alvaro Home
 *
 */

#include "vector3d.h"
using namespace std;

namespace bammm
{

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

	/**
	 set
	 @Pre-Condition- Takes in new values for x,y,z components
	 @Post-Condition- Returns nothing but sets x,y,z components to new values
	 */
	void Vector3D::set(float x, float y, float z)
	{
		_x = x;
		_y = y;
		_z = z;
	}

	/**
	 normalize
	 @Pre-Condition-Takes no arguments
	 @Post-Condition- returns nothing, just normalizea this Vector
	 Normal
	 A = {x,y,z} / |a| |a| = magnitude
	 */
	void Vector3D::normalize()
	{
		float normal = magnitude();
		_x = _x / normal;
		_y = _y / normal;
		_z = _z / normal;
	}

	/**
	 magnitude
	 @Pre-Condition-Takes no arguments
	 @Post-Condition- returns vectors length
	 |a| = sqrt( x^2 + y^2 + z^2)
	 */
	float Vector3D::magnitude()
	{
		return sqrt((_x * _x) + (_y * _y) + (_z * _z));
	}
	/*
	 sqrMagnitude
	 @Pre-Condition-Takes no arguments
	 @Post-Condition- returns sqaured length of vector
	 |a| = sx^2 + y^2 + z^2
	 */
	float Vector3D::sqrMagnitude()
	{
		return (_x * _x) + (_y * _y) + (_z * _z);
	}

	/**
	 dotProduct
	 @Pre-Condition-Takes a Vector and will perform a Dot Product
	 @Post-Condition- It will return the resulting int
	 Dot Product
	 A*B = Ax*Bx + Ay*By + Az*Bz
	 */
	float Vector3D::dotProduct(Vector3D &vect)
	{
		return (_x * vect.x()) + (_y * vect.y()) + (_z * vect.z());
	}

	/**
	 divideVector
	 @Pre-Condition- Takes in scalar value
	 @Post-Condition- returns a Vector with representing the division
	 Vector Division
	 A/n = {Ax/n,Ay/n,Az/n}  n = scalar value
	 */
	void Vector3D::divideVector(int n)
	{
		_x = _x / n;
		_y = _y / n;
		_z = _z / n;
	}

	/**
	 multiplyVector
	 @Pre-Condition- Takes in scalar value
	 @Post-Condition- returns a Vector with representing the multiplication
	 Vector Multiplication
	 A*n = {Ax*n,Ay*n,Az*n}  n = scalar value
	 */
	void Vector3D::multiplyVector(int n)
	{
		_x = _x * n;
		_y = _y * n;
		_z = _z * n;
	}

	/**
	 crossProduct
	 @Pre-Condition- Takes a Vector and performs a Cross Product
	 @Post-Condition- returns a vector representing the result
	 Cross Product
	 AxB = [(Ay * Bz) - (Az - By), (Ax * Bz) - (Az - Bx), (Ax * By) - (Ay -Bx)]
	 */
	Vector3D Vector3D::crossProduct(Vector3D &vector)
	{
		return Vector3D((_y * vector.z()) - (_z - vector.y()),
				(_x * vector.z()) - (_z - vector.x()),
				(_x * vector.y()) - (_y - vector.x()));

	}

	/**
	 toString
	 @Pre-Condition- Takes no parameters
	 @Post-Condition- returns a String representing a vector
	 */
	string Vector3D::toString()
	{
		return "<" + std::to_string(_x) + " " + std::to_string(_y) + " "
				+ std::to_string(_z) + ">";
	}

	/**
	 Overload ==
	 @Pre-Condition-Takes a vector
	 @Post-Condition- compares the equality of the vectors
	 */
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

	/**
	 Overload !=
	 @Pre-Condition-Takes a vector
	 @Post-Condition- compares the equality of the vectors
	 */
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

	/**
	 Overload +
	 @Pre-Condition-Takes a vector
	 @Post-Condition- adds two vectors
	 */
	Vector3D Vector3D::operator+(const Vector3D &vector)
	{
		return Vector3D(_x + vector.x(), _y + vector.y(), _z + vector.z());
	}

	/**
	 Overload +=
	 @Pre-Condition-Takes a vector
	 @Post-Condition- adds two vectors together stores it in original
	 */
	Vector3D& Vector3D::operator+=(const Vector3D &vector)
	{
		_x += vector.x();
		_y += vector.y();
		_z += vector.z();
	}

	/**
	 Overload -
	 @Pre-Condition-Takes a vector
	 @Post-Condition- subtracts two vectors
	 */
	Vector3D Vector3D::operator-(const Vector3D &vector)
	{
		return Vector3D(_x - vector.x(), _y - vector.y(), _z - vector.z());
	}

	/**
	 Overload -=
	 @Pre-Condition-Takes a vector
	 @Post-Condition- subtracts two vectors together stores it in original
	 */
	Vector3D& Vector3D::operator-=(const Vector3D &vector)
	{
		_x -= vector.x();
		_y -= vector.y();
		_z -= vector.z();
	}
}
