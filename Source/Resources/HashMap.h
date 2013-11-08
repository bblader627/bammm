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
 * Hashmap header file.
 *
 * Last Modified: Bradely Crusco
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
			int _mapSize, _numberOfNodes;
			HashNode<T>** hashMap;
			HashNode<T>* find(string key);
			long hashString(string key);

		public:
			HashMap(int size = DEFAULT_MAPSIZE);
			virtual ~HashMap();
			int getNumerOfNodes();
			int getSize();
			bool contains(string key);
			bool add(string key, T value);
			bool remove(string key);
			void removeAll();
			HashNode<T>* getNode(string);
			DynamicArray<string>* getAllKeys();
			DynamicArray<T>* getAllValues();
			T getValue(string key);
			void printBucket(int index);
			void printTable();
	};

	/**
	 * HashMap<T>::HashMap(int size)
	 * @brief Constructor for HashMap, specified by the argument size.
	 * @param size An int used to set the size of the HashMap.
	 */
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

	/**
	 * HashMap<T>::~HashMap()
	 * @brief Destructor for HashMap, removes all nodes in the map, then deletes the hashMap.
	 */
	template<class T>
	HashMap<T>::~HashMap()
	{
		removeAll();
		delete[] hashMap;
	}

	/**
	 * HashMap<T>::getNumerOfNodes()
	 * @brief Returns the number of nodes in the HashMap.
	 * @return int
	 */
	template<class T>
	int HashMap<T>::getNumerOfNodes()
	{
		return _numberOfNodes;
	}

	/**
	 * @brief Returns the size of the HashMap
	 * @return int
	 */
	template<class T>
	int HashMap<T>::getSize()
	{
		return _mapSize;
	}

	/**
	 * HashMap<T>::contains(string key)
	 * @brief Returns true if the given key argument exists in the HashMap, false otherwise.
	 * @param key The key to check if it is present in the HashMap.
	 * @return bool
	 */
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

	/**
	 * HashMap<T>::add(string key, T value)
	 * @brief Takes a key and a value and adds them to the HashMap. Returns true on success, false otherwise.
	 * @param key The key to assign to pair with the value.
	 * @param value The value being stored in the HashMap.
	 * @return bool
	 */
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

	/**
	 * HashMap<T>::remove(string key)
	 * @brief Removes the HashNode from the HashMap that corresponds to the given key. Returns true on success, false otherwise.
	 * @param key The key for the HashNode to be removed.
	 * @return bool
	 */
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

	/**
	 * HashMap<T>::removeAll()
	 * @brief Removes all HashNodes from the HeapMap.
	 */
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

	/**
	 * HashMap<T>::getAllKeys()
	 * @brief Returns the set of all keys in the form of a DynamicArray.
	 * @return DynamicArray<string>&
	 */
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

		return keys;
	}

	/**
	 * HashMap<T>::getAllValues()
	 * @brief Returns the set of all values in the HashMap in the form of a DynamicArray.
	 * @return DynamicArray<T>
	 */
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

	/**
	 * HashMap<T>::getValue(string key)
	 * @brief Returns the value that corresponds to the given key, or a NULL cast as T otherwise.
	 * @param key The key to look up in the HashMap.
	 * @return T
	 */
	template<class T>
	T HashMap<T>::getValue(string key)
	{
		int bucket = hashString(key);
		HashNode<T>* temporary = hashMap[bucket];

		while (temporary != NULL)
		{
			if (key.compare(temporary->getKey()) == 0)
			{
				return temporary->getValue();
			}

			temporary = &(temporary->getNextNode());
		}

		T *ret = NULL;
		return *ret;
		//return (T) NULL;
	}

	/**
	 * HashMap<T>::find(string key)
	 * @brief Finds and returns the HashNode that corresponds to the given key.
	 * @param key The key to lookup in the HashMap.
	 * @return HashNode<T>*
	 */
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

	/**
	 * HashMap<T>::hashString(string key)
	 * @brief The hash function for a given string. Determines where into the HashMap to insert our key value pair.
	 * @param key The key to hash.
	 * @return long
	 */
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

	/*
	 * @brief: Return the entire node that has the corresponding key
	 */
	template<class T>
	HashNode<T>* HashMap<T>::getNode(string key)
	{
		return find(key);
	}

}

#endif /* HASHMAP_H_ */
