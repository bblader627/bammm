/*
 * ashap+tests.h
 *
 *  Created on: Oct 15, 2013
 *      Author: bradley
 */

#ifndef HASHMAP_TESTS_H_
#define HASHMAP_TESTS_H_

#include "HashMap.h"
#include "../TestSuite/TestSuite.h"

namespace bammm
{
	namespace HashMapTests
	{
		bool testConstructor();

		bool testGetNumberOfNodes();
		bool testGetSize();
		bool testContains();
		bool testAdd();
		bool testRemove();
		bool testRemoveAll();
		bool testGetAllKeys();
		bool testGetAllValues();
		bool testGetValue();

		/**
		 * @brief Add all tests with names into the TestSuite
		 */
		TestSuite& addToTestSuite(TestSuite& testSuite);
	}
}
#endif /* HASHMAP_TESTS_H_ */
