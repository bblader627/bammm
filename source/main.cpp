#include <iostream>
#include "resources/grid3d.h"
#include "controllers/PlayerController.h"
#include "weapons/Stein.h"
#include "actors/DwarfActor.h"
#include "actors/OrcActor.h"
#include "weapons/MeleeWeapon.h"
#include <random>
//#include "JSON/JSONParser.h"
//#include "IStateCallback.h"

using namespace bammm;
using namespace std;

void printWelcome();
void printOptions();

int main()
{
	printWelcome();
	bool printMap = true;
	int gridX = 10;
	int gridY = 10;
	int gridZ = 10;
	Grid3d<Actor*>* GRID = new Grid3d<Actor*>(gridX,gridY,gridZ);
	MeleeCombat* meleeCombat = new MeleeCombat();

	//Creation of Hero
	DwarfActor* bob = new DwarfActor();
	Vector3D* temp = new Vector3D(0,0,0);
	GRID->insert(temp, bob);
	delete temp;

	//Random number generator
	random_device rd;
	mt19937 generator(rd());

	//Pick random number of orcs
	int minOrc = 1;
	int maxOrc = 10;
	uniform_int_distribution<int> orcDistribution (minOrc, maxOrc);
	int orcCount = orcDistribution(generator);

	//Create the orcs
	uniform_int_distribution<int> xDistribution (0, gridX - 1);
	uniform_int_distribution<int> yDistribution (0, gridY - 1);
	for(int i = 0; i < orcCount; i++)
	{
		int randomX = xDistribution(generator);
		int randomY = yDistribution(generator);
		temp = new Vector3D(randomX, randomY, 0);
		GRID->insert(temp, new OrcActor());
		delete temp;
	}

	PlayerController* controller = new PlayerController(GRID, meleeCombat);
	controller->setup(bob);

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
			cout << GRID->to_string() << "\n";
		}

		controller->printOptions();
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
				//wait
				break;
			default:
				cout << "Invalid Input" << endl;
				break;
		}

		if(!playGame)
		{
    		break;
		}
		controller->input(input, dTime);
	}
	delete input;

	cout << "Thanks for playing!  Press enter to quit." << endl;
	//string waitfortext;
	//cin >> waitfortext;

	//provide option for state change

	//tick
	delete GRID;
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
