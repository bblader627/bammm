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
 * MapEditor cpp file
 *
 */

#include "MapEditor.h" 

namespace bammm
{
	MapEditor::MapEditor()
	{
		_cursorZ = 0;
		_cursorX = 0;
		_cursorY = 0;

		_grass.setSymbol(".");
		_grass.addColor("green");

		_water.setSymbol("~");
		_water.removeColor("green");
		_water.addColor("blue");
		
		_tree.setSymbol("+");
		_tree.addColor("red");
		_tree.addColor("black");
		_tree.addColor("blue");
		
		_wall.setSymbol("#");
		_wall.removeColor("green");
		_wall.addColor("black");
		_wall.addColor("yellow");
		
		_bridge.setSymbol("=");
		_bridge.removeColor("green");
		_bridge.addColor("yellow");
		
		_mine.setSymbol("^");
		_mine.removeColor("green");
		_mine.addColor("white");
		_mine.addColor("yellow");
		_mine.addColor("black");
		
		_pub.setSymbol("P");
		_pub.removeColor("green");
		_pub.addColor("purple");
		
		_inn.setSymbol("I");
		_inn.removeColor("green");
		_inn.addColor("purple");
		
		_dock.setSymbol("-");
		_dock.removeColor("green");
		_dock.addColor("yellow");
	}

	MapEditor::~MapEditor()
	{
		for (int i = 0; i < _y; i++)
		{
			for (int j = 0; j < _x; j++)
			{
				delete[] _grid[i][j];
			}

			delete[] _grid[i];
		}

		delete[] _grid;
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
		_fileOutput.open(_name + ".json");
		_fileOutput << createJSON();
		_fileOutput.close();
		return true;
	}

