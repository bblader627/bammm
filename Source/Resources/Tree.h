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
			//TreeNode<T>** tree;
			DynamicArray<TreeNode<T>*>* tree;

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
			bool add(T* value, TreeNode<T>* parent);

			/**
			 remove
			 @Pre-Condition- Takes a string key
			 @Post-Condition- Remove the node that corresponds to the given key and returns true on success
			 */
			bool remove(T& value);

			/**
			 removeAll
			 @Pre-Condition- No input
			 @Post-Condition- Removes all the nodes in the map
			 */
			void removeAll();

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

			TreeNode<T>* getAt(int index);

			T getValueAt(int index);
	};

	template<class T>
	Tree<T>::Tree()
	{
		tree = new DynamicArray<TreeNode<T>*>();
		_numberOfNodes = 0;

	}

	template<class T>
	Tree<T>::~Tree()
	{
		removeAll();
		delete[] tree;
	}

	template<class T>
	int Tree<T>::getSize()
	{
			return _numberOfNodes;
	}

	template<class T>
	bool Tree<T>::contains(T& value)
	{
		return false;
	}

	template<class T>
	bool Tree<T>::add(T* value, TreeNode<T>* parent)
	{
		TreeNode<T>* node;
		node = new TreeNode<T>(*value, *parent);

		tree->add(node);

		_numberOfNodes++;
		return true;
	}

	template<class T>
	bool Tree<T>::remove(T& value)
	{
		for (int i = 0; i < tree->getSize(); i++)
		{
			if (tree->get(i) == value)
			{
				tree->remove(i);
				_numberOfNodes--;
				return true;
			}
		}
		return false;
	}

	template<class T>
	void Tree<T>::removeAll()
	{
		if (_numberOfNodes != 0)
		{
			for (int i = tree->getSize()-1; i >= 0; i++)
			{
				tree->remove(i);
				_numberOfNodes--;
			}
		}
	}

	template<class T>
	T& Tree<T>::getValue(T& value)
	{
		for (int i = 0; i < tree->getSize(); i++)
		{
			if (tree->get(i) == value)
			{
				return tree->get(i);
			}
		}

		T *ret = NULL;
		return *ret;
	}

	template<class T>
	TreeNode<T>* Tree<T>::getNode(T& value)
	{
		return NULL;
	}

	template<class T>
	TreeNode<T>* Tree<T>::getAt(int index)
	{
		if ((uint)index < tree->getSize())
		{
			return tree->get(index);
		}
		cout << "RETURNING NULL" << endl;
		return NULL;
	}

	template<class T>
	T Tree<T>::getValueAt(int index)
	{
		return getAt(index)->getValue();
	}


}

#endif
