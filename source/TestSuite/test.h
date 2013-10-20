/**
 * @file test.h
 * @class Test
 * @brief Class that defines a Test object, which holds a function to be tested and a name for that test.
 * @author: Bradley Crusco
 * @version 1.0 10/7/13
 */

#ifndef TEST_H_
#define TEST_H_

#include <string>
#include <functional>

namespace bammm
{
	class Test
	{
		public:
			typedef std::function<int(void)> Func;
			Test();
			Test(Func func, std::string name);
			virtual ~Test();
			Func getFunction();
			std::string getName();

		private:
			Func _function;
			std::string _name;
	};
}

#endif /* TEST_H_ */
