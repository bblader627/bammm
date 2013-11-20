/*
 * JSONArray.h
 *
 *  Created on: Nov 19, 2013
 *      Author: michael
 *
 *      DOCUMENTATION
 *
 *      Inherits from JSON
 *      Represents an Array in JSON
 *      May hold any JSON Object including JSONPrimitive and JSONArray
 *      Stores JSON Objects in a DynamicArray
 *
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

			~JSONArray();

			JSON operator[](const unsigned int & rhs);

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

	JSONArray::~JSONArray()
	{
		cout << "Deleting JSON Array \n";
		delete _children;
	}

	JSON JSONArray::operator[](const unsigned int & rhs)
	{
		if (_children[rhs].getType() == JSON_NULL)
		{
			cout
					<< "Error: JSONPrimitive Object not initialized to a value or incorrect type :: JSON_NULL \n";
			return "error";
		}
		else
		{
			return _children[rhs];
		}
	}

}
#endif /* JSONARRAY_H_ */
