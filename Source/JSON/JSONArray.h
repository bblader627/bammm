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

#include "../Resources/DynamicArray.h"
#include "JSON.h"

namespace bammm
{

	class JSONArray: public JSON
	{

		private:

			DynamicArray<JSON> _children;

		public:

			JSONArray();
			JSONArray(string);
			JSONArray(string, JSON*);

			~JSONArray();

			void addChild(JSON &);

			JSON operator[](const unsigned int & rhs);

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
			 getBoolValue
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns a bool that is equal to the boolean value of this JSON Node
			 */
			bool getBoolValue();

			/*
			 getStringValue
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns a string that is equal to the value of this JSON Node
			 */
			string getStringValue();

	};

}
#endif /* JSONARRAY_H_ */
