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

using namespace std;

namespace bammm
{
	class ActorInfo
	{
		private:
			string _name;
			string _type;
			int _health;
			bool _collision;
			int _stamina;
			int _attack;
			int _defense;
			string _behavior;
			Vector3D* _location;
			AllianceType _alliance;
			string _symbol;
			string _color;

		public:
			ActorInfo();
			ActorInfo(string type, string name, int health, int stamina,
					int attack, int defense, string behavior, bool collision,
					AllianceType alliance, string symbol, string color);

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
			 getBehavior
			 @Pre-Condition- takes no arguments
			 @Post-Condition- returns behavior
			 */
			string getBehavior();

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
			 getSymbol
			 @Pre-Condition- No input
			 @Post-Condition- Returns _color
			 */
			string getColor();

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
			 setDefense
			 @Pre-Condition- takes in defense
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
	};
}

#endif
