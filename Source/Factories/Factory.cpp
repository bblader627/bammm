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
 * Factory cpp file.
 *
 */

#include "Factory.h"

namespace bammm
{
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

	Actor Factory::getActor(string type, string name, int health, int stamina,
			int attack, int defense, string behavior)
	{
		Actor* newActor = new Actor(type, name, health, stamina, attack,
				defense, behavior);
		newActor->setLocation(new Vector3D(0.0f, 0.0f, 0.0f));
		return *newActor;

	}

	void Factory::parseToActorInfo(JSON* rootNode, string type,
			HashMap<ActorInfo>* map)
	{
		for (int i = 0; i < rootNode->sizeOfChildren(); i++)
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

			ActorInfo* info = new ActorInfo(type, name->getStringValue(),
					health->getIntValue(), stamina->getIntValue(),
					attack->getIntValue(), defense->getIntValue(),
					behavior->getStringValue());

			info->setLocation(
					new Vector3D((float) (x->getDoubleValue()),
							(float) (y->getDoubleValue()),
							(float) (z->getDoubleValue())));

			string i_str = "" + i;
			map->add(type + i_str, *info);
			scene->addActor(new Actor(info));
		}
	}
}
