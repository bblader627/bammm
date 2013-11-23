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
			void setupArmor();
		public:
			Actor getActor(string type);
			HashMap<ActorInfo> actorData;
			HashMap<ActorInfo> mapData;
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

			ActorInfo* info = new ActorInfo(name->getStringValue(), health->getIntValue(),
								stamina->getIntValue(), attack->getIntValue(),
								defense->getIntValue());
			actorData.add(name->getStringValue(), *info);
		}

	}

}

/*
Actor Factory::getActor(string type)
{
	if (type == "dwarf")
	{

	}
	else if (type == "block")
	{

	}
	return new Actor();

}
*/

