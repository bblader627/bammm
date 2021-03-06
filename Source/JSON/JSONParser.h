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
#include <stdlib.h>
#include "../Resources/HashMap.h"
#include "JSON.h"
#include "JSONPrimitive.h"
#include "../Resources/Constant.h"
#include "JSONParser.h"
#include "../Resources/DynamicArray.h"
#include "JSONArray.h"

using namespace std;

namespace bammm
{
	class JSONParser
	{
		private:
			HashMap<JSON*> _rootMap;

			/**
			 addRoot
			 @Pre-Condition- Takes in a JSON node
			 @Post-Condition- Adds the node as a root node
			 */
			void addRoot(JSON& newNode);

			/**
			 addChild
			 @Pre-Condition- Takes in a JSON  rootNode and a JSON childNode
			 @Post-Condition- Adds the child to the specified rootNode
			 */
			void addChild(JSON& rootNode, JSON& newNode);

		public:
			JSONParser();

			/**
			 parseFile
			 @Pre-Condition- Takes in a filename
			 @Post-Condition- Parses the file and returns true if successful
			 */
			bool parseFile(string filename);

			/**
			 getMap
			 @Pre-Condition- No input
			 @Post-Condition- Returns the entire map as a HashMap
			 */
			HashMap<JSON*>* getMap();

			/**
			 getRootNode
			 @Pre-Condition- Takes in the key of the desired JSON node
			 @Post-Condition- Returns the JSON node with name "key"
			 */
			JSON* getRootNode(string key);

			/**
			 printAllRoots
			 @Pre-Condition- No input
			 @Post-Condition- Prints all the roots
			 */
			void printAllRoots();

			/**
			 operator[]
			 @Pre-Condition- Takes in const string key
			 @Post-Condition- Returns JSON *
			 */
			JSON* operator[](const string key)
			{
				return _rootMap.getValue(key);
			}
	};
}

#endif
