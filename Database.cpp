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
        vector<string> tables;
        
        for(auto it = DB.begin(); it != DB.end(); it++){
            tables.push_back(it->first);
        }
        return tables;
    }
    
    Table* MyDataBase::get_table(char *table_name){
        return DB[table_name];
    }
    
    // query function
    
    Table MyDataBase::query(std::string SELECT, std::string FROM, std::string WHERE){
        
    }
    
    // record functions
    MyRecord::MyRecord(int size);
        records[size];
    }

    int MyRecord::returnSize();
        return records.size();
    }


    
    // table functions
    Table::Table (){
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
    
    

    
    
}