	void MapEditor::createMap(int x, int y, int z)
	{
		_x = x;
		_y = y;
		_z = z;

		_grid = new TerrainSquare**[_y];
		for (int i = 0; i < _y; i++)
		{
			_grid[i] = new TerrainSquare*[_x];
			for (int j = 0; j < _x; j++)
			{
				_grid[i][j] = new TerrainSquare[_z];
				for (int k = 0; k < _z; k++)
				{
					_grid[i][j][k] = _grass;
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
		} while (convertedChoice != 1 && convertedChoice != 2);

		string filename;
		int x, y, z;
		switch (convertedChoice)
		{
			case 1:
				cout << "Enter the name of the file\n";
				getline(cin, filename);
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

		while (true)
		{
			displayCoordinates();
			displayMap();
			cout << "Enter a command. Enter h for help:" << "\n";
			cin >> choice;
			convertedChoice = choice.at(0);
			if (convertedChoice == 'v')
			{
				saveMap();
				break;
			}
			else if (convertedChoice == 'x')
			{
				break;
			}
			else if (convertedChoice == 'h')
			{
				displayHelp();
			}
			else if (convertedChoice == 'w')
			{
				moveUp();
			}
			else if (convertedChoice == 'a')
			{
				moveLeft();
			}
			else if (convertedChoice == 's')
			{
				moveDown();
			}
			else if (convertedChoice == 'd')
			{
				moveRight();
			}
			else if (convertedChoice == 'q')
			{
				moveZDown();
			}
			else if (convertedChoice == 'e')
			{
				moveZUp();
			}
			else if (convertedChoice == 'r')
			{
				removeItem(_cursorX, _cursorY, _cursorZ);
			}
			else if (convertedChoice == '1')
			{
				addItem(_cursorX, _cursorY, _cursorZ, _water);
			}
			else if (convertedChoice == '2')
			{
				addItem(_cursorX, _cursorY, _cursorZ, _wall);
			}
			else if (convertedChoice == '3')
			{
				addItem(_cursorX, _cursorY, _cursorZ, _mine);
			}
			else if (convertedChoice == '4')
			{
				addItem(_cursorX, _cursorY, _cursorZ, _bridge);
			}
			else if (convertedChoice == '5')
			{
				addItem(_cursorX, _cursorY, _cursorZ, _tree);
			}
			else if (convertedChoice == '6')
			{
				addItem(_cursorX, _cursorY, _cursorZ, _pub);
			}
			else if (convertedChoice == '7')
			{
				addItem(_cursorX, _cursorY, _cursorZ, _inn);
			}
			else if (convertedChoice == '8')
			{
				addItem(_cursorX, _cursorY, _cursorZ, _dock);
			}
		}

		cout << "Thank you for using the BAMMM editor.\n";
	}

	void MapEditor::removeItem(int x, int y, int z)
	{
		_grid[y][x][z] = _grass;
	}

	void MapEditor::addItem(int x, int y, int z, TerrainSquare& item)
	{
		if(_grid[y][x][z] == item)
		{
			_grid[y][x][z].nextColor();
		}
		else
		{
			_grid[y][x][z] = item;
		}
	}

	void MapEditor::displayMap()
	{
		for (int i = 0; i < _y; i++)
		{
			for (int j = 0; j < _x; j++)
			{
				if (i == _cursorY && j == _cursorX)
				{
					_grid[i][j][_cursorZ].selectSquare(true);
					cout << _grid[i][j][_cursorZ].toString();
				}
				else
				{
					_grid[i][j][_cursorZ].selectSquare(false);
					cout << _grid[i][j][_cursorZ].toString();
				}
				cout << " ";
			}
			cout << "\n";
		}
	}

	void MapEditor::displayCoordinates()
	{
		cout << "(" << _cursorX << ", " << _cursorY << ", " << _cursorZ
				<< ")\n";
	}

	void MapEditor::displayHelp()
	{
		cout << "v. Save" << "\n";
		cout << "x. Exit" << "\n";
		cout << "w. Move Up" << "\n";
		cout << "a. Move Left" << "\n";
		cout << "s. Move Down" << "\n";
		cout << "d. Move Right" << "\n";
		cout << "q. Z Up" << "\n";
		cout << "e. Z Down" << "\n";
		cout << "r. Remove" << "\n";
		cout << "1. Water" << "\n";
		cout << "2. Block" << "\n";
		cout << "3. Mine" << "\n";
		cout << "4. Bridge" << "\n";
		cout << "5. Tree" << "\n";
		cout << "6. Pub" << "\n";
		cout << "7. Inn" << "\n";
		cout << "8. Dock" << "\n";
		cout << "Placing the same object on the same space will cycle through the types." << "\n";
		cout << "Press enter to continue" << "\n";
		cin.ignore();
		cin.get();
	}

	void MapEditor::moveUp()
	{
		_cursorY -= 1;

		if (_cursorY < 0)
		{
			_cursorY = _y - 1;
		}
	}

	void MapEditor::moveDown()
	{
		_cursorY += 1;

		if (_cursorY >= _y)
		{
			_cursorY = 0;
		}
	}

	void MapEditor::moveLeft()
	{
		_cursorX -= 1;

		if (_cursorX < 0)
		{
			_cursorX = _x - 1;
		}
	}

	void MapEditor::moveRight()
	{
		_cursorX += 1;

		if (_cursorX >= _x)
		{
			_cursorX = 0;
		}
	}

	void MapEditor::moveZUp()
	{
		_cursorZ += 1;

		if (_cursorZ >= _z)
		{
			_cursorZ = 0;
		}
	}

	void MapEditor::moveZDown()
	{
		_cursorZ -= 1;

		if (_cursorZ < 0)
		{
			_cursorZ = _z - 1;
		}
	}

	string MapEditor::createJSONObject(int x, int y, int z, string name,
			string walkable)
	{
		string nameVal = "\"name\": \"" + name + "\",\n";
		string xVal = "\"x\": " + to_string(x) + ",\n";
		string yVal = "\"y\": " + to_string(y) + ",\n";
		string zVal = "\"z\": " + to_string(z) + ",\n";
		string walkVal = "\"walkable\": " + walkable + "\n";
		return "{\n" + nameVal + xVal + yVal + zVal + walkVal + "}";
	}

	string MapEditor::createDimensions(int x, int y, int z)
	{
		string sectionName = "dimensions";
		string sectionValue = "\t\"" + sectionName + "\": [\n";
		string xValue = "\t\t{ \"x\":" + to_string(x) + ", ";
		string yValue = "\"y\":" + to_string(y) + ", ";
		string zValue = "\"z\":" + to_string(z) + " }\n";
		string closeValue = "\t],\n";
		return sectionValue + xValue + yValue + zValue + closeValue;
	}

	string MapEditor::createJSONObjectNew(string name, int health, int stamina, int attack, int defense, string behavior, int x, int y, int z, int alliance, string color, string symbol, bool collision)
	{
		string collisionValue;
		string startValue = "\t\t{ ";
		string nameValue = "\"name\":\"" + name + "\", ";
		string healthValue = "\"health\":" + to_string(health) + ", ";
		string attackValue = "\"attack\":" + to_string(attack) + ", ";
		string staminaValue = "\"stamina\":" + to_string(stamina) + ", ";
		string defenseValue = "\"defense\":" + to_string(defense) + ", ";
		string behaviorValue = "\"behavior\":\"" + behavior + "\", ";
		string xValue = "\"x\":" + to_string(x) + ", ";
		string yValue = "\"y\":" + to_string(y) + ", ";
		string zValue = "\"z\":" + to_string(z) + ", ";
		string allianceValue = "\"alliance\":" + to_string(alliance) + ", ";
		string colorValue = "\"color\":\"" + color + "\", ";
		string symbolValue = "\"symbol\":\"" + symbol + "\", ";
		if(collision)
		{
			collisionValue = "\"collision\":true";
		}
		else
		{
			collisionValue = "\"collision\":false";
		}
		string endValue = " }";

		return startValue + nameValue + healthValue + staminaValue + attackValue + defenseValue + behaviorValue + xValue + yValue + zValue + allianceValue + colorValue + symbolValue + collisionValue + endValue;
	}

	string MapEditor::createJSON()
	{
		string jsonString = "{\n";
		jsonString += createDimensions(_x, _y, _z);
		jsonString += createWallJSON();
		jsonString += createWaterJSON();
		jsonString += createMineJSON();
		jsonString += createTreeJSON();
		jsonString += createBuildingJSON();
		jsonString += "\n}";
		return jsonString;
	}

	string MapEditor::createWallJSON()
	{
		string sectionName = "wall";
		string symbol = "#";
		string sectionValue = "\t\"" + sectionName + "\": [\n";
		string content = "";
		string name = "Wall";
		int health = 100;
		int stamina = 0;
		int attack = 0;
		int defense = 20;
		string behavior = "block";
		int alliance = 0;
		bool collision = true;
		bool firstItem = true;
		int id = 1;

		for (int x = 0; x < _x; x++)
		{
			for (int y = 0; y < _y; y++)
			{
				for (int z = 0; z < _z; z++)
				{
					TerrainSquare& current = _grid[y][x][z];
					if (current.getSymbol() == symbol)
					{
						if (!firstItem)
						{
							content += ",\n";
						}
						firstItem = false;

						if(current.getCurrentColor() == "yellow")
						{
							collision = false;
						}
						else
						{
							collision = true;
						}

						content += createJSONObjectNew(name + to_string(id), health, stamina, attack, defense, behavior, x, y, z, alliance, current.getCurrentColor(), current.getSymbol(), collision);
						
						id++;
					}
				}
			}
		}
		
		string closeValue = "\t],\n";
		return sectionValue + content + closeValue;
	}
	
	string MapEditor::createWaterJSON()
	{
		string sectionName = "water";
		string symbol = "~";
		string symbol2 = "=";
		string sectionValue = "\t\"" + sectionName + "\": [\n";
		string content = "";
		string name = "Water";
		int health = 100;
		int stamina = 0;
		int attack = 0;
		int defense = 20;
		string behavior = "block";
		int alliance = 0;
		bool collision = true;
		bool firstItem = true;
		int id = 1;

		for (int x = 0; x < _x; x++)
		{
			for (int y = 0; y < _y; y++)
			{
				for (int z = 0; z < _z; z++)
				{
					TerrainSquare& current = _grid[y][x][z];
					if (current.getSymbol() == symbol || current.getSymbol() == symbol2)
					{
						if(current.getSymbol() == symbol)
						{
							name = "Water";
							collision = true;
						}
						else
						{
							name = "Bridge";
							collision = false;
						}

						if (!firstItem)
						{
							content += ",\n";
						}
						firstItem = false;


						content += createJSONObjectNew(name + to_string(id), health, stamina, attack, defense, behavior, x, y, z, alliance, current.getCurrentColor(), current.getSymbol(), collision);
						
						id++;
					}
				}
			}
		}
		
		string closeValue = "\t],\n";
		return sectionValue + content + closeValue;
	}
	
	string MapEditor::createBuildingJSON()
	{
		string sectionName = "buildings";
		string symbol = "P";
		string symbol2 = "I";
		string sectionValue = "\t\"" + sectionName + "\": [\n";
		string content = "";
		string name = "Pub";
		int health = 100;
		int stamina = 0;
		int attack = 0;
		int defense = 20;
		string behavior = "block";
		int alliance = 0;
		bool collision = false;
		bool firstItem = true;
		int id = 1;

		for (int x = 0; x < _x; x++)
		{
			for (int y = 0; y < _y; y++)
			{
				for (int z = 0; z < _z; z++)
				{
					TerrainSquare& current = _grid[y][x][z];
					if (current.getSymbol() == symbol || current.getSymbol() == symbol2)
					{
						if(current.getSymbol() == symbol)
						{
							name = "Pub";
						}
						else
						{
							name = "Inn";
						}

						if (!firstItem)
						{
							content += ",\n";
						}
						firstItem = false;


						content += createJSONObjectNew(name + to_string(id), health, stamina, attack, defense, behavior, x, y, z, alliance, current.getCurrentColor(), current.getSymbol(), collision);
						
						id++;
					}
				}
			}
		}
		
		string closeValue = "\t],\n";
		return sectionValue + content + closeValue;
	}
	
	string MapEditor::createMineJSON()
	{
		string sectionName = "ore";
		string symbol = "^";
		string sectionValue = "\t\"" + sectionName + "\": [\n";
		string content = "";
		string name = "iron";
		int health = 20;
		int stamina = 0;
		int attack = 0;
		int defense = 2;
		string behavior = "block";
		int alliance = 0;
		bool collision = false;
		bool firstItem = true;
		int id = 1;

		for (int x = 0; x < _x; x++)
		{
			for (int y = 0; y < _y; y++)
			{
				for (int z = 0; z < _z; z++)
				{
					TerrainSquare& current = _grid[y][x][z];
					if (current.getSymbol() == symbol)
					{
						if (!firstItem)
						{
							content += ",\n";
						}
						firstItem = false;

						if(current.getCurrentColor() == "yellow")
						{
							name = "gold";
						}
						else if(current.getCurrentColor() == "white")
						{
							name = "iron";
						}
						else if(current.getCurrentColor() == "black")
						{
							name = "coal";
						}

						content += createJSONObjectNew(name + to_string(id), health, stamina, attack, defense, behavior, x, y, z, alliance, current.getCurrentColor(), current.getSymbol(), collision);
						
						id++;
					}
				}
			}
		}
		
		string closeValue = "\t],\n";
		return sectionValue + content + closeValue;
	}
	
	string MapEditor::createTreeJSON()
	{
		string sectionName = "trees";
		string symbol = "+";
		string sectionValue = "\t\"" + sectionName + "\": [\n";
		string content = "";
		string name = "birch";
		int health = 20;
		int stamina = 0;
		int attack = 0;
		int defense = 5;
		string behavior = "block";
		int alliance = 0;
		bool collision = false;
		bool firstItem = true;
		int id = 1;

		for (int x = 0; x < _x; x++)
		{
			for (int y = 0; y < _y; y++)
			{
				for (int z = 0; z < _z; z++)
				{
					TerrainSquare& current = _grid[y][x][z];
					if (current.getSymbol() == symbol)
					{
						if (!firstItem)
						{
							content += ",\n";
						}
						firstItem = false;

						if(current.getCurrentColor() == "red")
						{
							name = "redwood";
						}
						else if(current.getCurrentColor() == "black")
						{
							name = "birch";
						}
						else if(current.getCurrentColor() == "green")
						{
							name = "oak";
						}
						else if(current.getCurrentColor() == "blue")
						{
							name = "cedar";
						}

						content += createJSONObjectNew(name + to_string(id), health, stamina, attack, defense, behavior, x, y, z, alliance, current.getCurrentColor(), current.getSymbol(), collision);
						
						id++;
					}
				}
			}
		}
		
		string closeValue = "\t],\n";
		return sectionValue + content + closeValue;
	}
}
