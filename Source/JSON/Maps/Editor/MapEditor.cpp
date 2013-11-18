#include "MapEditor.h" 

namespace bammm
{
	MapEditor::MapEditor()
	{
		_cursorZ = 0;
		_cursorX = 0;
		_cursorY = 0;
	}

	MapEditor::~MapEditor()
	{
	}

	bool MapEditor::loadMap(string filename)
	{
		cout << "Under construction. Needs JsonParser\n";
		//cout << filename << "\n";
		//_parser.parseFile(filename);
		return true;
	}

	bool MapEditor::saveMap()
	{
		cout << "Save as: \n";
		cin >> _name;
		fileOutput.open(_name + ".json");
		fileOutput << createJson();
		fileOutput.close();
		return true;
	}

	void MapEditor::createMap(int x, int y, int z)
	{
		_x = x;
		_y = y;
		_z = z;

		_grid = new char**[_y];
		for(int i = 0; i < _y; i++)
		{
			_grid[i] = new char*[_x];
			for(int j = 0; j < _x; j++)
			{
				_grid[i][j] = new char[_z];
				for(int k = 0; k < _z; k++)
				{
					_grid[i][j][k] = '.';
				}
			}
		}
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

		while(true)
		{
			displayCoordinates();
			displayMap();
			cout << "Enter a command. Enter h for help:" << "\n";
			cin >> choice;
			convertedChoice = choice.at(0);
			if(convertedChoice == 'v')
			{
				saveMap();
				break;
			}
			else if(convertedChoice == 'h')
			{
				displayHelp();
			}
			else if(convertedChoice == 'w')
			{
				moveUp();
			}
			else if(convertedChoice == 'a')
			{
				moveLeft();
			}
			else if(convertedChoice == 's')
			{
				moveDown();
			}
			else if(convertedChoice == 'd')
			{
				moveRight();
			}
			else if(convertedChoice == 'q')
			{
				moveZDown();
			}
			else if(convertedChoice == 'e')
			{
				moveZUp();
			}
			else if(convertedChoice == 'r')
			{
				removeItem(_cursorX, _cursorY, _cursorZ);
			}
			else if(convertedChoice == '1')
			{
				addItem(_cursorX, _cursorY, _cursorZ, 'W');
			}
			else if(convertedChoice == '2')
			{
				addItem(_cursorX, _cursorY, _cursorZ, 'B');
			}
			else if(convertedChoice == '3')
			{
				addItem(_cursorX, _cursorY, _cursorZ, 'F');
			}
			else if(convertedChoice == '4')
			{
				addItem(_cursorX, _cursorY, _cursorZ, 'A');
			}
			else if(convertedChoice == '5')
			{
				addItem(_cursorX, _cursorY, _cursorZ, 'G');
			}
			else if(convertedChoice == '6')
			{
				addItem(_cursorX, _cursorY, _cursorZ, 'M');
			}
			else if(convertedChoice == '7')
			{
				addItem(_cursorX, _cursorY, _cursorZ, 'S');
			}
		}
	}

	void MapEditor::removeItem(int x, int y, int z)
	{
		_grid[y][x][z] = '.';
	}
	
	void MapEditor::addItem(int x, int y, int z, char item)
	{
		_grid[y][x][z] = item;
	}

	void MapEditor::displayMap()
	{
		for(int i = 0; i < _y; i++)
		{
			for(int j = 0; j < _x; j++)
			{
				if(i == _cursorY && j == _cursorX)
				{
					cout << "\033[44m" << _grid[i][j][_cursorZ];
				}
				else
				{
					cout << _grid[i][j][_cursorZ];
				}
				cout << "\033[49m" << " ";
			}
			cout << "\n";
		}
	}

	void MapEditor::displayCoordinates()
	{
		cout << "(" << _cursorX << ", " << _cursorY << ", " << _cursorZ << ")\n";
	}

	void MapEditor::displayHelp()
	{
		cout << "v. Save" << "\n";
		cout << "w. Move Up" << "\n";
		cout << "a. Move Left" << "\n";
		cout << "s. Move Down" << "\n";
		cout << "d. Move Right" << "\n";
		cout << "q. Z Up" << "\n";
		cout << "e. Z Down" << "\n";
		cout << "r. Remove" << "\n";
		cout << "1. Water" << "\n";
		cout << "2. Block" << "\n";
		cout << "3. Fire pit" << "\n";
		cout << "4. Armory" << "\n";
		cout << "5. Gym" << "\n";
		cout << "6. Mine" << "\n";
		cout << "7. Blacksmith" << "\n";
		cout << "Press enter to continue" << "\n";
		cin.ignore();
		cin.get();
	}

	void MapEditor::moveUp()
	{
		_cursorY -= 1;

		if(_cursorY < 0)
		{
			_cursorY = _y - 1;
		}
	}

	void MapEditor::moveDown()
	{
		_cursorY += 1;

		if(_cursorY >= _y)
		{
			_cursorY = 0;
		}
	}

	void MapEditor::moveLeft()
	{
		_cursorX -= 1;

		if(_cursorX < 0)
		{
			_cursorX = _x - 1;
		}
	}

