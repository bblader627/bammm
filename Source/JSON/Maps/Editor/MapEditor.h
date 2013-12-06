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
 * MapEditor header file
 *
 */

#ifndef MAPEDITOR_H_
#define MAPEDITOR_H_

#include <iostream>
#include <fstream>
#include "../../JSONParser.h"
#include "TerrainSquare.h"

namespace bammm
{
	class MapEditor
	{
		private:
			int _x;
			int _y;
			int _z;
			int _cursorX;
			int _cursorY;
			int _cursorZ;
			string _name;
			TerrainSquare*** _grid;
			//JSONParser _parser;
			ofstream _fileOutput;

			TerrainSquare _grass;
			TerrainSquare _water;
			TerrainSquare _tree;
			TerrainSquare _wall;
			TerrainSquare _bridge;
			TerrainSquare _mine;
			TerrainSquare _pub;
			TerrainSquare _inn;
			TerrainSquare _dock;

			/**
			 loadMap
			 @Pre-Condition- Takes in a string filename
			 @Post-Condition- Loads the map specified by the file
			 */
			bool loadMap(string filename);

			/**
			 saveMap
			 @Pre-Condition- No input
			 @Post-Condition- Returns true is the map was saved correctly, false otherwise
			 */
			bool saveMap();

			/**
			 createMap
			 @Pre-Condition- Takes in three ints: x, y, and z
			 @Post-Condition- Creates a map using the three given ints
			 */
			void createMap(int x, int y, int z);

			/**
			 removeItem
			 @Pre-Condition- Takes in three ints: x, y, and z
			 @Post-Condition- Removes the item at the given coordinates
			 */
			void removeItem(int x, int y, int z);

			/**
			 addItem
			 @Pre-Condition- Takes in three ints: x, y, and z and a char item.
			 @Post-Condition- Adds the item at the given coordinates
			 */
			void addItem(int x, int y, int z, TerrainSquare& item);

			/**
			 displayMap
			 @Pre-Condition- No input
			 @Post-Condition- The map is displayed
			 */
			void displayMap();

			/**
			 displayHelp
			 @Pre-Condition- No input
			 @Post-Condition- Help is displayed
			 */
			void displayHelp();

			/**
			 moveUp
			 @Pre-Condition- No input
			 @Post-Condition- The cursor is moved up
			 */
			void moveUp();

			/**
			 moveDown
			 @Pre-Condition- No input
			 @Post-Condition- The cursor is moved down
			 */
			void moveDown();

			/**
			 moveLeft
			 @Pre-Condition- No input
			 @Post-Condition- The cursor is moved left
			 */
			void moveLeft();

			/**
			 moveRight
			 @Pre-Condition- No input
			 @Post-Condition- The cursor is moved right
			 */
			void moveRight();

			/**
			 moveZUp
			 @Pre-Condition- No input
			 @Post-Condition- The cursor is moved up in the Z direction
			 */
			void moveZUp();

			/**
			 moveZDown
			 @Pre-Condition- No input
			 @Post-Condition- The cursor is moved down in the Z direction
			 */
			void moveZDown();

			/**
			 displayCoordinates
			 @Pre-Condition- No input
			 @Post-Condition- Displays the coordinates
			 */
			void displayCoordinates();

			/**
			 createJSONObject
			 @Pre-Condition- Takes in ints x, y, and z, a string name, and a string walkable
			 @Post-Condition- Returns a JSON object
			 */
			string createJSONObject(int x, int y, int z, string name,
					string walkable);

			/**
			 createJSONObjectNew
			 @Pre-Condition- Takes in many parameters
			 @Post-Condition- Returns a JSON object
			 */
			string createJSONObjectNew(string name, int health, int stamina, int attack, int defense, string behavior, int x, int y, int z, int alliance, string color, string symbol, bool collision);

			/**
			 createJSON
			 @Pre-Condition- No input
			 @Post-Condition- Creates and returns our JSON
			 */
			string createJSON();
			
			/**
			 createDimensions
			 @Pre-Condition- An integer for x,y,z
			 @Post-Condition- Creates dimensions block for JSON
			 */
			string createDimensions(int x, int y, int z);

			/**
			 createWaterJSON
			 @Pre-Condition- No input
			 @Post-Condition- Returns a JSON object for water
			 */
			string createWaterJSON();

			/**
			 createWallJSON
			 @Pre-Condition- No input
			 @Post-Condition- Returns a JSON object for walls
			 */
			string createWallJSON();
			
			/**
			 createTreeJSON
			 @Pre-Condition- No input
			 @Post-Condition- Returns a JSON object for trees
			 */
			string createTreeJSON();

			/**
			 createMineJSON
			 @Pre-Condition- No input
			 @Post-Condition- Returns a JSON object for mine
			 */
			string createMineJSON();

			/**
			 createBuildingJSON
			 @Pre-Condition- No input
			 @Post-Condition- Returns a JSON object for building
			 */
			string createBuildingJSON();

		public:
			MapEditor();
			~MapEditor();

			/**
			 StartEditor
			 @Pre-Condition- No input
			 @Post-Condition- The editor is started
			 */
			void startEditor();
	};
}

#endif
