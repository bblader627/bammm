/*
 * JSONParser.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: michael
 */

#include "JSONParser.h"

using namespace std;
using namespace bammm;

void JSONParser::addRoot(JSON & newNode)
{
	root.add(newNode.getName(), newNode);
}

void JSONParser::addChild(JSON & rootNode, JSON & newNode)
{
	rootNode.addChild(newNode);
}

bool JSONParser::parseFile(string filename)
{

	ifstream input;
	char current;
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

		if (current == '[')
		{

		}
		else if (current == '{')
		{
			//create object to be stored in structure
		}
		else if (current == '"')
		{
			current = input.get();

			while (current != '"')
			{
				current = (char) input.get();
				name += current;
			}

			while (!input.eof())
			{
				current = (char) input.get();

				if (current == ':')
				{
					while (!input.eof())
					{

					}
				}
			}

		}
	}

	return true;

}
