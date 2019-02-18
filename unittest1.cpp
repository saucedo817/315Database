
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
            
        }
        

        
    
        
        
  
        
        
    };
}
