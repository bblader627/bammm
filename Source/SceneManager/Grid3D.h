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
 * Grid3D header file.
 *
 */

#ifndef GRID3D_H_
#define GRID3D_H_

#include <iostream>
#include "../Resources/DynamicArray.h"
#include "Vector3D.h"
#include "../Resources/Stack.h"
#include "../Actors/Actor.h"

using namespace std;

#ifndef NULL
#define NULL (void *)0
#endif

namespace bammm
{
	template<typename T> class Grid3D
	{
		private:
			DynamicArray<DynamicArray<T>*>* _grid;
			int _width;
			int _length;
			int _height;

			/*
			 convertToPosition
			 @Pre-Condition- Takes a Vector3D vector
			 @Post-Condition- Converts it to an int representing a position in the grid
			 */
			int convertToPosition(Vector3D* vector);

			/*
			 * convertToVector
			 * @Pre-Condition- Takes integer
			 * @Post-Condition- Converts integer to vector3d
			 */
			Vector3D* convertToVector(int position);

			/*
			 * getPath
			 * @Pre-Condition- takes Position of actor to be found, current location, and stack of directions
			 * @Post-Condition- returns stack of directions
			 */
			Stack<Vector3D*>* getPath(Vector3D* actorPos, Vector3D* currentLoc, Stack<Vector3D*>* path);

		public:
			Grid3D();
			Grid3D(int width, int length, int height);
			~Grid3D();

			/*
			 access
			 @Pre-Condition- takes in x,y,z  point system ( a vector)
			 @Post-Condition- will return an array that represents the surrounding point
			 */
			DynamicArray<DynamicArray<T>*>* access(Vector3D *vector,
					int radius);

			/*
			 access
			 @Pre-Condition- Takes in an int x, y, and z
			 @Post-Condition- Returns location of that position on the grid
			 */
			DynamicArray<T>* access(int x, int y, int z);

			/*
			 add
			 @Pre-Condition- Takes in a vector an an object
			 @Post-Condition- The object is added to the grid at the given vector
			 */
			void add(Vector3D* vector, T object);

			/*
			 insert
			 @Pre-Condition- Takes a vector and and object to insert
			 @Post-Condition- Inserts object into the grid space
			 */
			void insert(Vector3D *vector, T object);

			/*
			 remove
			 @Pre-Condition- Takes in xyz coordinate (a vector)
			 @Post-Condition- Removes object specified by the coordinates
			 */
			bool remove(Vector3D *vector, T object);

			/*
			 * getPath
			 * @Pre-Condition- takes current Actor, destination string
			 * @Post-Condition- returns stack of directions
			 */
			Stack<Vector3D*>* getPath(Actor* actor, string destination);

			Vector3D* findInGrid(string target);

			string to_string();
			T getEnemy(Vector3D* loc, T actor);
			DynamicArray<T>* access(int x, int y, int z);
			void add(Vector3D* vect, T add);
			void move(T actor, Vector3D* newLoc);
			void moveTowards(T ordered, Vector3D* loc);
			/*
			toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string that represents the Grid3D
			 */
			string toString();

			/*
			 getEnemy
			 @Pre-Condition- Takes location and an enemy
			 @Post-Condition- Returns that enemy on that location
			 */
			T getEnemy(Vector3D* location, T enemy);

			/*
			 move
			 @Pre-Condition- Takes in an actor and a vector newLocation
			 @Post-Condition- The actor moves to the new location
			 */
			void move(T actor, Vector3D* newLocation);

			/*
			 moveTowards
			 @Pre-Condition- Takes in the object being ordered and a vector newLocation
			 @Post-Condition- The ordered object is told to move towards the new location
			 */
			void moveTowards(T ordered, Vector3D* newLocation);

			/*
			 getX
			 @Pre-Condition- No input
			 @Post-Condition- Returns _x as an int
			 */
			int getX();

			/*
			 getY
			 @Pre-Condition- No input
			 @Post-Condition- Returns _y as an int
			 */
			int getY();

			/*
			 getZ
			 @Pre-Condition- No input
			 @Post-Condition- Returns _z as an int
			 */
			int getZ();
	};

	template<class T>
	Grid3D<T>::Grid3D()
	{
		_width = 0;
		_length = 0;
		_height = 0;
		_grid = new DynamicArray<DynamicArray<T>*>();
	}

