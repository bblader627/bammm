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
 * JSON cpp file.
 *
 */

#include <sstream>
#include <iostream>
#include "JSONParser.h"

using namespace std;

namespace bammm
{
	JSON::JSON()
	{
		_name = "empty";
		_value = "empty";
		_type = JSON_NULL;
		_parent = NULL;
	}

	JSON::JSON(string name, string value, JSON_TYPE type, const JSON & parent)
	{
		_name = name;
		_value = value;
		_type = type;
		*_parent = parent;
	}

	JSON::~JSON()
	{
	}

	JSON JSON::getParent()
	{
		return *_parent;
	}

	JSON JSON::getChild(string name)
	{
		if (this->_value != "empty")
		{
			return *this;
		}
		else
		{
			return this->_children.getValue(name);
		}
	}

	HashMap<JSON>* JSON::getChildren()
	{
		return &_children;
	}

	string JSON::getName()
	{
		return _name;
	}

	JSON_TYPE JSON::getType()
	{
		return _type;
	}

	bool JSON::setParent(JSON newParent)
	{
		*_parent = newParent;
		return true;
	}

	bool JSON::setValue(string newValue)
	{
		this->_value = newValue;
		return true;
	}

	bool JSON::setValue(bool newValue)
	{
		if (this->_type != JSON_BOOL)
		{
			return false;
		}
		else
		{
			if (newValue == false)
			{
				this->_value = "false";
			}
			else
			{
				this->_value = "true";
			}
			return true;
		}
	}

	bool JSON::setValue(int newValue)
	{
		if (this->_type != JSON_INT)
		{
			return false;
		}
		else
		{
			/*	The to_string() function is not recognized for me. Something wrong with compiler.	*/
			stringstream stringStreamValue;
			stringStreamValue >> newValue;
			this->_value = stringStreamValue.str();
			return true;

		}
	}

	bool JSON::setValue(double newValue)
	{
		if (this->_type != JSON_DOUBLE)
		{
			return false;
		}
		else
		{
			/*	The to_string() function is not recognized for me. Something wrong with compiler.	*/
			stringstream stringStreamValue;
			stringStreamValue >> newValue;
			this->_value = stringStreamValue.str();
			return true;
		}
	}

	bool JSON::setName(string newName)
	{
		this->_name = newName;
		return true;
	}

	bool JSON::setType(JSON_TYPE newType)
	{
		this->_type = newType;
		return true;
	}

	void JSON::addChild(JSON & newNode)
	{
		this->_children.add(newNode._name, newNode);
		newNode.setParent(*this);
		cout << "addChild" << endl;
	}

	JSON& JSON::operator=(const JSON & rightHandSide)
	{
		this->_name = rightHandSide._name;
		this->_value = rightHandSide._value;
		this->_type = rightHandSide._type;
		this->_parent = rightHandSide._parent;
		this->_children = rightHandSide._children;

		return *this;
	}

	string JSON::operator[](const string & index)
	{

		if (this->_value == "empty")
		{
			JSON temporary = this->getChild(index);
			return temporary[index];
		}
		else
		{
			return this->_value;
		}
	}
}

