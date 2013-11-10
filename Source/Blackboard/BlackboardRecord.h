/*
 * BlackboardRecord.h
 *
 *  Created on: Nov 9, 2013
 *      Author: bradley
 */

#ifndef BLACKBOARDRECORD_H_
#define BLACKBOARDRECORD_H_

#include <string>

#ifndef NULL
#define NULL ((void*)0)
#endif

using namespace std;
//eh?

namespace bammm
{
	class BlackboardRecord
	{
		private:
			enum EnumRecordType
			{
				Invalid, Attacking
			};
			EnumRecordType _enumType;
			string _subjectID;
			string _targetID;
			float _data;

		public:
			BlackboardRecord(EnumRecordType enumType, string subjectID);
			BlackboardRecord(EnumRecordType enumType, string subjectID,
					string targetID, float _value);
			EnumRecordType getEnumRecordType();
			string getSubjectID();
			string getTargetID();
			float getData();
	};
}

#endif /* BLACKBOARDRECORD_H_ */
