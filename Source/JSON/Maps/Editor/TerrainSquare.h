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

#ifndef TERRAINSQUARE_H_
#define TERRAINSQUARE_H_

#include <iostream>
#include <string>
#include "../../../Resources/DynamicArray.h"
#include "../../../Resources/Color.h"
#include "../../../Resources/Constant.h"

namespace bammm
{
	class TerrainSquare
	{
		private:
			DynamicArray<string> _colors;
			string _symbol;
			uint _currentSymbol;
			bool _selected;
			
		public:
			TerrainSquare();
			TerrainSquare(string symbol, string color);
			~TerrainSquare();

			/**
			 addColor
			 @Pre-Condition- The new color to add
			 @Post-Condition- The editor is started
			 */
			void addColor(string color);

			/**
			 addColor
			 @Pre-Condition- A string for the color to add
			 @Post-Condition- Removes the color from _colors
			 */
			void removeColor(string color);
			
			/**
			 setSymbol
			 @Pre-Condition- The new symbol to use
			 @Post-Condition- Sets the _symbol
			 */
			void setSymbol(string symbol);
			
			/**
			 getSymbol
			 @Pre-Condition- 
			 @Post-Condition- Sets the _symbol
			 */
			string getSymbol();
			
			/**
			 nextColor
			 @Pre-Condition- None
			 @Post-Condition- Goes to the next color in the list
			 */
			void nextColor();
			
			/**
			 getCurrentColor
			 @Pre-Condition- None
			 @Post-Condition- Returns the current color for the tile
			 */
			string getCurrentColor();
			
			/**
			 selectSquare
			 @Pre-Condition- A bool to select the square or not
			 @Post-Condition- Sets _selected
			 */
			void selectSquare(bool selected);
			
			/**
			 toString
			 @Pre-Condition- None
			 @Post-Condition- Displays the current colored symbol
			 */
			string toString();

			/**
			 getColors
			 @Pre-Condition- None
			 @Post-Condition- Gets all the colors this TerrainSquare uses
			 */
			DynamicArray<string>& getColors();

			/**
			 operator=
			 @Pre-Condition- A constant TerrainSquare reference
			 @Post-Condition- Makes this TerrainSquare the same as the passed in one
			 */
			void operator=(TerrainSquare& terrainSquare);
	};
}

#endif
