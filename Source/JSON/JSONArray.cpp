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
 * JSONArray cpp file.
 *
 */

#include <iostream>
#include "JSONArray.h"

namespace bammm
{
	JSONArray::JSONArray()
	{
		_name = "empty";
		_type = JSON_ARRAY;
		_parent = NULL;
	}

	JSONArray::JSONArray(string name)
	{
		_name = name;
		_type = JSON_ARRAY;
		_parent = NULL;
	}

	JSONArray::JSONArray(string name, JSON *parent)
	{
		_name = name;
		_type = JSON_ARRAY;
		_parent = parent;
	}

	JSONArray::~JSONArray()
	{
		cout << "Deleting JSON Array \n";
	}

	void JSONArray::addChild(JSON & newNode)
	{
		_children.add(newNode);
	}

	JSON JSONArray::operator[](const unsigned int & rhs)
	{
		cout << "returning child of array" << endl;
		if (_children[rhs].getType() == JSON_NULL)
		{
			cout
					<< "Error: JSONPrimitive Object not initialized to a value or incorrect type :: JSON_NULL \n";
			return *this;
		}

		return _children[rhs];
	}

	int JSONArray::getIntValue()
	{
		return 0;

	}

	double JSONArray::getDoubleValue()
	{
		return 0.0;
	}

	bool JSONArray::getBoolValue()
	{
		return false;
	}

	string JSONArray::getStringValue()
	{
		return "";
	}
}
