/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski	
 *   Bradley Crusco
 * Description:
 * WeaponData Class header file.
 *
 * Last Modified: Alvaro Home
 *
 */

#ifndef ACTOR_H_
#define ACTOR_H_

#include <iostream>
#include "vector3d.h"
using namespace std;

namespace bammm
{
	class WeaponData
	{
		private:
			int _range;
			int _clipCapacity;
			int _damage;
			Vector3D *velocity;
			float _reloadSpeed;
			int _ammoCount;
			float _fireRate;
			string _model;
			string _type;
		public:
	};	
}
#endif
