/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *	Bradley Crusco
 * Description:
 * ITickable cpp file.
 *
 */

#include "ITickable.h"

namespace bammm
{
	ITickable::~ITickable()
	{
	}

	bool ITickable::canDelete()
	{
		return false;
	}
}
