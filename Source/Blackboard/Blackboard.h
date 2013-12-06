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
 * Blackboard header file.
 *
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

			/**
			 addRecord
			 @Pre-Condition- Takes a RecordType type and string subjectID
			 @Post-Condition- Returns true if successfully added
			 */
			bool addRecord(RecordType type, string subjectID);

			/**
			 addRecord
			 @Pre-Condition- Takes a RecordType type and string subjectID, string targetID, and float data
			 @Post-Condition- Returns true if successfully added
			 */
			bool addRecord(RecordType type, string subjectID, string targetID,
					float data);

			/**
			 removeRecord
			 @Pre-Condition- Takes a RecordType type and string subjectID
			 @Post-Condition- Returns true if successfully removed
			 */
			bool removeRecord(RecordType type, string subjectID);

			/**
			 removeAllRecords
			 @Pre-Condition- Takes a RecordType type
			 @Post-Condition- Returns void
			 */
			void removeAllRecords(RecordType type);

			/**
			 countRecords
			 @Pre-Condition- Takes a RecordType type
			 @Post-Condition- Returns the number counted as an int
			 */
			int countRecords(RecordType type);

			/**
			 countRecords
			 @Pre-Condition- Takes a RecordType type and string target
			 @Post-Condition- Returns the number counted as an int
			 */
			int countRecords(RecordType type, string targetID);

			/**
			 getData
			 @Pre-Condition- Takes a RecordType type
			 @Post-Condition- Returns the data as a float
			 */
			float getData(RecordType type);

			/**
			 getData
			 @Pre-Condition- Takes a RecordType type and string targetID
			 @Post-Condition- Returns the data as a float
			 */
			float getData(RecordType type, string targetID);
	};
}

#endif
