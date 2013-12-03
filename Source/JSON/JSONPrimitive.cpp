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
 * JSONPrimitive cpp file.
 *
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

	JSONPrimitive::JSONPrimitive(string newName, bool newValue,
			JSON_TYPE newType)
	{
		_name = newName;
		_value.b = newValue;
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

	float JSONPrimitive::getFloatValue()
	{
		return _value.f;
	}

	uint JSONPrimitive::getUIntValue()
	{
		return _value.u;
	}

	void JSONPrimitive::setValue(int newValue)
	{
		_value.i = newValue;
	}

	void JSONPrimitive::setValue(double newValue)
	{
		_value.d = newValue;
	}

	void JSONPrimitive::setValue(string newValue)
	{
		_value.str = newValue;
	}

	JSONPrimitive & JSONPrimitive::operator[](const string & rhs)
	{
		return *this;
	}
}
