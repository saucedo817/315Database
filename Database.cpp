//
//  Database.cpp
//  database1
//
//  Created by Daniel Saucedo on 2/23/19.
//  Copyright © 2019 Daniel Saucedo. All rights reserved.
//

#include "Database.h"


bool Database::MyDataBase::add_table(Table *table, char *table_name){
    
    DB.insert(make_pair(table_name,table));
    
    return true;
    
}
