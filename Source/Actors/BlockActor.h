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
 * BlockActor header file.
 *
 */
#ifndef BLOCKACTOR_H_
#define BLOCKACTOR_H_

#include <iostream>
#include "../SceneManager/Vector3D.h"
#include "Actor.h"

using namespace std;

namespace bammm
{

	class BlockActor: public Actor
	{
		public:
			BlockActor();
			BlockActor(string name, Vector3D* location, int health);
	};

	BlockActor::BlockActor()
	{
		_name = "Building";
		_location = new Vector3D();
	}

	BlockActor::BlockActor(string name, Vector3D* location, int health)
	{
		_name = name;
		_location = location;
		MAX_HEALTH = health;
	}
}
#endif
