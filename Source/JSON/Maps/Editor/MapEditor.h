#ifndef MAPEDITOR_H_
#define MAPEDITOR_H_

#include "../../JSONParser.h"
#include <iostream> 
namespace bammm
{
	class MapEditor
	{
		private:
			JSONParser parser;
		public:
			MapEditor();
			~MapEditor();
			bool loadMap(string filename);
			bool saveMap(string filename);
			void createMap(int x, int y, int z);
			void startEditor();
			void removeItem(int x, int y, int z);
			void addItem(string item);
	};
}

#endif
