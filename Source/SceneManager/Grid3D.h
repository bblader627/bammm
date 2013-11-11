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
#include "../Resources/DynamicArray.h"
#include "Vector3D.h"
#include "../Actors/Actor.h"
using namespace std;

#ifndef NULL
#define NULL (void *)0
#endif

namespace bammm
{

	template<typename T> class Grid3d
	{
		private:
			DynamicArray<DynamicArray<T>* >* grid;
			int width;
			int length;
			int height;
			int convertToPos(Vector3D* vect);

		public:
			Grid3d();
			Grid3d(int w, int l, int h);
			~Grid3d();
			/*
			 access
			 @Pre-Condition- takes in x,y,z  point system ( a vector)
			 @Post-Condition- will return an array that represents the surrounding point
			 */
			DynamicArray<DynamicArray<T>* >* access(Vector3D *vect, int radius);

			/*
			 insert
			 @Pre-Condition- Takes a vector and and object to insert
			 @Post-Condition- Inserts object into the grid space
			 */
			void insert(Vector3D *vect, T obj);
			/*
			 remove
			 @Pre-Condition- Takes in xyz coordinate (a vector)
			 @Post-Condition- Removes object specified by the coordinates
			 */
			bool remove(Vector3D *vect, T actor);

			string to_string();
			T getEnemy(Vector3D* loc, T actor);
			DynamicArray<T>* access(int x, int y, int z);
			void add(Vector3D* vect, T add);
			void move(T actor, Vector3D* newLoc);
			void moveTowards(T ordered, Vector3D* loc);
			int getX();
			int getY();
			int getZ();
	};

	//Creates an grid
	template<class T>
	Grid3d<T>::Grid3d()
	{
		width = 0;
		length = 0;
		height = 0;
		grid = new DynamicArray<DynamicArray<T>* >();
	}
	//creates a Grid with  size
	template<class T>
	Grid3d<T>::Grid3d(int w, int l, int h)
	{
		width = w;
		length = l;
		height = h;
		grid = new DynamicArray<DynamicArray<T>* >(width * length * height);

		int size = width * length * height;
		for(int i = 0; i < size; i++)
		{
			grid->add(new DynamicArray<T>);
		}
	}

	//destructor
	template<class T>
	Grid3d<T>::~Grid3d()
	{
		int size = width * length * height;
		for(int i = 0; i < size; i++)
		{
			delete grid->get(i);
		}
		delete grid;
	}

	template<class T>
	DynamicArray<DynamicArray<T>* >* Grid3d<T>::access(Vector3D *vect, int radius)
	{
		int pos = convertToPos(vect);
		int start = pos - radius;
		int end = pos + radius;
		DynamicArray<DynamicArray<T>* >*space = new DynamicArray<DynamicArray<T>* >();
		if (start < 0)
		{
			start = 0;
		}
		if (end > (int)grid->getCapacity())
		{
			end = grid->getSize() - 1;
		}
		for (int i = start; i <= end; i++)
		{
			grid->get(i);
			space->add(grid->get(i));
		}
		return space;
	}

	template <class T>
	DynamicArray<T>* Grid3d<T>::access(int x, int y, int z)
	{
		int pos = x + (y * width) + (z * width * height);
		return grid->get(pos);
	}

	template<class T>
	void Grid3d<T>::insert(Vector3D *vect, T obj)
	{
		int pos = convertToPos(vect);
		grid->get(pos)->insert(pos, obj);
	}

	template <class T>
	int Grid3d<T>::convertToPos(Vector3D* vect)
	{
		return vect->x() + (vect->y() * width)
				+ (vect->z() * width * height);
	}

	template<class T>
	void Grid3d<T>::add(Vector3D* vect, T obj)
	{
		int pos = convertToPos(vect);
		grid->get(pos)->add(obj);
		obj->setLocation(vect);
	}

	template<class T>
	bool Grid3d<T>::remove(Vector3D *vect, T elem)
	{
		int pos = convertToPos(vect);
		bool deletedVal = access(vect, 0)->get(pos)->removeElem(elem);
		return deletedVal;
	}

