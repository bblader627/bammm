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


#include "vector3d.h"



//public variables
const Vector3D Vector3D::UP= {0, 1, 0};
const Vector3D Vector3D::DOWN = {0, -1, 0};
const Vector3D Vector3D::LEFT = {-1, 0, };
const Vector3D Vector3D::RIGHT = {1, 0, 0};
const Vector3D Vector3D::ZERO = {0, 0, 0};


//constructors
Vector3D::Vector3D()
{
	//private variables
	x = 0;
	y = 0;
	z = 0;
}
Vector3D::Vector3D(float x float y, float z)
{
	//private variables
	this.x = x;
	this.y = y;
	this.z = z;
}

//functions
void Vector3D::set(float x, float y, float z)
{
	this.x = x;
	this.y = y;
	this.z = z;
}	
void Vector3D::normalize()
{
	float normal = magnitude();
	x = x / normal;
	y = y / normal;
	z = z / normal;
}
float Vector3D::magnitude()
{
	return sqrt( (x * x) + (y * y) + (z * z));
}	
float Vector3D::sqrMagnitude()
{
	return (x * x) + (y * y) + (z * z);
}
float Vector3D::dotProduct(Vector3D &vect)
{
	return (x*vect.x()) + (y*vect.y()) + (z*vect.z());
}
void Vector3D::divideVector(int n)
{
	x = x / n;
	y = y / n;
	z = z / n;
	
}
void Vector3D::multiplyVector(int n)
{
	x = x * n;
	y = y * n;
	z = z * n;		
}
Vector3D* Vector3D::crossProduct(Vector3D &vect)
{
	 return Vector3D( (y * vect.z()) - (z - vect.y()), (x * vect.z()) - (z - vect.x()), (x * vect.y()) - (y - vect.x()));

		
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
	if( (x == vect.x()) && (y == vect.y()) && (z == vect.z()) )
		return true;
	else
		return false;
}


Vector3D Vector3D::operator!=(const Vector3D &vect)
{
	if( (x == vect.x()) && (y == vect.y()) && (z == vect.z()) )
		return false;
	else
		return true;
}
Vector3D Vector3D::operator+(const Vector3D &vect)
{
	return Vector3D(x + vect.x(), y + vect.y(), z + vect.z());
}

Vector3D Vector3D::operator+=(const Vector3D &vect)
{
	x += vect.x();
	y += vect.y();
	z += vect.z();
}
Vector3D Vector3D::operator-(const Vector3D &vect)
{
	return Vector3D(x - vect.x(), y - vect.y(), z - vect.z());
}
Vector3D Vector3D::operator-=(const Vector3D &vect)
{
	x -= vect.x();
	y -= vect.y();
	z -= vect.z();
}		

	

	


