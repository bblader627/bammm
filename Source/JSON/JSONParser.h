#include <iostream>
#include <fstream>
#include <string>
#include "../Resources/DynamicArray.h"
#include "../Resources/HashMap.h"

#ifndef NULL
#define NULL (void *) 0
#endif

using namespace std;


namespace bammm
{

	enum JSON_TYPE
	{
		JSON_NULL, JSON_ARRAY, JSON_STRING, JSON_INT, JSON_DOUBLE, JSON_BOOL
	};

	class JSON
	{

		private:

			string name;
			string value;
			JSON_TYPE type;
			JSON *parent;

			HashMap<JSON> children;

		public:

			JSON();
			JSON(string, string, JSON_TYPE, const JSON&);
			~JSON();

			JSON getParent();
			JSON getChild(string);
			string getValue();
			string getName();
			JSON_TYPE getType();

			bool setParent(JSON);
			bool setValue(string);
			bool setValue(bool);
			bool setValue(int);
			bool setValue(double);
			bool setName(string);
			bool setType(JSON_TYPE);

			void addChild(JSON &);
			void addChild(JSON, JSON);

			JSON & operator=(const JSON &);
			string operator[](const string &);

	};

	class JSONParser
	{

		private:

			HashMap<JSON> rootMap;

			void addRoot(JSON&);
			void addChild(JSON&, JSON&);

		public:

			bool parseFile(string);

	};

}
