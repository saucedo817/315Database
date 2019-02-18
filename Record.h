//

//  Database.hpp

//  Database

//

//  Created by Daniel Saucedo on 2/7/19.

//  Copyright © 2019 Daniel Saucedo. All rights reserved.

//



#ifndef Record_hpp

#define Record_hpp

#include <stdexcept>

#include <vector>

#include <string>

//#include "Table.h"
#include<string>

using namespace std;



namespace Record {
    
    class MyRecord {
        
    public:
        
        MyRecord();
        
        //Constructor creates a record of arbitrary size, and initializes entries to null string :
        MyRecord(int size);
        
        //Function that returns the size of the record :
        int returnSize();
        
        //Accessor function that allows access to individual - entries in the record
        string& operator[](int);
        
    };
    
}



#endif /* Record_hpp */
