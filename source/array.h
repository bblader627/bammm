/*
 * CS585
 *
 * Team MMA
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *
 * Description:
 * 	Array template header file.
 *
 * Last Modified: Michael Abramo
 *
 */


#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <cstring>
#include <cassert>

#ifndef NULL
#define NULL (void *)0
#endif

using namespace std;

template<typename T> class Array
{

private:

	int buffersize, //holds current size
		buffercapacity; //holds current capacity
	T * buffer;

public:

	/*constructors */

	//default constructor reserves array capacity of 1 for simplicity
	Array<T>()
	{
		buffersize = 1;
		buffercapacity = 1;
		buffer = new T[1];

	}

	//create an array of the specified length
	Array<T>(int length)
	{
		buffersize = length;
		buffercapacity = length;
		buffer = new T[length];
	}

	//copy constructor -- duplicate another array() object
	Array<T>(const Array<T> & constObj)
	{

		buffersize = constObj.buffersize;
		buffercapacity = constObj.buffercapacity;
		buffer = new T[buffersize];

		for(int i = 0; i < buffersize; i++)
			buffer[i] = constObj.buffer[i];
	}

	//copy values and size of an array into an object array
	Array<T>(const T & constBuff, int constSize)
	{

		buffersize = constSize;
		buffercapacity = constSize;
		buffer = new T[constSize];

		for(int i = 0; i < constSize; i++)
		{
			buffer[i] = constBuff[i];
		}
	}

	//destructor
	~Array<T>()
	{
		delete [] buffer;
	}

	/*
	 * 	[] Operator Override
	 * 	@Pre-Condition: Takes an integer
	 * 	@Post-Condition: Allows return of value stored in the index of buffer in object array
	 * 						using array[] notation
	 *
	 */
	T & operator[](int index)
	{

		assert(index >= 0);

		if(index > capacity())
		{
			resize(capacity() * 2);
			buffersize = index + 1;
			return buffer[index];
		}
		else
		{
			return buffer[index];
		}
	}

	/*
	 *	at
	 * 	@Pre-Condition: Takes an integer
	 * 	@Post-Condition: Returns the value stored in the specified index
	 *
	 */
	T * at(int index)
	{
		return &buffer[index];
	}

	/*
	 *	size
	 * 	@Pre-Condition: Takes no input
	 * 	@Post-Condition: Returns current size of the array
	 *
	 */
	int size()
	{
		return buffersize;
	}

	/*
	 *	capacity
	 * 	@Pre-Condition: Takes no input
	 * 	@Post-Condition: Returns the current capacity of the array
	 *
	 */
	int capacity()
	{
		return buffercapacity;
	}

	/*
	 *	empty
	 * 	@Pre-Condition: Takes no input
	 * 	@Post-Condition: Returns 'true' if there are any values stored in the array; else 'false'
	 *
	 */
	bool isEmpty()
	{
		if(size() > 0)
			return false;
		else
			return true;
	}

	/*
	 *	resize
	 * 	@Pre-Condition: Takes an integer argument
	 * 	@Post-Condition: Increase capacity of array to specified size
	 *
	 */
	void resize(int new_size)
	{
		reserve(new_size); //resize vector[]
		buffersize = new_size;
	}

	/*
	 *	reserve
	 * 	@Pre-Condition: Takes an integer argument
	 * 	@Post-Condition: Increase capacity of array to specified size.
	 *
	 *	create pointer new_vector of capacity new_capacity,
	 *		create fill new_vector[] with items of vector[], and make vector = new_vector
	 */
	void reserve(int new_capacity)
	{
		/*
		 * There is a problem here with some type of allocation that causes
		 * heap's shiftUp an shiftDown to break when running a.out
		 */
		int temp_size;

		if(buffer == NULL)
		{
			buffersize = 0;
			buffercapacity = 0;
		}

		T * new_vector = new T[new_capacity];


		if(new_capacity < buffersize)
		{
			temp_size = new_capacity;
		}
		else
		{
			temp_size = buffersize;
		}

		for(int i = 0; i < temp_size; i++)
		{
			new_vector[i] = buffer[i];
		}

		buffercapacity = new_capacity;
		delete [] buffer;
		buffer = new_vector;
	}

	/*
	 *	pop_back
	 * 	@Pre-Condition: Takes no argument
	 * 	@Post-Condition: Decrease the size of array by one and returns the popped value
	 *
	 */
	T pop_back()
	{
		T return_val = buffer[size() - 1];
		resize(size() - 1);
		return return_val;
	}

	/*
	 *	pop_front
	 * 	@Pre-Condition: Takes no argument
	 * 	@Post-Condition: erases the value at index [0] and returns the erased value
	 *
	 */

	T pop_front()
	{
		T return_val = buffer[0];
		erase(0);
		return return_val;
	}

	/*
	 *	push_back
	 * 	@Pre-Condition: Takes an argument of type T
	 * 	@Post-Condition: Adds the argument value to the end of array
	 *
	 */
	void push_back(const T &new_val)
	{
		resize(size() + 1); //vector size increase by 1
		buffer[size() - 1] = new_val;
	}

	/*
	 *	assign
	 * 	@Pre-Condition: Takes and integer and type T input
	 * 	@Post-Condition: Assigns value of index integer argument to value of type T in array
	 *
	 */
	void assign(int position, const T &new_val)
	{
		buffer[position] = new_val; //assign new_value to vector[specified_index]
	}

	/*
	 *	clear
	 * 	@Pre-Condition: Takes no argument
	 * 	@Post-Condition: Clears all values in array. Clears memory.
	 *
	 */
	void clear() //clear all values of vector
	{
		delete [] buffer;
		buffer = 0;
		buffercapacity = 0;
		buffersize = 0;
	}

	/*
	 *	erase
	 * 	@Pre-Condition: Takes integer argument
	 * 	@Post-Condition: Erases the value at the specified index and moves all values to contiguous indices
	 *
	 */
	void erase(int position)
	{
		buffer[position] = NULL; //erase value at specified index
		do{
			buffer[position] = buffer[position + 1]; //make position = position + 1
			position++;
		}while(position + 1 < size()); //while not at the end of the size of vector[]
		resize(size() - 1); //resize vector to size - 1
	}

	/*
	 *	erase
	 * 	@Pre-Condition: Takes integer and integer arguments
	 * 	@Post-Condition: Erases all values between the two specified indices and moves all remaining values to contiguous indices
	 *
	 */
	void erase(int in, int between)
	{
		int i = in + 1, j = between;
		while(i < between){ //shift to the left (j - i) places
			buffer[i] = buffer[j];
			buffer[j] = NULL;
			i++, j++;
		}
		resize(between);
	}

	/*
	 *	insert
	 * 	@Pre-Condition: Takes integer and type T reference argument
	 * 	@Post-Condition: Inserts value at the specified index and moves all values following forward one index
	 *
	 */
	void insert(int index, const T &new_val)
	{
		resize(size() + 1); //make size = size + 1 to make room for the inserted item
		for(int i = size() - 1; i > index; i--) //start at the end and iterate backwards to copy values
			buffer[i] = buffer[i - 1];
		buffer[index] = new_val; //insert new_value at vector[index]
	}

	/*
	 * swap
	 * @Pre-Condition: Takes two indexes to be swapped
	 * @Post-Condition: Returns true if swap is successful, false if not
	 */
	bool swap(int index1, int index2)
	{
		if (index1 > buffer->length || index2 > buffer->length)
		{
			return false;
		}
		else
		{
			T temp = buffer[index1];
			buffer[index1] = index2;
			buffer[index2] = temp;
			return true;
		}
	}


};

#endif /* ARRAY_H_ */
