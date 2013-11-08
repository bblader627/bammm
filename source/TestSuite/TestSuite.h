/**
 * @file testsuite.h
 * @class TestSuite
 * @brief Allows a user to add and execute test functions. Displays success or failure, start time, end time, run time, and memory usage information.
 * @author: Bradley Crusco
 * @version 1.0 10/7/13
 */

#ifndef TESTSUITE_H_
#define TESTSUITE_H_

#include "Time.h"
#include "Test.h"
#include <iostream>

namespace bammm
{
	class TestSuite
	{
		public:
			TestSuite();
			virtual ~TestSuite();
			/**
			 *
			 * @brief convert a test function returns boolean into one return int
			 * utilizing std::function in the TestSuite only,
			 * it won't hurt the performance of the main codes
			 *
			 **/
			void addTest(std::function<bool(void)> testFunction,
					std::string testName);
			void addTestWithMemoryCheck(Test::Func testFunction,
					std::string testName);
			void runTests();
			bool executeTest(Test test);

		private:
			static const int MaximumNumberOfTests = 250;
			int numberOfTests;
			Test tests[MaximumNumberOfTests];
	};
}
#endif /* TESTSUITE_H_ */
