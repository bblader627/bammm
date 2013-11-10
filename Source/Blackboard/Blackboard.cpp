/*
 * Blackboard.cpp
 *
 *  Created on: Nov 9, 2013
 *      Author: bradley
 */

#include "Blackboard.h"

namespace bammm
{
	//constructors/destructors?

	bool Blackboard::addRecord(EnumRecordType type, string subjectID)
	{
		BlackboardRecord record(type, subjectID);
		if (_listOfRecords.add(record))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Blackboard::addRecord(EnumRecordType type, string subjectID,
			string targetID, float data)
	{
		BlackboardRecord record(type, subjectID, targetID, data);
		if (_listOfRecords.add(record))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Blackboard::removeRecord(EnumRecordType type, string subjectID)
	{
		for(int i = 0; i < _listOfRecords.getSize(); i++)
		{
			if ((_listOfRecords.get(i).getEnumRecordType() == type) && (_listOfRecords.get(i).getSubjectID().compare(subjectID) == 0))
			{
				_listOfRecords.remove(i);
				return true;
			}
		}

		return false;
	}

	void Blackboard::removeAllRecords(EnumRecordType type)
	{
		for(int i = 0; i < _listOfRecords.getSize(); i++)
		{
			if(_listOfRecords.get(i).getEnumRecordType() == type)
			{
				_listOfRecords.remove(i);
			}
		}
	}

	int Blackboard::countRecords(EnumRecordType type)
	{
		int count = 0;

		for (int i = 0; i < _listOfRecords.getSize(); i++)
		{
			/* This should just be an int compare, right? */
			if (_listOfRecords.get(i).getEnumRecordType() == type)
			{
				count++;
			}
		}

		return count;
	}

	int Blackboard::countRecords(EnumRecordType type, string targetID)
	{
		int count = 0;

		for (int i = 0; i < _listOfRecords.getSize(); i++)
		{
			/* This should just be an int compare, right? */
			if ((_listOfRecords.get(i).getEnumRecordType() == type)
					&& (_listOfRecords.get(i).getTargetID().compare(targetID)
							== 0))
			{
				count++;
			}
		}

		return count;
	}

	/* Returns the data at the first found type (To get specific data, use the target specifier function*/
	float Blackboard::getData(EnumRecordType type)
	{
		for (int i = 0; i < _listOfRecords.getSize(); i++)
		{
			if (_listOfRecords.get(i).getEnumRecordType() == type)
			{
				return _listOfRecords.get(i).getData();
			}
		}
	}

	float Blackboard::getData(EnumRecordType type, string targetID)
	{
		for (int i = 0; i < _listOfRecords.getSize(); i++)
		{
			if ((_listOfRecords.get(i).getEnumRecordType() == type)
					&& (_listOfRecords.get(i).getTargetID().compare(targetID)
							== 0))
			{
				return _listOfRecords.get(i).getData();
			}
		}
	}
}

