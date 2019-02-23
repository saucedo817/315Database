//
//  Database.cpp
//  database1
//
//  Created by Daniel Saucedo on 2/23/19.
//  Copyright © 2019 Daniel Saucedo. All rights reserved.
//

#include "Database.h"

namespace Database {
    
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
    
    
}
