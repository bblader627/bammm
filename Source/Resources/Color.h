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

		string colorText(string text, string color);
	}
}

#endif
