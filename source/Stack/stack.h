/*
 * stack.h
 *
 *  Created on: Oct 12, 2013
 *          Author: mwitkows
 */

#ifndef STACK_H_
#define STACK_H_

#include "../DynamicArray/dynamicarray.h"

namespace bammm
{
	/**
	 * @brief A stack data structure where only the top element can be
	 * seen, or removed. This uses DynamicArray as its base.
	 *
	 */
	template<class T>
	class Stack
	{
		private:
			DynamicArray<T>* _stack;
			static const uint initialSize = 10;
			void errorMsg(string msg);

		public:
			Stack();
			bool isEmpty();
			T& peek();
			T& pop();
			T& push(T& element);
			uint getSize();
			string toString();
			~Stack();
	};

	/**
	 * @brief Creates a new Stack of size initialSize.
	 *
	 */
	template<class T>
	Stack<T>::Stack()
	{
		_stack = new DynamicArray<T>(initialSize);
	}

	/**
	 * @brief Checks if the stack is empty.
	 * @returns Returns a boolean representing if the stack is empty.
	 */
	template<class T>
	bool Stack<T>::isEmpty()
	{
		if (_stack->getSize() > 0)
		{
			return false;
		}

		return true;
	}

	/**
	 * @brief Allows the user to look at the top element of the stack without
	 * removing it.
	 * @returns Returns the top element of the stack.
	 */
	template<class T>
	T& Stack<T>::peek()
	{
		if (_stack->getSize() == 0)
		{
			errorMsg("Index out of bounds.");
			assert(0);
		}

		return _stack->get(_stack->getSize() - 1);
	}

	/**
	 * @brief Removes the top element of the stack.
	 * @returns Returns the removed element.
	 * @throws Asserts an error when there is nothing to be removed.
	 */
	template<class T>
	T& Stack<T>::pop()
	{
		if (_stack->getSize() == 0)
		{
			errorMsg("Index out of bounds.");
			assert(0);
		}
		return _stack->remove(_stack->getSize() - 1);
	}

	/**
	 * @brief Adds a new element to the top of the stack.
	 * @params element The element to be added.
	 * @returns Returns the added element.
	 */
	template<class T>
	T& Stack<T>::push(T& element)
	{
		_stack->add(element);
		return element;
	}

	/**
	 * @brief Gets the size of the stack.
	 * @Returns the size of the stack.
	 */
	template<class T>
	uint Stack<T>::getSize()
	{
		return _stack->getSize();
	}

	/**
	 * @brief Deletes the stack if it hasn't already been deleted.
	 * @throws Asserts an error if the stack has already been deleted.
	 */
	template<class T>
	Stack<T>::~Stack()
	{
		if (_stack == NULL)
		{
			errorMsg("Cannot delete null stack.");
			assert(0);
		}

		delete _stack;
	}

	/**
	 * @brief Outputs an error message to the console.
	 * @param msg The error message.
	 */
	template<class T>
	void Stack<T>::errorMsg(string msg)
	{
		cout << "An error has occurred. " << msg << "\n";
	}

	/**
	 * @brief Creates a string of the Stack
	 * @returns Returns a string that represents the Stack
	 */
	template<class T>
	string Stack<T>::toString()
	{
		return _stack->toString();
	}
}

#endif
