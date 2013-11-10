/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *
 * Description:
 * ActorFactory header file.
 *
 * Last Modified: Matthew Konstantinou
 *
 */

#include <iostream>
#include "../JSON/JSONParser.h"
#include "../Resources/DynamicArray.h"
#include "../Resources/HashMap.h"
#include "../Actors/Actor.h"
#include "../Actors/ActorInfo.h"
#include "../Weapons/IWeaponType.h"

using namespace bammm;

namespace bammm
{
	class Factory
	{
		private:
			void setupArmor();
		public:
			Actor getActor(string type);
			HashMap<ActorInfo> actorData;
			//HashMap<ArmorInfo> armorData;
			void setup();

			/*
			 * Weapon getWeapon(string type);
			 * Item getItem(string type);
			 * BehaviorMap getBehavior(string type);
			 */

	};

	void Factory::setup()
	{
		string actorJSON;
		//JSONParser.parse(lkjsdlfjklsdf) into actorData
	}

	Actor Factory::getActor(string type)
	{
		//return new Actor(actorData.getItem(type));
	}

}
