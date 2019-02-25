//
//  Database.cpp
//  database1
//
//  Created by Daniel Saucedo on 2/23/19.
//  Copyright © 2019 Daniel Saucedo. All rights reserved.
//

#include "Database.h"

namespace Database {
    // MyDatabase functions
    void MyDataBase::add_table(Table *table, char *table_name){
        DB.insert(make_pair(table_name,table));
    }
    
    void MyDataBase::drop_table(char* table_name) {
        DB.erase(table_name);
    }
    
    vector<string> MyDataBase::list_table(){
        
        for(auto it = DB.begin(); it != DB.end(); it++) {
            tables.push_back(it->first);
        }
        return tables;
    }
    
    Table* MyDataBase::get_table(char *table_name){
        return DB[table_name];
    }
    
    // query function
    
    //Table MyDataBase::query(std::string SELECT, std::string FROM, std::string WHERE){
    
    //  }
    
    // record functions
    MyRecord::MyRecord(int size) {
        records[size];
    }
    
    int MyRecord::returnSize() {
        return records.size();
    }

    MyRecord::string& operator[](std::size_t idx){ 
        return mVector[idx]; 
    }

    // table functions
    Database::Table::Table (){
        numRow = 0;
        numColumn = 0;
    }
    
    
    void Table::addAttribute(Table* table, std::string attribute){
        // add attribute to attribute list
        attributeList.push_back(attribute);
        // create new column vector
        std::vector<std::string> newColumn;
        
        for (int i = 0; i < table->numRow; i++){
            newColumn.push_back("");
        }
        
        table->tableData.push_back(newColumn);
        table->numColumn++;
    }
    
    
    void Table::deleteAttribute(Table* table, std::string attribute){
        // find the arrubute in the atttrubute list, because location in list is the same as the location of the column in the table
        for (int i = 0; i < attributeList.size(); i++){
            if (attributeList[i] == attribute){
                int location = i;
                table->tableData.erase(table->tableData.begin()+location);
                table->numColumn--;
                
                // remove from attribute list too
                table->attributeList.erase(table->attributeList.begin()+location);
                break;
            }
        }
    }
    
    
    void Table::insertRecord(Table* table, std::vector<std::string> records){
        // add each string in record to it's corresponding column
        for (int i = 0; i < table->numColumn; i++){
            table->tableData[i].push_back(records[i]);
        }
        table->numRow++;
    }
    
    
    std::string Table::getAttributes(Table* tableName){
        std::string attributes;
        // return a comma separted string of the arrtibutes list
        for ( int i = 0; i < tableName->attributeList.size(); i++){
            attributes = attributes + ',' + tableName->attributeList[i];
        }
        
        return attributes;
    }
    
    
    int Table::getSize(Table* tableName){
        return tableName->numRow;
    }
    
    int getRecord(std::string record, std::vector<std::string> records){
        for(int i = 0; i<records.size(); ++i){  //iterate through records to find matching key and return index
            if(records.at(i) == record){
                return i;
            }
        }
        return -1; //-1 to signal not found
    }
    
    void makeKey(Table* tableIn, std::string keyName){
        int index;
        vector<std::string> attrString;
        for ( int i = 0; i < tableName->attributeList.size(); i++){
            if(tableName->attributeList[i] == keyName){
                index = i;
            }
        }
        for(int i = 0; i<numRow; ++i){
            attrString.push_back(tableIn.at(i).at(index));
        }
        std::sort(attrString.begin(), attrString.end());
        auto temp = attrString.end();
        std::unique(attrString.begin(), attrString.end());
        if(attrString.end() != temp){
            //throw error, not a unique attribute
        }
        else{
            //if eligible, can just return
        }
    }
    
    std::vector<std::vector<std::string>> crossJoin(std::vector<std::vector<std::string>> table1, std::vector<std::vector<std::string>> table2){
        int addSize = table2.numRow;
        for (int i = 0; i < addSize; i++){
            insertRecord(table1, table2.at(i));
            numRow++;
        }
        //delete table 2
    }

    Table naturalJoin(Table a, Table b) {
		Table c;
		a_Att = a.getAttributes();
		b_Att = b.getAttributes();
		a_Rec = a.records;
		b_Rec = b.records;
		if (b.key.size() == 0) {
			cout << "no key set";
			return c;
		}
		for (int i = 0; i < b.key.size(); i++) {
			if (find(a_Att.begin(), a_Att.end(), b.key[i]) == a_Att.end()) {
				cout << "key does not perfectly match attributes in other table";
				return c;
			}
		}
		vector<string> temp; //temp vector for key record entries
		for (int i = 0; i < b.key.size(); i++) { //search for key in table A
			for (int j = 0; j < a_Att.size(); j++) {
				if (b.key[i] == a_Att[j]) {
					int recordNumber = a.countRecords(b.key[i]);
					for (int x = 0; x < recordNumber; x++) {
						temp.push_back(a_Rec[x][j]);
					}
				}
			}
		}
		for (int i = 0; i < b.key.size(); i++) { //searching in b and adding to a at correct spot
			for (int j = 0; j < b_Att.size(); j++) {
				if (b.key[i] == b_Att[j]) {
					int recordNumber = b.countRecords(b.key[i]);
					for (int x = 0; x < recordNumber; x++) {
						for (int n = 0; n < temp.size(); n++) {
							if (b_Rec[x][j] == temp[n]) {
								for (int y = 0; y < b_Att.size(); y++) {
									if (y != j) {
										a_Rec[n]push_back(b_Rec[x][y]);
									}
								}
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < b.key.size(); i++) { //add non-key attributes to table
			for (int j = 0; j < b_Att.size(); j++) {
				if (b.key[i] != b_Att[j]) {
					a.addAttribute(b_Att[j]);
				}
			}
		}
		return a;
	}

    
    int count(Table* tableName, std::string attribute){
        int index;
        int counter;
        for (int i = 0; i < attributeList.size(); i++){
            if (attributeList[i] == attribute){
                int index = i;
            }
        }
        for(int i = 0; i < numRow; ++i){
            if(tableName.at(index).at(i) != NULL){
                counter++;
            }
        }
        return counter;
    }
    
    int min(Table* tableName, std::string attribute){
        int index;
        int counter;
        int min = MAX_NUM;
        for (int i = 0; i < attributeList.size(); i++){
            if (attributeList[i] == attribute){
                int index = i;
            }
        }
        for(int i = 0; i < numRow; ++i){
            if(tableName.at(index).at(i) < min){
                min = tableName.at(index).at(i);
            }
        }
        return min;
    }
    
    int max(Table* tableName, std::string attribute){
        int index;
        int counter;
        int max = MIN_NUM;
        for (int i = 0; i < attributeList.size(); i++){
            if (attributeList[i] == attribute){
                int index = i;
            }
        }
        for(int i = 0; i < numRow; ++i){
            if(tableName.at(index).at(i) > max){
                max = tableName.at(index).at(i);
            }
        }
        return max;        
        
    }    
}
