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
 * JSONParser header file.
 *
 */

#ifndef JSONPARSER_H_
#define JSONPARSER_H_

#include <iostream>
#include <fstream>
#include <string>
#include "../Resources/DynamicArray.h"
#include "../Resources/HashMap.h"

#ifndef NULL
#define NULL (void *) 0
#endif

using namespace std;

namespace bammm
{
	enum JSON_TYPE
	{
		JSON_NULL, JSON_ARRAY, JSON_STRING, JSON_INT, JSON_DOUBLE, JSON_BOOL
	};

	class JSON
	{

		private:
			string _name;
			string _value;
			JSON_TYPE _type;
			JSON *_parent;
			HashMap<JSON> _children;

		public:
			JSON();
			JSON(string name, string value, JSON_TYPE type, const JSON& parent);
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
			string operator[](const string & index);
	};

	class JSONParser
	{
		private:
			HashMap<JSON> _rootMap;

			/**
			 addRoot
			 @Pre-Condition- Takes in a JSON node
			 @Post-Condition- Adds the node as a root node
			 */
			void addRoot(JSON & newNode);

			/**
			 addChild
			 @Pre-Condition- Takes in a JSON  rootNode and a JSON childNode
			 @Post-Condition- Adds the child to the specified rootNode
			 */
			void addChild(JSON & rootNode, JSON & newNode);

		public:
			/**
			 parseFile
			 @Pre-Condition- Takes in a fileName
			 @Post-Condition- Parses the file and returns true if successful
			 */
			bool parseFile(string fileName);

			/**
			 getMap
			 @Pre-Condition- No input
			 @Post-Condition- Returns the entire map as a HashMap
			 */
			HashMap<JSON>* getMap();

			/*
			 getRootNode
			 @Pre-Condition- Takes in the key of the desired JSON node
			 @Post-Condition- Returns the JSON node with name "key"
			 */

			JSON getRootNode(string key);
	};
}

#endif