	void MapEditor::moveRight()
	{
		_cursorX += 1;

		if(_cursorX >= _x)
		{
			_cursorX = 0;
		}
	}

	void MapEditor::moveZUp()
	{
		_cursorZ += 1;

		if(_cursorZ >= _z)
		{
			_cursorZ = 0;
		}
	}

	void MapEditor::moveZDown()
	{
		_cursorZ -= 1;

		if(_cursorZ < 0)
		{
			_cursorZ = _z - 1;
		}
	}

	string MapEditor::createJsonObject(int x, int y, int z, string name, string walkable)
	{
		string nameVal = "\"name\": \"" + name + "\",\n";
		string xVal = "\"x\": " + to_string(x) + ",\n";
		string yVal = "\"y\": " + to_string(y) + ",\n";
		string zVal = "\"z\": " + to_string(z) + ",\n";
		string walkVal = "\"walkable\": " + walkable + "\n";
		return "{\n" + nameVal + xVal + yVal + zVal + walkVal + "}";
	}

	string MapEditor::createJson()
	{
		string jsonString = "{\n";
		jsonString = jsonString + "\"" + _name + "\":\n";
		jsonString = jsonString + "[\n";
		jsonString = jsonString + "\"x\": " + to_string(_x) + ",\n";
		jsonString = jsonString + "\"y\": " + to_string(_y) + ",\n";
		jsonString = jsonString + "\"z\": " + to_string(_z) + ",\n";
		jsonString = jsonString + createWaterJson() + ",\n";
		jsonString = jsonString + createBarrierJson() + ",\n";
		jsonString = jsonString + createMineJson() + ",\n";
		jsonString = jsonString + createBuildingJson() + "\n";
		jsonString = jsonString + "]\n";
		jsonString = jsonString + "}";
		return jsonString;
	}

	string MapEditor::createWaterJson()
	{
		char item = 'W';
		bool firstItem = true;
		string name = "Water Objects";
		string jsonString = "\"" + name + "\":\n";
		jsonString = jsonString + "[\n";
		for(int x = 0; x < _x; x++)
		{
			for(int y = 0; y < _y; y++)
			{
				for(int z = 0; z < _z; z++)
				{
					if(_grid[y][x][z] == item)
					{
						if(!firstItem)
						{
							jsonString = jsonString + ",\n";
						}
						jsonString = jsonString + createJsonObject(x, y, z, "Deep Water", "false") + "\n";
					}
				}
			}
		}
		jsonString = jsonString + "]";
		return jsonString;
	}

	string MapEditor::createBarrierJson()
	{
		char item = 'B';
		bool firstItem = true;
		string name = "Barrier Objects";
		string jsonString = "\"" + name + "\":\n";
		jsonString = jsonString + "[\n";
		for(int x = 0; x < _x; x++)
		{
			for(int y = 0; y < _y; y++)
			{
				for(int z = 0; z < _z; z++)
				{
					if(_grid[y][x][z] == item)
					{
						if(!firstItem)
						{
							jsonString = jsonString + ",\n";
						}
						firstItem = false;
						jsonString = jsonString + createJsonObject(x, y, z, "Fortress Wall", "false") + "";
					}
				}
			}
		}
		jsonString = jsonString + "]";
		return jsonString;
	}

	string MapEditor::createMineJson()
	{
		char item = 'M';
		bool firstItem = true;
		string name = "Mine Objects";
		string jsonString = "\"" + name + "\":\n";
		jsonString = jsonString + "[\n";
		for(int x = 0; x < _x; x++)
		{
			for(int y = 0; y < _y; y++)
			{
				for(int z = 0; z < _z; z++)
				{
					if(_grid[y][x][z] == item)
					{
						if(!firstItem)
						{
							jsonString = jsonString + ",\n";
						}
						firstItem = false;
						jsonString = jsonString + createJsonObject(x, y, z, "Iron ore", "false") + "";
					}
				}
			}
		}
		jsonString = jsonString + "]";
		return jsonString;
	}

	string MapEditor::createBuildingJson()
	{
		char gym = 'G';
		char fire = 'F';
		char smith = 'S';
		char armory = 'A';
		bool matched = false;
		string buildingName = "";
		bool firstItem = true;
		string name = "Building Objects";
		string jsonString = "\"" + name + "\":\n";
		jsonString = jsonString + "[\n";
		for(int x = 0; x < _x; x++)
		{
			for(int y = 0; y < _y; y++)
			{
				for(int z = 0; z < _z; z++)
				{
					if(_grid[y][x][z] == gym)
					{
						buildingName = "Gym";
						matched = true;
					}
					if(_grid[y][x][z] == fire)
					{
						buildingName = "Fire pit";
						matched = true;
					}
					if(_grid[y][x][z] == smith)
					{
						buildingName = "Blacksmith";
						matched = true;
					}
					if(_grid[y][x][z] == armory)
					{
						buildingName = "Armory";
						matched = true;
					}

					if(matched)
					{
						matched = false;
						if(!firstItem)
						{
							jsonString = jsonString + ",\n";
						}
						firstItem = false;
						jsonString = jsonString + createJsonObject(x, y, z, buildingName, "false") + "";
					}
				}
			}
		}
		jsonString = jsonString + "]";
		return jsonString;
	}
}
