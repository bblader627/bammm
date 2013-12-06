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
 * Factory header file.
 *
 */

#ifndef FACTORY_H_
#define FACTORY_H_

#include <iostream>
#include "../JSON/JSONParser.h"
#include "../JSON/JSON.h"
#include "../JSON/JSONArray.h"
#include "../JSON/JSONPrimitive.h"
#include "../Resources/DynamicArray.h"
#include "../Resources/HashMap.h"
#include "../Actors/Actor.h"
#include "../Actors/ActorInfo.h"
#include "../Interfaces/IWeaponType.h"
#include "../SceneManager/SceneManager.h"
#include "../Resources/Constant.h"
#include "../Weapons/MeleeWeapon.h"
#include "../Weapons/RangedWeapon.h"
#include "../Weapons/WeaponData.h"
#include "../Behavior/Behavior.h"
#include "../Inventory/Inventory.h"
#include "../Inventory/Item.h"

using namespace std;

namespace bammm
{
	class Factory
	{
		private:
			HashMap<ActorInfo> _actorData;
			HashMap<ActorInfo> _blockData;
			HashMap<ActorInfo> _mapData;
			HashMap<WeaponData> _meleeWeaponData;
			HashMap<WeaponData> _rangedWeaponData;
			SceneManager* _scene;

			JSON* _craftables;

			/*
			 parseToActorInfo
			 @Pre-Condition- accepts pointer to root JSON node and type string
			 @Post-Condition- returns void
			 */
			void parseToActorInfo(JSON* rootNode, string type,
					HashMap<ActorInfo>* map);

			/*
			 parseMeleeWeaponToWeaponData
			 @Pre-Condition- accepts pointer to root JSON node and type string and map
			 @Post-Condition- Data is parsed and stored in map
			 */
			void parseMeleeWeaponToWeaponData(JSON* rootNode,
					HashMap<WeaponData>* map);

			/*
			 parseRangedWeapontoWeaponData
			 @Pre-Condition- accepts pointer to root JSON node and type string and map
			 @Post-Condition- Data is parsed and stored in map
			 */
			void parseRangedWeaponToWeaponData(JSON* rootNode,
					HashMap<WeaponData>* map);

		public:
			Factory(SceneManager* manager);

			/*
			 getActor
			 @Pre-Condition- accepts characteristics of desired actor
			 @Post-Condition- returns new actor
			 */
			Actor getActor(string type, string name, int health, int stamina,
					int attack, int defense, string behavior, bool collision);

			/*
			 getMeleeWeapon
			 @Pre-Condition- Takes in a string type
			 @Post-Condition- Returns a MeleeWeapon
			 */
			MeleeWeapon* getMeleeWeapon(string type);

			/*
			 getRangedWeapon
			 @Pre-Condition- Takes in a string type
			 @Post-Condition- Returns a RangedWeapon
			 */
			RangedWeapon* getRangedWeapon(string type);

			/*
			 getCraftables
			 @Pre-Condition- No input
			 @Post-Condition- Returns JSON for craftables
			 */
			JSON* getCraftables();

			/*
			 setup
			 @Pre-Condition- No input
			 @Post-Condition- Sets up factory
			 */
			void setup();
	};
}

#endif
