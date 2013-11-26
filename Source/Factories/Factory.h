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
#include "../JSON/JSON.h"
#include "../JSON/JSONArray.h"
#include "../JSON/JSONPrimitive.h"
#include "../Resources/DynamicArray.h"
#include "../Resources/HashMap.h"
#include "../Actors/Actor.h"
#include "../Actors/ActorInfo.h"
#include "../Weapons/IWeaponType.h"

using namespace bammm;
using namespace std;

#ifndef NULL
#define NULL ((void *)0)
#endif



namespace bammm
{
	class Factory
	{
		private:
			HashMap<ActorInfo> actorData;
			HashMap<ActorInfo> mapData;
			//HashMap<ArmorInfo> armorData;

		public:

			/*
			 getActor
			 @Pre-Condition- accepts characteristics of desired actor
			 @Post-Condition- returns new actor
			 */
			Actor getActor(string type, string name, int health, int stamina, int attack, int defense, string behavior);

			void setup();
			void setupArmor();

			/*
			 * Weapon getWeapon(string type);
			 * Item getItem(string type);
			 * BehaviorMap getBehavior(string type);
			 */

	};

	void Factory::setup()
	{
		string actorJSON;
		JSONParser* parser = new JSONParser();
		string filename = "actors.json";
		parser->parseFile(filename);

		cout << "poop" << endl;

		JSON* dwarves = parser->getRootNode("dwarves");
		cout << dwarves->getName() << endl;

		for (int i = 0; i<dwarves->sizeOfChildren(); i++)
		{
			JSON* name = dwarves[i]["name"];
			JSON* health = dwarves[i]["health"];
			JSON* stamina = dwarves[i]["stamina"];
			JSON* attack = dwarves[i]["attack"];
			JSON* defense = dwarves[i]["defense"];
			JSON* behavior = dwarves[i]["behavior"];

			JSON* x = dwarves[i]["x"];
			JSON* y = dwarves[i]["y"];
			JSON* z = dwarves[i]["z"];

			ActorInfo* info = new ActorInfo("dwarf", name->getStringValue(), health->getIntValue(),
								stamina->getIntValue(), attack->getIntValue(),
								defense->getIntValue(), behavior->getStringValue());
			info->setLocation(new Vector3D((float)(x->getDoubleValue()), (float)(y->getDoubleValue()), (float)(z->getDoubleValue())));

			actorData.add("dwarf" + i, *info);
		}

	}

	Actor Factory::getActor(string type, string name, int health, int stamina, int attack, int defense, string behavior)
	{
		Actor* newActor = new Actor(type, name, health, stamina, attack, defense, behavior);
		newActor->setLocation(new Vector3D(0.0f,0.0f,0.0f));
		return *newActor;

	}

}

/*

*/

