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
 * DamageState header file.
 *
 */

#ifndef DAMAGESTATE_H_
#define DAMAGESTATE_H_

#include <iostream>
#include "State.h"
#include "../Weapons/MeleeWeapon.h"

using namespace std;

namespace bammm
{
	class DamageState: public State
	{
		private:
			Actor* _target;

		public:
			DamageState(Actor& actor);
			DamageState(Actor& actor, IStateCallback& stateMachine);

			/**
			 Update this to take a Vector3D once we get rid of circular
			 setup
			 @Pre-Condition- Takes nothing
			 @Post-Condition- Sets up the state
			 */
			virtual void setup();

			/**
			 setup
			 @Pre-Condition- Takes an Actor to apply damage to
			 @Post-Condition- Sets up the state with an Actor
			 */
			void setTarget(Actor& target);
			
			/**
			 breakdown
			 @Pre-Condition- No input
			 @Post-Condition- Performs a breakdown on the state
			 */
			void breakdown();

			/**
			 tick
			 @Pre-Condition- Takes in a float deltaTime
			 @Post-Condition- Executes a tick of length deltaTime
			 */
			virtual void tick(float deltaTime);

			/**
			 switchState
			 @Pre-Condition- Takes in a string nextState
			 @Post-Condition- The current state is switched to the given nextState
			 */
			virtual void switchState(string nextState);

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string representation of the state
			 */
			string toString();
	};
}

#endif
