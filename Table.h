#pragma once

#include <string>
#include <vector>
#include "Record.h"

using namespace std;


namespace Database {


	class Table {
	public:
		Table::Table();
		Table::Table(vector<string> attrNames);

		Table::~Table();

		bool Table::add(string attrName);

		bool Table::del(string attrName);

		bool Table::insert(Record* record);

		vector<string> Table::getAttributes();

		int Table::getSize();

		Record* Table::iterate(int key);

		bool Table::assignKey(string attrName);

		Table* Table::crossJoin(Table* table1, Table* table2);

		Table* Table::naturalJoin(Table* table, Table* table2);
		
		int Table::count(string attrName);

		int Table::min(string attrName);

		int Table::max(string attrName);
	};
}