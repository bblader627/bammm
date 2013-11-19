/*
 * JSONPrimitive.h
 *
 *  Created on: Nov 19, 2013
 *      Author: michael
 */

#ifndef JSONPRIMITIVE_H_
#define JSONPRIMITIVE_H_

#include "JSON.h"

namespace bammm
{

	class JSONPrimitive: JSON
	{

		protected:

			string _value;

		public:

			JSONPrimitive()
			{
				_name = "empty";
				_value = "empty";
				_type = JSON_NULL;
			}

			virtual ~JSONPrimitive();
	};

}

#endif /* JSONPRIMITIVE_H_ */
