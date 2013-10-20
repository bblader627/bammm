/*
 * hashmap+tests.cpp
 *
 *  Created on: Oct 15, 2013
 *      Author: bradley
 */

#include "hashmap+tests.h"

namespace bammm
{
	namespace HashMapTests
	{
		bool testConstructor()
		{
			HashMap<int> hashMap;

			if (hashMap.getNumerOfNodes()
					!= 0&& hashMap.getSize() != DEFAULT_MAPSIZE)
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		bool testGetNumberOfNodes()
		{
			HashMap<int> hashMap;

			if (hashMap.getNumerOfNodes() != 0)
			{
				return false;
			}

			/*
			 * Add node to hashMap and recheck number of nodes
			 */
			hashMap.add("Test", 10);
			if (hashMap.getNumerOfNodes() != 1)
			{
				return false;
			}

			/*
			 * Remove node from hashMap and recheck number of nodes
			 */
			hashMap.remove("Test");
			if (hashMap.getNumerOfNodes() != 0)
			{
				return false;
			}

			return true;
		}

		bool testGetSize()
		{
			HashMap<int> hashMap;

			if (hashMap.getSize() != 1000)
			{
				return false;
			}
			else
			{
				return false;
			}
		}

		bool testContains()
		{
			HashMap<int> hashMap;

			/*
			 * Add a value to the hashMap and then return the return value of contains (which is a bool).
			 */
			hashMap.add("Test", 10);
			return hashMap.contains("Test");
		}

		bool testAdd()
		{
			HashMap<int> hashMap;

			/*
			 * Add a value and then see if contains returns true (thus it is in the hashMap if contains is working correctly).
			 */
			hashMap.add("Test", 10);
			return hashMap.contains("Test");
		}

		bool testRemove()
		{
			HashMap<int> hashMap;

			/*
			 * Add a value and then see if contains returns true.
			 * Then remove that value, and see if contains returns false.
			 * If so then remove works.
			 */
			hashMap.add("Test", 10);
			if (hashMap.contains("Test") == false)
			{
				return false;
			}

			hashMap.remove("Test");
			if (hashMap.contains("Test") == false)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool testRemoveAll()
		{
			HashMap<int> hashMap;

			/*
			 * Add two values to the HashMap, then call removeAll.
			 * Successful if contains returns false for both.
			 */

			hashMap.add("Test1", 10);
			hashMap.add("Test2", 20);

			hashMap.removeAll();

			if ((hashMap.contains("Test1") == false)
					&& (hashMap.contains("Test2") == false))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool testGetAllKeys()
		{
			HashMap<int> hashMap;
			//DynamicArray instead?
			DynamicArray<string> keys;

			/*
			 * Add two values to a HashMap, then call getAllKeys.
			 * Check if the added keys exist in the returned array.
			 * If they do, return true.
			 */

			hashMap.add("Test1", 10);
			hashMap.add("Test2", 20);

			keys = *(hashMap.getAllKeys());

			if (((keys[0].compare("Test1") == 0)
					|| (keys[0].compare("Test2") == 0))
					&& ((keys[1].compare("Test1") == 0)
							|| (keys[1].compare("Test2") == 0)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool testGetAllValues()
		{
			HashMap<int> hashMap;
			DynamicArray<int> values;

			/*
			 * Add two values to the HashMap, then call getAllValues.
			 * Check if the added values exist in the returned array.
			 * If they do, return true.
			 */

			hashMap.add("Test1", 10);
			hashMap.add("Test2", 20);

			values = *(hashMap.getAllValues());

			if (((values[0] == 10) || (values[0] == 20))
					&& ((values[1] == 10) || (values[1] == 20)))
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		bool testGetValue()
		{
			HashMap<int> hashMap;

			/*
			 * Add a value to the hashMap, then check that the result of getValue is equal to the value added.
			 */

			hashMap.add("Test", 10);

			if (hashMap.getValue("Test") == 10)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		TestSuite& addToTestSuite(TestSuite& testSuite)
		{
			testSuite.addTest(&Triforce::HashMapTests::testConstructor,
					"testConstructor");
			testSuite.addTest(&Triforce::HashMapTests::testGetNumberOfNodes,
					"testGetNumberOfNodes");
			testSuite.addTest(&Triforce::HashMapTests::testGetSize,
					"testGetSize");
			testSuite.addTest(&Triforce::HashMapTests::testContains,
					"testContains");
			testSuite.addTest(&Triforce::HashMapTests::testAdd, "testAdd");
			testSuite.addTest(&Triforce::HashMapTests::testRemove,
					"testRemove");
			testSuite.addTest(&Triforce::HashMapTests::testRemoveAll,
					"testRemoveAll");
			testSuite.addTest(&Triforce::HashMapTests::testGetAllKeys,
					"testGetAllKeys");
			testSuite.addTest(&Triforce::HashMapTests::testGetAllValues,
					"testGetAllValues");
			testSuite.addTest(&Triforce::HashMapTests::testGetValue,
					"testGetValue");

			return testSuite;
		}
	}
}
