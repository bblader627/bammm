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
 * Hashnode  header file.
 *
 */
#ifndef HASHNODE_H_
#define HASHNODE_H_

#include <string>

#ifndef NULL
#define NULL ((void*)0)
#endif

using namespace std;

namespace bammm
{
	template<class T>
	class HashNode
	{
		private:
			string _key;
			T _value;
			HashNode* _nextNode;

		public:
			HashNode();
			HashNode(string key, T value);
			virtual ~HashNode();

			/**
			 getKey
			 @Pre-Condition- No input
			 @Post-Condition- Returns _key as a string
			 */
			string getKey();

			/**
			 setKey
			 @Pre-Condition- Takes a string key
			 @Post-Condition- Sets _key as key
			 */
			void setKey(string key);

			/**
			 getValue
			 @Pre-Condition- No input
			 @Post-Condition- Returns _value
			 */
			T getValue();

			/**
			 setValue
			 @Pre-Condition- Takes a T value
			 @Post-Condition- Sets _value to the given value
			 */
			void setValue(T value);

			/**
			 getNextNode
			 @Pre-Condition- No input
			 @Post-Condition- Returns _nextNode
			 */
			HashNode& getNextNode();

			/**
			 setNextNode
			 @Pre-Condition- Takes a HashNode address node
			 @Post-Condition- Sets _nextNode to node
			 */
			void setNextNode(HashNode& node);
	};

	template<class T>
	HashNode<T>::HashNode()
	{
		_key = "";
		_nextNode = NULL;
	}

	template<class T>
	HashNode<T>::HashNode(string key, T value)
	{
		_key = key;
		_value = value;
		_nextNode = NULL;
	}

	template<class T>
	HashNode<T>::~HashNode()
	{
	}

	template<class T>
	string HashNode<T>::getKey()
	{
		return _key;
	}

	template<class T>
	void HashNode<T>::setKey(string key)
	{
		_key = key;
	}

	template<class T>
	T HashNode<T>::getValue()
	{
		return _value;
	}

	template<class T>
	void HashNode<T>::setValue(T value)
	{
		_value = value;
	}

	template<class T>
	HashNode<T>& HashNode<T>::getNextNode()
	{
		return *(_nextNode);
	}

	template<class T>
	void HashNode<T>::setNextNode(HashNode& node)
	{
		_nextNode = &node;
	}
}

#endif
