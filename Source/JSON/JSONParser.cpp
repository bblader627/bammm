/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski
 *  Bradley Crusco
 * Description:
 * JSONParser cpp file.
 */

#include "JSONParser.h"
#include "JSONPrimitive.h"
#include "../Resources/DynamicArray.h"
#include "JSON.h"
#include "JSONArray.h"
#include <stdlib.h>

using namespace std;

namespace bammm
{

	JSONParser::JSONParser()
	{
	}

	void JSONParser::addRoot(JSON & newNode)
	{
		cout << "adding root \n";
		_rootMap.add(newNode.getName(), &newNode);
		cout << "root added \n";
	}

	void JSONParser::addChild(JSON & rootNode, JSON & newNode)
	{
		rootNode.addChild(newNode);
	}

	HashMap<JSON*>* JSONParser::getMap()
	{
		return &_rootMap;
	}

	JSON* JSONParser::getRootNode(string key)
	{
		return _rootMap.getValue(key);
	}

	void JSONParser::printAllRoots()
	{
		DynamicArray<string>* keys = _rootMap.getAllKeys();
		for (unsigned int i = 0; i < keys->getSize(); i++)
		{
			cout << keys->get(i) << endl;
		}
	}

	bool JSONParser::parseFile(string filename)
	{

		ifstream input;
		char current;
		bool isKey = false;
		bool isValue = false;
		bool isDouble = false;
		JSON *currentNode = NULL;
		JSON *parentNode = NULL;
		JSON *arrayRootNode = NULL;
		bool skipGet = false;
		bool isArray = false;
		bool isNewArrayObject = false;
		string name = "";
		string value = "";

		input.open(filename.c_str());

		if (!input.is_open())
		{
			cout << "Failed to open file: " << filename << " does not exist."
					<< "\n";
			return false;
		}

		cout << "File found and opened. Beginning parse. \n";
		cout.flush();

		while (!input.eof())
		{
			if (!skipGet)
			{
				current = (char) input.get();
			}
			skipGet = false;

			if (current == '[')
			{
				cout << "found [" << endl;
			}

			switch (current)
			{

				case '{':
					cout << "\n\nParsing { \n";
					cout.flush();

					if (currentNode == NULL)
					{
						currentNode = new JSON("root");
						addRoot(*currentNode);
						cout.flush();
					}

					if (isArray)
					{
						if (!isNewArrayObject)
						{
							isNewArrayObject = true;
						}
						parentNode = arrayRootNode;		//parent should be dwarves array
						currentNode = new JSON();		//Children will be attributes
						currentNode->setParent(*parentNode);
						//parentNode->addChild(*currentNode);

					}

					isValue = false;
					isKey = true;

					break;

				case '}':
					cout << "Parsing } \n";
					cout.flush();

					if (parentNode == NULL)
					{
						/* This will be the final output of the parser. This should not output before completion. */
						cout << "Completed parsing " << filename << ". \n";
						input.close();

						currentNode = NULL;
					}
					else if (isArray)
					{
						//TODO: UNDO THIS SHIT
						cout << "\n================ENDING ARRAY OBJECT===============" << endl;
						cout << "Parent: " << currentNode->getParent()->getName() << " current: " << currentNode->getName() << endl;


						//parentNode = currentNode->getParent()->getParent();		//parent should be dwarves array
						arrayRootNode->addChild(*currentNode->getParent());
						parentNode = arrayRootNode;
						currentNode = arrayRootNode;
						//currentNode = currentNode->getParent();		//Children will be attributes
						//currentNode->setParent(*parentNode);
					}
					else
					{
						currentNode = currentNode->getParent();
						parentNode = parentNode->getParent();

						isKey = true;
					}

					break;

				case '[':
					cout << "Parsing [ \n";
					cout.flush();
					isArray = true;
					if (currentNode == NULL)
					{
						currentNode = new JSONArray(name);
						addRoot(*currentNode);
					}
					else
					{
						parentNode = currentNode->getParent();
						currentNode = new JSONArray(name);
						parentNode->addChild(*currentNode);
					}
					break;

				case ']':
					cout << "Parsing ] \n";
					cout.flush();

					currentNode = currentNode->getParent();
					parentNode = parentNode->getParent();

					isKey = true;
					isArray = false;

					break;

				case '"':
					cout << "Parsing \"";
					cout.flush();

					current = (char) input.get();
					name = "";
					value = "";
					while (!input.eof() && current != '"')
					{
						if (isValue == false && isKey == true)
						{
							name += current;
						}
						else if (isValue == true && isKey == false)
						{
							value += current;
						}
						current = (char) input.get();
					}

					break;

				case ':':
					cout << "Parsing : \n";
					cout.flush();

					isKey = false;
					isValue = true;

					value = "";

					/* check  what comes after colon so we may determine type */
					current = (char) input.peek();
					while (!input.eof() && current == ' ')
					{
						current = (char) input.get();
					}

					/* Now that we know the value, we may confirm the type of the JSON Node and create it. */

					parentNode = currentNode;

					if (current == '{')
					{
						if (isArray)
						{
							currentNode->addChild(*(new JSON(name)));
						}
						else
						{
							currentNode = new JSON(name);
						}
						isKey = true;
						isValue = false;
					}
					else if (current == '[')
					{
						//parentNode = currentNode->getParent()->getParent();
						if (isArray)
						{
							currentNode->addChild(*(new JSONArray(name)));
						}
						else
						{
							currentNode = new JSONArray(name);
							arrayRootNode = currentNode;
						}

						isArray = true;
						currentNode->setParent(*parentNode);
						parentNode->addChild(*currentNode);
						//parentNode = currentNode;

						isKey = true;
						isValue = false;

					}
					else if (current == '"')
					{
						current = (char) input.get();
						current = (char) input.get();
						while (!input.eof() && current != '"')
						{
							value += current;
							current = (char) input.get();
						}

						if (isNewArrayObject)
						{
							currentNode->setName(value);
							isNewArrayObject = false;
						}

						//cout << "\nValue:  " << value << "\n";

						if (isArray)
						{
							currentNode->addChild(*(new JSONPrimitive(name, value, JSON_STRING)));

						}
						else
						{
							currentNode = new JSONPrimitive(name, value,
									JSON_STRING);
						}

					}
					else if (current == 'f' || current == 't')
					{

						while (!input.eof() && current != ' ')
						{
							value += current;
							current = (char) input.get();
						}

						if (value == "false")
						{
							if (isArray)
							{
								currentNode->addChild(*(new JSONPrimitive(name, false, JSON_BOOL)));
							}
							else
							{
								currentNode = new JSONPrimitive(name, false,
										JSON_BOOL);
							}
						}
						else if (value == "true")
						{
							if (isArray)
							{
								currentNode->addChild(*(new JSONPrimitive(name, true, JSON_BOOL)));
							}
							else
							{
								currentNode = new JSONPrimitive(name, true,
										JSON_BOOL);
							}
						}
						else
						{
							cout << "Error parsing string or bool value \n";
							cout.flush();
							return false;
						}
					}
					else if (isdigit(current))
					{

						while (!input.eof() && current != ','&& current != '}')
						{
							value += current;
							current = (char) input.get();
						}

						/* Determine whether value has a decimal. If so, make DOUBLE. Else INT */

						for (unsigned int i; i < value.size(); i++)
						{
							if (value[i] == '.')
							{
								isDouble = true;
								break;
							}
							isDouble = false;
						}

						if (isDouble == false)
						{
							currentNode = new JSONPrimitive(name,
									atoi(value.c_str()), JSON_INT);
						}
						else
						{
							currentNode = new JSONPrimitive(name,
									atof(value.c_str()), JSON_DOUBLE);
						}

						skipGet = true;
						isValue = false;
						isKey = true;
					}
					else
					{
						cout  << "Error parsing value. Invalid character found. \n";
						return false;
					}

					currentNode->setParent(*parentNode);

					if (parentNode == NULL)
					{
						addRoot(*currentNode);
					}
					else
					{
						parentNode->addChild(*currentNode);
					}

					cout << "\tName: " << name << " Value: " << value
							<< " Parent: " << currentNode->getParent()->getName() << endl;
					break;

				case ',':
					cout << "Parsing ," << "\n";
					cout.flush();

					/* reset node to parent so next key/value may be added as a child to parent */
					currentNode = currentNode->getParent();
					parentNode = currentNode->getParent();

					isValue = false;
					isKey = true;

					break;

			}
		}

		cout << "End of file reached \n";
		cout.flush();

		currentNode = NULL;
		parentNode = NULL;
		delete currentNode;
		delete parentNode;

		return true;
	}
}
