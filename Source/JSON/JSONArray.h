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
 * JSONArray header file.
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
			JSONArray(string name);
			JSONArray(string name, JSON *parent);
			~JSONArray();

			/**
			 addChild
			 @Pre-Condition-  Takes a JSON
			 @Post-Condition- Adds this argument to the array
			 */
			void addChild(JSON & newNode);

			/**
			 operator[]
			 @Pre-Condition-  const unsigned int & rhs
			 @Post-Condition- Returns a JSON
			 */
			JSON operator[](const unsigned int & rhs);

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
	};
}

#endif
