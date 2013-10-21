#include <iostream>
#include "actors/actor.h"
#include "controllers/PlayerController.h"
//#include "JSON/JSONParser.h"
//#include "IStateCallback.h"

using namespace bammm;
using namespace std;

void printWelcome();

int main()
{
	printWelcome();

	Actor* bob = new Actor("Bob");

	PlayerController* controller = new PlayerController();
	controller->initialize(bob);


//start dwarf in IDLE			note - this will occur in initialize once statemachine is functional

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

bool createActor()
{

	return false;
}