	template <class T>
	string Grid3d<T>::to_string()
	{
		string gridString = "";

		for(int i = 0; i < length; i++)
		{
			for(int i2 = 0; i2 < width; i2++)
			{
				DynamicArray<T>* atLoc;
				atLoc = access(i, i2, 0);

				if(atLoc->getSize() <= 0)
				{
					gridString = gridString + "- ";
				}
				else
				{
					if(atLoc->get(0)->getName() == "Orc")
					{
						gridString = gridString + "O ";
					}
					else
					{
						gridString = gridString + "X ";
					}
				}
			}
			gridString = gridString + "\n";
		}

		return gridString;	
	}

	template <class T>
	T Grid3d<T>::getEnemy(Vector3D* loc, T actor)
	{
		DynamicArray<DynamicArray<T>* >* tiles = access(loc, 0);
		DynamicArray<T>* allOnTile = tiles->get(0);
		int actorEnemyAlliance = actor->getEnemyAlliance();
	
		for(int i = 0; i < (int) allOnTile->getSize(); i++)
		{
			Actor* otherActor = allOnTile->get(i);
			if(actorEnemyAlliance == otherActor->getAlliance())
			{
				delete tiles;
				return otherActor;
			}
		}

		delete tiles;
		return NULL;
	}

	template <class T>
	void Grid3d<T>::move(T actor, Vector3D* newLoc)
	{
		remove(actor->getLocation(), actor);
		delete actor->getLocation();
		add(newLoc, actor);
	}

	template <class T>
	void Grid3d<T>::moveTowards(T ordered, Vector3D* target)
	{
		Vector3D* orderedLocation = ordered->getLocation();
		Vector3D* targetLocation = target;
		//Vector3D* orderedLocation = ordered->getLocation();
		//Vector3D* targetLocation = target->getLocation();

		//Comparisons
		bool sameX = orderedLocation->x() == targetLocation->x();
		bool sameY = orderedLocation->y() == targetLocation->y();
		bool orderedXLess = orderedLocation->x() < targetLocation->x();
		bool orderedXGreater = orderedLocation->x() > targetLocation->x();
		bool orderedYLess = orderedLocation->y() < targetLocation->y();
		bool orderedYGreater = orderedLocation->y() > targetLocation->y();

		//New Location
		float newX;
		float newY;
		Vector3D* newLoc;
		
		if(sameX && sameY)
		{
			return;
		}
		else if(sameX)
		{
			if(orderedYLess)
			{
				newY = orderedLocation->y() + 1;
			}
			else
			{
				newY = orderedLocation->y() - 1;
			}
			
			newX = orderedLocation->x();
		}
		else if(sameY)
		{
			if(orderedXLess)
			{
				newX = orderedLocation->x() + 1;
			}
			else
			{
				newX = orderedLocation->x() - 1;
			}
			
			newY = orderedLocation->y();
		}
		else
		{
			
			if(orderedXLess && orderedYLess)
			{
				newX = orderedLocation->x() + 1;
				newY = orderedLocation->y() + 1;
			}
			else if(orderedXLess && orderedYGreater)
			{
				newX = orderedLocation->x() + 1;
				newY = orderedLocation->y() - 1;
			}
			else if(orderedXGreater && orderedYLess)
			{
				newX = orderedLocation->x() - 1;
				newY = orderedLocation->y() + 1;
			}
			else if(orderedXGreater && orderedYGreater)
			{
				newX = orderedLocation->x() - 1;
				newY = orderedLocation->y() - 1;
			}
		}
		newLoc = new Vector3D(newX, newY, 0);
		move(ordered, newLoc);
	}
	
	template<class T>
	int Grid3d<T>::getX()
	{
		return width;
	}

	template<class T>
	int Grid3d<T>::getY()
	{
		return length;
	}

	template<class T>
	int Grid3d<T>::getZ()
	{
		return height;
	}
}

#endif
