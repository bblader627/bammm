#include "MapEditor.h" 

namespace bammm
{
	MapEditor::MapEditor()
	{
	}

	MapEditor::~MapEditor()
	{
	}

	bool MapEditor::loadMap(string filename)
	{
		cout << filename << "\n";
		cout << parser.parseFile(filename) << endl;
		return true;
	}

	bool MapEditor::saveMap(string filename)
	{
		return true;
	}

	void MapEditor::createMap(int x, int y, int z)
	{
		cout << x << "," << y << "," << z << "\n";
	}

	void MapEditor::startEditor()
	{
		cout << "Welcome to BAMMM's Map Editor\n";
		cout << "Please enter a command.\n";
		cout << "1. Load existing map.\n";
		cout << "2. Create new map.\n";

		string choice;
		int convertedChoice;
		do
		{
			getline(cin, choice);
			convertedChoice = atoi(choice.c_str());
		}while(convertedChoice != 1 && convertedChoice != 2);

		string filename;
		int x, y, z;
		switch(convertedChoice)
		{
			case 1:
				cout << "Enter the name of the file\n";
				getline(cin,filename);
				loadMap(filename);
				break;
			case 2:
				cout << "Enter x dimension of map\n";
				cin >> x;
				cout << "Enter y dimension of map\n";
				cin >> y;
				cout << "Enter z dimension of map\n";
				cin >> z;
				createMap(x, y, z);
				break;
		} 
	}

	void MapEditor::removeItem(int x, int y, int z)
	{
	}
	
	void MapEditor::addItem(string item)
	{
	}
}
