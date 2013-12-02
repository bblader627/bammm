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
 * DamageState cpp file.
 *
 */

#include "DamageState.h"

namespace bammm
{
	DamageState::DamageState(Actor& actor)
	{
		_actor = &actor;
	}

	DamageState::DamageState(Actor& actor, IStateCallback* stateMachine)
	{
		_actor = &actor;
		registerTransitionCallback(stateMachine);
	}

	void DamageState::setTarget(Actor& target)
	{
		_target = &target;
	}

	void DamageState::setup()
	{
	}

	void DamageState::breakdown()
	{
		cout << "State is broken\n";
	}

	void DamageState::tick(float deltaTime)
	{
		MeleeWeapon* weapon = _actor->getMeleeWeapon();
		string attackerName = _actor->getName();
		string targetName = _target->getName();
		if (weapon->canAttack())
		{
			int damage = weapon->attack();
			_target->reduceHealth(damage);
			cout << attackerName << " hits " << targetName << " for " << damage
					<< " damage. \n";
			if (_target->getHealth() <= 0)
			{
				cout << attackerName << " has slain " << targetName << ".\n";
			}
		}
		else
		{
			cout << attackerName << " can't attack yet." << "\n";
		}

		switchState("null");
	}

	void DamageState::switchState(string nextState)
	{
		_stateMachine->switchState(this, nextState);
	}

	string DamageState::toString()
	{
		return "damage";
	}
}
