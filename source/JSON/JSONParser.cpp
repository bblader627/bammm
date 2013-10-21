/*
 * JSONParser.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: michael
 */

#include "JSONParser.h"
#include "../resources/dynamicarray.h"

using namespace std;
using namespace bammm;

namespace bammm
{

	void JSONParser::addRoot(JSON & newNode)
	{
		rootMap.add(newNode.getName(), newNode);
	}

	void JSONParser::addChild(JSON & rootNode, JSON & newNode)
	{
		rootNode.addChild(newNode);
	}

	bool JSONParser::parseFile(string filename)
	{

		ifstream input;
		char current;
		bool isValue = false;
		int isArray = 0;
		JSON *currentNode = NULL;
		JSON *parentNode = NULL;
		string name = "";
		string value = "";

		input.open(filename.c_str());

		if (!input.is_open())
		{
			cout << "Failed to open file: " << filename << " does not exist."
					<< endl;
			return false;
		}

		while (!input.eof())
		{

			current = (char) input.get();

			switch (current)
			{

				case '[':
					isValue = false;
					isArray++;
					break;

				case '{':
					isValue = false;
					parentNode = currentNode;
					currentNode = new JSON();
					currentNode->setParent(*parentNode);
					parentNode->addChild(*currentNode);
					break;

				case '"':

					if (currentNode == NULL)
					{
						cout << "Error reading in JSON object" << endl;
						return false;
					}

					current = (char) input.get();
					while (!input.eof() && current != '"')
					{
						if (isValue == false)
						{
							name += current;
						}
						else
						{
							value += current;
						}
						current = (char) input.get();
					}

					if (isValue == false)
					{
						currentNode->setName(name);
					}
					else
					{
						currentNode->setValue(current);
						currentNode->setType(JSON_STRING);
					}
					break;

				case ':':
					isValue = true;

					while (input.peek() == ' ' || isdigit(input.peek())
							|| input.peek == 't' || input.peek() == 'f')
					{

						current = (char) input.get();

						if (isdigit(current))
						{
							while (isdigit(current))
							{
								value += current;
								current = (char) input.get();
							}
							currentNode->setValue(value);
							currentNode->setType(JSON_INT);
							break;
						}
						else if (current == 't' || current == 'f')
						{
							while (isalpha(current))
							{
								value += current;
								current = (char) input.get();
							}
							if (value == "false" || value == "true")
							{
								currentNode->setValue(value);
								currentNode->setType(JSON_BOOL);
								break;
							}
							else
							{
								cout
										<< "Error parsing BOOLEAN value in JSON file."
										<< endl;
								return 1;
							}
						}

					}

					break;

				case ',':
					isValue = false;
					break;

				case ']':
					isArray--;
					break;

				case '}':
					currentNode = parentNode;
					*parentNode = parentNode->getParent();
					break;

				default:
					break;
			}

			continue;
		}

		return true;
	}
}
