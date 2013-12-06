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
 * TestSuite cpp file.
 *
 */

#include "TestSuite.h"

namespace bammm
{
	namespace TestSuitePrivate
	{
		/**
		 * A helper function a wrap a test function which returns boolean
		 * into one returns int to utilize the consistent addTestWithMemoryCheck
		 */
		int wrapperFuncReturnBool(std::function<bool(void)> funcReturnBool)
		{
			return (funcReturnBool() ? 0 : -1);
		}
	}

	TestSuite::TestSuite()
	{
		_numberOfTests = 0;
	}

	TestSuite::~TestSuite()
	{
	}

	void TestSuite::addTest(std::function<bool(void)> testFunction,
			string testName)
	{
		addTestWithMemoryCheck(
				bind(TestSuitePrivate::wrapperFuncReturnBool, testFunction),
				testName);
	}

	void TestSuite::addTestWithMemoryCheck(Test::Func testFunction,
			string testName)
	{
		if (_numberOfTests == _MaximumNumberOfTests)
		{
			cout
					<< "Could not add test to TestSuite, maximum number of tests have been added."
					<< "\n";
		}
		else
		{
			_tests[_numberOfTests] = Test(testFunction, testName);
			_numberOfTests++;
		}
	}

	void TestSuite::runTests()
	{
		int numberOfSuccesses = 0, numberOfFailures = 0;

		for (int i = 0; i < _numberOfTests; i++)
		{
			if (executeTest(_tests[i]))
			{
				numberOfSuccesses++;
			}
			else
			{
				numberOfFailures++;
			}
		}

		cout << "Summary: ";
		cout << "\e[32m" << "Number of successes: " << numberOfSuccesses
				<< "\e[0m";
		cout << "\e[31m" << " Number of failures: " << numberOfFailures
				<< "\e[0m" << "\n";
	}

	bool TestSuite::executeTest(Test test)
	{
		Time startTime(Time::current());
		int result = test.getFunction()();
		Time endTime(Time::current());
		Time duration(startTime - endTime);

		cout << "\e[33m" << "Test: " << test.getName() << "\e[0m" << "\n";
		cout << "Start time: " << startTime << " End time: " << endTime
				<< " Duration: " << duration << "\n";

		if (result == -1)
		{
			cout << "Result: " << "\e[31m" << "Failed" << "\e[0m" << "\n";

			return false;

		}
		else
		{
			cout << "Number of memory allocations not freed: " << result
					<< "\n";
			cout << "Result: " << "\e[32m" << "Success" << "\e[0m" << "\n";

			return true;
		}
	}
}

