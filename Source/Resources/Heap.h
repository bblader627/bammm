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
 * Heap header file.
 *
 */

#ifndef HEAP_H_
#define HEAP_H_

#include "DynamicArray.h"
#include "Constant.h"

namespace bammm
{
	template<class T>
	class Heap
	{
		private:
			bool _isMax;
			DynamicArray<T>* _heap;
			const static uint initialSize = 10;

			/**
			 adjustParent
			 @Pre-Condition- Takes uint index
			 @Post-Condition- Parent nodes of the index will have been adjusted to follow the heap's rules
			 */
			void adjustParent(uint index);

			/**
			 adjustParent
			 @Pre-Condition- Takes uint index
			 @Post-Condition- Child nodes of the index will have been adjusted to follow the heap's rules
			 */
			void adjustChild(uint index);

			/**
			 errorMessage
			 @Pre-Condition- Takes a string message
			 @Post-Condition- Prints the message as an error
			 */
			void errorMessage(string message);

		public:
			Heap();
			Heap(bool isMaximum);
			~Heap();

			/**
			 add
			 @Pre-Condition- Takes an element
			 @Post-Condition- Adds the given element to the heap
			 */
			void add(T element);

			/**
			 remove
			 @Pre-Condition- No input
			 @Post-Condition- Removes the first element on the heap and returns it
			 */
			T remove();

			/**
			 getSize
			 @Pre-Condition- No input
			 @Post-Condition- Returns the size of the heap
			 */
			uint getSize();

			/**
			 isEmpty
			 @Pre-Condition- No input
			 @Post-Condition- Returns true if the heap is empty, false otherwise
			 */
			bool isEmpty();

			/**
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string representation of the heap
			 */
			string toString();
	};

	template<class T>
	Heap<T>::Heap()
	{
		_heap = new DynamicArray<T>(initialSize);
		_isMax = true;
	}

	template<class T>
	Heap<T>::Heap(bool isMaximum)
	{
		_heap = new DynamicArray<T>(initialSize);
		_isMax = isMaximum;
	}

	template<class T>
	Heap<T>::~Heap()
	{
		if (_heap == NULL)
		{
			errorMessage("Cannot delete null heap.");
			assert(0);
		}

		delete _heap;
	}

	template<class T>
	void Heap<T>::add(T element)
	{
		_heap->add(element);
		adjustParent(_heap->getSize() - 1);
	}

	template<class T>
	T Heap<T>::remove()
	{
		if (getSize() <= 0)
		{
			errorMessage("Index out of bounds.");
			assert(0);
		}

		T removed = _heap->get(0);
		_heap->set(0, _heap->get(_heap->getSize() - 1));
		_heap->remove(_heap->getSize() - 1);
		adjustChild(0);

		return removed;
	}

	template<class T>
	uint Heap<T>::getSize()
	{
		return _heap->getSize();
	}

	template<class T>
	bool Heap<T>::isEmpty()
	{
		if (getSize() > 0)
		{
			return false;
		}

		return true;
	}

	template<class T>
	string Heap<T>::toString()
	{
		return _heap->toString();
	}

	template<class T>
	void Heap<T>::adjustParent(uint index)
	{
		if (index == 0)
		{
			return;
		}

		int parent = (index - 1) / 2;

		if (_isMax)
		{
			if (_heap->get(parent) < _heap->get(index))
			{
				T temp = _heap->get(parent);
				_heap->set(parent, _heap->get(index));
				_heap->set(index, temp);

				adjustParent(parent);
			}
		}
		else
		{
			if (_heap->get(parent) > _heap->get(index))
			{
				T temp = _heap->get(parent);
				_heap->set(parent, _heap->get(index));
				_heap->set(index, temp);
				adjustParent(parent);
			}
		}
	}

	template<class T>
	void Heap<T>::adjustChild(uint index)
	{
		uint leftChild = (2 * index) + 1;
		uint rightChild = (2 * index) + 2;
		uint chosenChild;
		uint size = _heap->getSize();

		if (leftChild >= size)
		{
			return;
		}

		if (_isMax)
		{
			if (rightChild >= size)
			{
				chosenChild = leftChild;
			}
			else if (rightChild < size)
			{
				if (_heap->get(leftChild) > _heap->get(rightChild))
				{
					chosenChild = leftChild;
				}
				else
				{
					chosenChild = rightChild;
				}
			}
		}
		else
		{
			if (rightChild >= size)
			{
				chosenChild = leftChild;
			}
			else if (rightChild < size)
			{
				if (_heap->get(leftChild) < _heap->get(rightChild))
				{
					chosenChild = leftChild;
				}
				else
				{
					chosenChild = rightChild;
				}
			}
		}

		T temp = _heap->get(chosenChild);
		_heap->set(chosenChild, _heap->get(index));
		_heap->set(index, temp);
		adjustChild(chosenChild);
	}

	template<class T>
	void Heap<T>::errorMessage(string message)
	{
		cout << "An error has occurred. " << message << "\n";
	}
}

#endif
