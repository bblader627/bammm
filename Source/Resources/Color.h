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
 * Color header file.
 *
 */

#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>

using namespace std;

namespace bammm
{
	namespace Color
	{
		static const string _blackText = "30m";
		static const string _redText = "31m";
		static const string _greenText = "32m";
		static const string _yellowText = "33m";
		static const string _blueText = "34m";
		static const string _purpleText = "35m";
		static const string _cyanText = "36m";
		static const string _whiteText = "37m";
		static const string _startColor = "\033[";
		static const string _defaultText = "0m";

		/**
		 colorText
		 @Pre-Condition- Takes text and a color
		 @Post-Condition- A formatted string that uses color
		 */
		string colorText(string text, string color);
	}
}

#endif
