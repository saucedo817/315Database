#pragma once


#include <string>
#include <vector>

#include "Table.h"

using namespace std;

namespace Database {
	class  MyDatabase
	{
	public:
		MyDatabase::MyDatabase();

		MyDatabase::~MyDatabase();

		bool MyDatabase::addTable(string name, Table* table);

		bool MyDatabase::dropTable(string name);

		vector<string> MyDatabase::listTables();

		vector<Table> MyDatabase::getTables();

		Table* MyDatabase::query(string select, string where, string from);

	};
}