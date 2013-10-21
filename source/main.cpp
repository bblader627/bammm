#include <iostream>
#include "actors/actor.h"
#include "controllers/PlayerController.h"
//#include "JSON/JSONParser.h"
//#include "IStateCallback.h"

using namespace bammm;
using namespace std;

void printWelcome();
void printOptions();

int main()
{
	printWelcome();

	Actor* bob = new Actor("Bob");

	PlayerController* controller = new PlayerController();
	controller->setup(bob);

	bool playGame = true;
	int choice;

	cout << bob->getName() << " is waiting for instructions." << endl;

	while (playGame)
	{
		printOptions();
		cin >> choice;

		switch (choice)
		{
			case 0:
				playGame == false;
				break;
			case 1:
				controller->input("mine");
				break;
			case 2:
				controller->input("drink");
				break;
			case 3:
				controller->input("sing");
				break;
			case 4:
				controller->input("fight");
				break;
			case 5:
				controller->input("sleep");
				break;
		}
	}

	cout << "Thanks for playing!  Press enter to quit." << endl;
	string waitfortext;
	cin >> waitfortext;

	//provide option for state change

	//tick

	return 0;
}

void printWelcome()
{
	cout << "================================================" << endl;
	cout << "Welcome to BAMMM -  Alpha v0.1" << endl;
	cout << "Creators: Alvaro Home - Matthew Konstantinou - Matthew Witkowski - Bradley Crusco - Michael Abramo" << endl;
	cout << "================================================" << endl;
}

void printOptions()
{
	cout << "Select an activity for your dwarf:" << endl;
	cout << "0. Quit" << endl;
	cout << "1. Mine gold" << endl;
	cout << "2. Drink ale" << endl;
	cout << "3. Sing a song" << endl;
	cout << "4. Fight a dwarf" << endl;
	cout << "5. Go to sleep" << endl;
}

bool createActor()
{

	return false;
}
