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
 * TestSuite header file.
 *
 */

#ifndef TESTSUITE_H_
#define TESTSUITE_H_

#include <iostream>
#include "Time.h"
#include "Test.h"

using namespace std;

namespace bammm
{
	class TestSuite
	{
		private:
			static const int _MaximumNumberOfTests = 250;
			int _numberOfTests;
			Test _tests[_MaximumNumberOfTests];

		public:
			TestSuite();
			virtual ~TestSuite();

			/**
			 addTest
			 @Pre-Condition- Takes in a std::function<bool(void)>, which is the testFunction, and a name for the test
			 @Post-Condition- A test is created and added to the suite
			 */
			void addTest(std::function<bool(void)> testFunction,
					string testName);

			/**
			 addTestWithMemoryCheck
			 @Pre-Condition- Takes in a Test::Func testFunction, which is the testFunction that allows for memory checking, and a name for the test
			 @Post-Condition- A test is created and added to the suite
			 */
			void addTestWithMemoryCheck(Test::Func testFunction,
					string testName);

			/**
			 runTests
			 @Pre-Condition- No input
			 @Post-Condition- Runs all the tests in the test suite
			 */
			void runTests();

			/**
			 executeTest
			 @Pre-Condition- Takes a Test as input
			 @Post-Condition- Executes this test and returns true on success, false otherwise
			 */
			bool executeTest(Test test);
	};
}

#endif
