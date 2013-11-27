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
*** Orc names courtesy of Skyrim
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
#include "../SceneManager/SceneManager.h"

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
			HashMap<ActorInfo> blockData;
			HashMap<ActorInfo> mapData;
			//HashMap<ArmorInfo> armorData;
			SceneManager* scene;

			/*
			 parseToInfo
			 @Pre-Condition- accepts pointer to root JSON node and type string
			 @Post-Condition- returns void
			 */
			void parseToActorInfo(JSON* rootNode, string type, HashMap<ActorInfo>* map);

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


		// Parsing dwarves
		JSON* dwarves = parser->getRootNode("dwarves");
		this->parseToActorInfo(dwarves, "dwarf", &actorData);

		// Parsing orcs
		JSON* orcs = parser->getRootNode("orcs");
		this->parseToActorInfo(orcs, "orc", &actorData);

		//Parsing Map info
		JSON* map = parser->getRootNode("map");
		//JSON* x = map["x"];
		//JSON* y = map["y"];
		//JSON* z = map["z"];
		
		JSON* wall = map["Wall"];
		this->parseToActorInfo(wall, "Wall", &blockData);

		JSON* buildings = map["Buildings"];
		this->parseToActorInfo(buildings, "Building", &blockData);

		JSON* trees = map["Trees"];
		this->parseToActorInfo(trees, "Tree", &blockData);

		JSON* ore = map["Ore"];
		this->parseToActorInfo(ore, "Ore", &blockData);


	}

	Actor Factory::getActor(string type, string name, int health, int stamina, int attack, int defense, string behavior)
	{
		Actor* newActor = new Actor(type, name, health, stamina, attack, defense, behavior);
		newActor->setLocation(new Vector3D(0.0f,0.0f,0.0f));
		return *newActor;

	}

	void Factory::parseToActorInfo(JSON* rootNode, string type, HashMap<ActorInfo>* map)
	{
		for (int i = 0; i<rootNode->sizeOfChildren(); i++)
		{
			JSON* name = rootNode[i]["name"];
			JSON* health = rootNode[i]["health"];
			JSON* stamina = rootNode[i]["stamina"];
			JSON* attack = rootNode[i]["attack"];
			JSON* defense = rootNode[i]["defense"];
			JSON* behavior = rootNode[i]["behavior"];

			JSON* x = rootNode[i]["x"];
			JSON* y = rootNode[i]["y"];
			JSON* z = rootNode[i]["z"];

			ActorInfo* info = new ActorInfo(type, name->getStringValue(), health->getIntValue(),
								stamina->getIntValue(), attack->getIntValue(),
								defense->getIntValue(), behavior->getStringValue());

			info->setLocation(new Vector3D((float)(x->getDoubleValue()), (float)(y->getDoubleValue()), (float)(z->getDoubleValue())));

			string i_str = "" + i;
			map->add(type + i_str, *info);
			scene->addActor(new Actor(info));
		}
	}

}

/*

*/

