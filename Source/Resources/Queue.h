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
 * Queue header file.
 *
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "DynamicArray.h"

namespace bammm
{
	template<class T>
	class Queue
	{
		private:
			DynamicArray<T>* _queue;
			static const uint initialSize = 10;

			/**
			 errorMessage
			 @Pre-Condition- Takes a string message
			 @Post-Condition- Prints the message as an error
			 */
			void errorMessage(string message);

		public:
			Queue();
			~Queue();

			/**
			 isEmpty
			 @Pre-Condition- No input
			 @Post-Condition- Returns true if empty
			 */
			bool isEmpty();

			/**
			 peek
			 @Pre-Condition- No input
			 @Post-Condition- Returns the first element of the queue
			 */
			T peek();

			/**
			 remove
			 @Pre-Condition- No input
			 @Post-Condition- Removes the first element of the queue and returns it
			 */
			T remove();

			/**
			 add
			 @Pre-Condition- Takes a T element as input
			 @Post-Condition- Adds the given element to the back of the queue
			 */
			T add(T element);

			/**
			 getSize
			 @Pre-Condition- No input
			 @Post-Condition- Returns the size of the queue
			 */
			uint getSize();

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string representation of the queue
			 */
			string toString();
	};

	template<class T>
	Queue<T>::Queue()
	{
		_queue = new DynamicArray<T>(initialSize);
	}

	template<class T>
	Queue<T>::~Queue()
	{
		if (_queue == NULL)
		{
			errorMessage("Cannot delete null queue.");
			assert(0);
		}

		delete _queue;
	}

	template<class T>
	bool Queue<T>::isEmpty()
	{
		if (_queue->getSize() > 0)
		{
			return false;
		}

		return true;
	}

	template<class T>
	T Queue<T>::peek()
	{
		if (_queue->getSize() == 0)
		{
			errorMessage("Index out of bounds.");
			assert(0);
		}

		return _queue->get(0);
	}

	template<class T>
	T Queue<T>::remove()
	{
		if (_queue->getSize() == 0)
		{
			errorMessage("Index out of bounds.");
			assert(0);
		}

		return _queue->remove(0);
	}

	template<class T>
	T Queue<T>::add(T element)
	{
		_queue->add(element);

		return element;
	}

	template<class T>
	uint Queue<T>::getSize()
	{
		return _queue->getSize();
	}

	template<class T>
	string Queue<T>::toString()
	{
		return _queue->toString();
	}

	template<class T>
	void Queue<T>::errorMessage(string message)
	{
		cout << "An error has occurred. " << message << "\n";
	}
}

#endif
