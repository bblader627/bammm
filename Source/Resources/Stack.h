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
 * Stack header file.
 *
 */

#ifndef STACK_H_
#define STACK_H_

#include "DynamicArray.h"

namespace bammm
{
	template<class T>
	class Stack
	{
		private:
			DynamicArray<T>* _stack;
			static const uint initialSize = 10;

			/**
			 errorMessage
			 @Pre-Condition- Takes a string message
			 @Post-Condition- Prints the message as an error
			 */
			void errorMessage(string message);

		public:
			Stack();
			~Stack();

			/**
			 isEmpty
			 @Pre-Condition- No input
			 @Post-Condition- Returns true if the stack is empty, false otherwise
			 */
			bool isEmpty();

			/**
			 peek
			 @Pre-Condition- No input
			 @Post-Condition- Returns the top element of the stack
			 */
			T peek();

			/**
			 pop
			 @Pre-Condition- No input
			 @Post-Condition- Removes and returns the top element on the stack
			 */
			T pop();

			/**
			 push
			 @Pre-Condition- Takes a T element
			 @Post-Condition- Adds the given element to the top of the stack
			 */
			T push(T element);

			/**
			 getSize
			 @Pre-Condition- No input
			 @Post-Condition- Returns the size of the stack
			 */
			uint getSize();

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string that represents the stack
			 */
			string toString();
	};

	template<class T>
	Stack<T>::Stack()
	{
		_stack = new DynamicArray<T>(initialSize);
	}

	template<class T>
	Stack<T>::~Stack()
	{
		if (_stack == NULL)
		{
			errorMessage("Cannot delete null stack.");
			assert(0);
		}

		delete _stack;
	}

	template<class T>
	bool Stack<T>::isEmpty()
	{
		if (_stack->getSize() > 0)
		{
			return false;
		}

		return true;
	}

	template<class T>
	T Stack<T>::peek()
	{
		if (_stack->getSize() == 0)
		{
			errorMessage("Index out of bounds.");
			assert(0);
		}

		return _stack->get(_stack->getSize() - 1);
	}

	template<class T>
	T Stack<T>::pop()
	{
		if (_stack->getSize() == 0)
		{
			errorMessage("Index out of bounds.");
			assert(0);
		}
		return _stack->remove(_stack->getSize() - 1);
	}

	template<class T>
	T Stack<T>::push(T element)
	{
		_stack->add(element);
		return element;
	}

	template<class T>
	uint Stack<T>::getSize()
	{
		return _stack->getSize();
	}

	template<class T>
	string Stack<T>::toString()
	{
		return _stack->toString();
	}

	template<class T>
	void Stack<T>::errorMessage(string message)
	{
		cout << "An error has occurred. " << message << "\n";
	}
}

#endif
