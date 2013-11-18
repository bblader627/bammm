#ifndef MAPEDITOR_H_
#define MAPEDITOR_H_

#include "../../JSONParser.h"
#include <iostream>
#include <string>
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
			char _grid[10][10][10];
			JSONParser _parser;
		public:
			MapEditor();
			~MapEditor();
			bool loadMap(string filename);
			bool saveMap();
			void createMap(int x, int y, int z);
			void startEditor();
			void removeItem(int x, int y, int z);
			void addItem(int x, int y, int z, char item);
			void displayMap();
			void displayHelp();
			void moveUp();
			void moveDown();
			void moveLeft();
			void moveRight();
			void moveZUp();
			void moveZDown();
			void displayCoordinates();
			string createJsonObject(int x, int y, int z, string name, string walkable);
			string createJson();
			string createWaterJson();
			string createBarrierJson();
			string createMineJson();
			string createBuildingJson();
	};
}

#endif
