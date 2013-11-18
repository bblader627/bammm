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
 * Test cpp file.
 *
 */

#include "Test.h"

namespace bammm
{
	Test::Test()
	{
		_function = nullptr;
		_name = "";
	}

	Test::Test(Func func, string name)
	{
		_function = func;
		_name = name;
	}

	Test::~Test()
	{
	}

	Test::Func Test::getFunction()
	{
		return _function;
	}

	string Test::getName()
	{
		return _name;
	}
}
