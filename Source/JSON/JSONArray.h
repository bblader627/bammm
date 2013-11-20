/*
 * JSONArray.h
 *
 *  Created on: Nov 19, 2013
 *      Author: michael
 */

#ifndef JSONARRAY_H_
#define JSONARRAY_H_

#include "JSON.h"

namespace bammm
{

	class JSONArray: JSON
	{

		private:

			DynamicArray<JSON> _children;

		public:

			JSONArray();
			JSONArray(string);
			JSONArray(string, JSON*);

			virtual ~JSONArray();

			JSONPrimitive::value_t operator[](const unsigned int & rhs);

	};

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

	virtual JSONArray::~JSONArray()
	{
		delete _children;
	}

	JSONPrimitive::value_t JSONArray::operator[](const unsigned int & rhs)
	{
		if (_children[rhs].getType() == JSON_ARRAY)
		{
			cout
					<< "Error: Can not return a JSON ARRAY using the [] operator \n";
			return "error";
		}
		else if (_children[rhs].getType() == JSON_NULL)
		{
			cout
					<< "Error: JSONPrimitive Object not initialized to a value or incorrect type :: JSON_NULL \n";
			return "error";
		}
		else
		{
			return _children[rhs].getValue();
		}
	}

}
#endif /* JSONARRAY_H_ */
