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
 * Actor header file.
 *
 */

#ifndef ACTOR_H_
#define ACTOR_H_

#include <iostream>
#include "../SceneManager/Vector3D.h"
#include "../Weapons/MeleeWeapon.h"
#include "../Weapons/RangedWeapon.h"
#include "ActorInfo.h"

using namespace std;

namespace bammm
{
	class MeleeWeapon;

	class Actor
	{
		protected:
			float _rotation;
			string _name;
			string _type;
			string _behavior;
			Vector3D *_velocity;
			Vector3D *_location;

			int _healthBar;
			int _staminaBar;
			int MAX_HEALTH;
			int MAX_STAMINA;

			int _attack;
			int _defense;

			int _gold;
			float _BAC;

			enum AllianceType
			{
				enemy = -1, neutral = 0, ally = 1
			};
			AllianceType _alliance;

			MeleeWeapon *_meleeWeapon;
			RangedWeapon *_rangedWeapon;

		public:
			Actor();
			Actor(string name, string type);
			Actor(string type, string name, int health, int stamina, int attack,
					int defense, string behavior);
			Actor(ActorInfo* info);

			/**
			 setMeleeWeapon
			 @Pre-Condition- takes no arguments
			 @Post-Condition- sets the weapon to weapon
			 */
			void setMeleeWeapon(MeleeWeapon* weapon);

			/**
			 setRangedWeapon
			 @Pre-Condition- takes no arguments
			 @Post-Condition- sets the weapon to w
			 */
			void setRangedWeapon(RangedWeapon* weapon);

			/**
			 setRotation
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns rotation
			 */
			void setRotation(float myRotation);

			/**
			 setName
			 @Pre-Condition- takes name
			 @Post-Condition- returns void
			 */
			void setName(string name);

			/**
			 setType
			 @Pre-Condition- takes type
			 @Post-Condition- returns void
			 */
			void setType(string type);

			/**
			 setBehavior
			 @Pre-Condition- takes behavior
			 @Post-Condition- returns void
			 */
			void setBehavior(string behavior);

			/**
			 setLocation
			 @Pre-Condition- takes the location to set
			 @Post-Condition- returns nothing
			 */
			void setLocation(Vector3D* location);

			/**
			 increaseHealth
			 @Pre-Condition- Takes an float amount
			 @Post-Condition- Increases health by said amount
			 */
			void increaseHealth(int amount);

			/**
			 increaseStamina
			 @Pre-Condition- Takes an float amount
			 @Post-Condition- Increases stamina by said amount
			 */
			void increaseStamina(int amount);

			/**
			 reduceHealth
			 @Pre-Condition- Takes an float amount
			 @Post-Condition- Decreases health by said amount
			 */
			void reduceHealth(int amount);

			/*
			 reduceHealth
			 @Pre-Condition- Takes an float amount
			 @Post-Condition- Decreases stamina by said amount
			 */
			void reduceStamina(int amount);

			/**
			 isFullyRested
			 @Pre-Condition- no parameters
			 @Post-Condition- returns true if healthBar and staminaBar are equal to 								MAX_HEALTH and MAX_STAMINA
			 returns false otherwise;
			 */
			bool isFullyRested();

			/**
			 increaseBAC
			 @Pre-Condition- no parameters;
			 @Post-Condition- increments BAC by .05;
			 */
			void incrementBAC();

			/*
			 resetBAC
			 @Pre-Condition- no parameters;
			 @Post-Condition- sets BAC back to 0
			 */
			void resetBAC();

			/**
			 addGold
			 @Pre-Condition- takes amount of gold to add
			 @Post-Condition- returns total amount of gold
			 */
			int addGold(int amount);

			/**
			 resetBAC
			 @Pre-Condition- takes amount of gold to spend;
			 @Post-Condition- decrements gold and returns true if there is enough, returns false if not
			 */
			bool spendGold(int amount);

			/**
			 getGold
			 @Pre-Condition- No input
			 @Post-Condition- Returns _gold
			 */
			int getGold();

			/**
			 getMeleeWeapon
			 @Pre-Condition- No input
			 @Post-Condition- Returns _meleeWeapon
			 */
			MeleeWeapon* getMeleeWeapon();

			/**
			 getRangedWeapon
			 @Pre-Condition- No input
			 @Post-Condition- Returns _rangedWeapon
			 */
			RangedWeapon* getRangedWeapon();

			/**
			 getBAC
			 @Pre-Condition- No input
			 @Post-Condition- Returns _BAC
			 */
			float getBAC();

			/**
			 getRotation
			 @Pre-Condition- No input
			 @Post-Condition- Returns _rotation
			 */
			float getRotation();

			/**
			 getName
			 @Pre-Condition- No input
			 @Post-Condition- Returns _name
			 */
			string getName();

			/**
			 getType
			 @Pre-Condition- No input
			 @Post-Condition- Returns _type
			 */
			string getType();

			/**
			 getBehavior
			 @Pre-Condition- No input
			 @Post-Condition- Returns _behavior
			 */
			string getBehavior();

			/**
			 getVelocity
			 @Pre-Condition- No input
			 @Post-Condition- Returns _velocity
			 */
			string getVelocity();

			/**
			 getLocation
			 @Pre-Condition- No input
			 @Post-Condition- Returns _location
			 */
			Vector3D* getLocation();

			/**
			 getHealth
			 @Pre-Condition- No input
			 @Post-Condition- Returns _healthBar
			 */
			int getHealth();

			/**
			 getStamina
			 @Pre-Condition- No input
			 @Post-Condition- Returns _staminaBar
			 */
			int getStamina();

			/**
			 getAttack
			 @Pre-Condition- No input
			 @Post-Condition- Returns _attack
			 */
			int getAttack();

			/**
			 getDefense
			 @Pre-Condition- No input
			 @Post-Condition- Returns _defense
			 */
			int getDefense();

			/**
			 getX
			 @Pre-Condition- No input
			 @Post-Condition- Returns _location->x
			 */
			int getX();

			/**
			 getY
			 @Pre-Condition- No input
			 @Post-Condition- Returns _location->y
			 */
			int getY();

			/**
			 getZ
			 @Pre-Condition- No input
			 @Post-Condition- Returns _location->z
			 */
			int getZ();

			/**
			 getVectorLocation
			 @Pre-Condition- No input
			 @Post-Condition- Returns _location
			 */
			Vector3D * getVectorLocation();

			/**
			 getAlliance
			 @Pre-Condition- No input
			 @Post-Condition- Returns _alliance
			 */
			int getAlliance();

			/**
			 getEnemyAlliance
			 @Pre-Condition- No input
			 @Post-Condition- Returns _alliance * -1
			 */
			int getEnemyAlliance();

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns _name
			 */
			string toString();
	};
}

#endif
