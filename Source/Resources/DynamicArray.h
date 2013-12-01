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
 * DynamicArray header file.
 *
 */

#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include <iostream>
#include <cstring>
#include <cassert>
#include <typeinfo>
#include "Constant.h"
using namespace std;

namespace bammm
{
	template<class T>
	class DynamicArray
	{
		private:
			T* _array;
			uint _size;
			uint _capacity;

			/**
			 increaseCapacity
			 @Pre-Condition- Takes a uint of the new capacity
			 @Post-Condition- Increases the capacity of the array to the new capacity specified
			 */
			void increaseCapacity(uint newCapacity);

			/**
			 shiftElementsLeft
			 @Pre-Condition- Takes a uint of the index to shift to
			 @Post-Condition- Shifts the elements of the array towards the left to the index
			 */
			void shiftElementsLeft(uint index);

			/**
			 shiftElementsRight
			 @Pre-Condition- Takes a uint of the index to shift to
			 @Post-Condition- Shifts the elements of the array towards the right to the index
			 */
			void shiftElementsRight(uint index);

			/**
			 errorMessage
			 @Pre-Condition- Takes a string message
			 @Post-Condition- Prints the message as an error
			 */
			void errorMessage(string message);

		public:
			DynamicArray();
			DynamicArray(uint capacity);
			virtual ~DynamicArray();

			/**
			 getSize
			 @Pre-Condition- No input
			 @Post-Condition- Returns the size as a uint
			 */
			uint getSize();

			/**
			 getCapacity
			 @Pre-Condition- No input
			 @Post-Condition- Returns the capacity as a uint
			 */
			uint getCapacity();

			/**
			 getMemoryUsage
			 @Pre-Condition- No input
			 @Post-Condition- Returns memory usage
			 */
			uint getMemoryUsage();

			/**
			 set
			 @Pre-Condition- Takes an index and a value
			 @Post-Condition- Sets the given index to the given value
			 */
			void set(uint index, T value);

			/**
			 add
			 @Pre-Condition- Takes an element
			 @Post-Condition- Adds the element to the end of the array
			 */
			bool add(T element);

			/**
			 insert
			 @Pre-Condition- Takes an index and an element
			 @Post-Condition- Inserts the element in the location at the given index
			 */
			void insert(uint index, T element);

			/**
			 remove
			 @Pre-Condition- Takes an index
			 @Post-Condition- Removes the element at the given index
			 */
			T& remove(uint index);

			/**
			 removeElement
			 @Pre-Condition- Takes an element
			 @Post-Condition- Finds the element and removes it
			 */
			bool removeElement(T element);

			/**
			 clear
			 @Pre-Condition- Takes no input
			 @Post-Condition- Clears the entire array
			 */
			void clear();

			/**
			 toString
			 @Pre-Condition- Takes no input
			 @Post-Condition- Returns a string that represents the array
			 */
			string toString();

			/**
			 indexOf
			 @Pre-Condition- Takes an element
			 @Post-Condition- Returns the index of the given element
			 */
			int indexOf(T element);

			/**
			 ensureCapacity
			 @Pre-Condition- Takes a unit minimum value
			 @Post-Condition- Ensures that the array has at least the given minimum capacity
			 */
			void ensureCapacity(uint minimum);

			/**
			 contains
			 @Pre-Condition- Takes an element
			 @Post-Condition- Returns true if the array contains that element, false otherwise
			 */
			bool contains(T element);

			/**
			 trimToSize
			 @Pre-Condition- No input
			 @Post-Condition- Trims the capacity of the array to the size of the array
			 */
			void trimToSize();

			/**
			 get
			 @Pre-Condition- Takes a unit index
			 @Post-Condition- Returns the element at that index
			 */
			T& get(uint index);

			/**
			 operator[]
			 @Pre-Condition- Takes a unit index
			 @Post-Condition- Returns the element at that index
			 */
			T& operator[](uint index);
	};

	template<class T>
	DynamicArray<T>::DynamicArray()
	{
		_capacity = 10;
		_array = new T[_capacity];
		_size = 0;
	}

	template<class T>
	DynamicArray<T>::DynamicArray(uint capacity)
	{
		_capacity = capacity;
		_size = 0;

		if (capacity > 0)
		{
			_array = new T[_capacity];
		}
		else
		{
			errorMessage("Cannot have zero capacity");
			assert(0);
		}
	}

	template<class T>
	DynamicArray<T>::~DynamicArray()
	{
		if (_array == NULL)
		{
			errorMessage("Array is null.");
		}
		else
		{
			delete[] _array;
			_array = NULL;
		}
	}

	template<class T>
	uint DynamicArray<T>::getSize()
	{
		return _size;
	}

	template<class T>
	uint DynamicArray<T>::getCapacity()
	{
		return _capacity;
	}

	template<class T>
	uint DynamicArray<T>::getMemoryUsage()
	{
		return sizeof(this) + (sizeof(T) * _capacity);
	}

	template<class T>
	void DynamicArray<T>::set(uint index, T value)
	{
		if (_array == NULL)
		{
			errorMessage("Array is null.");
			assert(0);
		}

		if (index >= _size)
		{
			errorMessage("Index out of bounds.");
			assert(0);
		}

		_array[index] = value;
	}

