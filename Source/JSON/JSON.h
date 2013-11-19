/*
 * JSON.h
 *
 *  Created on: Nov 19, 2013
 *      Author: michael
 */

#ifndef JSON_H_
#define JSON_H_

#include "JSONParser.h"

namespace bammm
{
	enum JSON_TYPE
	{
		JSON_NULL, JSON_ARRAY, JSON_STRING, JSON_INT, JSON_DOUBLE, JSON_BOOL
	};

	class JSON
	{

		protected:

			string _name;
			JSON_TYPE _type;
			JSON *_parent;
			HashMap<JSON> _children;

		public:
			JSON();
			~JSON();

			/**
			 getParent
			 @Pre-Condition- No input
			 @Post-Condition- Returns the parent
			 */
			JSON getParent();

			/**
			 getChild
			 @Pre-Condition- Takes in the name of a child
			 @Post-Condition- Returns the child with that name
			 */
			JSON getChild(string name);

			/**
			 getChildren
			 @Pre-Condition- No input
			 @Post-Condition- Returns a HashMap containing all the children
			 */
			HashMap<JSON>* getChildren();

			//TODO: This isn't implemented
			string getValue();

			/**
			 getName
			 @Pre-Condition- No input
			 @Post-Condition- Returns the name as a string
			 */
			string getName();

			/**
			 getType
			 @Pre-Condition- No input
			 @Post-Condition- Returns the JSON_TYPE
			 */
			JSON_TYPE getType();

			/**
			 setParent
			 @Pre-Condition- Takes a new parent
			 @Post-Condition- Returns true if parent set correctly
			 */
			bool setParent(JSON newParent);

			/**
			 setValue
			 @Pre-Condition- Takes a string as the value
			 @Post-Condition- Returns true if the value set correctly
			 */
			bool setValue(string newValue);

			/**
			 setValue
			 @Pre-Condition- Takes a bool as the value
			 @Post-Condition- Returns true if the value set correctly
			 */
			bool setValue(bool newValue);

			/**
			 setValue
			 @Pre-Condition- Takes an int as the value
			 @Post-Condition- Returns true if the value set correctly
			 */
			bool setValue(int newValue);

			/**
			 setValue
			 @Pre-Condition- Takes a double as the value
			 @Post-Condition- Returns true if the value set correctly
			 */
			bool setValue(double newValue);

			/**
			 setName
			 @Pre-Condition- Takes a string name
			 @Post-Condition- Returns true if the name set correctly
			 */
			bool setName(string newName);

			/**
			 setType
			 @Pre-Condition- Takes in a new type JSON_TYPE
			 @Post-Condition- Returns true the type was set correctly
			 */
			bool setType(JSON_TYPE newType);

			/**
			 addChild
			 @Pre-Condition- Takes in a new type JSON_TYPE
			 @Post-Condition- Returns true the type was set correctly
			 */
			void addChild(JSON & newNode);

			//TODO: I don't think this is even implemented?
			void addChild(JSON, JSON);

			JSON & operator=(const JSON & rightHandSide);
			virtual string operator[](const string & index);
	};

}

#endif /* JSON_H_ */
