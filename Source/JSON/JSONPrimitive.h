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

#ifndef JSONPRIMITIVE_H_
#define JSONPRIMITIVE_H_

#include "JSON.h"

namespace bammm
{

	class JSONPrimitive: JSON
	{

		private:

			struct value_t
			{
					string str;
					int i;
					double d;
			} _value;

		public:

			JSONPrimitive();
			JSONPrimitive(string newName, value_t newValue, JSON_TYPE newType);
			JSONPrimitive(string newName, string newValue, JSON_TYPE newType);
			JSONPrimitive(string newName, int newValue, JSON_TYPE newType);
			JSONPrimitive(string newName, double newValue, JSON_TYPE newType);

			~JSONPrimitive();

			/*
			getValue
			@Pre-Condition-  Takes no argument
			@Post-Condition- returns a STRUCT that contains the value of this JSON Node depending on type
			*/
			value_t getValue();


			/*
			setValue
			@Pre-Condition-  Takes an int argument
			@Post-Condition- sets this JSON Nodes value equal to the int argument. Returns void.
			*/
			void setValue(int);

			/*
			setValue
			@Pre-Condition-  Takes a double argument
			@Post-Condition- sets this JSON Nodes value equal to the double argument. Returns void.
			*/
			void setValue(double);

			/*
			setValue
			@Pre-Condition-  Takes a string argument
			@Post-Condition- sets this JSON Nodes value equal to the string argument. Returns void.
			*/
			void setValue(string);

			/*
			setType
			@Pre-Condition-  Takes a JSON_TYPE argument
			@Post-Condition- sets this JSON Nodes JSON_TYPE equal to the JSON_TYPE argument. Returns void.
			*/
			void setType(JSON_TYPE);

			/*
			getIntValue
			@Pre-Condition-  Takes no argument
			@Post-Condition- returns an int that is equal to the value of this JSON Node
			*/
			int getIntValue();

			/*
			getDoubleValue
			@Pre-Condition-  Takes no argument
			@Post-Condition- returns a double that is equal to the value of this JSON Node
			*/
			double getDoubleValue();

			/*
			getStringValue
			@Pre-Condition-  Takes no argument
			@Post-Condition- returns a string that is equal to the value of this JSON Node
			*/
			string getStringValue();

			JSONPrimitive & operator[](const string & rhs);

	};

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
		cout << "Deleting JSON Primitive \,";
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

#endif /* JSONPRIMITIVE_H_ */
