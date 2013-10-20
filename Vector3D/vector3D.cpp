/*
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

#include "vector3D.h"

namespace bammm
{
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

	Vector3D::Vector3D()
	{
		_x = 0;
		_y = 0;
		_z = 0;
	}

	Vector3D::Vector3D(float x, float y, float z)
	{
		_x = x;
		_y = y;
		_z = z;
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

	Vector3D* Vector3D::crossProduct(Vector3D &vect)
	{
		return Vector3D((_y * vect.z()) - (_z - vect.y()),
				(_x * vect.z()) - (_z - vect.x()),
				(_x * vect.y()) - (_y - vect.x()));

	}
	string Vector3D::toString()
	{
		string output;
		output.append("<");
		//output.append(output.to_string(x));
		output.append(",");
		//output.append(output.to_string(y));
		output.append(",");
		//output.append(output.to_string(z));
		output.append(">");
		return output;
	}

//Operator Overloads
	bool Vector3D::operator==(const Vector3D &vect)
	{
		if ((_x == vect.x()) && (_y == vect.y()) && (_z == vect.z()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Vector3D Vector3D::operator!=(const Vector3D &vect)
	{
		if ((_x == vect.x()) && (_y == vect.y()) && (_z == vect.z()))
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	Vector3D Vector3D::operator+(const Vector3D &vect)
	{
		return Vector3D(_x + vect.x(), _y + vect.y(), _z + vect.z());
	}

	Vector3D Vector3D::operator+=(const Vector3D &vect)
	{
		_x += vect.x();
		_y += vect.y();
		_z += vect.z();
	}

	Vector3D Vector3D::operator-(const Vector3D &vect)
	{
		return Vector3D(_x - vect.x(), _y - vect.y(), _z - vect.z());
	}

	Vector3D Vector3D::operator-=(const Vector3D &vect)
	{
		_x -= vect.x();
		_y -= vect.y();
		_z -= vect.z();
	}
}
