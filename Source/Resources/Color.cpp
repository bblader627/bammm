/*
 * CS585
 *
 * Team Bammm
 *  Alvaro Home
 *  Matt Konstantinou
 *  Michael Abramo
 *  Matt Witkowski  
 *  Bradley Crusco
 * Description:
 * Color cpp file.
 *
 */

#include "Color.h"

namespace bammm
{
	namespace Color
	{
		string colorText(string text, string color)
		{
			string selectedColor;
			if (color == "black")
			{
				selectedColor = _blackText;
			}
			else if (color == "red")
			{
				selectedColor = _redText;
			}
			else if (color == "green")
			{
				selectedColor = _greenText;
			}
			else if (color == "yellow")
			{
				selectedColor = _yellowText;
			}
			else if (color == "blue")
			{
				selectedColor = _blueText;
			}
			else if (color == "purple")
			{
				selectedColor = _purpleText;
			}
			else if (color == "cyan")
			{
				selectedColor = _cyanText;
			}
			else if (color == "white")
			{
				selectedColor = _whiteText;
			}
			else
			{
				selectedColor = _defaultText;
			}

			string colorString = _startColor + selectedColor + text
					+ _startColor + _defaultText;
			return colorString;
		}
	}
}
