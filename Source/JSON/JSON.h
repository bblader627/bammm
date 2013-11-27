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
 * JSON header file.
 *
 */

#ifndef JSON_H_
#define JSON_H_

#include <string>
#include "../Resources/HashMap.h"

namespace bammm
{
	enum JSON_TYPE
	{
		JSON_NULL,
		JSON_ARRAY,
		JSON_STRING,
		JSON_INT,
		JSON_DOUBLE,
		JSON_BOOL,
		JSON_OBJECT
	};

	class JSON
	{
		protected:
			string _name;
			JSON_TYPE _type;
			JSON *_parent;
			HashMap<JSON*> _children;

		public:
			JSON();
			JSON(string newName);
			virtual ~JSON();

			/**
			 getName
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns the name (key) of this JSON Node
			 */
			string getName();

			/**
			 getType
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns the JSON_TYPE of this JSON Node
			 */
			JSON_TYPE getType();

			/**
			 getParent
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns the parent of this JSON Node
			 */
			JSON * getParent();

			/**
			 sizeOfChildren
			 @Pre-Condition- Takes no argument
			 @Post-Condition- return size of _children
			 */
			int sizeOfChildren();

			/**
			 setName
			 @Pre-Condition-  Takes a string argument
			 @Post-Condition- sets this JSON Nodes name equal to the string argument. Returns void.
			 */
			void setName(string newName);

			/**
			 setType
			 @Pre-Condition-  Takes a JSON_TYPE argument
			 @Post-Condition- sets this JSON Nodes JSON_TYPE equal to the JSON_TYPE argument. Returns void.
			 */
			void setType(JSON_TYPE newType);

			/**
			 setParent
			 @Pre-Condition-  Takes a JSON argument
			 @Post-Condition- Sets this JSON node's parent to the given argument
			 */
			void setParent(JSON & newParent);

			/**
			 addChild
			 @Pre-Condition-  Takes a JSON argument
			 @Post-Condition- Adds the given argument as a child of this node
			 */
			void addChild(JSON & newNode);

			/**
			 getIntValue
			 @Pre-Condition-  No input
			 @Post-Condition- Returns an int value
			 */
			virtual int getIntValue();

			/**
			 getDoubleValue
			 @Pre-Condition-  No input
			 @Post-Condition- Returns a double value
			 */
			virtual double getDoubleValue();

			/**
			 getBoolValue
			 @Pre-Condition-  No input
			 @Post-Condition- Returns a bool value
			 */
			virtual bool getBoolValue();

			/**
			 getStringValue
			 @Pre-Condition-  No input
			 @Post-Condition- Returns a string value
			 */
			virtual string getStringValue();

			//TODO: Can this be removed?
			/*
			 JSON * operator[](int index)
			 {
			 DynamicArray<JSON*>* childrenArray = _children.getAllValues();
			 return childrenArray->get(index);
			 //return _children.getValue(key);
			 }
			 */

			/**
			 operator[]
			 @Pre-Condition-  const unsigned int & rhs
			 @Post-Condition- Returns a JSON
			 */
			JSON operator[](const unsigned int & rhs);

			//TODO: Can this implementation be moved to JSON.cpp?
			/**
			 operator[]
			 @Pre-Condition-  const string key
			 @Post-Condition- Returns a JSON
			 */
			JSON* operator[](const string key)
			{
				return _children.getValue(key);
			}
	};
}

#endif
