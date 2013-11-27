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
 * BlockActor cpp file.
 *
 */

#include "BlockActor.h"

namespace bammm
{
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
