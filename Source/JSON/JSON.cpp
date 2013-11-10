/*
 * JSON.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: michael
 */

#include "JSONParser.h"
#include <sstream>

using namespace bammm;
using namespace std;

namespace bammm
{

	JSON::JSON()
	{
		name = "empty";
		value = "empty";
		type = JSON_NULL;
		parent = NULL;
	}

	JSON::JSON(string jname, string jvalue, JSON_TYPE jtype,
			const JSON & jparent)
	{
		name = jname;
		value = jvalue;
		type = jtype;
		*parent = jparent;
	}

	JSON::~JSON()
	{
	}

	JSON JSON::getParent()
	{
		return *parent;
	}

	string JSON::getName()
	{
		return name;
	}

	JSON_TYPE JSON::getType()
	{
		return type;
	}

	JSON JSON::getChild(string childName)
	{
		if (this->value != "empty")
		{
			return *this;
		}
		else
		{
			return this->children.getValue(childName);
		}
	}

	HashMap<JSON>* JSON::getChildren()
	{
		return &children;
	}

	JSON& JSON::operator=(const JSON & rhs)
	{
		this->name = rhs.name;
		this->value = rhs.value;
		this->type = rhs.type;
		this->parent = rhs.parent;
		this->children = rhs.children;

		return *this;
	}

	string JSON::operator[](const string & index)
	{

		if (this->value == "empty")
		{
			JSON temporary = this->getChild(index);
			return temporary[index];
		}
		else
		{
			return this->value;
		}
	}

	bool JSON::setName(string newName)
	{
		this->name = newName;
		return true;
	}

	bool JSON::setType(JSON_TYPE newType)
	{
		this->type = newType;
		return true;
	}

	bool JSON::setParent(JSON newParent)
	{
		*parent = newParent;
		return true;
	}

	bool JSON::setValue(string newValue)
	{
		this->value = newValue;
		return true;
	}

	bool JSON::setValue(bool newValue)
	{
		if (this->type != JSON_BOOL)
		{
			return false;
		}
		else
		{
			if (newValue == false)
			{
				this->value = "false";
			}
			else
			{
				this->value = "true";
			}
			return true;
		}
	}

	bool JSON::setValue(double newValue)
	{
		if (this->type != JSON_DOUBLE)
		{
			return false;
		}
		else
		{
			/*	The to_string() function is not recognized for me. Something wrong with compiler.	*/
			stringstream val;
			val >> newValue;
			this->value = val.str();
			return true;
		}
	}

	bool JSON::setValue(int newValue)
	{
		if (this->type != JSON_INT)
		{
			return false;
		}
		else
		{
			/*	The to_string() function is not recognized for me. Something wrong with compiler.	*/
			stringstream val;
			val >> newValue;
			this->value = val.str();
			return true;

		}
	}

	void JSON::addChild(JSON & newNode)
	{
		this->children.add(newNode.name, newNode);
		newNode.setParent(*this);
	}

}

