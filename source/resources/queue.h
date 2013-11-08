/*
 * CS585
 *
 * Team Bammm
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *	Matt Witkowski	
 *   Bradley Crusco
 * Description:
 * Queue header file.
 *
 * Last Modified: Matt Witkowski
 *
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "dynamicarray.h"

namespace bammm
{
	/**
	 * @brief A queue data structure where only the first element can be
	 * seen, or removed. This uses DynamicArray as its base.
	 *
	 */
	template<class T>
	class Queue
	{
		private:
			DynamicArray<T>* _queue;
			static const uint initialSize = 10;
			void errorMsg(string msg);

		public:
			Queue();
			bool isEmpty();
			T peek();
			T remove();
			T add(T element);
			uint getSize();
			string toString();
			~Queue();
	};

	/**
	 * @brief Creates a new Queue of size initialSize.
	 *
	 */
	template<class T>
	Queue<T>::Queue()
	{
		_queue = new DynamicArray<T>(initialSize);
	}

	/**
	 * @brief Checks if the queue is empty.
	 * @returns Returns a boolean representing if the queue is empty.
	 */
	template<class T>
	bool Queue<T>::isEmpty()
	{
		if (_queue->getSize() > 0)
		{
			return false;
		}

		return true;
	}

	/**
	 * @brief Allows the user to look at the first element of the queue without
	 * removing it.
	 * @returns Returns the first element of the queue.
	 */
	template<class T>
	T Queue<T>::peek()
	{
		if (_queue->getSize() == 0)
		{
			errorMsg("Index out of bounds.");
			assert(0);
		}

		return _queue->get(0);
	}

	/**
	 * @brief Removes the first element of the queue.
	 * @returns Returns the removed element.
	 * @throws Asserts an error when there is nothing to be removed.
	 */
	template<class T>
	T Queue<T>::remove()
	{
		if (_queue->getSize() == 0)
		{
			errorMsg("Index out of bounds.");
			assert(0);
		}
		return _queue->remove(0);
	}

	/**
	 * @brief Adds a new element to the back of the queue.
	 * @params element The element to be added.
	 * @returns Returns the added element.
	 */
	template<class T>
	T Queue<T>::add(T element)
	{
		_queue->add(element);
		return element;
	}

	/**
	 * @brief Gets the size of the queue.
	 * @Returns the size of the queue.
	 */
	template<class T>
	uint Queue<T>::getSize()
	{
		return _queue->getSize();
	}

	/**
	 * @brief Deletes the queue if it hasn't already been deleted.
	 * @throws Asserts an error if the queue has already been deleted.
	 */
	template<class T>
	Queue<T>::~Queue()
	{
		if (_queue == NULL)
		{
			errorMsg("Cannot delete null queue.");
			assert(0);
		}

		delete _queue;
	}

	/**
	 * @brief Outputs an error message to the console.
	 * @param msg The error message.
	 */
	template<class T>
	void Queue<T>::errorMsg(string msg)
	{
		cout << "An error has occurred. " << msg << "\n";
	}

	/**
	 * @brief Creates a string from the Queue
	 * @Returns a string that represents the Queue
	 */
	template<class T>
	string Queue<T>::toString()
	{
		return _queue->toString();
	}
}

#endif