	template<class T>
	bool DynamicArray<T>::add(T element)
	{
		if (_array == NULL)
		{
			errorMessage("Cannot add to null array");
			return false;
		}

		if (_size == _capacity)
		{
			increaseCapacity(_capacity * 2);
		}

		_array[_size] = element;
		_size++;

		return true;
	}

	template<class T>
	void DynamicArray<T>::insert(uint index, T element)
	{
		if (_array == NULL)
		{
			errorMessage("Cannot add to null array");
			return;
		}

		if (_size == _capacity)
		{
			increaseCapacity(_capacity * 2);
		}

		if (index == _size)
		{
			add(element);
		}
		else if (index < _size)
		{
			shiftElementsRight(index);
			_array[index] = element;
			_size++;
		}
		else
		{
			errorMessage("Index out of bounds.");
		}
	}

	template<class T>
	T& DynamicArray<T>::remove(uint index)
	{
		if (_array == NULL)
		{
			errorMessage("Array is null.");
			assert(0);
		}

		if (index >= _size)
		{
			errorMessage("Index out of bounds.");
			assert(0);
		}
		T& removedElement = _array[index];
		shiftElementsLeft(index);
		_size--;

		return removedElement;
	}

	template<class T>
	bool DynamicArray<T>::removeElement(T element)
	{
		if (_array == NULL)
		{
			errorMessage("Array is null.");
			assert(0);
		}

		for (uint i = 0; i < _size; i++)
		{
			if (_array[i] == element)
			{
				remove(i);
				return true;
			}
		}

		return false;
	}

	template<class T>
	void DynamicArray<T>::clear()
	{
		if (_array == NULL)
		{
			errorMessage("Array is null");
			return;
		}

		while (_size > 0)
		{
			remove(0);
		}
	}

	template<class T>
	string DynamicArray<T>::toString()
	{
		if (_array == NULL)
		{
			errorMessage("Array is null.");
			return "";
		}

		string output = "[";

		for (uint i = 0; i < _size; i++)
		{
			if (i != _size - 1)
			{
				output = output + to_string((_array[i])) + ", ";
			}
			else
			{
				output = output + to_string((_array[i]));
			}
		}

		output = output + "]\n";
		return output;
	}

	template<class T>
	int DynamicArray<T>::indexOf(T element)
	{
		if (_array == NULL)
		{
			errorMessage("Array is null.");
			return -1;
		}

		for (uint i = 0; i < _size; i++)
		{
			if (element == _array[i])
			{
				return i;
			}
		}

		return -1;
	}

	template<class T>
	void DynamicArray<T>::ensureCapacity(uint minimum)
	{
		if (_array == NULL)
		{
			errorMessage("Array is null");
		}

		if (_capacity < minimum)
		{
			increaseCapacity(minimum);
		}
	}

	template<class T>
	bool DynamicArray<T>::contains(T element)
	{
		if (_array == NULL)
		{
			errorMessage("Array is null");
			return false;
		}

		for (uint i = 0; i < _size; i++)
		{
			if (element == _array[i])
			{
				return true;
			}
		}
		return false;
	}

	template<class T>
	void DynamicArray<T>::trimToSize()
	{
		if (_array == NULL)
		{
			errorMessage("Array is null.");
			return;
		}

		if (_size == 0)
		{
			errorMessage("Cannot trim to size 0.");
			return;
		}

		if (_size == _capacity)
		{
			return;
		}

		T* newArray = new T[_size];
		_capacity = _size;
		for (uint i = 0; i < _size; i++)
		{
			newArray[i] = _array[i];
		}
		delete[] _array;
		_array = newArray;
	}

	template<class T>
	T& DynamicArray<T>::get(uint index)
	{
		if (_array == NULL)
		{
			errorMessage("Array is null.");
			assert(0);
		}

		if (index >= _size)
		{
			errorMessage("Index out of bounds.");
			assert(0);
		}

		return _array[index];
	}

	template<class T>
	T& DynamicArray<T>::operator[](uint index)
	{
		if (_array == NULL)
		{
			errorMessage("Array is null.");
			assert(0);
		}

		if (index >= _size)
		{
			errorMessage("Index out of bounds.");
			assert(0);
		}

		return _array[index];
	}

	template<class T>
	void DynamicArray<T>::increaseCapacity(uint newCapacity)
	{
		T* tempArray = new T[newCapacity];
		for (uint i = 0; i < _size; i++)
		{
			tempArray[i] = _array[i];
		}
		_capacity = newCapacity;
		delete[] _array;
		_array = tempArray;
	}

	template<class T>
	void DynamicArray<T>::shiftElementsLeft(uint index)
	{
		for (uint i = index; i < _size - 1; i++)
		{
			_array[i] = _array[i + 1];
		}
	}

	template<class T>
	void DynamicArray<T>::shiftElementsRight(uint index)
	{
		for (uint i = _size; i > index; i--)
		{
			_array[i] = _array[i - 1];
		}
	}

	template<class T>
	void DynamicArray<T>::errorMessage(string message)
	{
		cout << "An error has occurred. " << message << "\n";
	}
}

#endif
