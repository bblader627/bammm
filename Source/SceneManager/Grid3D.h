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
#include "../Resources/Constant.h"
#include "../Resources/Color.h"
#include "../Resources/Tree.h"
#include "../Resources/TreeNode.h"

using namespace std;

namespace bammm
{
	template<typename T> class Grid3D
	{
		private:
			DynamicArray<DynamicArray<T>*>* _grid;
			int _width;
			int _length;
			int _height;

			//Directions


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
			 * @Post-Condition- returns true if path is found
			 */
			bool getPath(Vector3D* actorPos, Vector3D* currentLoc,
					Stack<Vector3D*>* path, DynamicArray<DynamicArray<bool>*>* visited);

		public:
			Vector3D* UP;
			Vector3D* DOWN;
			Vector3D* LEFT;
			Vector3D* RIGHT;
			Vector3D* ZERO;

			Grid3D();
			Grid3D(int width, int length, int height);
			~Grid3D();

			/*
			 setupDirections
			 @Pre-Condition- No input
			 @Post-Condition- Sets up directions
			 */
			void setupDirections();

			/*
			 access
			 @Pre-Condition- Takes in x,y,z  point system ( a vector)
			 @Post-Condition- Will return an array that represents the surrounding point
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

			/*
			 findInGrid
			 @Pre-Condition- Takes a string target
			 @Post-Condition- Returns the vector3D location of the target's position in the grid
			 */
			Vector3D* findInGrid(string target);

			/*
			 toString
			 @Pre-Condition- No input
			 @Post-Condition- Returns a string that represents the Grid3D
			 */
			string toString();

			/*
			 getEnemy
			 @Pre-Condition- Takes location and an actor
			 @Post-Condition- Returns that enemy on that location
			 */
			T getEnemy(Vector3D* location, T unit);

			/*
			 move
			 @Pre-Condition- Takes in an actor and a vector newLocation
			 @Post-Condition- The actor moves to the new location. newLocation will be deleted if the actor cannot move.
			 */
			void move(T actor, Vector3D* newLocation);

			/*
			 moveTowards
			 @Pre-Condition- Takes in the object being ordered and a vector newLocation
			 @Post-Condition- The ordered object is told to move towards the new location
			 */
			void moveTowards(T ordered, Vector3D* newLocation);

			/*
			 isWalkable
			 @Pre-Condition- Takes a location/vector
			 @Post-Condition- A boolean representing if the spot is walkable
			 */
			bool isWalkable(Vector3D location);

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

		setupDirections();

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

		setupDirections();
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
	void Grid3D<T>::setupDirections()
	{
		UP = new Vector3D(-1, 0, 0);
		DOWN = new Vector3D(1, 0, 0);
		LEFT = new Vector3D(0,-1, 0);
		RIGHT = new Vector3D(0, 1, 0);
		ZERO = new Vector3D(0, 0, 0);
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
		Vector3D* actorLocation = actor->getLocation();
		int actorLocInt = convertToPosition(actorLocation);

		cout << actorLocInt << endl;

		DynamicArray<DynamicArray<bool>*>* visited = new DynamicArray<DynamicArray<bool>*>();

		cout << "populating visisted array" << endl;
		for (uint i = 0; i < (uint)_width; i++)
		{
			visited->add(new DynamicArray<bool>());
			for (uint j= 0; j < (uint)_length; j++)
			{
				visited->get(i)->add(false);
			}
		}

		Tree<Vector3D*>* mapTree = new Tree<Vector3D*>();
		TreeNode<Vector3D*>* rootNode = new TreeNode<Vector3D*>(target);
		mapTree->add(&target, rootNode);
		TreeNode<Vector3D*>* current;

		uint i = 0;
		while (i < (uint)mapTree->getSize())

		{
			current = mapTree->getAt(i);
			Vector3D* currentLocation = current->getValue();
			int currentLocInt = convertToPosition(currentLocation);
			visited->get(currentLocation->getX())->get(currentLocation->getY()) = true;

			cout << currentLocation->getX() << ", " << currentLocation->getY() << endl;

			if (currentLocInt == actorLocInt)
			{
				cout << "FOUND!!" << endl;
				break;
			}

			//Start adding if possible
			Vector3D newLoc1;
			bool hasVisited;

			newLoc1 = *currentLocation + *UP;
			if (isWalkable(newLoc1))
			{
				Vector3D* newLocation = new Vector3D(newLoc1.getX(), newLoc1.getY(), newLoc1.getZ());
				hasVisited = visited->get(newLocation->getX())->get(newLocation->getY());
				if (!hasVisited)
				{
					//cout << "===Goign up at at " << newLocation->getX() << ", " << newLocation->getY() << endl;
					cout << "Adding " << newLocation->getX() << ", " << newLocation->getY() << endl;
					//visited->get(newLocation->getX())->get(newLocation->getY()) = true;
					mapTree->add(&newLocation, current);
				}
			}
			else
			{
				//cout << "~~~Can't go up at " << newLoc.getX() << ", " << newLoc.getY() << endl;
			}

			Vector3D newLoc2 = *currentLocation + *RIGHT;
			if (isWalkable(newLoc2))
			{
				Vector3D* newLocation = new Vector3D(newLoc2.getX(), newLoc2.getY(), newLoc2.getZ());
				hasVisited = visited->get(newLocation->getX())->get(newLocation->getY());
				if (!hasVisited)
				{
					cout << "Adding " << newLocation->getX() << ", " << newLocation->getY() << endl;
					//visited->get(newLocation->getX())->get(newLocation->getY()) = true;
					mapTree->add(&newLocation, current);
				}
			}
			else
			{
				//cout << "~~~Can't go right at " << newLoc.getX() << ", " << newLoc.getY() << endl;
			}

			Vector3D newLoc3 = *currentLocation + *DOWN;
			if (isWalkable(newLoc3))
			{
				Vector3D* newLocation = new Vector3D(newLoc3.getX(), newLoc3.getY(), newLoc3.getZ());
				hasVisited = visited->get(newLocation->getX())->get(newLocation->getY());
				if (!hasVisited)
				{
					cout << "Adding " << newLocation->getX() << ", " << newLocation->getY() << endl;
					//visited->get(newLocation->getX())->get(newLocation->getY()) = true;
					mapTree->add(&newLocation, current);
				}
			}
			else
			{
				//cout << "~~~Can't go down at " << newLoc.getX() << ", " << newLoc.getY() << endl;
			}

			Vector3D newLoc4 = *currentLocation + *LEFT;
			if (isWalkable(newLoc4))
			{
				Vector3D* newLocation = new Vector3D(newLoc4.getX(), newLoc4.getY(), newLoc4.getZ());
				hasVisited = visited->get(newLocation->getX())->get(newLocation->getY());
				if (!hasVisited)
				{
					cout << "Adding " << newLocation->getX() << ", " << newLocation->getY() << endl;
					//visited->get(newLocation->getX())->get(newLocation->getY()) = true;
					mapTree->add(&newLocation, current);
				}
			}
			else
			{
				//cout << "~~~Can't go left at " << newLoc.getX() << ", " << newLoc.getY() << endl;
			}
			i++;
		}

		for (uint i = 0; i < (uint)_width; i++)
		{
			visited->add(new DynamicArray<bool>());
			for (uint j= 0; j < (uint)_length; j++)
			{
					cout << visited->get(i)->get(j);
			}
			cout << endl;
		}


/*
		cout << "==============IN getPath================" << endl;
		Vector3D* target = findInGrid(destination);
		cout << target->getX() << ", " << target->getY() << ", " << target->getZ() << endl;

		if (target == NULL)
		{
			return new Stack<Vector3D*>();
		}


		Vector3D* actorLocation = actor->getLocation();
		Stack<Vector3D*>* path = new Stack<Vector3D*>();

		cout << "Actor: " << actorLocation->getX() << ", " << actorLocation->getY() << ", " << actorLocation->getZ() << endl;
		cout << destination << ": " << target->getX() << ", " << target->getY() << ", " << target->getZ() << endl;

		DynamicArray<DynamicArray<bool>*>* visited = new DynamicArray<DynamicArray<bool>*>();

		cout << "populating visisted array" << endl;
		for (uint i = 0; i < _width; i++)
		{
			visited->add(new DynamicArray<bool>());
			for (uint j= 0; j < _length; j++)
			{
				visited->get(i)->add(false);
			}
		}

		if (getPath(actorLocation, target, path, visited))
		{
			return path;
		}

		else
		{
			cout << "Path not found" << "\n";
			return new Stack<Vector3D*>*;
		}

		return path;
		*/
		return new Stack<Vector3D*>();
	}

	template<class T>
	bool Grid3D<T>::getPath(Vector3D* actorPos, Vector3D* currentPos,
			Stack<Vector3D*>* path, DynamicArray<DynamicArray<bool>*>* visited)
	{
		//Base Case
		int actorPosInt = convertToPosition(actorPos);
		int currentPosInt = convertToPosition(currentPos);

		if (actorPosInt == currentPosInt)
		{
			cout << "SUCCESS" << endl;
			return true;
		}


		//Collision testing
		if (_grid->get(currentPosInt)->getSize() > 0)
		{
			Actor* actor = static_cast<Actor*>(_grid->get(currentPosInt)->get(0));
			if (actor->getCollision())
			{
				cout << "pop" << endl;
				path->pop();
				return false;
			}
		}

		//Out of Bounds
		if (currentPosInt > (_length * _width))
		{
			cout << "pop" << endl;
			path->pop();
			return false;
		}

		Vector3D newLoc;

		//Begin Recursion
		if (!(currentPosInt % _width == 0))
		{

			newLoc = *currentPos + *UP;
			if (newLoc.getY() == currentPos->getY() &&			//If no overflow
					visited->get(newLoc.getX())->get(newLoc.getY()) == 0)	//And if hasn't been visited
			{
				cout << "Move up" << endl;

				path->push(DOWN);
				visited->get(newLoc.getX())->get(newLoc.getY()) = true;
				if (getPath(actorPos, &newLoc, path, visited))
				{
					return true;
				}

			}
		}

		if (currentPosInt > _width)
		{
			newLoc = *currentPos + *LEFT;
			if (visited->get(newLoc.getX())->get(newLoc.getY()) == 0)	//And if hasn't been visited
			{
				cout << "Move Left" << endl;

				path->push(RIGHT);
				visited->get(newLoc.getX())->get(newLoc.getY()) = true;
				if (getPath(actorPos, &newLoc, path, visited))
				{
					return true;
				}

			}
		}

		if (currentPosInt < (_length * _width)-_length)
		{
			newLoc = *currentPos + *RIGHT;
			if (visited->get(newLoc.getX())->get(newLoc.getY()) == false)	//And if hasn't been visited
			{
				cout << "Move Right" << endl;

				path->push(LEFT);
				visited->get(newLoc.getX())->get(newLoc.getY()) = true;
				if (getPath(actorPos, &newLoc, path, visited))
				{
					return true;
				}

			}
		}
		newLoc = *currentPos + *DOWN;
		if (newLoc.getY() == currentPos->getY() &&			//If no overflow
						visited->get(newLoc.getX())->get(newLoc.getY()) == false)	//And if hasn't been visited
		{
			cout << "Move Down" << endl;

			path->push(UP);
			visited->get(newLoc.getX())->get(newLoc.getY()) = true;
			if (getPath(actorPos, &newLoc, path, visited))
			{
				return true;
			}

		}

		cout << "END PATHFINDING" << endl;
		return false;
	}

	template<class T>
	Vector3D* Grid3D<T>::findInGrid(string target)
	{
		for (uint gridIndex = 0; gridIndex < _grid->getSize(); gridIndex++)
		{
			DynamicArray<T>* cell = _grid->get(gridIndex);
			for (uint cellIndex = 0; cellIndex < cell->getSize(); cellIndex++)
			{
				T actor = cell->get(cellIndex);
				if (actor->toString() == target)
				{
					return convertToVector(gridIndex);
				}
			}
		}
		return NULL;
	}

	template<class T>
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
					gridString = gridString + Color::colorText(". ", "green");
				}
				else
				{
					int size = atLocation->getSize() - 1;
					string symbol = atLocation->get(size)->getSymbol();
					string color = atLocation->get(size)->getColor();
					gridString = gridString + Color::colorText(symbol, color)
							+ " ";
				}
			}
			gridString = gridString + "\n";
		}

		return gridString;
	}

	template<class T>
	T Grid3D<T>::getEnemy(Vector3D* location, T unit)
	{
		DynamicArray<DynamicArray<T>*>* tiles = access(location, 0);
		DynamicArray<T>* allOnTile = tiles->get(0);
		int actorEnemyAlliance = unit->getEnemyAlliance();

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
		if (isWalkable(*newLocation))
		{
			remove(actor->getLocation(), actor);
			delete actor->getLocation();
			add(newLocation, actor);
		}
		else
		{
			delete newLocation;
		}
	}

	template<class T>
	bool Grid3D<T>::isWalkable(Vector3D location)
	{
		//Checks for in grid bounds
		if (location.getX() < 0 || location.getY() < 0 || location.getZ() < 0)
		{
			return false;
		}

		//Checks for in grid bounds
		if (location.getX() >= _width || location.getY() >= _length
				|| location.getZ() >= _height)
		{
			return false;
		}

		//int radius = 0;
		DynamicArray<DynamicArray<T>*>* tiles = access(&location, 0);
		DynamicArray<T>* allOnTile = tiles->get(0);
		int size = allOnTile->getSize();
		for (int i = 0; i < size; i++)
		{
			if (allOnTile->get(i)->getCollision() == 1)
			{
				return false;
			}
		}

		return true;
	}

	template<class T>
	void Grid3D<T>::moveTowards(T ordered, Vector3D* newLocation)
	{
		Vector3D* orderedLocation = ordered->getLocation();
		Vector3D* targetLocation = newLocation;

		bool sameX = orderedLocation->getX() == targetLocation->getX();
		bool sameY = orderedLocation->getY() == targetLocation->getY();
		bool orderedXLess = orderedLocation->getX() < targetLocation->getX();
		bool orderedXGreater = orderedLocation->getX() > targetLocation->getX();
		bool orderedYLess = orderedLocation->getY() < targetLocation->getY();
		bool orderedYGreater = orderedLocation->getY() > targetLocation->getY();

		float newX;
		float newY;

		if (sameX && sameY)
		{
			return;
		}
		else if (sameX)
		{
			if (orderedYLess)
			{
				newY = orderedLocation->getY() + 1;
			}
			else
			{
				newY = orderedLocation->getY() - 1;
			}

			newX = orderedLocation->getX();
		}
		else if (sameY)
		{
			if (orderedXLess)
			{
				newX = orderedLocation->getX() + 1;
			}
			else
			{
				newX = orderedLocation->getX() - 1;
			}

			newY = orderedLocation->getY();
		}
		else
		{
			if (orderedXLess && orderedYLess)
			{
				newX = orderedLocation->getX() + 1;
				newY = orderedLocation->getY() + 1;
			}
			else if (orderedXLess && orderedYGreater)
			{
				newX = orderedLocation->getX() + 1;
				newY = orderedLocation->getY() - 1;
			}
			else if (orderedXGreater && orderedYLess)
			{
				newX = orderedLocation->getX() - 1;
				newY = orderedLocation->getY() + 1;
			}
			else if (orderedXGreater && orderedYGreater)
			{
				newX = orderedLocation->getX() - 1;
				newY = orderedLocation->getY() - 1;
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
		return vector->getX() + (vector->getY() * _width)
				+ (vector->getZ() * _width * _height);
	}

	template<class T>
	Vector3D* Grid3D<T>::convertToVector(int position)
	{
		int z = (position - (position % (_length * _width)))/(_length * _width);
		int y = position / _length;
		int x = position % _length;
		return new Vector3D(x, y, z);
	}
}

#endif
