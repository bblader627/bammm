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
		cout << "file parsed" << endl;

		// Parsing dwarves

		parser->printAllRoots();

		//segfault on getRootNode
		JSON* root = parser->getRootNode("root");

		HashMap<JSON*>* rootChildren = root->getAllChildren();

		JSON* dwarves = rootChildren->getValue("dwarves");
		this->parseToActorInfo(dwarves, "dwarf", &actorData);
		cout << "Dwarves Parsed" << endl;

		JSON* orcs = rootChildren->getValue("orcs");
		this->parseToActorInfo(orcs, "orc", &actorData);
		cout << "Orcs parsed" << endl;

		//===========MAP=========//
		JSON* wall = rootChildren->getValue("wall");
		this->parseToActorInfo(wall, "wall", &blockData);
		cout << "Wall parsed" << endl;

		JSON* buildings = rootChildren->getValue("buildings");
		this->parseToActorInfo(buildings, "building", &blockData);
		cout << "Buildings parsed" << endl;

		JSON* trees = rootChildren->getValue("trees");
		this->parseToActorInfo(trees, "tree", &blockData);
		cout << "Trees parsed" << endl;

		JSON* ore = rootChildren->getValue("ore");
		this->parseToActorInfo(ore, "ore", &blockData);
		cout << "Ore parsed" << endl;

		// Parsing orcs

		/*
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
		 */

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

		cout << "in parseToActorInfo" << endl;
		int numberOfChildren = rootNode->sizeOfChildren();
		cout << "numberOfChildren: " << numberOfChildren << endl;

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

			int x = child->getChild("x")->getIntValue();
			int y = child->getChild("y")->getIntValue();
			int z = child->getChild("z")->getIntValue();

			ActorInfo* info = new ActorInfo(type, name, health, stamina, attack, defense, behavior);

			info->setLocation(new Vector3D((float)x, (float)y, (float)z));

			cout << name << " " << health << " " << stamina  << " " << attack  << " " << defense  << " " << behavior
					 << " " << x  << " " << y  << " " << z << endl;

			string i_str = "" + i;
			map->add(type + i_str, *info);
			Actor* myActor = new Actor(info);
			scene->addActor(myActor);

		}
	}
}
