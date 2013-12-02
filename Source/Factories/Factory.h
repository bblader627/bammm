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
#include "../Weapons/MeleeWeaponType.h"
#include "../Weapons/MeleeWeapon.h"
#include "../Weapons/RangedWeapon.h"
#include "../Weapons/WeaponData.h"

using namespace std;

namespace bammm
{
	class Factory
	{
		private:
			HashMap<ActorInfo> actorData;
			HashMap<ActorInfo> blockData;
			HashMap<ActorInfo> mapData;
			//HashMap<ArmorInfo> armorData;
			SceneManager* scene;

			/*
			 parseToInfo
			 @Pre-Condition- accepts pointer to root JSON node and type string
			 @Post-Condition- returns void
			 */
			void parseToActorInfo(JSON* rootNode, string type,
					HashMap<ActorInfo>* map);

		public:
			//Add default constructor where scene is instantiated
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
			MeleeWeapon getMeleeWeapon(string type);

			/*
			 getRangedWeapon
			 @Pre-Condition- Takes in a string type
			 @Post-Condition- Returns a RangedWeapon
			 */
			RangedWeapon getRangedWeapon(string type);

			/*
			 setup
			 @Pre-Condition- No input
			 @Post-Condition- Sets up factory
			 */
			void setup();

			/*
			 setupArmor
			 @Pre-Condition- No input
			 @Post-Condition- Sets up armor
			 */
			void setupArmor();

			/*
			 * Item getItem(string type);
			 * BehaviorMap getBehavior(string type);
			 */
	};
}

#endif
