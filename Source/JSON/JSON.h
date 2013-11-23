/*
 * JSON.h
 *
 *  Created on: Nov 19, 2013
 *      Author: michael
 */

#ifndef JSON_H_
#define JSON_H_

#include <string>
#include "../Resources/HashMap.h"

namespace bammm
{
	enum JSON_TYPE
	{
		JSON_NULL,
		JSON_ARRAY,
		JSON_STRING,
		JSON_INT,
		JSON_DOUBLE,
		JSON_BOOL,
		JSON_OBJECT
	};

	class JSON
	{

		protected:

			string _name;
			JSON_TYPE _type;
			JSON *_parent;
			HashMap<JSON*> _children;

		public:

			JSON();
			JSON(string);
			~JSON();

			/*
			 getName
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns the name (key) of this JSON Node
			 */
			string getName();

			/*
			 getType
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns the JSON_TYPE of this JSON Node
			 */
			JSON_TYPE getType();

			/*
			 getParent
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns the parent of this JSON Node
			 */
			JSON * getParent();

			/*
			 sizeOfChildren
			 @Pre-Condition- Takes no argument
			 @Post-Condition- return size of _children
			 */
			int sizeOfChildren();

			/*
			 setName
			 @Pre-Condition-  Takes a string argument
			 @Post-Condition- sets this JSON Nodes name equal to the string argument. Returns void.
			 */
			void setName(string);

			/*
			 setType
			 @Pre-Condition-  Takes a JSON_TYPE argument
			 @Post-Condition- sets this JSON Nodes JSON_TYPE equal to the JSON_TYPE argument. Returns void.
			 */
			void setType(JSON_TYPE);

			void setParent(JSON &);

			void addChild(JSON &);

			/*
			 getIntValue
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns an int that is equal to the value of this JSON Node
			 */
			virtual int getIntValue();

			/*
			 getDoubleValue
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns a double that is equal to the value of this JSON Node
			 */
			virtual double getDoubleValue();

			/*
			 getBoolValue
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns a bool that is equal to the boolean value of this JSON Node
			 */
			virtual bool getBoolValue();

			/*
			 getStringValue
			 @Pre-Condition-  Takes no argument
			 @Post-Condition- returns a string that is equal to the value of this JSON Node
			 */
			virtual string getStringValue();


			JSON * operator[](int index)
			{
				DynamicArray<JSON*>* childrenArray = _children.getAllValues();
				return childrenArray->get(index);
				//return _children.getValue(key);
			}

			JSON* operator[](const string key)
			{
				return _children.getValue(key);
			}

	};

}

#endif /* JSON_H_ */
