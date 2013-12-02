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
 * HashMap header file.
 *
 */

#ifndef HASHMAP_H_
#define HASHMAP_H_

#include "HashNode.h"
#include "DynamicArray.h"
#include <string>
#include <cmath>

#define DEFAULT_MAPSIZE 1000

using namespace std;

namespace bammm
{
	template<class T>
	class HashMap
	{
		private:
			int _mapSize;
			int _numberOfNodes;
			HashNode<T>** hashMap;

			/**
			 find
			 @Pre-Condition- Takes a string key
			 @Post-Condition- Finds and returns the HashNode with the given key
			 */
			HashNode<T>* find(string key);

			/**
			 hashString
			 @Pre-Condition- Takes a string key
			 @Post-Condition- Calculates a hash string based on the given key and returns it as a long
			 */
			long hashString(string key);

		public:
			HashMap(int size = DEFAULT_MAPSIZE);
			virtual ~HashMap();

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
			bool contains(string key);

			/**
			 add
			 @Pre-Condition- Takes a string key and a T value
			 @Post-Condition- Adds the key value pair as a node to the map and returns true on success
			 */
			bool add(string key, T value);

			/**
			 remove
			 @Pre-Condition- Takes a string key
			 @Post-Condition- Remove the node that corresponds to the given key and returns true on success
			 */
			bool remove(string key);

			/**
			 removeAll
			 @Pre-Condition- No input
			 @Post-Condition- Removes all the nodes in the map
			 */
			void removeAll();

			/**
			 getAllKeys
			 @Pre-Condition- No input
			 @Post-Condition- Returns a DynamicArray containing all the keys in the map
			 */
			DynamicArray<string>* getAllKeys();

			/**
			 getAllValues
			 @Pre-Condition- No input
			 @Post-Condition- Returns a DynamicArray containing all the values in the map
			 */
			DynamicArray<T>* getAllValues();

			/**
			 getNode
			 @Pre-Condition- Takes a string key
			 @Post-Condition- Finds and returns the node corresponding to the given key
			 */
			HashNode<T>* getNode(string key);

			/**
			 getValue
			 @Pre-Condition- No input
			 @Post-Condition- Returns a DynamicArray containing all the values in the map
			 */
			T& getValue(string key);
	};

	template<class T>
	HashMap<T>::HashMap(int size)
	{
		_numberOfNodes = 0;
		_mapSize = size;
		hashMap = new HashNode<T>*[_mapSize];
		for (int i = 0; i < _mapSize; i++)
		{
			hashMap[i] = NULL;
		}
	}

	template<class T>
	HashMap<T>::~HashMap()
	{
		removeAll();
		delete[] hashMap;
	}

	template<class T>
	int HashMap<T>::getNumerOfNodes()
	{
		return _numberOfNodes;
	}

	template<class T>
	int HashMap<T>::getSize()
	{
		return _mapSize;
	}

	template<class T>
	bool HashMap<T>::contains(string key)
	{
		if (find(key) == NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	template<class T>
	bool HashMap<T>::add(string key, T value)
	{
		if (find(key) != NULL)
		{
			return false;
		}

		HashNode<T>* node;
		node = new HashNode<T>(key, value);
		int bucket = hashString(key);
		node->setNextNode(*hashMap[bucket]);
		hashMap[bucket] = node;
		_numberOfNodes++;
		return true;
	}

	template<class T>
	bool HashMap<T>::remove(string key)
	{
		int bucket = hashString(key);
		HashNode<T>* temporary = hashMap[bucket];

		if (temporary == NULL)
		{
			return false;
		}
		else if (key.compare(temporary->getKey()) == 0)
		{
			hashMap[bucket] = &temporary->getNextNode();
			delete temporary;
			_numberOfNodes--;
			return true;
		}
		else
		{
			HashNode<T>* temporaryNext = &temporary->getNextNode();
			while (temporaryNext != NULL)
			{
				if (key.compare(temporaryNext->getKey()) == 0)
				{
					temporary->setNextNode(temporaryNext->getNextNode());
					delete temporaryNext;
					_numberOfNodes--;
					return true;
				}
				temporary = &temporary->getNextNode();
				temporaryNext = &temporaryNext->getNextNode();
			}
		}

		return false;
	}

	template<class T>
	void HashMap<T>::removeAll()
	{
		if (_numberOfNodes != 0)
		{
			DynamicArray<string>* setOfKeys;
			setOfKeys = this->getAllKeys();
			for (int i = 0; i <= _numberOfNodes; i++)
			{
				remove(setOfKeys->get(i));
			}
		}
	}

	template<class T>
	DynamicArray<string>* HashMap<T>::getAllKeys()
	{
		DynamicArray<string>* keys;
		keys = new DynamicArray<string>(_numberOfNodes);
		for (int i = 0; i < _mapSize; i++)
		{
			HashNode<T>* temporary = hashMap[i];
			while (temporary != NULL)
			{
				keys->add(temporary->getKey());
				temporary = &(temporary->getNextNode());
			}
		}
		cout << "Size of keys" << keys->getSize() << endl;
		return keys;
	}

	template<class T>
	DynamicArray<T>* HashMap<T>::getAllValues()
	{
		DynamicArray<T>* values;
		values = new DynamicArray<T>(_numberOfNodes);

		for (int i = 0; i < _mapSize; i++)
		{
			HashNode<T>* temporary = hashMap[i];
			while (temporary != NULL)
			{
				values->add(temporary->getValue());
				temporary = &(temporary->getNextNode());
			}
		}

		return values;
	}

	template<class T>
	T& HashMap<T>::getValue(string key)
	{
		int bucket = hashString(key);
		HashNode<T>* temporary = hashMap[bucket];

		while (temporary != NULL)
		{
			cout << "getKey: " << temporary->getKey() << endl;
			if (key.compare(temporary->getKey()) == 0)
			{
				return temporary->getValue();
			}

			temporary = &(temporary->getNextNode());
		}
		T *ret = NULL;
		return *ret;
	}

	template<class T>
	HashNode<T>* HashMap<T>::find(string key)
	{
		int bucket = hashString(key);
		HashNode<T>* temporary = hashMap[bucket];

		while (temporary != NULL)
		{
			if (key.compare(temporary->getKey()) == 0)
			{
				return temporary;
			}

			temporary = &(temporary->getNextNode());
		}

		return NULL;
	}

	template<class T>
	long HashMap<T>::hashString(string key)
	{
		int keyLength = key.length(), hash = 0;

		for (int i = 0; i < keyLength; i++)
		{
			hash = (hash << 3) ^ key[i];
		}

		return abs(hash % _mapSize);
	}
}

#endif
