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
 * Blackboard cpp file.
 *
 */

#include "Blackboard.h"

namespace bammm
{
	Blackboard::Blackboard()
	{
	}

	Blackboard::~Blackboard()
	{
	}

	bool Blackboard::addRecord(RecordType type, string subjectID)
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

	bool Blackboard::addRecord(RecordType type, string subjectID,
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

	bool Blackboard::removeRecord(RecordType type, string subjectID)
	{
		for (int i = 0; i < _listOfRecords.getSize(); i++)
		{
			if ((_listOfRecords.get(i).getRecordType() == type)
					&& (_listOfRecords.get(i).getSubjectID().compare(subjectID)
							== 0))
			{
				_listOfRecords.remove(i);
				return true;
			}
		}

		return false;
	}

	void Blackboard::removeAllRecords(RecordType type)
	{
		for (int i = 0; i < _listOfRecords.getSize(); i++)
		{
			if (_listOfRecords.get(i).getRecordType() == type)
			{
				_listOfRecords.remove(i);
			}
		}
	}

	int Blackboard::countRecords(RecordType type)
	{
		int count = 0;

		for (int i = 0; i < _listOfRecords.getSize(); i++)
		{
			//This should just be an int compare, right?
			if (_listOfRecords.get(i).getRecordType() == type)
			{
				count++;
			}
		}

		return count;
	}

	int Blackboard::countRecords(RecordType type, string targetID)
	{
		int count = 0;

		for (int i = 0; i < _listOfRecords.getSize(); i++)
		{
			//This should just be an int compare, right?
			if ((_listOfRecords.get(i).getRecordType() == type)
					&& (_listOfRecords.get(i).getTargetID().compare(targetID)
							== 0))
			{
				count++;
			}
		}

		return count;
	}

	/* Returns the data at the first found type (To get specific data, use the target specifier function */
	float Blackboard::getData(RecordType type)
	{
		for (int i = 0; i < _listOfRecords.getSize(); i++)
		{
			if (_listOfRecords.get(i).getRecordType() == type)
			{
				return _listOfRecords.get(i).getData();
			}
		}

		return 0.0;
	}

	float Blackboard::getData(RecordType type, string targetID)
	{
		for (int i = 0; i < _listOfRecords.getSize(); i++)
		{
			if ((_listOfRecords.get(i).getRecordType() == type)
					&& (_listOfRecords.get(i).getTargetID().compare(targetID)
							== 0))
			{
				return _listOfRecords.get(i).getData();
			}
		}

		return 0.0;
	}
}
