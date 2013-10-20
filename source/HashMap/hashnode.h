/**
 * @file hashnode.h
 * @class HashNode
 * @brief A class for storying the key and value pairs for our hash table.
 * @author: Bradley Crusco
 * @version 1.0 10/13/13
 */

#ifndef HASHNODE_H_
#define HASHNODE_H_

/*
 * TODO: is "using namespace std" a candidate for removal?
 */
using namespace std;

#ifndef NULL
#define NULL ((void*)0)
#endif

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
			string getKey();
			void setKey(string key);
			T getValue();
			void setValue(T value);
			HashNode& getNextNode();
			void setNextNode(HashNode& node);
	};

	/**
	 * HashNode<T>::HashNode()
	 * @brief Empty constructor for HashNode(). Sets _key to empty string and _nextNode to NULL.
	 */
	template<class T>
	HashNode<T>::HashNode()
	{
		_key = "";
		_nextNode = NULL;
	}

	/**
	 * HashNode<T>::HashNode(string key, T value)
	 * @brief Constructor for HashNode with arguments key and value. Sets each member function accordingly.
	 * @param key Key for this value.
	 * @param value Value being stored in the hash.
	 */
	template<class T>
	HashNode<T>::HashNode(string key, T value)
	{
		_key = key;
		_value = value;
		_nextNode = NULL;
	}

	/**
	 * HashNode<T>::~HashNode()
	 * @brief Default destructor for a HashNode.
	 */
	template<class T>
	HashNode<T>::~HashNode()
	{
	}

	/**
	 * HashNode<T>::getKey()
	 * @brief Returns the key stored in this HashNode.
	 * @return string
	 */
	template<class T>
	string HashNode<T>::getKey()
	{
		return _key;
	}

	/*
	 * HashNode<T>::setKey(string key)
	 * @brief Sets _key to the argument key.
	 * @param key The key to assign to the member.
	 */
	template<class T>
	void HashNode<T>::setKey(string key)
	{
		_key = key;
	}

	/**
	 * HashNode<T>::getValue()
	 * @brief Returns the value stored in this HashNode.
	 * @return T
	 */
	template<class T>
	T HashNode<T>::getValue()
	{
		return _value;
	}

	/**
	 * HashNode<T>::setValue(T value)
	 * @brief Sets _value to the argument value.
	 * @param value The value to assign to the member.
	 */
	template<class T>
	void HashNode<T>::setValue(T value)
	{
		_value = value;
	}

	/**
	 * HashNode<T>::getNextNode()
	 * @brief Returns the address of _nextNode.
	 * @return HashNode<T>&
	 */
	template<class T>
	HashNode<T>& HashNode<T>::getNextNode()
	{
		return *(_nextNode);
	}

	/**
	 * HashNode<T>::setNextNode(HashNode& node)
	 * @brief Sets _nextNode to the argument node.
	 * @param node The node to assign to the member.
	 */
	template<class T>
	void HashNode<T>::setNextNode(HashNode& node)
	{
		_nextNode = &node;
	}
}

#endif /* HASHNODE_H_ */
