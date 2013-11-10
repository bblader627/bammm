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
			Blackboard();
			virtual ~Blackboard();
			bool addRecord(RecordType type, string subjectID);
			bool addRecord(RecordType type, string subjectID, string targetID, float data);
			bool removeRecord(RecordType type, string subjectID);
			void removeAllRecords(RecordType type);
			int countRecords(RecordType type);
			int countRecords(RecordType type, string target);
			float getData(RecordType type);
			float getData(RecordType type, string target);
			//Add functions that replace records?
	};
}


#endif /* BLACKBOARD_H_ */
