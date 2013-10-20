/**
 * @file test.cpp
 * @class Test
 * @brief Class that defines a Test object, which holds a function to be tested and a name for that test.
 * @author: Bradley Crusco
 * @version 1.0 10/7/13
 */

#include "test.h"
#include <cstdlib>

using namespace std;

namespace bammm
{

    /**
     * Test::Test()
     * Default constructor for Test object, lets _function to NULL and _name to empty string.
     */
    Test::Test()
    {
        _function = nullptr;
        _name = "";
    }

    /**
     * Test::Test()
     * Constructor for Test object with two arguments, func and name, which specify the function and name of the test.
     *
     * @param func The function to be tested.
     * @param name The name of the test.
     */
    Test::Test(Func func, string name)
    {
        _function = func;
        _name = name;
    }

    /**
     * Test::~Test()
     * The default destructor for a Test object.
     */
    Test::~Test()
    {
    }

    /**
     * Test::getFunction()
     * Returns _function.
     *
     * @return Test:Func
     */
    Test::Func Test::getFunction()
    {
        return _function;
    }

    /**
     * Test::getName()
     * Returns _name.
     *
     * @return string
     */
    string Test::getName()
    {
        return _name;
    }
}
