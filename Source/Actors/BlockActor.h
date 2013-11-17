/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *
 * Description:
 * Actor header file.
 *
 * Last Modified: Matthew Konstantinou
 *
 */

#include <iostream>
#include "../SceneManager/Vector3D.h"
#include "Actor.h"

using namespace std;

namespace bammm
{
	
	class BlockActor : public Actor
	{
		public:
			BlockActor();
			BlockActor(string name, Vector3D* loc, int health);
	};

	BlockActor::BlockActor()
	{
		_name = "Building";
		_location = new Vector3D();
	}

	BlockActor::BlockActor(string name, Vector3D* loc, int health)
	{
		_name = name;
		_location = loc;
		MAX_HEALTH = health;
	}
}
