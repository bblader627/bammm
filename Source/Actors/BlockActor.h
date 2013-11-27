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
}

#endif
