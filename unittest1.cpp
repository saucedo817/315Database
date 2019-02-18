
#include "stdafx.h"
#include "CppUnitTest.h"
#include "Database.h"

using namespace Microsfot::VisualStudio::CppUnitTestFramework;

namespace TestFramework1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            using namespace Database;
            Database::MyDatabase db;
            bool isTableAdded == db.addTable("test",nullptr);
            Assert::IsTrue(isTableAdded);
            
            
            Database::MyDatabase db;
            bool isTableDropped == db.dropTable("test");
            Assert::IsTrue(isTableDropped);
            
            Database::MyDatabase db;
            vector<string> tableList == db.listTables();
            Assert::IsNull(tableList);
            
            Database::MyDatabase db;
            vector<string> tables == db.getTables();
            Assert::IsNull(tables);
            
            
            Database::MyDatabase db;
            Table* isTableEmpty == db.query("test","","");
            Assert::IsNull(isTableEmpty);
            
            Table::MyTable t; 
            bool isAdded = t.add(nullptr,"test");
            Assert::AreEqual(isAdded,true);

            Table::MyTable t; 
            bool isDeleted = t.del(nullptr,"test");
            Assert::AreEqual(isDeleted,true);

            Table::MyTable t; 
            bool isInserted = t.insert(nullptr,"test");
            Assert::AreEqual(isInserted,true);

            Table::MyTable t; 
            vector<string> attributes == t.getAttributes();
            Assert::IsNull(attributes);

            Table::MyTable t; 
            int tableSizeCheck = t.getSize(); 
            Assert::IsNull(tableSizeCheck);

            Table::MyTable t;
            Record* isIterate = t.iterate(nullptr);
            Assert::IsNull(isIterate);

            Table::MyTable t; 
            bool isKeyAssigned = t.assignKey("test");
            Assert::AreEqual(isKeyAssigned,true);

            Table::MyTable t; 
            Table* testCrossJoin = t.crossJoin(nullptr, nullptr);
            Assert::IsNull(testCrossJoin);

            Table::MyTable t; 
            Table* testNaturalJoin = t.naturalJoin(nullptr, nullptr);
            Assert::IsNull(testNaturalJoin);

            Table::MyTable t; 
            int testCount = t.count("test");
            Assert::IsNull(testCount);

            Table::MyTable t; 
            int testMin = t.min("test");
            Assert::IsNull(testMin);

            Table::MyTable t; 
            int testMax = t.max("test");
            Assert::IsNull(testMax);
            
        }
        

        
    
        
        
  
        
        
    };
}
