#pragma once

#include <string>
#include <vector>

using namespace std;

namespace Database {
	class Record {
	public:
		Record::Record();
		Record::Record(int size);

		int Record::getSize();

		string* getEntry(int index);
	};
}