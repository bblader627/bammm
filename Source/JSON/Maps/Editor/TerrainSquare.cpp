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
 * TerrainSquare header file
 *
 */

#include <iostream>
#include <string>
#include "TerrainSquare.h"
#include "../../../Resources/DynamicArray.h"
#include "../../../Resources/Color.h"
#include "../../../Resources/Constant.h"

namespace bammm
{
	TerrainSquare::TerrainSquare()
	{
		_currentSymbol = 0;
		_symbol = ".";
		addColor("green");
		_selected = false;
	}

	TerrainSquare::TerrainSquare(string symbol, string color)
	{
		_currentSymbol = 0;
		_symbol = symbol;
		addColor(color);
		_selected = false;
	}

	TerrainSquare::~TerrainSquare()
	{
	}

	void TerrainSquare::addColor(string color)
	{
		_colors.add(color);
	}

	void TerrainSquare::removeColor(string color)
	{
		_colors.removeElement(color);
	}

	void TerrainSquare::setSymbol(string symbol)
	{
		_symbol = symbol;
	}

	string TerrainSquare::getSymbol()
	{
		return _symbol;
	}

	void TerrainSquare::nextColor()
	{
		_currentSymbol++;

		if(_currentSymbol >= _colors.getSize())
		{
			_currentSymbol = 0;
		}
	}
			
	string TerrainSquare::getCurrentColor()
	{
		return _colors.get(_currentSymbol);
	}
			
	void TerrainSquare::selectSquare(bool selected)
	{
		_selected = selected;
	}

	DynamicArray<string>& TerrainSquare::getColors()
	{
		return _colors;
	}
			
	string TerrainSquare::toString()
	{
		string output;

		if(_selected)
		{
			output = Color::colorTextHighlight(_symbol, _colors.get(_currentSymbol));
		}
		else
		{
			output = Color::colorText(_symbol, _colors.get(_currentSymbol));
		}

		return output;
	}

	void TerrainSquare::operator=(TerrainSquare& terrainSquare)
	{
		_colors.clear();
		_symbol = terrainSquare._symbol;
		_currentSymbol = 0;
		_selected = true;

		for(uint i = 0; i < terrainSquare.getColors().getSize(); i++)
		{
			_colors.add(terrainSquare.getColors().get(i));
		}
	}
}
