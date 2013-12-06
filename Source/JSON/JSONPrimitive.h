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
 * JSONPrimitive header file.
 *
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
					float f;
					uint u;
			} _value;

		public:
			JSONPrimitive();
			JSONPrimitive(string newName, value_t newValue, JSON_TYPE newType);
			JSONPrimitive(string newName, string newValue, JSON_TYPE newType);
			JSONPrimitive(string newName, int newValue, JSON_TYPE newType);
			JSONPrimitive(string newName, bool newValue, JSON_TYPE newType);
			JSONPrimitive(string newName, double newValue, JSON_TYPE newType);
			~JSONPrimitive();

			/**
			 getValue
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns a STRUCT that contains the value of this JSON Node depending on type
			 */
			value_t getValue();

			/**
			 setValue
			 @Pre-Condition-  Takes an int argument
			 @Post-Condition- sets this JSON Nodes value equal to the int argument. Returns void.
			 */
			void setValue(int newValue);

			/**
			 setValue
			 @Pre-Condition-  Takes a double argument
			 @Post-Condition- sets this JSON Nodes value equal to the double argument. Returns void.
			 */
			void setValue(double newValue);

			/**
			 setValue
			 @Pre-Condition-  Takes a string argument
			 @Post-Condition- sets this JSON Nodes value equal to the string argument. Returns void.
			 */
			void setValue(string newValue);

			/**
			 getIntValue
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns an int that is equal to the value of this JSON Node
			 */
			int getIntValue();

			/**
			 getDoubleValue
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns a double that is equal to the value of this JSON Node
			 */
			double getDoubleValue();

			/**
			 getBoolValue
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns a bool that is equal to the boolean value of this JSON Node
			 */
			bool getBoolValue();

			/**
			 getStringValue
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns a string that is equal to the value of this JSON Node
			 */
			string getStringValue();

			/**
			 getFloatValue
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns a float that is equal to the value of this JSON Node
			 */
			float getFloatValue();

			/**
			 getUIntValue
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns a uint that is equal to the value of this JSON Node
			 */
			uint getUIntValue();

			/**
			 operator[]
			 @Pre-Condition-  const string & rhs
			 @Post-Condition- Returns a JSONPrimitive &
			 */
			JSONPrimitive& operator[](const string& rhs);
	};
}

#endif
