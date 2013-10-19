/*
 * CS585
 *
 * Team MMA
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *
 * Description:
 *	Stack template header file.
 *
 * Last Modified: Matt Konstantinou 
 *
 */
#ifndef STACK_H_
#define STACK_H_

#include <iostream>
#include "dynamicarray.h"

#ifndef NULL
#define NULL (void *)0
#endif

using namespace std;

template<typename T> class Stack
{

private:
	DynamicArray<T> * stack;
public:
	Stack<T>()
	{
		//Create new array of size and capacity 1
		stack = new DynamicArray<T>(0);
	}

	bool isEmpty()
	{
		if ( stack->size() == 0 )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool push_back(const T &new_val)
	{
		stack->push_back(new_val);
		return true;
	}

	T pop_back()
	{
		T item = *(stack->at(stack->size()-1));
		stack->pop_back();
		return item;
	}

	int size()
	{
		return stack->size();
	}

	T get(int index)
	{
		return *stack->at(index);
	}

};


#endif /* MY_ARRAY_H_ */
