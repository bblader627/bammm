#include <iostream>
#include "SceneManager/SceneManager.h"
#include "Controllers/PlayerController.h"
#include "Controllers/AiController.h"
#include "Weapons/Stein.h"
#include "Actors/DwarfActor.h"
#include "Actors/OrcActor.h"
#include "Weapons/MeleeWeapon.h"
#include <random>

using namespace bammm;
using namespace std;

void printWelcome();
void printOptions();

int main()
{
	printWelcome();
	bool printMap = true;
	SceneManager sceneManager;
	MeleeCombat meleeCombat;
	DynamicArray<AiController*> aiControllers;

	//Creation of Hero
	DwarfActor* bob = new DwarfActor();
	Vector3D* temp = new Vector3D(0,0,0);
	sceneManager.getSceneGraph().add(temp, bob);

	//Random number generator
	random_device rd;
	mt19937 generator(rd());

	//Pick random number of orcs
	int minOrc = 1;
	int maxOrc = 10;
	uniform_int_distribution<int> orcDistribution (minOrc, maxOrc);
	int orcCount = orcDistribution(generator);

	//Create the orcs
	uniform_int_distribution<int> xDistribution (0, sceneManager.getSceneGraph().getX() - 1);
	uniform_int_distribution<int> yDistribution (0, sceneManager.getSceneGraph().getY() - 1);
	DynamicArray<OrcActor*> orcActors;
	for(int i = 0; i < orcCount; i++)
	{
		int randomX = xDistribution(generator);
		int randomY = yDistribution(generator);
		temp = new Vector3D(randomX, randomY, 0);

		OrcActor* newOrc = new OrcActor();
		orcActors.add(newOrc);

		AiController* newAi = new AiController();
		newAi->setup(*orcActors.get(i), sceneManager, meleeCombat);
		sceneManager.getSceneGraph().add(temp, (orcActors.get(i)));
		aiControllers.add(newAi);
	}

	PlayerController controller;
	controller.setup(*bob, sceneManager, meleeCombat);

	bool playGame = true;
	int choice;

	cout << bob->getName() << " is waiting for instructions." << endl;

    DynamicArray<string>* input = new DynamicArray<string>();
	string sleep = "sleep";
	string mine = "mine";
	string drink = "drink";
	string sing = "sing";
	string brawl = "brawl";
	string attack = "combat";
	float dTime = 0;
	while (playGame)
	{
		input->clear();

		if(printMap)
		{
			cout << sceneManager.getSceneGraph().to_string() << "\n";
		}

		controller.printOptions();
		cin >> choice;

		switch (choice)
		{
			case 0:
				playGame = false;
				break;
			case 1:
                input->add(mine);
				break;
			case 2:
                input->add(drink);
				break;
			case 3:
                input->add(sing);
				break;
			case 4:
                input->add(brawl);
				break;
			case 5:
				input->add(sleep);
				break;
			case 6:
				input->add(attack);
			case 7:
				break;
			default:
				cout << "Invalid Input" << endl;
				break;
		}

		if(!playGame)
		{
    		break;
		}
		controller.input(input, dTime);

		for(int i = 0; i < (int)aiControllers.getSize(); i++)
		{
			if(aiControllers.get(i)->update(dTime))
			{
				aiControllers.remove(i);
			}

		}
	}
	delete input;


	for(int i = 0; i < (int)aiControllers.getSize(); i++)
	{
		if(aiControllers.get(i)->update(dTime))
		{
			delete aiControllers.remove(i);
		}

	}
	cout << "Thanks for playing!  Press enter to quit." << endl;
	return 0;
}

void printWelcome()
{
	cout << "================================================" << endl;
	cout << "Welcome to BAMMM -  Alpha v0.1" << endl;
	cout << "Creators: \tAlvaro Home - Matthew Konstantinou - Matthew Witkowski\n\t\tBradley Crusco - Michael Abramo" << endl;
	cout << "================================================" << endl;
}



bool createActor()
{

	return false;
}
