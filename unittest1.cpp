#include "stdafx.h"
#include "CppUnitTest.h"
#include "Database.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestFramework1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        
        TEST_METHOD(TestMethod1)
        {
            using namespace Database;
            
            // Database and tables objects
            Database::MyDatabase db;
            Table* table1;
            Table table2;
            
            // test add function
            bool isTableAdded = db.addTable("test1",nullptr);
            Assert::IsTrue(isTableAdded);
            
            isTableAdded = db.addTable("test2",table1);
            Assert::IsTrue(isTableAdded);
            
            // test drop table function
            db.dropTable("test2");
            //Assert::IsTrue(db.getTables("test2"));
            
            
            // test list table function
            //Assert::IsTrue(db.listTables());
            
            
            
            
            
            
            
            // test cases for Table.h
            Record* record1;
            
            
            bool isAdded = table1->add("test");
            Assert::AreEqual(isAdded,true);
            
            
            bool isDeleted = table1->del("test");
            Assert::AreEqual(isDeleted,true);
            
            
            bool isInserted = table1->insert(record1);
            Assert::AreEqual(isInserted,true);
            
            
            vector<string> attributes = table1->getAttributes();
            // Assert::Is(attributes);
            
            
            int tableSizeCheck = table1->getSize();
            Assert::IsTrue(tableSizeCheck);
            
            
            Record* isIterate = table1->iterate(0);
            Assert::IsNull(isIterate);
            
            
            bool isKeyAssigned = table1->assignKey("test");
            Assert::AreEqual(isKeyAssigned,true);
            
            
            Table* testCrossJoin = table1->crossJoin(nullptr, nullptr);
            Assert::IsNull(testCrossJoin);
            
            
            Table* testNaturalJoin = table1->naturalJoin(nullptr, nullptr);
            Assert::IsNull(testNaturalJoin);
            
            
            int testCount = table1->count("test");
            Assert::IsTrue(testCount);
            
            int testMin = table1->min("test");
            Assert::IsTrue(testMin);
            
            
            int testMax = table1->max("test");
            Assert::IsTrue(testMax);
            
            
            
            
            
            // Test cases for Record.h
            Record record4 = Record(1);
            bool flag = false;
            
            flag = false;
            if (record4.getSize() == 1) {
                flag = true;
            }
            Assert::IsTrue(flag);
            
            
            // if (record4[0] == "") {
            //     flag = true;
            // }
            // Assert::IsTrue(flag);
            
            
            
            
        }
        
        
        
    };
}
