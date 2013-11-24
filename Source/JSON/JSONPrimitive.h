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

#include <string>
#include "JSON.h"

namespace bammm
{

	class JSONPrimitive: public JSON
	{

		private:

			struct value_t
			{
					string str;
					int i;
					double d;
					bool b;
			} _value;

		public:

			JSONPrimitive();
			JSONPrimitive(string, value_t, JSON_TYPE);
			JSONPrimitive(string, string, JSON_TYPE);
			JSONPrimitive(string, int, JSON_TYPE);
			JSONPrimitive(string, double, JSON_TYPE);

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

			JSONPrimitive & operator[](const string & rhs);

			//JSON operator[](const unsigned int & rhs);
	};

}

#endif /* JSONPRIMITIVE_H_ */
