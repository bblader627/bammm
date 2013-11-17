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
 * BlackboardRecord cpp file.
 *
 */

#include "BlackboardRecord.h"

namespace bammm
{
	BlackboardRecord::BlackboardRecord(RecordType enumType, string subjectID)
	{
		_enumType = enumType;
		_subjectID = subjectID;
		_targetID = NULL;
		_data = 0.0;
	}

	BlackboardRecord::BlackboardRecord(RecordType enumType, string subjectID,
			string targetID, float data)
	{
		_enumType = enumType;
		_subjectID = subjectID;
		_targetID = targetID;
		_data = data;
	}

	RecordType BlackboardRecord::getRecordType()
	{
		return _enumType;
	}

	string BlackboardRecord::getSubjectID()
	{
		return _subjectID;
	}

	string BlackboardRecord::getTargetID()
	{
		return _targetID;
	}

	float BlackboardRecord::getData()
	{
		return _data;
	}
}
