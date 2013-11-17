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
 * Test header file.
 *
 */

#ifndef TEST_H_
#define TEST_H_

#include <string>
#include <functional>
#include <cstdlib>

using namespace std;

namespace bammm
{
	class Test
	{
		public:
			typedef std::function<int(void)> Func;
			Test();
			Test(Func function, std::string name);
			virtual ~Test();

			/**
			 getFunction
			 @Pre-Condition- No input
			 @Post-Condition- Returns Func _function
			 */
			Func getFunction();

			/**
			 getName
			 @Pre-Condition- No input
			 @Post-Condition- Returns _name
			 */
			string getName();

		private:
			Func _function;
			string _name;
	};
}

#endif
