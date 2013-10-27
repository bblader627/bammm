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
 * DynamicArray header file.
 *
 * Last Modified: Matt Witkowski
 *
 */
#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include <iostream>
#include <cstring>
#include <cassert>
#include <typeinfo>

using namespace std;

#ifndef UINT
#define UINT
typedef unsigned int uint;
#endif

#ifndef NULL
#define NULL ((void*)0)
#endif

using namespace std;

namespace bammm
{
    /**
     * @brief An array that auto expands by doubling in size when
     * an index goes out of bounds.
     */
    template<class T>
    class DynamicArray
    {
        private:
            T* _array;
            uint _size;
            uint _capacity;

            void increaseCapacity(uint newCapacity);
            void shiftElementsLeft(uint index);
            void shiftElementsRight(uint index);
            void errorMsg(string s);

        public:
            DynamicArray();
            DynamicArray(uint capacity);
            uint getSize();
            uint getCapacity();
            T operator[](uint index);
            bool add(T element);
            void add(uint index, T element);
            T remove(uint index);
            bool removeElem(T elem);
            void clear();
            string toString();
            uint getMemoryUsage();
            virtual ~DynamicArray();
            T get(uint index);
            void set(uint index, T value);
            int indexOf(T element);
            void ensureCapacity(uint min);
            bool contains(T element);
            void trimToSize();

    };

    /**
     * Creates a DynamicArray with the default capacity of 10.
     */
    template<class T>
    DynamicArray<T>::DynamicArray()
    {
        _capacity = 10;
        _array = new T[_capacity];
        _size = 0;
    }

    /**
     * @brief Creates a DynamicArray with a controlled default capacity.
     * @param capacity Default size of the array.
     * @throws Throws an error when capacity is 0.
     */
    template<class T>
    DynamicArray<T>::DynamicArray(uint capacity)
    {
        _capacity = capacity;
        _size = 0;

        if(capacity > 0)
        {
            _array = new T[_capacity];
        }
        else
        {
            errorMsg("Cannot have zero capacity");
            assert(0);
        }
    }

    /**
     * @brief Returns the number of elements in the array.
     * @returns The number of elements in the array.
     */
    template<class T>
    uint DynamicArray<T>::getSize()
    {
        return _size;
    }

    /**
     * @brief Returns the current capacity of the array.
     * @returns The current capacity of the array.
     */
    template<class T>
    uint DynamicArray<T>::getCapacity()
    {
        return _capacity;
    }

    /**
     * @brief Get and set method for the DynamicArray.
     * @param index The element to be accessed.
     * @throws Throws an error when the array is null or when index is out of bounds.
     * @returns A reference to the element at the specified index.
     */
     template <class T>
     T DynamicArray<T>::operator[](uint index)
     {
        if(_array == NULL)
        {
            errorMsg("Array is null.");
            assert(0);
        }

        if(index >= _size)
        {
            errorMsg("Index out of bounds.");
            assert(0);
        }

        return _array[index];
     }

    /**
     * @brief Adds an element to the end of the array. The array will double in size,
     * if needed.
     * @param element The element to be added to the array.
     * @returns Returns if the element was added successfully.
     */
    template<class T>
    bool DynamicArray<T>::add(T element)
    {
        if(_array == NULL)
        {
            errorMsg("Cannot add to null array");
            return false;
        }

        if(_size == _capacity)
        {
            increaseCapacity(_capacity * 2);
        }

        _array[_size] = element;
        _size++;

        return true;
    }

    /*template<class T>
    bool DynamicArray<T>::add(T element)
    {
        if(_array == NULL)
        {
            errorMsg("Cannot add to null array");
            return false;
        }

        if(_size == _capacity)
        {
            increaseCapacity(_capacity * 2);
        }

        _array[_size] = &element;
        _size++;

        return true;
    }*/

