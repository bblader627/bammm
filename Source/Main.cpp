#include <iostream>
#include "Factories/Factory.h"
#include "SceneManager/SceneManager.h"
#include "Controllers/PlayerController.h"
#include "Factories/Factory.h"
#include "Resources/Constant.h"
#include <unistd.h>
#include <random>
#include "LevelingSystem/LevelingSystem.h"

namespace bammm
{
	Factory* factory;
}

using namespace bammm;
using namespace std;

void printWelcome();
void printTutorial();
void printOptions();
void printStory();
void clearTerminal();
DynamicArray<string>* parseInput(string);

int main()
{

	printWelcome();
	printStory();
	bool printMap = true;

	SceneManager sceneManager;
	bammm::factory = new Factory(&sceneManager);

	bammm::factory->setup();

	bool playGame = true;
	bool doTick = true;
	bool justStarted = true;
	string command;
	uint loopCounter = 0;

	DynamicArray<string>* input = new DynamicArray<string>();

	DynamicArray<string> validCommands = *(new DynamicArray<string>());
	validCommands.add("mine");
	validCommands.add("drink");
	validCommands.add("brawl");
	validCommands.add("chop");
	validCommands.add("fish");
	validCommands.add("focus");
	validCommands.add("lose");
	validCommands.add("inventory");
	validCommands.add("eat");
	validCommands.add("craft");

	float deltaTime = 0;

	while (playGame)
	{
		command = "";
		doTick = true;
		bool doInput = true;
		if (loopCounter == 0)
		{

			input->clear();

			if (printMap)
			{
				if (!justStarted)
				{
					//clearTerminal();
				}

				cout << sceneManager.getSceneGraph().toString() << "\n";
			}

			justStarted = false;

			while (command == "")
			{
				cout << "What would you like your dwarves to do? ";
				getline(cin, command);
			}

			input = parseInput(command);
			command = input->get(0);

			if (command == "wait")
			{
				if (input->getSize() == 2)
				{
					string number_str = input->get(1);
					loopCounter = atoi(number_str.c_str());
					doInput = false;
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
			else if (!(validCommands.contains(command)))
			{
				cout << "Invalid argument" << endl;
				doTick = false;
			}

			if (!playGame)
			{
				break;
			}

			if (doTick)
			{
				if (doInput)
				{
					sceneManager.input(input, deltaTime);
				}

				sceneManager.tick(0);

				if (loopCounter > 0)
				{
					loopCounter--;
				}
			}
		}
		else
		{
			uint pause = 1;
			sleep(pause);
			loopCounter--;
			//clearTerminal();
			cout << sceneManager.getSceneGraph().toString() << "\n";
			sceneManager.tick(0);
		}

	}

	delete input;

	cout << "Thanks for playing!" << "\n";
	exit(1);
}

void printWelcome()
{
	cout << "================================================" << "\n";
	cout << "Welcome to BAMMM - Alpha v0.2.1.1.2.3.400 " << "\n";
	cout
			<< "Creators: \tAlvaro Home - Matthew Konstantinou - Matthew Witkowski\n\t\tBradley Crusco - Michael Abramo"
			<< "\n";
	cout << "================================================" << "\n";
}

void clearTerminal()
{
	cout << "\033[2J";
}

void printTutorial()
{

}

void printStory()
{
	clearTerminal();
	cout << "The year is 13 of the Third Age. \n\n";
	cout
			<< "The realm of Sojo has erupted into turmoil. Orcs of the LA offices are beginning their march upon the Dwarves of New York. \n";
	cout
			<< "The Orcs want to implement a new networking system in our fortress, but FUCK THAT! I've seen their code. \n";
	cout
			<< "Here, in our fortress of New York, we make our final stand against their bullshit... \n\n";
	cout
			<< "You have control over the actions of Bob, Jim, Joe, Phil, and Frank.\n\n";
}

DynamicArray<string>* parseInput(string input)
{
	char delimiter = ' ';
	char current;

	string builder = "";
	DynamicArray<string>* result = new DynamicArray<string>();

	for (uint i = 0; i < input.size(); i++)
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
