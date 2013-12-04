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

		JSON* water = rootChildren->getValue("water");
		this->parseToActorInfo(water, "water", &blockData);
	}

	Actor Factory::getActor(string type, string name, int health, int stamina,
			int attack, int defense, string behavior, bool collision)
	{
		Actor* newActor = new Actor(type, name, health, stamina, attack,
				defense, behavior, AllianceType::enemy);
		newActor->setLocation(new Vector3D(0.0f, 0.0f, 0.0f));
		return *newActor;
	}

	MeleeWeapon getMeleeWeapon(string type)
	{
		//Why not get the parsed weapons from json?
		//Automatically parse them so you can just do weaponData.getValue(type);

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

		WeaponData weaponData(range, clipCapacity, damage,
				reloadSpeed, fireRate, "", type);
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
			int health = child->getChild("health")->getIntValue();
			int stamina = child->getChild("stamina")->getIntValue();
			int attack = child->getChild("attack")->getIntValue();
			int defense = child->getChild("defense")->getIntValue();
			string behavior = child->getChild("behavior")->getStringValue();
			bool collision = child->getChild("collision")->getBoolValue();
			float x = (float) child->getChild("x")->getIntValue();
			float y = (float) child->getChild("y")->getIntValue();
			float z = (float) child->getChild("z")->getIntValue();
			int parsedAlliance = child->getChild("alliance")->getIntValue();
			string symbol = child->getChild("symbol")->getStringValue();
			string color = child->getChild("color")->getStringValue();
			int gold = 100;
			int coal = 100;
			int iron = 100;
			int wood = 100;

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

			ActorInfo* info = new ActorInfo(type, name, health, stamina, attack,
					defense, behavior, collision, alliance, symbol, color, gold,
					coal, iron, wood);
			info->setLocation(new Vector3D(x, y, z));

			string i_str = "" + i;
			map->add(type + i_str, *info);
			Actor* myActor = new Actor(info);
			WeaponData weaponData(10,2,"","");
			MeleeWeapon* meleeWeapon = new MeleeWeapon(weaponData);
			myActor->setMeleeWeapon(meleeWeapon);
			scene->addActor(myActor);
		}
	}
}
