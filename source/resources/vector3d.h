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
			void set(float a, float b, float c);
			void normalize();
			float magnitude();
			float sqrMagnitude();
			float dotProduct(Vector3D &vector);
			void divideVector(int n);
			void multiplyVector(int n);
			Vector3D crossProduct(Vector3D &vector);
			string toString();

			bool operator==(const Vector3D &vector);
			bool operator!=(const Vector3D &vector);
			Vector3D operator+(const Vector3D &vector);
			Vector3D& operator+=(const Vector3D &vector);
			Vector3D operator-(const Vector3D &vector);
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
}
#endif

