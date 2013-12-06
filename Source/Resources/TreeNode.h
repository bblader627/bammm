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
 * TreeNode  header file.
 *
 */
#ifndef TREENODE_H_
#define TREENODE_H_

#include <string>
#include "Constant.h"

using namespace std;

namespace bammm
{
	template<class T>
	class TreeNode
	{
		private:
			T _value;
			TreeNode* _parentNode;

		public:
			TreeNode();
			TreeNode(T value);
			TreeNode(T value, TreeNode<T>* parent);
			virtual ~TreeNode();

			/**
			 getValue
			 @Pre-Condition- No input
			 @Post-Condition- Returns _value
			 */
			T& getValue();

			/**
			 setValue
			 @Pre-Condition- Takes a T value
			 @Post-Condition- Sets _value to the given value
			 */
			void setValue(T value);

			/**
			 getNextNode
			 @Pre-Condition- No input
			 @Post-Condition- Returns _parentNode
			 */
			TreeNode* getParent();

			/**
			 setParent
			 @Pre-Condition- Takes a TreeNode address node
			 @Post-Condition- Sets _parent to node
			 */
			void setParent(TreeNode& node);
	};

	template<class T>
	TreeNode<T>::TreeNode()
	{
		_value = NULL;
		_parentNode = NULL;
	}

	template<class T>
	TreeNode<T>::TreeNode(T value)
	{
		_value = value;
		_parentNode = NULL;
	}

	template<class T>
	TreeNode<T>::TreeNode(T value, TreeNode<T>* parent)
	{
		_value = value;
		_parentNode = parent;
	}

	template<class T>
	TreeNode<T>::~TreeNode()
	{
	}

	template<class T>
	T& TreeNode<T>::getValue()
	{
		return _value;
	}

	template<class T>
	void TreeNode<T>::setValue(T value)
	{
		_value = value;
	}

	template<class T>
	TreeNode<T>* TreeNode<T>::getParent()
	{
		return _parentNode;
	}

	template<class T>
	void TreeNode<T>::setParent(TreeNode& node)
	{
		_parentNode = &node;
	}
}

#endif
