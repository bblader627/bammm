/*
 * CS585
 *
 * Team MMA
 * 	Alvaro Home
 * 	Matt Konstantinou
 * 	Michael Abramo
 *
 * Description:
 * 	Hashmap template header file.
 *
 * Last Modified: Michael Abramo
 *
 */

#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <string>

using namespace std;

template<class Key, class T> class Hashmap
{

private:

	struct Elem
	{
		Key name;
		T value;
		Elem *next;
	};

	static const double LOADFACTOR = 0.75;
	static const int mapsize = 97;
	Elem *mapdata[mapsize];

public:

	/* constructor */

	Hashmap<Key, T>()
	{

		for(int i = 0; i < mapsize; i++)
		{
			mapdata[i] = new Elem;
			mapdata[i]->name = "empty";
			mapdata[i]->next = NULL;
		}
	}

	/* destructor */

	~Hashmap<Key, T>()
	{

	}

	/*
	 * 	hash
	 * 	@Pre-Condition: Takes an argument of type Key.
	 * 	@Post-Condition: Returns the hash value of Key.
	 *
	 */
	int hash(Key key)
	{
		int index;
		int asciisum = 0;

		for(unsigned int i = 0; i < key.length(); i++)
		{
			asciisum += (int) key[i] * 17;
		}

		index = asciisum % mapsize;

		return index;
	}

	/*
	 * 	insert
	 * 	@Pre-Condition:	Takes a key and value as arguments
	 * 	@Post-Condition: places the key/value in an object Elem stored in the hashed index bucket
	 *
	 */
	void insert(Key name, T value)
	{
		int index = hash(name);

		if(mapdata[index]->name == "empty")
		{
			mapdata[index]->name = name;
			mapdata[index]->value = value;
		}
		else
		{
			Elem* nextPos = mapdata[index];
			Elem* item = new Elem;
			item->name = name;
			item->value = value;
			item->next = NULL;

			while(nextPos->next != NULL)
			{
				nextPos = nextPos->next;
			}

			nextPos->next = item;
		}
	}

	/*
	* 	bucketSize
	* 	@Pre-Condition: takes a bucket index
	* 	@Post-Condition: returns how many items are in the bucket
	*
	*/
	int bucketSize(int index)
	{

		int count = 0;

		if(mapdata[index]->name == "empty")
		{
			return count;
		}
		else
		{
			Elem* item = mapdata[index];
			count++;

			while(item->next != NULL)
			{
				item = item->next;
				count++;
			}
		}

		return count;
	}

	/*
	* 	printTable
	* 	@Pre-Condition: no arguments
	* 	@Post-Condition: prints the items in each bucket and print how many are in each bucket.
	*
	*/
	void printTable()
	{

		int count;

		for(int i = 0; i < mapsize; i++)
		{
			count = bucketSize(i);

			if(count == 0)
			{
				cout << "Index: " << i << endl;
				cout << "Has 0 items." << endl;
				continue;
			}

			cout << "Index: " << i << endl;
			cout << mapdata[i]->name << endl;
			cout << mapdata[i]->value << endl;
			cout << count << " items in this bucket" << endl;
		}
	}

	/*
	 * 	printBucket
	 * 	@Pre-Condition:	takes a bucket index
	 * 	@Post-Condition: prints all items in the specified bucket
	 */
	void printBucket(int index)
	{

		Elem* item = mapdata[index];

		if(item->name == "empty")
		{
			cout << "Index: " << index <<  " is empty." << endl;
		}
		else
		{
			cout << "Items in bucket index" << index << endl;

			while(item->name != "empty")
			{
				cout << "Item: " << item->name << endl;
				cout << "Value: " << item->value << endl;
				item = item->next;
			}
		}
	}

	/*
	* 	findValue
	* 	@Pre-Condition: takes a Key argument
	* 	@Post-Condition: returns the value held by the Key argument
	*
	*/
	T findValue(Key name)
	{

		int index = hash(name);
		bool isFound = false;
		T value;

		Elem* item = mapdata[index];

		while(item != NULL)
		{

			if(item->name == name)
			{
				isFound = true;
				value = item->value;
			}

			item = item->next;

		}

		if(isFound == true)
		{
			return value;
		}
		else
		{
			return false;
		}
	}

	/*
	* 	remove
	* 	@Pre-Condition: takes a Key argument
	* 	@Post-Condition: removes the item stored by the Key argument
	*
	*/
	void remove(Key name)
	{

		int index = hash(name);

		Elem* rmItem;
		Elem* Ptr1;
		Elem* Ptr2;

		if(bucketSize(index) == 0)
		{
			cout << name << " was not found in the hash table" << endl;
			return;
		}
		else if(mapdata[index]->name == name && mapdata[index]->next == NULL)
		{
			mapdata[index]->name = "empty";
		}
		else if(mapdata[index]->name == name)
		{
			rmItem = mapdata[index];
			mapdata[index] = mapdata[index]->next;
			delete rmItem;
		}
		else
		{
			Ptr1 = mapdata[index]->next;
			Ptr2 = mapdata[index];

			while(Ptr1 != NULL && Ptr1->name != name)
			{
				Ptr2 = Ptr1;
				Ptr1 = Ptr1->next;
			}

			if(Ptr1 == NULL)
			{
				cout << name << " was not found in the hash table" << endl;
				return;
			}
			else
			{
				rmItem = Ptr1;
				Ptr1 = Ptr1->next;
				Ptr2->next = Ptr1;

				delete rmItem;
			}

		}

		return;
	}

	/*
	* 	tableSize
	* 	@Pre-Condition: takes no argument
	* 	@Post-Condition: returns how many items are in the hash table
	*
	*/
	int tableSize()
	{
		int count = 0;

		for(int i = 0; i < mapsize; i++)
		{
			count += bucketSize(i);
		}

		return count;
	}

	/*
	* 	isEmpty
	* 	@Pre-Condition: takes no arguments
	* 	@Post-Condition: returns True if the hash table holds no items
	*
	*/
	bool isEmpty()
	{
		return tableSize() == 0;
	}

};

#endif