    /**
     * @brief Adds an element to the specified index, and shifts the elements
     * to the right.
     * @param index The spot for the element to be inserted.
     * @param element The element to be inserted.
     */
    template<class T>
    void DynamicArray<T>::add(uint index, T element)
    {
        if(_array == NULL)
        {
            errorMsg("Cannot add to null array");
            return;
        }

        if(_size == _capacity)
        {
            increaseCapacity(_capacity * 2);
        }

        if(index == _size)
        {
            add(element);
        }
        else if(index < _size)
        {
            shiftElementsRight(index);
            _array[index] = element;
            _size++;
        }
        else
        {
            errorMsg("Index out of bounds.");
        }

    }

    /**
     * @brief Removes the element at the index, and shifts the elements to the
     * left.
     * @param index The index to remove.
     * @returns Returns the removed element.
     * @throws Throws an error when the array is null or when the index is out of bounds.
     */
    template<class T>
    T DynamicArray<T>::remove(uint index)
    {
        if(_array == NULL)
        {
            errorMsg("Array is null.");
            assert(0);
        }

        if(index >= _size)
        {
            errorMsg("Index out of bounds.");
            assert(0);
        }
        T removedElement = _array[index];
        shiftElementsLeft(index);
        _size--;

        return removedElement;
    }

    /**
     * @brief Removes the first occurrence of elem from the array.
     * @param elem The elem to remove.
     * @returns Returns a boolean indicating if removal was a success.
     * @throws Throws an error when the array is null.
     */
    template <class T>
    bool DynamicArray<T>::removeElem(T elem)
    {
        if(_array == NULL)
        {
            errorMsg("Array is null.");
            assert(0);
        }
    
        for(uint i = 0; i < _size; i++)
        {
            if(_array[i] == elem)
            {
                remove(i);
                return true;
            }
        }
    
        return false;
    }

    /**
     * @brief Clears the array by setting the size to 0.
     */
    template<class T>
    void DynamicArray<T>::clear()
    {
        if(_array == NULL)
        {
            errorMsg("Array is null");
            return;
        }

        while(_size > 0)
        {
            remove(0);
        }
    }

    /**
     * @brief Creates a new array that has a capacity of newCapacity. Elements
     * are copied over to the new array.
     * @param newCapacity The new capacity for the array.
     */
    template<class T>
    void DynamicArray<T>::increaseCapacity(uint newCapacity)
    {
        T* tempArray = new T[newCapacity];
        for(uint i = 0; i < _size; i++)
        {
            tempArray[i] = _array[i];
        }
        _capacity = newCapacity;
        delete[] _array;
        _array = tempArray;
    }

    /**
     * @brief Shifts elements in the array to the left
     * @param emptySpot The spot being written over.
     */
    template<class T>
    void DynamicArray<T>::shiftElementsLeft(uint emptySpot)
    {
        //uint diff = _size - emptySpot - 1;
        for(uint i = emptySpot; i < _size - 1; i++)
        {
            _array[i] = _array[i+1];
        }
    }

    /**
     * @brief Shifts elements in the array to the right
     * @param newItem The insert position.
     */
    template<class T>
    void DynamicArray<T>::shiftElementsRight(uint newItem)
    {
        for(uint i = _size; i > newItem; i--)
        {
            _array[i] = _array[i-1];
        }
    }

