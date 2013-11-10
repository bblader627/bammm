/*
 * BlackboardRecord.cpp
 *
 *  Created on: Nov 9, 2013
 *      Author: bradley
 */

#include "BlackboardRecord.h"

namespace bammm
{
	BlackboardRecord::BlackboardRecord(EnumRecordType enumType,
			string subjectID)
	{
		_enumType = enumType;
		_subjectID = subjectID;
		_targetID = NULL;
		_data = 0;
	}

	BlackboardRecord::BlackboardRecord(EnumRecordType enumType,
			string subjectID, string targetID, float data)
	{
		_enumType = enumType;
		_subjectID = subjectID;
		_targetID = targetID;
		_data = data;
	}

	// Maybe I shouldn't return EnumRecordType? just the int?
	BlackboardRecord::EnumRecordType BlackboardRecord::getEnumRecordType()
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

