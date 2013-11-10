/*
 * Blackboard.h
 *
 *  Created on: Nov 9, 2013
 *      Author: bradley
 */

#ifndef BLACKBOARD_H_
#define BLACKBOARD_H_

#include "BlackboardRecord.h"

namespace bammm
{
	class Blackboard
	{
		private:
			DynamicArray<BlackboardRecord> _listOfRecords;

		public:
			bool addRecord(EnumRecordType type, string subjectID);
			bool addRecord(EnumRecordType type, string subjectID, string targetID, float data);
			bool removeRecord(EnumRecordType type, string subjectID);
			void removeAll(EnumRecordType type);
			int countRecords(EnumRecordType type);
			int countRecords(EnumRecordType type, string target);
			float getData(EnumRecordType type);
			float getData(EnumRecordType type, string target);
			//Add functions that replace records?
	};
}


#endif /* BLACKBOARD_H_ */
