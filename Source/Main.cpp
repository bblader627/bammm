#include <iostream>
#include "SceneManager/SceneManager.h"
#include "Controllers/PlayerController.h"
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
	sceneManager.setMeleeCombat(meleeCombat);

	//Creation of Hero
	Actor* bob = new Actor("Bob", "dwarf");
	Vector3D* temp = new Vector3D(0, 0, 0);
	sceneManager.getSceneGraph().add(temp, bob);

	PlayerController controller;
	controller.setup(*bob, meleeCombat, sceneManager.getSceneGraph());

	bool playGame = true;
	int choice;

	cout << bob->getName() << " is waiting for instructions." << "\n";

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

		if (printMap)
		{
			cout << sceneManager.getSceneGraph().toString() << "\n";
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
				cout << "Invalid Input" << "\n";
				break;
		}

		if (!playGame)
		{
			break;
		}
		controller.input(input, dTime);
		sceneManager.tick(0);
	}
	delete input;

	cout << "Thanks for playing!  Press enter to quit." << "\n";
	return 0;
}

void printWelcome()
{
	cout << "================================================" << "\n";
	cout << "Welcome to BAMMM -  Alpha v0.1" << "\n";
	cout
			<< "Creators: \tAlvaro Home - Matthew Konstantinou - Matthew Witkowski\n\t\tBradley Crusco - Michael Abramo"
			<< "\n";
	cout << "================================================" << "\n";
}

bool createActor()
{

	return false;
}
