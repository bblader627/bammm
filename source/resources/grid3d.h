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
 * Grid3d header file.
 *
 * Last Modified: Alvaro Home
 *
 */
#ifndef GRID3D_H_
#define GRID3D_H_

#include <iostream>
#include "dynamicarray.h"
#include "vector3d.h"
using namespace std;

#ifndef NULL
#define NULL (void *)0
#endif

namespace bammm
{

	template<typename T> class Grid3d
	{
		private:
			DynamicArray<T> *grid;
			int width;
			int length;
			int height;

		public:
			Grid3d<T>();
			Grid3d<T>(int w, int l, int h);
			~Grid3d<T>();
			/*
			 access
			 @Pre-Condition- takes in x,y,z  point system ( a vector)
			 @Post-Condition- will return an array that represents the surrounding point
			 */
			DynamicArray<T>* access(Vector3D *vect);
			/*
			 insert
			 @Pre-Condition- Takes a vector and and object to insert
			 @Post-Condition- Inserts object into the grid space
			 */
			void insert(Vector3D *vect, T &obj);
			/*
			 remove
			 @Pre-Condition- Takes in xyz coordinate (a vector)
			 @Post-Condition- Removes object specified by the coordinates
			 */
			void remove(Vector3D *vect);

	};

	//Creates an grid
	template<class T>
	Grid3d<T>::Grid3d()
	{
		width = 0;
		length = 0;
		height = 0;
		grid = new DynamicArray<T>();
	}
	//creates a Grid with  size
	template<class T>
	Grid3d<T>::Grid3d(int w, int l, int h)
	{
		width = w;
		length = l;
		height = h;
		grid = new DynamicArray<T>(width * length * height);
	}

	//destructor
	template<class T>
	Grid3d<T>::~Grid3d()
	{
		delete grid;
	}

	template<class T>
	DynamicArray<T>* Grid3d<T>::access(Vector3D *vect)
	{
		int pos = vect->x() + (vect->y() * width)
				+ (vect->z() * width * height);
		int start = pos - 5;
		int end = pos + 5;
		int i;
		DynamicArray<T> *space = new DynamicArray<T>(end + start + end);
		if (start < 0)
		{
			start = 0;
		}
		if (end > grid->getCapacity())
		{
			end = grid->getSize() - 1;
		}
		for (i = start; i <= end; i++)
		{
			space->add(grid->get(i));
		}
		return space;
	}

	template<class T>
	void Grid3d<T>::insert(Vector3D *vect, T &obj)
	{
		int pos = vect->x() + (vect->y() * width)
				+ (vect->z() * width * height);
		grid->insert(pos, obj);
	}

	template<class T>
	void Grid3d<T>::remove(Vector3D *vect)
	{
		int pos = vect->x() + (vect->y() * width)
				+ (vect->z() * width * height);
		grid->erase(pos);
	}
}

#endif
