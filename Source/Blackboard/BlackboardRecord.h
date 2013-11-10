/*
 * BlackboardRecord.h
 *
 *  Created on: Nov 9, 2013
 *      Author: bradley
 */

#ifndef BLACKBOARDRECORD_H_
#define BLACKBOARDRECORD_H_

#include <string>
#include "RecordType.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

using namespace std;

namespace bammm
{
	class BlackboardRecord
	{
		private:
			RecordType _enumType;
			string _subjectID;
			string _targetID;
			float _data;

		public:
			BlackboardRecord(RecordType enumType, string subjectID);
			BlackboardRecord(RecordType enumType, string subjectID,
					string targetID, float _value);
			RecordType getRecordType();
			string getSubjectID();
			string getTargetID();
			float getData();
	};
}

#endif /* BLACKBOARDRECORD_H_ */
