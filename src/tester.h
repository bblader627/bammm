;/*
 * my_tester.h
 *
 *  Created on: Oct 1, 2013
 *      Author: Matthew Konstantinou
 */
#include<iostream>

//Define null
#ifndef NULL
#define NULL (void *)0
#endif

using namespace std;

const string PASS = "Pass";
const string FAIL = "Fail";

class Tester {

	private:
		//Private variables representing the numbers of successes and failures the tester object has ran
		int successes;
		int failures;

		//Print results of the current test
		void printResult(int elapsedTime, string testName, string result)
		{
			cout << "\t[" << elapsedTime << "]\t" << testName << "\t\t" << result << endl;
			return;
		}

	public:

		//Default constructor
		Tester()
		{
				successes = 0;
				failures = 0;
		}

		/*
		 	 Assert
		 	 @Pre-Condition- Takes in actual value, expected value, and name of test
		  	 @Post-Condition- Returns true or false if the test passes or fails, respectively
		  	 	 	 	 	 	 and prints details of test
		 */
		void Assert(int given, int expected, string testName)
		{
			int startTime = time(NULL);
			string result;
			if ( given == expected )
			{
				result = PASS;
				successes++;
			}
			else
			{
				result = FAIL;
				failures++;
			}
			printResult(time(NULL)-startTime, testName, result);
		}

		/*
			 Assert
			 @Pre-Condition- Takes in actual value, expected value, and name of test
			 @Post-Condition- Returns true or false if the test passes or fails, respectively
								 and prints details of test
		 */
		void Assert(double given, double expected, string testName)
		{
			int startTime = time(NULL);
			string result;
			if ( given == expected )
			{
				result = PASS;
				successes++;
			}
			else
			{
				result = FAIL;
				failures++;
			}
			printResult(time(NULL)-startTime, testName, result);
		}

		/*
			 Assert
			 @Pre-Condition- Takes in actual value, expected value, and name of test
			 @Post-Condition- Returns true or false if the test passes or fails, respectively
								 and prints details of test
		 */
		void Assert(string given, string expected, string testName)
		{
			int startTime = time(NULL);
			string result;
			if (given == expected )
			{
				result = PASS;
				successes++;
			}
			else
			{
				result = FAIL;
				failures++;
			}
			printResult(time(NULL)-startTime, testName, result);
		}

		/*
			 Assert
			 @Pre-Condition- Takes in actual value, expected value, and name of test
			 @Post-Condition- Returns true or false if the test passes or fails, respectively
								 and prints details of test
		 */
		void Assert(bool given, bool expected, string testName)
		{
			int startTime = time(NULL);
			string result;
			if (given == expected)
			{
				result = PASS;
				successes++;
			}
			else
			{
				result = FAIL;
				failures++;
			}
			printResult(time(NULL)-startTime, testName, result);
		}

		/*
			 Assert
			 @Pre-Condition- no parameters
			 @Post-Condition- returns number of successes for current tester object
		 */
		int getSuccesses()
		{
			return successes;
		}

		/*
			 Assert
			 @Pre-Condition- no parameters
			 @Post-Condition- returns number of failures for current tester object
		 */
		int getFailures()
		{
			return failures;
		}

		/*
			 Assert
			 @Pre-Condition- no parameters
			 @Post-Condition- Prints summary of all tests run by tester object
		 */
		void printSummary()
		{
			cout << "Summary:\tSuccesses: " << successes << "\tFailures: " << failures << endl;
		}


};