	template<class T>
	Grid3D<T>::Grid3D(int width, int length, int height)
	{
		_width = width;
		_length = length;
		_height = height;
		_grid = new DynamicArray<DynamicArray<T>*>(_width * _length * _height);

		int size = _width * _length * _height;
		for (int i = 0; i < size; i++)
		{
			_grid->add(new DynamicArray<T>);
		}
	}

	template<class T>
	Grid3D<T>::~Grid3D()
	{
		int size = _width * _length * _height;
		for (int i = 0; i < size; i++)
		{
			delete _grid->get(i);
		}
		delete _grid;
	}

	template<class T>
	DynamicArray<DynamicArray<T>*>* Grid3D<T>::access(Vector3D *vector,
			int radius)
	{
		int position = convertToPosition(vector);
		int start = position - radius;
		int end = position + radius;
		DynamicArray<DynamicArray<T>*>*space =
				new DynamicArray<DynamicArray<T>*>();
		if (start < 0)
		{
			start = 0;
		}
		if (end > (int) _grid->getCapacity())
		{
			end = _grid->getSize() - 1;
		}
		for (int i = start; i <= end; i++)
		{
			_grid->get(i);
			space->add(_grid->get(i));
		}
		return space;
	}

	template<class T>
	DynamicArray<T>* Grid3D<T>::access(int x, int y, int z)
	{
		int position = x + (y * _width) + (z * _width * _height);
		return _grid->get(position);
	}

	template<class T>
	void Grid3D<T>::add(Vector3D* vector, T object)
	{
		int position = convertToPosition(vector);
		_grid->get(position)->add(object);
		object->setLocation(vector);
	}

	template<class T>
	void Grid3D<T>::insert(Vector3D *vector, T object)
	{
		int position = convertToPosition(vector);
		_grid->get(position)->insert(position, object);
	}

	template<class T>
	bool Grid3D<T>::remove(Vector3D *vector, T object)
	{
		bool deletedValue = access(vector, 0)->get(0)->removeElement(object);
		return deletedValue;
	}

	template<class T>
	Stack<Vector3D*>* Grid3D<T>::getPath(Actor* actor, string destination)
	{
		Vector3D* target = findInGrid(destination);
		if (target==NULL)
		{
			return new Stack<Vector3D*>();
		}

		Vector3D* actorLocation = actor->getLocation();
		return getPath(actorLocation, target, new Stack<Vector3D*>);

	}

	template<class T>
	Stack<Vector3D*>* Grid3D<T>::getPath(Vector3D* actorPos, Vector3D* currentLoc, Stack<Vector3D*>* path)
	{
		/*
		 UP = { 0, 1, 0 };
		 DOWN = { 0, -1, 0 };
		 LEFT = { -1, 0, 0};
		 RIGHT = { 1, 0, 0 };
		 ZERO = { 0, 0, 0 };
		 */

		int actorPosition = convertToPosition(actorPos);
		int currentPosition = convertToPosition(currentLoc);
		if (actorPosition == currentPosition)
		{
			return path;
		}

		if (actorPosition < currentPosition) //Have to go down or left of currentLoc(Favor left)
		{
			for (int xDiff = currentPosition % actorPosition; xDiff > 0; xDiff--)
			{
				DynamicArray<T*>* cell = _grid->get(currentPosition);
				if (cell->_size == 0)
				{
					path->push(new Vector3D(-1, 0, 0));
					currentPosition -= 1;
				}
				else
				{
					//break loop
					xDiff = 0;
					currentLoc = convertToVector(currentPosition);
					return getPath(actorPos, currentLoc, path);

				}
			}
		}
		else if (actorPosition > currentPosition) //Anywhere up or to the right on the same y
		{
			if ((actorPosition - currentPosition) < _width)
			{
				//Same Y; Move RIGHT
				//return path when found
				for (int xDiff = actorPosition - currentPosition; xDiff > 0; xDiff--)
				{
					DynamicArray<T*>* cell = _grid->get(currentPosition);
					if (cell->_size == 0)
					{
						path->push(new Vector3D(1, 0, 0));
						currentPosition += 1;
					}
					else
					{
						xDiff = 0;
						currentLoc = convertToVector(currentPosition);
						return getPath(actorPos, currentLoc, path);
					}

				}
			}
			else
			{
				path->push(new Vector3D(0, 1, 0));
				currentPosition += _width;
				currentLoc = convertToVector(currentPosition);
				return getPath(actorPos, currentLoc, path);
				//move up
				//recursion
			}
		}


	}

