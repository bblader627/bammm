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

			JSONArray()
			{
				_name = "empty";
				_type = JSON_ARRAY;
				_parent = NULL;
			}

			virtual ~JSONArray();

			string operator[](const unsigned int rhs)
			{
				return _children[rhs].getName();
			}

	};

}
#endif /* JSONARRAY_H_ */
