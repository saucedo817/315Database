#ifndef Database_h
#define Database_h

#include <stdexcept>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


namespace Database {

	class MyRecord {
	private:
		// vector for the record's contents.
		vector<string> records;

	public:

		MyRecord();

		~MyRecord();

		//Constructor creates a record of arbitrary size, and initializes entries to null string :
		MyRecord(int size);

		//Function that returns the size of the record :
		int returnSize();

		//Accessor function that allows access to individual - entries in the record
		std::string& operator[](int);

	};

	class Table {

	private:

		//int numRow;

		//int numColumn;

		//std::vector<std::vector<std::string> > tableData;

		//// Vector for storing attribute names 

		//std::vector<std::string> attributeList;


	public:

		int numRow;

		int numColumn;

		std::vector<std::vector<std::string> > tableData;

		// Vector for storing attribute names 

		std::vector<std::string> attributeList;

		// Constructor of a table. An empty constructor should be allowed, to create a table with no rows or columns.

		Table();

		~Table();

		// A constructor should also be supported that takes a list of attribute names, or use a new structure with a name/type, passed in as arrays, or as some other container, etc.

		Table(std::string attributeList);



		// An add function that takes in a single attribute name, and adds a column to the end of the table with that new attribute. Any entries currently in the table should get NULL for that entry.

		void addAttribute(Table* table, std::string attribute);



		// A delete function that takes an attribute name and deletes it from the table.

		void deleteAttribute(Table* table, std::string attribute);



		// An insert command that takes a record and adds it to the table.

		void insertRecord(Table* table, std::vector<std::string> records);



		// A get attributes command that returns a list of the attributes for that table, in order

		std::string getAttributes(Table* tableName);



		// A get size command that returns the number of records in the table

		int getSize(Table* tableName);



		// An iterator of some sort that can be used to return individual records from the table. There are many ways this can be done.

		// This will use a for loop to iterate through the table and return the location of the wanted record

		int getRecord(std::string record, std::vector<std::string> records);



		// A function that allows a single attribute name to be designated as a key for the table.

		void makeKey(Table* tableIn, std::string keyName);



		// A cross join command that takes two tables as input and produces one table as output.

		std::vector<std::vector<std::string>> crossJoin(std::vector<std::vector<std::string>> table1, std::vector<std::vector<std::string>> table2);



		// A natural join command as follows: Two tables are taken as input, and one is produced as output. The first table should have an attribute name(s) matching the key from the second table. The join should create one entry for each row of the first table, with the additional columns from the matching key in the second table. If the second table does not have a key, or the first table does not have an attribute matching the key name, then an exception can be thrown, or an error returned.

		Table naturalJoin(Table a, Table b);



		// Routines that take a single attribute name as input, and compute the count

		int count(Table* tableName, std::string attribute);



		// Routines that take a single attribute name as input, and compute the min

		int min(Table* tableName, std::string attribute);



		// Routines that take a single attribute name as input, and compute the max

		int max(Table* tableName, std::string attribute);

	};

	class MyDataBase {
	private:
		// maps the table name to a table
		unordered_map <char*, Table*> DB;
	public:

		MyDataBase();

		~MyDataBase();

		void add_table(Table* table, char* table_name);

		void drop_table(char* table_name);

		vector<string> list_table();

		Table* get_table(char *table_name);

		// query function

		Table query(string SELECT, string FROM, string WHERE);

	};
}

#endif /* Database_h */