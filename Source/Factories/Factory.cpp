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
	Factory::Factory(SceneManager* manager)
	{
		scene = manager;
	}
	void Factory::setup()
	{
		string actorJSON;
		JSONParser* parser = new JSONParser();
		string filename = "JSON/actors.json";
		parser->parseFile(filename);

		// Parsing dwarves
		JSON* root = parser->getRootNode("root");

		HashMap<JSON*>* rootChildren = root->getAllChildren();

		JSON* dwarves = rootChildren->getValue("dwarves");
		this->parseToActorInfo(dwarves, "dwarf", &actorData);

		JSON* orcs = rootChildren->getValue("orcs");
		this->parseToActorInfo(orcs, "orc", &actorData);
		//===========MAP=========//
		JSON* wall = rootChildren->getValue("wall");
		this->parseToActorInfo(wall, "wall", &blockData);

		JSON* buildings = rootChildren->getValue("buildings");
		this->parseToActorInfo(buildings, "building", &blockData);

		JSON* trees = rootChildren->getValue("trees");
		this->parseToActorInfo(trees, "tree", &blockData);

		JSON* ore = rootChildren->getValue("ore");
		this->parseToActorInfo(ore, "ore", &blockData);

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

		int numberOfChildren = rootNode->sizeOfChildren();
		DynamicArray<JSON*>* rootChildren = rootNode->getAllChildren()->getAllValues();

		for (int i = 0; i < numberOfChildren; i++)
		{
			JSON* child = rootChildren->get(i);

			string name = child->getChild("name")->getStringValue();
			int health = child->getChild("health")->getIntValue();
			int stamina = child->getChild("stamina")->getIntValue();
			int attack = child->getChild("attack")->getIntValue();
			int defense = child->getChild("defense")->getIntValue();
			string behavior = child->getChild("behavior")->getStringValue();

			float x = (float)child->getChild("x")->getIntValue();
			float y = (float)child->getChild("y")->getIntValue();
			float z = (float)child->getChild("z")->getIntValue();

			ActorInfo* info = new ActorInfo(type, name, health, stamina, attack, defense, behavior);

			info->setLocation(new Vector3D(x, y, z));

			//cout << name << " " << health << " " << stamina  << " " << attack  << " " << defense  << " " << behavior
			//		 << " " << x  << " " << y  << " " << z << endl;

			string i_str = "" + i;
			map->add(type + i_str, *info);
			Actor* myActor = new Actor(info);
			scene->addActor(myActor);

		}
	}
}
