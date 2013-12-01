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
 * BlackboardRecord header file.
 *
 */

#ifndef BLACKBOARDRECORD_H_
#define BLACKBOARDRECORD_H_

#include <string>
#include "RecordType.h"
#include "../Resources/Constant.h"

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

			/**
			 getRecordType
			 @Pre-Condition- Takes no arguments
			 @Post-Condition- Returns RecordType _enumType
			 */
			RecordType getRecordType();

			/**
			 getSubjectID
			 @Pre-Condition- Takes no arguments
			 @Post-Condition- Returns subjectID
			 */
			string getSubjectID();

			/**
			 getSubjectID
			 @Pre-Condition- Takes no arguments
			 @Post-Condition- Returns targetID
			 */
			string getTargetID();

			/**
			 getSubjectID
			 @Pre-Condition- Takes no arguments
			 @Post-Condition- Returns _data
			 */
			float getData();
	};
}

#endif
