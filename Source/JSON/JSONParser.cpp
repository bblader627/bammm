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
 *
 */

#include "JSONParser.h"
#include "../Resources/DynamicArray.h"

using namespace std;

namespace bammm
{
	void JSONParser::addRoot(JSON & newNode)
	{
		_rootMap.add(newNode.getName(), newNode);
	}

	void JSONParser::addChild(JSON & rootNode, JSON & newNode)
	{
		rootNode.addChild(newNode);
	}

	HashMap<JSON>* JSONParser::getMap()
	{
		return &_rootMap;
	}

	bool JSONParser::parseFile(string fileName)
	{

		ifstream input;
		char current;
		bool isValue = false;
		int isArray = 0;
		JSON *currentNode = NULL;
		JSON *parentNode = NULL;
		JSON *childNode = NULL;
		string name = "";
		string value = "";

		input.open(fileName.c_str());

		if (!input.is_open())
		{
			cout << "Failed to open file: " << fileName << " does not exist."
					<< endl;
			return false;
		}

		while (!input.eof())
		{

			current = (char) input.get();

			switch (current)
			{

				case '[':
					currentNode->setType(JSON_ARRAY);
					isValue = false;
					isArray++;
					break;
				case '{':
					isValue = false;

					if (currentNode == NULL)
					{
						currentNode = new JSON();
						this->addRoot(*currentNode);
						// JSON node is created - now we continue so we may parse the name and set values
					}
					else
					{
						//seg faulted before changes to this
						parentNode = currentNode;
						currentNode = new JSON();
						currentNode->setParent(*parentNode);
						parentNode->addChild(*currentNode);
					}
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
						//the name of the first attribute is the name of the JSON node. Need to fix.
						currentNode->setName(name);
					}
					else
					{
						currentNode->setValue(value);

						if (value == "false" || value == "true")
						{
							currentNode->setType(JSON_BOOL);
						}
						else if (value == "")
						{
							currentNode->setType(JSON_NULL);
						}
						else if (isdigit(value[0]))
						{
							for (unsigned int i = 0; i < value.size(); i++)
							{
								if (value[i] == '.')
								{
									currentNode->setType(JSON_DOUBLE);
								}
								else
								{
									currentNode->setType(JSON_INT);
								}
							}
						}
						else
						{
							currentNode->setType(JSON_STRING);
						}
					}
					break;
				case ':':
					isValue = true;
					break;
				case ',':
					isValue = false;

					childNode = new JSON();

					*currentNode = currentNode->getParent();
					currentNode->addChild(*childNode);
					childNode->setParent(*currentNode);

					currentNode = childNode;
					break;
				case ']':
					isArray--;
					break;
				case '}':

					if (parentNode == NULL)
					{
						break;
					}

					currentNode = parentNode;
					*parentNode = currentNode->getParent();
					break;
				default:
					break;
			}

			continue;
		}

		if (isArray > 0)
		{
			cout
					<< "Error: Not all brackets or braces are closed in the JSON file."
					<< endl;
			return 1;
		}

		return true;
	}
}
