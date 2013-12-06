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
 * Tree header file.
 *
 */

#ifndef TREE_H_
#define TREE_H_

#include "TreeNode.h"
#include "DynamicArray.h"
#include "Queue.h"
#include <string>
#include <cmath>
#include "Constant.h"

#define DEFAULT_MAPSIZE 1000

using namespace std;

namespace bammm
{
	template<class T>
	class Tree
	{
		private:
			int _numberOfNodes;
			Queue<TreeNode<T>*>* _tree;

		public:
			Tree<T>();
			virtual ~Tree();

			/**
			 getNumerOfNodes
			 @Pre-Condition- No input
			 @Post-Condition- Returns the number of nodes in the map
			 */
			int getNumerOfNodes();

			/**
			 getSize
			 @Pre-Condition- No input
			 @Post-Condition- Returns the size of the map
			 */
			int getSize();

			/**
			 contains
			 @Pre-Condition- Takes a string key
			 @Post-Condition- Returns true if the key is found in the map
			 */
			bool contains(T& value);

			/**
			 add
			 @Pre-Condition- Takes a string key and a T value
			 @Post-Condition- Adds the key value pair as a node to the map and returns true on success
			 */
			bool add(T value, TreeNode<T>* parent);

			/**
			 getNode
			 @Pre-Condition- Takes a string key
			 @Post-Condition- Finds and returns the node corresponding to the given key
			 */
			TreeNode<T>* getNode(T& value);

			/**
			 getValue
			 @Pre-Condition- No input
			 @Post-Condition- Returns a DynamicArray containing all the values in the map
			 */
			T& getValue(T& value);

			/**
			 get
			 @Pre-Condition- No input
			 @Post-Condition- Returns a TreeNode
			 */
			TreeNode<T>* get();

			/**
			 isEmpty
			 @Pre-Condition- No input
			 @Post-Condition- Returns true if empty, false otherwise
			 */
			bool isEmpty();
	};

	template<class T>
	Tree<T>::Tree()
	{
		_tree = new Queue<TreeNode<T>*>();
		_numberOfNodes = 0;

	}

	template<class T>
	Tree<T>::~Tree()
	{
		delete[] _tree;
	}

	template<class T>
	int Tree<T>::getSize()
	{
		return _tree->getSize();
	}

	template<class T>
	bool Tree<T>::contains(T& value)
	{
		return false;
	}

	template<class T>
	bool Tree<T>::add(T value, TreeNode<T>* parent)
	{
		TreeNode<T>* node;
		node = new TreeNode<T>(value, parent);

		_tree->add(node);

		_numberOfNodes++;
		return true;
	}

	template<class T>
	TreeNode<T>* Tree<T>::get()
	{
		return _tree->remove();
	}

	template<class T>
	bool Tree<T>::isEmpty()
	{
		return _tree->isEmpty();
	}
}

#endif
