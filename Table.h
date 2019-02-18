//

//  Tables.hpp

//  Database

//

//  Created by Kassy Guzman on 2/7/19.

//  Copyright © 2019 Kassy Guzman. All rights reserved.

//

/*
 Table:
 Note: Tables only have a name in the database; an individual table will not be named, in general. A table can exist outside the database, but will not have a name or be saved as part of the database save command.
 The table class should support the following:
 Page | 3
 A natural join command as follows: Two tables are taken as input, and one is produced as output. The first table should have an attribute name(s) matching the key from the second table. The join should create one entry for each row of the first table, with the additional columns from the matching key in the second table. If the second table does not have a key, or the first table does not have an attribute matching the key name, then an exception can be thrown, or an error returned.
 Routines that take a single attribute name as input, and compute the following: o Count (counts non-null entries
 only)o Min
 o Max
 Note that there are many ways that some of these commands can be implemented, but the functionality needs to be provided. For example, a table does NOT need to keep records (but might choose to) – it could use a different storage format, but it needs to be able to take in a record and return a record.
 For this application, you can assume that all data types are strings (or character arrays, if you choose).
 No table should have two attributes with the same name.
 */



#ifndef Tables_hpp

#define Tables_hpp



#include <stdio.h>

#include <string>

#include <vector>

class Table {
    
private:
    
    int numRow;
    
    int numColumn;
    
    
    
public:
    
    // Constructor of a table. An empty constructor should be allowed, to create a table with no rows or columns.
    
    Table();
    
    
    
    // A constructor should also be supported that takes a list of attribute names, or use a new structure with a name/type, passed in as arrays, or as some other container, etc.
    
    Table(std::string attributeList);
    
    
    
    // An add function that takes in a single attribute name, and adds a column to the end of the table with that new attribute. Any entries currently in the table should get NULL for that entry.
    
    void addAttribute(std::string attribute);
    
    
    
    // A delete function that takes an attribute name and deletes it from the table.
    
    void deleteAttribute(std::string attribute);
    
    
    
    // An insert command that takes a record and adds it to the table.
    
    void insertRecord(std::string record);
    
    
    
    // A get attributes command that returns a list of the attributes for that table, in order
    
    std::string getAttributes(std::string tableName);
    
    
    
    // A get size command that returns the number of records in the table
    
    int getSize(std::string tableName);
    
    
    
    // An iterator of some sort that can be used to return individual records from the table. There are many ways this can be done.
    
    // This will use a for loop to iterate through the table and return the location of the wanted record
    
    int getRecord(std::string record);
    
    
    
    // A function that allows a single attribute name to be designated as a key for the table.
    
    void makeKey(std::string keyName);
    
    
    
    // A cross join command that takes two tables as input and produces one table as output.
    
    std::vector<std::vector<std::string>> crossJoin(std::vector<std::vector<std::string>> table1, std::vector<std::vector<std::string>> table2);
    
    
    
    // A natural join command as follows: Two tables are taken as input, and one is produced as output. The first table should have an attribute name(s) matching the key from the second table. The join should create one entry for each row of the first table, with the additional columns from the matching key in the second table. If the second table does not have a key, or the first table does not have an attribute matching the key name, then an exception can be thrown, or an error returned.
    
    std::vector<std::vector<std::string>> naturalJoin(std::vector<std::vector<std::string>> table1, std::vector<std::vector<std::string>> table2);
    
    
    
    // Routines that take a single attribute name as input, and compute the count
    
    int count(std::string attribute);
    
    
    
    // Routines that take a single attribute name as input, and compute the min
    
    int min(std::string attribute);
    
    
    
    // Routines that take a single attribute name as input, and compute the max
    
    int max(std::string attribute);
    
};



#endif /* Tables_hpp */
