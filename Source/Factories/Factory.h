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
		string filename = "/home/matthew/workspace/bammm/Source/JSON/actors.json";
		parser->parseFile(filename);



		cout << "poop" << endl;

		HashMap<JSON>* rootMap = parser->getMap();

		cout << "1" << endl;

		cout << rootMap->getNumerOfNodes() << endl;

		/*
		JSON* dwarfJSON = rootMap->getValue("dwarves");
		if (dwarfJSON == NULL)
		{
			cout << "caught NULL" << endl;
			return;
		}
		cout << "2" << endl;


		HashMap<JSON>* dwarves = dwarfJSON->getChildren();

		cout << "poop2" << endl;
		DynamicArray<JSON>* dwarfArray = dwarves->getAllValues();

		int size = dwarfArray->getSize();
		for (int i = 0; i < size; i++)
		{
			//ActorInfo info = new ActorInfo();
			//info.setName(dwarfArray->get(i).)
			//actorData.add()
			cout << dwarfArray->get(i).getName() << endl;
		}
		*/

	}
	/*
	Actor Factory::getActor(string type)
	{
		return new Actor();
		//return new Actor(actorData.getItem(type));
	}
	*/

}