    /**
     * @brief Creates a string of the DynamicArray.
     * @returns a string that represents the DynamicArray.
     */
    template<class T>
    string DynamicArray<T>::toString()
    {
        if(_array == NULL)
        {
            errorMsg("Array is null.");
            return "";
        }

        string output = "[";

        for (uint i = 0; i < _size; i++)
        {
            if(i != _size - 1)
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

    /**
     * @brief Gets the total amount of memory the DynamicArray uses.
     * @returns Returns the total amount of memory the DynamicArray uses.
     */
    template<class T>
    uint DynamicArray<T>::getMemoryUsage()
    {
        return sizeof(this) + (sizeof(T) * _capacity);
    }

    /**
     * @brief Gets the element at a specified index.
     * @param index The index of the element.
     * @returns Returns a reference to the element at index.
     * @throws Throws an error when index is out of bounds or when array is null.
     */
    template<class T>
    T DynamicArray<T>::get(uint index)
    {
        if(_array == NULL)
        {
            errorMsg("Array is null.");
            assert(0);
        }

        if(index >= _size)
        {
            errorMsg("Index out of bounds.");
            assert(0);
        }

        return _array[index];
    }

    /**
     * @brief Sets the element at a specific index to value.
     * @param index The index of the element to be changed.
     * @param value The new value for that index.
     * @throws Throws an error when the array is null or when the index is out of bounds.
     */
    template<class T>
    void DynamicArray<T>::set(uint index, T value)
    {
        if(_array == NULL)
        {
            errorMsg("Array is null.");
            assert(0);
        }

        if(index >= _size)
        {
            errorMsg("Index out of bounds.");
            assert(0);
        }

        _array[index] = value;
    }

    /**
     * @brief Gets the index of the first occurrence of element in the array.
     * @param element The element to be searched for.
     * @returns Returns the index of element or -1 if it wasn't found.
     */
    template<class T>
    int DynamicArray<T>::indexOf(T element)
    {
        if(_array == NULL)
        {
            errorMsg("Array is null.");
            return -1;
        }

        for(uint i = 0; i < _size; i++)
        {
            if(element == _array[i])
            {
                return i;
            }
        }

        return -1;
    }

    /**
     * @brief Makes sure the capacity is at least min.
     * @param min The minimum capacity for the array.
     */
    template <class T>
    void DynamicArray<T>::ensureCapacity(uint min)
    {
        if(_array == NULL)
        {
            errorMsg("Array is null");
        }

        if(_capacity < min)
        {
            increaseCapacity(min);
        }
    }

    /**
     * @brief Checks if the array contains element.
     * @param element The element to be searched for.
     * @returns Returns a boolean representing if element is in the array.
     */
    template <class T>
    bool DynamicArray<T>::contains(T element)
    {
        if(_array == NULL)
        {
            errorMsg("Array is null");
            return false;
        }

        for(uint i = 0; i < _size; i++)
        {
            if(element == _array[i])
            {
                return true;
            }
        }
        return false;
    }

    /**
     * @brief Copies the array over to a new array with capacity of _size.
     */
    template <class T>
    void DynamicArray<T>::trimToSize()
    {
        if(_array == NULL)
        {
            errorMsg("Array is null.");
            return;
        }

        if(_size == 0)
        {
            errorMsg("Cannot trim to size 0.");
            return;
        }

        if(_size == _capacity)
        {
            return;
        }

        T* newArray = new T[_size];
        _capacity = _size;
        for(uint i = 0; i < _size; i++)
        {
            newArray[i] = _array[i];
        }
        delete[] _array;
        _array = newArray;
    }

    /**
     * @brief Outputs an error message to the console.
     * @param msg The error message.
     */
    template <class T>
    void DynamicArray<T>::errorMsg(string msg)
    {
        cout << "An error has occurred. " << msg << "\n";
    }

    /**
     * @brief Frees up any memory the DynamicArray used.
     */
    template <class T>
    DynamicArray<T>::~DynamicArray()
    {
        if(_array == NULL)
        {
            errorMsg("Array is null.");
        }
        else
        {
            delete[] _array;
			_array = NULL;
        }
    }
}

namespace std
{
    /**
     * @brief The to_string function is crap, and doesn't have a to_string(str). This
     * is very bad practice, but is needed for templates to function properly without
     * includes.
     * @param str The string to be converted/returned.
     * @returns Returns the string passed.
     */
    string to_string(string str)
    {
        return str;
    }
}

#endif /* DYNAMICARRAY_H_ */
