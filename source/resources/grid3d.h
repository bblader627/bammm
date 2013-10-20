/*
 * CS585
 *
 * Team MMA
 * 	Alvaro Home
 * 	Matt Konstantino
 * 	Michael Abramo
 *
 * Description:
 * 	my_grid3d Header File
 *
 * Last Modified: Alvaro Home
 *
 */

#ifndef MY_GRID3D_H_
#define MY_GRID3D_H_


#include <iostream>
#include "dynamicarray.h"
using namespace std;

#ifndef NULL
#define NULL (void *)0
#endif



template<typename T> class Grid3d
{
	private:
		DynamicArray<T> grid;
		int width;
		int length;
		int height;

	public:
		//Constructors
		
		//Creates an grid
		Grid3d<T>()
		{
			width = 0;
			length = 0;
			height = 0;
			grid = new Array<T>();
		}
		//creates a Grid with  size
		Grid3d<T>(int w, int l, int h)
		{
			width = w;
			length = l;
			height = h;
			grid = new Array<T>(width * length * height);
		}

		//destructor
		~Grid3d<T>()
		{
			delete grid;
		}

		//Functions
		/*
			access
			@Pre-Condition- takes in x,y,z  point system
			@Post-Condition- will return the value in that point system
		*/
		T&  access(int x, int y, int z)
		{
			return grid.at(x + (y * width) + (z * width * height) );
		}



		
};
