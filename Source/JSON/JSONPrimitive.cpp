/*
 * JSONPrimitive.h
 *
 *  Created on: Nov 19, 2013
 *      Author: michael
 *
 *      DOCUMENTATION:
 *
 *      Inherits from JSON
 *      JSONPrimitive represents a key:value pair in a JSON Object
 */

#include "JSONPrimitive.h"

namespace bammm
{

	JSONPrimitive::JSONPrimitive()
	{
		_name = "empty";
		_value.str = "empty";
		_type = JSON_NULL;
	}

	JSONPrimitive::JSONPrimitive(string newName, value_t newValue,
			JSON_TYPE newType)
	{
		_name = newName;
		_value = newValue;
		_type = newType;
	}

	JSONPrimitive::JSONPrimitive(string newName, string newValue,
			JSON_TYPE newType)
	{
		_name = newName;
		_value.str = newValue;
		_type = newType;
	}

	JSONPrimitive::JSONPrimitive(string newName, int newValue,
			JSON_TYPE newType)
	{
		_name = newName;
		_value.i = newValue;
		_type = newType;
	}

	JSONPrimitive::JSONPrimitive(string newName, double newValue,
			JSON_TYPE newType)
	{
		_name = newName;
		_value.d = newValue;
		_type = newType;
	}

	JSONPrimitive::~JSONPrimitive()
	{
		cout << "Deleting JSON Primitive \n";
	}

	JSONPrimitive::value_t JSONPrimitive::getValue()
	{
		return _value;
	}

	int JSONPrimitive::getIntValue()
	{
		return _value.i;
	}

	double JSONPrimitive::getDoubleValue()
	{
		return _value.d;
	}

	bool JSONPrimitive::getBoolValue()
	{
		return _value.b;
	}

	string JSONPrimitive::getStringValue()
	{
		return _value.str;
	}

	void JSONPrimitive::setValue(int newVal)
	{
		_value.i = newVal;
	}

	void JSONPrimitive::setValue(double newVal)
	{
		_value.d = newVal;
	}

	void JSONPrimitive::setValue(string newVal)
	{
		_value.str = newVal;
	}

	JSONPrimitive & JSONPrimitive::operator[](const string & rhs)
	{
		return *this;
	}

}
