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
#include <string>
#include "../../JSONParser.h"

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
			char*** _grid;
			//JSONParser _parser;
			ofstream _fileOutput;

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
			void addItem(int x, int y, int z, char item);

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

			//TODO: Implement and add docstyle comments
			string createJSON();

			//TODO: Implement and add docstyle comments
			string createWaterJSON();

			//TODO: Implement and add docstyle comments
			string createBarrierJSON();

			//TODO: Implement and add docstyle comments
			string createMineJSON();

			//TODO: Implement and add docstyle comments
			string createBuildingJSON();

			/**
			 colorSymbol
			 @Pre-Condition- Takes in a char symbol and a bool determining whether or not the single is selected
			 @Post-Condition- Changes the color of the symbol in accordance with the input
			 */
			string colorSymbol(char symbol, bool selected);

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
