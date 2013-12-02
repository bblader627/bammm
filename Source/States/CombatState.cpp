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
 * CombatState header file.
 *
 */

#include "CombatState.h"

namespace bammm
{
	CombatState::CombatState(Actor& actor)
	{
		_actor = &actor;
	}

	CombatState::CombatState(Actor& actor, IStateCallback* stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	/*void CombatState::setup(DynamicArray<string>* args)
	 {
	 }*/

	void CombatState::setup()
	{

	}

	void CombatState::breakdown()
	{
	}

	void CombatState::tick(float deltaTime)
	{
	}

	string CombatState::toString()
	{
		return "combat";
	}
}
