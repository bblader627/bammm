#include <iostream>
#include "SceneManager/SceneManager.h"
#include "Controllers/PlayerController.h"
#include "Factories/Factory.h"
#include <unistd.h>
#include <random>
#include <exception>

using namespace bammm;
using namespace std;

void printWelcome();
void printOptions();
DynamicArray<string>* parseInput(string);

int main()
{

	printWelcome();
	bool printMap = true;

	SceneManager sceneManager;
	Factory* actorFactory = new Factory(&sceneManager);
	MeleeCombat meleeCombat;

	actorFactory->setup();
	sceneManager.setMeleeCombat(meleeCombat);

	//Will be deleted; controllers are added for each new actor created in factory
	PlayerController controller;

	bool playGame = true;
	bool doTick = true;
	string command;
	unsigned int loopCounter = 0;

	DynamicArray<string>* input = new DynamicArray<string>();

	//string sleep = "sleep";
	string mine = "mine";
	string drink = "drink";
	string sing = "sing";
	string brawl = "brawl";
	string attack = "combat";
	string wait = "wait";

	float dTime = 0;
	while (playGame)
	{
		doTick = true;
		if (loopCounter == 0)
		{
			input->clear();

			if (printMap)
			{
				cout << sceneManager.getSceneGraph().toString() << "\n";
			}

			//controller.printOptions();
			getline(cin, command);

			input = parseInput(command);
			command = input->get(0);

			if (command == wait)
			{
				//Wait [#]

				if (input->getSize() == 2)
				{
					string number_str = input->get(1);
					loopCounter = atoi(number_str.c_str());
				}
				else
				{
					cout << "Invalid input\n";
					doTick = false;
				}

				if (loopCounter == 0)
				{
					cout << "Invalid input\n";
					doTick = false;
				}

			}

			else if (command == "exit")
			{
				playGame = false;
			}

			if (!playGame)
			{
				break;
			}

			if (doTick)
			{
				controller.input(input, dTime);
				sceneManager.tick(0);
				if (loopCounter > 0)
				{
					loopCounter--;
				}
			}
		}
		else	//looping
		{
			unsigned int pause = 1;
			sleep(pause);
			loopCounter--;
			cout << sceneManager.getSceneGraph().toString() << "\n";
			sceneManager.tick(0);
		}

	}
	delete input;

	cout << "Thanks for playing!" << "\n";
	return 1;
}

void printWelcome()
{
	cout << "================================================" << "\n";
	cout << "Welcome to BAMMM -  Alpha v0.2" << "\n";
	cout
			<< "Creators: \tAlvaro Home - Matthew Konstantinou - Matthew Witkowski\n\t\tBradley Crusco - Michael Abramo"
			<< "\n";
	cout << "================================================" << "\n";
}

bool createActor()
{

	return false;
}

DynamicArray<string>* parseInput(string input)
{
	char delimiter = ' ';
	char current;

	string builder = "";
	DynamicArray<string>* result = new DynamicArray<string>();

	for (unsigned int i = 0; i < input.size(); i++)
	{
		current = input[i];

		if (i == input.size() - 1)
		{
			builder += current;
			result->add(builder);
			builder = "";
		}

		if (current == delimiter)
		{
			result->add(builder);
			builder = "";
		}
		else
		{
			builder += current;
		}
	}
	return result;
}