	template<class T>
	Vector3D* Grid3D<T>::findInGrid(string target)
	{
		return new Vector3D();
	}

	template <class T>
	string Grid3D<T>::toString()
	{
		string gridString = "";

		for (int i = 0; i < _length; i++)
		{
			for (int i2 = 0; i2 < _width; i2++)
			{
				DynamicArray<T>* atLocation;
				atLocation = access(i, i2, 0);

				if (atLocation->getSize() <= 0)
				{
					gridString = gridString + "- ";
				}
				else
				{
					if (atLocation->get(0)->getName() == "Orc")
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

	template<class T>
	T Grid3D<T>::getEnemy(Vector3D* location, T enemy)
	{
		DynamicArray<DynamicArray<T>*>* tiles = access(location, 0);
		DynamicArray<T>* allOnTile = tiles->get(0);
		int actorEnemyAlliance = enemy->getEnemyAlliance();

		for (int i = 0; i < (int) allOnTile->getSize(); i++)
		{
			Actor* otherActor = allOnTile->get(i);
			if (actorEnemyAlliance == otherActor->getAlliance())
			{
				delete tiles;
				return otherActor;
			}
		}

		delete tiles;
		return NULL;
	}

	template<class T>
	void Grid3D<T>::move(T actor, Vector3D* newLocation)
	{
		remove(actor->getLocation(), actor);
		delete actor->getLocation();
		add(newLocation, actor);
		add(newLocation, actor);

	}

	template<class T>
	void Grid3D<T>::moveTowards(T ordered, Vector3D* newLocation)
	{
		Vector3D* orderedLocation = ordered->getLocation();
		Vector3D* targetLocation = newLocation;

		bool sameX = orderedLocation->x() == targetLocation->x();
		bool sameY = orderedLocation->y() == targetLocation->y();
		bool orderedXLess = orderedLocation->x() < targetLocation->x();
		bool orderedXGreater = orderedLocation->x() > targetLocation->x();
		bool orderedYLess = orderedLocation->y() < targetLocation->y();
		bool orderedYGreater = orderedLocation->y() > targetLocation->y();

		float newX;
		float newY;
		Vector3D * newLocation;

		if (sameX && sameY)
		{
			return;
		}
		else if (sameX)
		{
			if (orderedYLess)
			{
				newY = orderedLocation->y() + 1;
			}
			else
			{
				newY = orderedLocation->y() - 1;
			}

			newX = orderedLocation->x();
		}
		else if (sameY)
		{
			if (orderedXLess)
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
			if (orderedXLess && orderedYLess)
			{
				newX = orderedLocation->x() + 1;
				newY = orderedLocation->y() + 1;
			}
			else if (orderedXLess && orderedYGreater)
			{
				newX = orderedLocation->x() + 1;
				newY = orderedLocation->y() - 1;
			}
			else if (orderedXGreater && orderedYLess)
			{
				newX = orderedLocation->x() - 1;
				newY = orderedLocation->y() + 1;
			}
			else if (orderedXGreater && orderedYGreater)
			{
				newX = orderedLocation->x() - 1;
				newY = orderedLocation->y() - 1;
			}
		}
		newLocation = new Vector3D(newX, newY, 0);
		move(ordered, newLocation);
	}

	template<class T>
	int Grid3D<T>::getX()
	{
		return _width;
	}

	template<class T>
	int Grid3D<T>::getY()
	{
		return _length;
	}

	template<class T>
	int Grid3D<T>::getZ()
	{
		return _height;
	}

	template<class T>
	int Grid3D<T>::convertToPosition(Vector3D* vector)
	{
		return vector->x() + (vector->y() * _width)
				+ (vector->z() * _width * _height);
	}

	template<class T>
	Vector3D* Grid3D<T>::convertToVector(int position)
	{
		int z = position % (_length * _width);
		int y = position % _width;
		int x = position % _length;
		return new Vector3D(x, y, z);
	}
}

#endif
