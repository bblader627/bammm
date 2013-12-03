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
		_scene = manager;
	}

	void Factory::setup()
	{
		//Parsing weapon data in
		JSONParser* weaponParser = new JSONParser();
		string weaponFilename = "JSON/weapons.json";
		weaponParser->parseFile(weaponFilename);

		JSON* weaponRoot = weaponParser->getRootNode("root");

		HashMap<JSON*>* weaponRootChildren = weaponRoot->getAllChildren();

		//Parse the melee weapons
		JSON* meleeWeapons = weaponRootChildren->getValue("meleeWeapons");
		this->parseMeleeWeaponToWeaponData(meleeWeapons, &_meleeWeaponData);

		//Parse the ranged weapons
		JSON* rangedWeapons = weaponRootChildren->getValue("rangedWeapons");
		this->parseRangedWeaponToWeaponData(rangedWeapons, &_rangedWeaponData);

		JSONParser* actorParser = new JSONParser();
		string actorFilename = "JSON/actors.json";
		actorParser->parseFile(actorFilename);

		//Parsing dwarves
		JSON* actorRoot = actorParser->getRootNode("root");

		HashMap<JSON*>* actorRootChildren = actorRoot->getAllChildren();

		JSON* dwarves = actorRootChildren->getValue("dwarves");
		this->parseToActorInfo(dwarves, "dwarf", &_actorData);

		JSON* orcs = actorRootChildren->getValue("orcs");
		this->parseToActorInfo(orcs, "orc", &_actorData);
		//===========MAP=========//
		JSON* wall = actorRootChildren->getValue("wall");
		this->parseToActorInfo(wall, "wall", &_blockData);

		JSON* buildings = actorRootChildren->getValue("buildings");
		this->parseToActorInfo(buildings, "building", &_blockData);

		JSON* trees = actorRootChildren->getValue("trees");
		this->parseToActorInfo(trees, "tree", &_blockData);

		JSON* ore = actorRootChildren->getValue("ore");
		this->parseToActorInfo(ore, "ore", &_blockData);

		JSON* water = actorRootChildren->getValue("water");
		this->parseToActorInfo(water, "water", &_blockData);
	}

	/*Actor Factory::getActor(string type, string name, int health, int stamina,
	 int attack, int defense, string behavior, bool collision)
	 {
	 Actor* newActor = new Actor(type, name, health, stamina, attack,
	 defense, behavior, AllianceType::enemy);
	 newActor->setLocation(new Vector3D(0.0f, 0.0f, 0.0f));
	 return *newActor;
	 }*/

	MeleeWeapon getMeleeWeapon(string type)
	{
		int damage;

		if (type == "stein")
		{
			damage = 2;
		}
		else if (type == "greatSword")
		{
			damage = 10;
		}
		else if (type == "battleAxe")
		{
			damage = 10;
		}
		else if (type == "chainSaw")
		{
			damage = 10;
		}
		else if (type == "katana")
		{
			damage = 10;
		}
		else if (type == "swordOf1000Truths")
		{
			damage = 110;
		}
		else if (type == "practiceSword")
		{
			damage = 1;
		}
		else
		{
			damage = 10;
		}

		WeaponData weaponData(0, 0, damage, 0, 0, "", type);
		MeleeWeapon* newWeapon = new MeleeWeapon(weaponData);

		return *newWeapon;
	}

	RangedWeapon getRangedWeapon(string type)
	{
		int range;
		int clipCapacity;
		int damage;
		float reloadSpeed;
		uint fireRate;

		if (type == "boomStick")
		{
			range = 2;
			clipCapacity = 10;
			damage = 15;
			reloadSpeed = 4;
			fireRate = 2.5;
		}
		else if (type == "bowAndArrow")
		{
			range = 3;
			clipCapacity = 50;
			damage = 10;
			reloadSpeed = 1;
			fireRate = 1;
		}
		else if (type == "chain")
		{
			range = 2;
			clipCapacity = 1;
			damage = 10;
			reloadSpeed = 1;
			fireRate = 2.5;
		}
		else if (type == "BFG")
		{
			range = 4;
			clipCapacity = 10;
			damage = 110;
			reloadSpeed = 4;
			fireRate = 5;
		}
		else if (type == "shuriken")
		{
			range = 3;
			clipCapacity = 10;
			damage = 15;
			reloadSpeed = 4;
			fireRate = 3;
		}
		else if (type == "bolas")
		{
			range = 3;
			clipCapacity = 5;
			damage = 8;
			reloadSpeed = 5;
			fireRate = 3;
		}
		else
		{
			range = 3;
			clipCapacity = 5;
			damage = 10;
			reloadSpeed = 5;
			fireRate = 3;
		}

		WeaponData weaponData(range, clipCapacity, damage, reloadSpeed,
				fireRate, "", type);
		RangedWeapon* newWeapon = new RangedWeapon(weaponData);

		return *newWeapon;
	}

	void Factory::parseToActorInfo(JSON* rootNode, string type,
			HashMap<ActorInfo>* map)
	{
		int numberOfChildren = rootNode->sizeOfChildren();
		DynamicArray<JSON*>* rootChildren =
				rootNode->getAllChildren()->getAllValues();

		for (int i = 0; i < numberOfChildren; i++)
		{
			JSON* child = rootChildren->get(i);

			string name = child->getChild("name")->getStringValue();
			int attack = child->getChild("attack")->getIntValue();
			int defense = child->getChild("defense")->getIntValue();
			string behaviorString =
					child->getChild("behavior")->getStringValue();
			int behaviorValue = child->getChild("behaviorValue")->getIntValue();
			bool collision = child->getChild("collision")->getBoolValue();
			float x = (float) child->getChild("x")->getIntValue();
			float y = (float) child->getChild("y")->getIntValue();
			float z = (float) child->getChild("z")->getIntValue();
			int parsedAlliance = child->getChild("alliance")->getIntValue();
			string symbol = child->getChild("symbol")->getStringValue();
			string color = child->getChild("color")->getStringValue();
			int gold = 0;
			int coal = 0;
			int iron = 0;
			int wood = 0;

			AllianceType alliance;
			if (parsedAlliance == 0)
			{
				alliance = AllianceType::neutral;
			}
			else if (parsedAlliance == 1)
			{
				alliance = AllianceType::ally;
			}
			else
			{
				alliance = AllianceType::enemy;
			}

			Behavior* behavior = new Behavior();
			behavior->addBaseBehavior(behaviorString, behaviorValue);

			ActorInfo* info = new ActorInfo(type, name, attack, defense,
					behavior, collision, alliance, symbol, color, gold, coal,
					iron, wood, 0); //that zero is for BAC
			info->setLocation(new Vector3D(x, y, z));

			string i_str = "" + i;
			map->add(type + i_str, *info);
			Actor* myActor = new Actor(info);

			//TODO: This needs to be redone to use the factory... so we ahve to parse weapon data first?
			WeaponData weaponData(10, 2, "", "");
			MeleeWeapon* meleeWeapon = new MeleeWeapon(weaponData);
			myActor->setMeleeWeapon(meleeWeapon);

			_scene->addActor(myActor);
		}
	}

	void Factory::parseMeleeWeaponToWeaponData(JSON* rootNode,
			HashMap<WeaponData>* map)
	{
		int numberOfChildren = rootNode->sizeOfChildren();
		DynamicArray<JSON*>* rootChildren =
				rootNode->getAllChildren()->getAllValues();

		//Cycle through every weapon type
		for (int i = 0; i < numberOfChildren; i++)
		{
			JSON* child = rootChildren->get(i);

			string type = child->getChild("type")->getStringValue();
			int damage = child->getChild("damage")->getIntValue();

			//Create the data specifying this melee weapon
			WeaponData* weaponData = new weaponData(0, 0, damage, 0, 0, "",
					type);

			map->add(type, *weaponData); //Save this data in the map.
		}
	}

	void Factory::parseRangedWeaponToWeaponData(JSON* rootNode,
			HashMap<WeaponData>* map)
	{
		int numberOfChildren = rootNode->sizeOfChildren();
		DynamicArray<JSON*>* rootChildren =
				rootNode->getAllChildren()->getAllValues();
		//Cycle through every weapon type
		for (int i = 0; i < numberOfChildren; i++)
		{
			JSON* child = rootChildren->get(i);
			string type = child->getChild("type")->getStringValue();
			int range = child->getChild("range")->getIntValue();
			int clipCapacity = child->getChild("clipCapacity")->getIntValue();
			int ammoCount = clipCapacity; //full clip
			int damage = child->getChild("damage")->getIntValue();
			float reloadSpeed = child->getChild("reloadSpeed")->getFloatValue();
			uint fireRate = child->getChild("fireRate")->getUIntValue();

			//Create the data specifying this ranged weapon
			WeaponData* weaponData = new weaponData(range, clipCapacity, damage,
					reloadSpeed, fireRate, "", type);

			map->add(type, *weaponData); //Save this data in the map.
		}
	}
}
