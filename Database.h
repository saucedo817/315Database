//

//  Database.hpp

//  Database

//

//  Created by Daniel Saucedo on 2/7/19.

//  Copyright © 2019 Daniel Saucedo. All rights reserved.

//



#ifndef Database_hpp

#define Database_hpp

#include <stdexcept>

#include <vector>

#include <string>

#include "Tables.hpp"

using namespace std;



namespace Database {
    
    class MyDataBase {
        
    public:
        
        MyDataBase();
        
        bool add_table(Table* table, char* table_name);
        
        void drop_table(char* table_name);
        
        string list_table();
        
        vector < vector<string>> get_table();
        
        // query function
        
        Table query(string SELECT, string FROM, string WHERE);
        
    };
}





#endif /* Database_hpp */
