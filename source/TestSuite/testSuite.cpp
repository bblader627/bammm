/**
 * @file testSuite.cpp
 * @class TestSuite
 * @brief Allows a user to add and execute test functions. Displays success or failure, start time, end time, run time, and memory usage information.
 * @author: Bradley Crusco
 * @version 1.0 10/7/13
 */

#include "testSuite.h"

using namespace std;

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

    /**
     * TestSuite::TestSuite()
     * Default constructor for TestSuite. Sets numberOfTests equal to 0.
     */
    TestSuite::TestSuite()
    {
        numberOfTests = 0;
    }

    /**
     * TestSuite::~TestSuite()
     * Default destructor for TestSuite.
     */
    TestSuite::~TestSuite()
    {
    }

    /**
     * TestSuite::addTest()
     * Takes a function to be tested and a name for that test and adds it to an array of tests to run.
     *
     * @param testFunction The function to be tested.
     * @param testName The name of the test being added.
     */
    void TestSuite::addTest(std::function<bool(void)> testFunction,
            string testName)
    {
        addTestWithMemoryCheck(
                std::bind(TestSuitePrivate::wrapperFuncReturnBool,
                        testFunction), testName);
    }

    void TestSuite::addTestWithMemoryCheck(Test::Func testFunction,
            std::string testName)
    {
        if (numberOfTests == MaximumNumberOfTests)
        {
            cout
                    << "Could not add test to TestSuite, maximum number of tests have been added."
                    << endl;
        }
        else
        {
            tests[numberOfTests] = Test(testFunction, testName);
            numberOfTests++;
        }
    }

    /**
     * TestSuite::runTests()
     * Executes all tests added to the suite. Prints results for each test as it completes them.
     * Prints a summary at the conclusion.
     */
    void TestSuite::runTests()
    {
        int numberOfSuccesses = 0, numberOfFailures = 0;

        for (int i = 0; i < numberOfTests; i++)
        {
            if (executeTest(tests[i]))
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
                << "\e[0m" << endl;
    }

    /**
     * TestSuite::executeTest()
     * Executes each individual test and prints results to screen.
     * Unit test function is to return an int. -1 will mean the test failed.
     * 0 or greater will indicate that the test was a success, and will give the number of
     * memory allocations that were not freed.
     *
     * @param test The test to be executed
     * @return bool
     */
    bool TestSuite::executeTest(Test test)
    {
        Time startTime(Time::current());
        int result = test.getFunction()();
        Time endTime(Time::current());
        Time duration(startTime - endTime);

        cout << "\e[33m" << "Test: " << test.getName() << "\e[0m" << endl;
        cout << "Start time: " << startTime << " End time: " << endTime
                << " Duration: " << duration << endl;

        if (result == -1)
        {
            cout << "Result: " << "\e[31m" << "Failed" << "\e[0m" << endl;
            return false;

        }
        else
        {
            cout << "Number of memory allocations not freed: " << result
                    << endl;
            cout << "Result: " << "\e[32m" << "Success" << "\e[0m" << endl;
            return true;
        }
    }
}

