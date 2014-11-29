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
void parseInput(string, DynamicArray<string>&);

int main()
{

	clearTerminal();
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

	DynamicArray<string> input;

	DynamicArray<string> validCommands;
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

			input.clear();

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

			parseInput(command, input);
			command = input.get(0);

			if (command == "wait")
			{
				if (input.getSize() == 2)
				{
					string number_str = input.get(1);
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
					sceneManager.input(&input, deltaTime);
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
	
	cout << "Thanks for playing!" << "\n";
	exit(1);
}

void printWelcome()
{
	cout << "===============================================================" << "\n";
	cout << "Welcome to BAMMM - Alpha v0.2.1.1.2.3.400 Revision 3" << "\n";
	cout
			<< "Creators: \tAlvaro Home - Matthew Konstantinou - Matthew Witkowski\n\t\tBradley Crusco - Michael Abramo"
			<< "\n"
			<< "For assistance regarding commands, please see README"
			<< "\n";
	cout << "===============================================================" << "\n\n";
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

	cout << "The year is 13 of the Third Age.\n\n";
	cout
			<< "The realm of Sojo has erupted into turmoil. Orcs of the Westlands are beginning their march upon the Dwarves of East Yorkshire.\n";
	cout
			<< "Here in your dwarf fortress, you must fight off the orc invaders if we are to have any hope of survival.\n";
	cout
			<< "You have control over the actions of Bob, Jim, Joe, Peter_Dinklage, and Frank. Our best warriors.\n\n";
}

void parseInput(string input, DynamicArray<string>& array)
{
	char delimiter = ' ';
	char current;

	string builder = "";
	array.clear();
	for (uint i = 0; i < input.size(); i++)
	{
		current = input[i];

		if (i == input.size() - 1)
		{
			builder += current;
			array.add(builder);
			builder = "";
		}

		if (current == delimiter)
		{
			array.add(builder);
			builder = "";
		}
		else
		{
			builder += current;
		}
	}
}
