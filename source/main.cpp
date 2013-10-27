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

    DynamicArray<string>* input = new DynamicArray<string>();
	string sleep = "sleep";
	string mine = "mine";
	string drink = "drink";
	string sing = "sing";
	string brawl = "brawl";
	float dTime = 0;
	while (playGame)
	{
		input->clear();
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
