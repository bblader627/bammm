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
 * ActorInfo header file.
 *
 */

#ifndef ACTORINFO_H_
#define ACTORINFO_H_

#include <iostream>
#include "../SceneManager/Vector3D.h"
#include "../Resources/Constant.h"
#include "../Behavior/Behavior.h"

using namespace std;

namespace bammm
{
	class ActorInfo
	{
		private:
			int MAX_HEALTH = 100;
			int MAX_STAMINA = 50;

			string _name;
			string _type;
			int _health;
			bool _collision;
			int _stamina;
			int _attack;
			int _defense;
			Behavior *_behaviors;
			Vector3D* _location;
			AllianceType _alliance;
			string _symbol;
			string _color;
			int _gold;
			int _coal;
			int _iron;
			int _wood;
			float _BAC;

		public:
			ActorInfo();
			ActorInfo(string type, string name,
					int attack, int defense, Behavior *behaviors, bool collision,
					AllianceType alliance, string symbol, string color, int gold, int coal, int iron, int wood, float BAC);

			/**
			 getType
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns type
			 */
			string getType();

			/**
			 getName
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns name
			 */
			string getName();

			/**
			 getHealth
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns health
			 */
			int getHealth();

			/**
			 getStamina
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns stamina
			 */
			int getStamina();

			/**
			 getAttack
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns attack
			 */
			int getAttack();

			/**
			 getDefense
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns defense
			 */
			int getDefense();

			/**
			 getBaseBehaviors
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns behavior
			 */
			DynamicArray<string>* getBaseBehaviors();

			/**
			 getLocation
			 @Pre-Condition- No input
			 @Post-Condition- Returns _location
			 */
			Vector3D* getLocation();

			/**
			 getCollision
			 @Pre-Condition- No input
			 @Post-Condition- Returns _collision
			 */
			bool getCollision();

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
			 getColor
			 @Pre-Condition- No input
			 @Post-Condition- Returns _gold
			 */
			int getGold();
			
			/**
			 getWood
			 @Pre-Condition- No input
			 @Post-Condition- Returns _wood
			 */
			int getWood();
			
			/**
			 getColor
			 @Pre-Condition- No input
			 @Post-Condition- Returns _coal
			 */
			int getCoal();
			
			/**
			 getIron
			 @Pre-Condition- No input
			 @Post-Condition- Returns _iron
			 */
			int getIron();

			/**
			 setType
			 @Pre-Condition- takes type
			 @Post-Condition- returns void
			 */
			void setType(string type);

			/**
			 setName
			 @Pre-Condition- takes in name to set
			 @Post-Condition- returns void
			 */
			void setName(string name);

			/**
			 setHealth
			 @Pre-Condition- takes in health to set
			 @Post-Condition- returns void
			 */
			void setHealth(int health);

			/**
			 setStamina
			 @Pre-Condition- takes in stamina to set
			 @Post-Condition- returns void
			 */
			void setStamina(int stamina);

			/**
			 setAttack
			 @Pre-Condition- takes in attack
			 @Post-Condition- returns void
			 */
			void setAttack(int attack);

			/**
			 setDefense
			 @Pre-Condition- takes in defense
			 @Post-Condition- returns void
			 */
			void setDefense(int defense);

			/**
			 setLocation
			 @Pre-Condition- takes the location to set
			 @Post-Condition- returns nothing
			 */
			void setLocation(Vector3D* location);

			/**
			 setCollision
			 @Pre-Condition- takes a boolean to set the collision
			 @Post-Condition- returns nothing
			 */
			void setCollision(bool collision);

			/**
			 setAlliance
			 @Pre-Condition- takes an Alliance to set the alliance
			 @Post-Condition- returns nothing
			 */
			void setAlliance(AllianceType alliance);

			/**
			 setSymbol
			 @Pre-Condition- takes a string to set the symbol
			 @Post-Condition- returns nothing
			 */
			void setSymbol(string symbol);

			/**
			 getBAC
			 @Pre-Condition- No input
			 @Post-Condition- Returns _BAC
			 */
			float getBAC();

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
			 getEnemyAlliance
			 @Pre-Condition- No input
			 @Post-Condition- Returns the enemy's alliance
			 */
			int getEnemyAlliance();

			/**
			 getEnemyAlliance
			 @Pre-Condition- takes in a behavior
			 @Post-Condition- sets Behavior table to behavior
			 */
			void setBehavior(Behavior *behaviors);

			/**
			 getEnemyAlliance
			 @Pre-Condition- No input
			 @Post-Condition- Returns the behavior structure for an actor
			 */
			Behavior* getBehavior();

	};
}

#endif
