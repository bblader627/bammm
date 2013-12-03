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
#include "../Resources/Constant.h"

using namespace std;

namespace bammm
{
	class MeleeWeapon;

	class Actor
	{
		protected:
			float _rotation;
			Vector3D *_velocity;
			Vector3D *_location;

			bool _collision;

			MeleeWeapon *_meleeWeapon;
			RangedWeapon *_rangedWeapon;

			ActorInfo *_stats;

		public:
			Actor();
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
			 setSymbol
			 @Pre-Condition- takes the string to set
			 @Post-Condition- returns nothing
			 */
			void setSymbol(string symbol);

			/**
			 setColor
			 @Pre-Condition- takes the color to set
			 @Post-Condition- returns nothing
			 */
			void setColor(string color);

			/**
			 setGold
			 @Pre-Condition- The amount to set the Actor's gold to
			 @Post-Condition- Returns nothing
			 */
			void setGold(int gold);

			/**
			 setGold
			 @Pre-Condition- The amount to set the Actor's iron to
			 @Post-Condition- Returns nothing
			 */
			void setIron(int iron);

			/**
			 setCoal
			 @Pre-Condition- The amount to set the Actor's coal to
			 @Post-Condition- Returns nothing
			 */
			void setCoal(int coal);

			/**
			 setWood
			 @Pre-Condition- The amount to set the Actor's wood to
			 @Post-Condition- Returns nothing
			 */
			void setWood(int wood);

			/**
			 getMaximumHealth
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns maximumHealth
			 */
			int getMaximumHealth();

			/**
			 setMaximumHealth
			 @Pre-Condition- takes in maximumHealth to set
			 @Post-Condition- returns void
			 */
			void setMaximumHealth(int maximumHealth);

			/**
			 getMaximumStamina
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns maximumStamina
			 */
			int getMaximumStamina();

			/**
			 setMaximumStamina
			 @Pre-Condition- takes in maximumStamina to set
			 @Post-Condition- returns void
			 */
			void setMaximumStamina(int maximumStamina);

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
			 getMeleeWeapon
			 @Pre-Condition- No input
			 @Post-Condition- Returns _collision
			 */
			bool getCollision();

			/**
			 getWood
			 @Pre-Condition- No input
			 @Post-Condition- Returns _wood
			 */
			int getWood();

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
			 getBaseBehaviors
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns behavior
			 */
			DynamicArray<string>* getBaseBehaviors();

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
			 setHealth
			 @Pre-Condition- Takes in an int newHealth
			 @Post-Condition- Returns sets _health to newHealth
			 */
			void setHealth(int newHealth);

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
			AllianceType getAlliance();

			/**
			 getSymbol
			 @Pre-Condition- No input
			 @Post-Condition- Returns _symbol
			 */
			string getSymbol();

			/**
			 getColor
			 @Pre-Condition- No input
			 @Post-Condition- Returns _color
			 */
			string getColor();

			/**
			 getGold
			 @Pre-Condition- No input
			 @Post-Condition- Returns the amount of gold the player has
			 */
			int getGold();

			/**
			 getIron
			 @Pre-Condition- No input
			 @Post-Condition- Returns the amount of iron the player has
			 */
			int getIron();

			/**
			 getCoal
			 @Pre-Condition- No input
			 @Post-Condition- Returns the amount of coal the player has
			 */
			int getCoal();

			/**
			 getEnemyAlliance
			 @Pre-Condition- No input
			 @Post-Condition- Returns the enemy's alliance
			 */
			int getEnemyAlliance();

			/**
			 getLevel
			 @Pre-Condition- No input
			 @Post-Condition- Returns the current level
			 */
			int getLevel();

			/**
			 setLevel
			 @Pre-Condition- Takes an int of new level
			 @Post-Condition- Sets the level to the given input
			 */
			void setLevel(int newLevel);

			/**
			 getExperience
			 @Pre-Condition- No input
			 @Post-Condition- Returns the current experience
			 */
			int getExperience();

			/**
			 setExperience
			 @Pre-Condition- Takes an int of newExperience
			 @Post-Condition- Sets the experience to the given input
			 */
			void setExperience(int newExperience);

			/**
			 getTotalExperienceThisLevel
			 @Pre-Condition- No input
			 @Post-Condition- Returns the current totalExperienceThisLevel
			 */
			int getTotalExperienceThisLevel();

			/**
			 setTotalExperienceThisLevel
			 @Pre-Condition- Takes an int of newTotalExperienceThisLevel
			 @Post-Condition- Sets the experience to the given input
			 */
			void setTotalExperienceThisLevel(int newTotalExperienceThisLevel);

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns _name
			 */
			string toString();
	};
}

#endif
