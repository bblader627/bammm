/*
 * JSONPrimitive.h
 *
 *  Created on: Nov 19, 2013
 *      Author: michael
 */

#ifndef JSONPRIMITIVE_H_
#define JSONPRIMITIVE_H_

#include "JSON.h"
using namespace bammm;
namespace bammm
{

	class JSONPrimitive: JSON
	{

		protected:

			union value_t
			{
					char c;
					int i;
					double d;
			} _value;

		public:

			JSONPrimitive();
			JSONPrimitive(char* newName, value_t newValue,
					bammm::JSON_TYPE newType);

			virtual ~JSONPrimitive();
			value_t getValue();

	};

	JSONPrimitive::JSONPrimitive()
	{
		_name = "empty";
		_value.i = 8;
		_type = JSON_NULL;
	}

	JSONPrimitive::JSONPrimitive(char* newName, value_t newValue,
			JSON_TYPE newType)
	{
		_name = newName;
		_value = newValue;
		_type = newType;
	}

	virtual JSONPrimitive::~JSONPrimitive()
	{

	}

	JSONPrimitive::value_t JSONPrimitive::getValue()
	{
		return _value;
	}

}

#endif /* JSONPRIMITIVE_H_ */
