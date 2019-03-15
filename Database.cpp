// DatabaseYelp.cpp : Defines the entry point for the console application.
/*
 *
 *
 *DOWNLOAD HEADER FILES FROM HERE AND IMPORT THEM INTO VISUAL STUDIOS
 *https://github.com/Tencent/rapidjson/tree/7e68aa0a21b7800ec98133cb106e49bd6536e25c/include/rapidjson
 *
 *Documentation on using the json and reading from it
 *https://github.com/Tencent/rapidjson/blob/7e68aa0a21b7800ec98133cb106e49bd6536e25c/doc/tutorial.md
 *
 */

//#include "stdafx.h"
#include "Database-2.h"
#include "Record.h"
#include "Table-2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "document.h"
#include "writer.h"
#include "stringbuffer.h"
//#include "pch.h"
// for convenience
using namespace rapidjson;

struct Business {
    string id;
    string name;
    string address;
    string postal_code;
    double latitude;
    double longitude;
    int review_count;
    
    
    Business() {};
};
struct User {
    string user_id;
    string name;
    int review_count;
    int useful;
    int funny;
    int cool;
    double average_stars;
    
    User() {};
};

struct Review {
    string review_id;
    string user_id;
    string business_id;
    int stars;
    string date;
    string text;
    int useful;
    
    
    Review() {};
};


void print_user_table(Database::Table* table) {   //print the user table
	vector<string> attributes = table->getAttributes();
	for (int i = 0; i < attributes.size(); ++i) {//print the attributes of table

		if (i == 0)
			cout << left << setw(25) << attributes.at(i);
		else if (i == 1)
			cout << left << setw(25) << attributes.at(i);
		else if (i == 2)
			cout << left << setw(25) << attributes.at(i);
		else if (i == 3)
			cout << left << setw(25) << attributes.at(i);
		else if (i == 4)
			cout << left << setw(25) << attributes.at(i);
		else if (i == 5)
			cout << left << setw(25) << attributes.at(i);
	}
	cout << endl;

	for (int i = 0; i < table->getSize(); ++i) {    //  print each record
		Database::Record* record = table->iterate(i);
		for (int j = 1; j < record->getSize(); ++j) {
			if (j == 1)
				cout << left << setw(25) << *record->getEntry(j);
			else if (j == 2)
				cout << left << setw(25) << *record->getEntry(j);
			else if (j == 3)
				cout << left << setw(25) << *record->getEntry(j);
			else if (j == 4)
				cout << left << setw(25) << *record->getEntry(j);
			else if (j == 5)
				cout << left << setw(25) << *record->getEntry(j);
			else if (j == 6)
				cout << left << setw(25) << *record->getEntry(j);

	
		}
		cout << endl;
	}
}

void print_table(Database::Table* t) {  // print the cross join table
	for (int i = 0; i < t->getSize(); ++i) {
		Database::Record* r = t->iterate(i);
		for (int j = 1; j < 2; ++j) {
			if (j == 1)
				cout << left << setw(5) << *r->getEntry(j);
			else if (j == 2)
				cout << left << setw(5) << *r->getEntry(j);
			else if (j == 3)
				cout << left << setw(5) << *r->getEntry(j);
			else if (j == 4)
				cout << left << setw(5) << *r->getEntry(j);
			else if (j == 5)
				cout << left << setw(5) << *r->getEntry(j);
			else if (j == 6)
				cout << left << setw(5) << *r->getEntry(j);
			

			cout << endl;


		}
		cout << endl;
	}
}

void print_business_table(Database::Table* t) {  //print the business table
	vector<string> attributes = t->getAttributes();
	for (int i = 0; i < attributes.size() ; ++i) {  //print the attributes of the table
		if(i ==0) 
			cout << left << setw(25) << attributes[i];
		else if (i==1)
			cout << left << setw(35) << attributes[i];
		else if (i == 2)
			cout << left << setw(55) << attributes[i];
		else if (i == 3)
			cout << left << setw(20) << attributes[i];
		else if (i == 4)
			cout << left << setw(20) << attributes[i];
		else 
			cout << left << setw(25) << attributes[i];
	



	}
	cout << endl;
	for (int i = 0; i < t->getSize(); ++i) {  //print record
		Database::Record* r = t->iterate(i);
		for (int j = 1; j < r->getSize(); ++j) {
			if (j == 1)
				cout <<left << setw(25) << *r->getEntry(j);
			else if (j == 2)
				cout << left << setw(35) << *r->getEntry(j);
			else if (j == 3)
				cout << left << setw(55) << *r->getEntry(j);
			else if (j==4)
				cout << left << setw(20) << *r->getEntry(j);
			else if (j == 5)
				cout << left << setw(20) << *r->getEntry(j);
			else if (j == 6)
				cout << left << setw(25) << *r->getEntry(j);
			else 
				cout << left << setw(25) << *r->getEntry(j);
		



		}
		cout << endl;
	}
}

int main()
{
    
    string first_line;
    string second_line;
    ifstream file("C:\\Users\\temporary\\source\\repos\\Project1\\Project1\\yelp_dataset.json");//read in file
    getline(file, first_line);//skip first line
  
    
    //create database table to push record into table in database
    Database::MyDatabase* Business_data = new Database::MyDatabase();
    Database::Table* business_table = new Database::Table(vector<string> {"business_id", "name", "address", "postal_code", "latitude",
        "longitude"});
    
    Database::Table* user_table = new Database::Table(vector<string> {"user_id", "name", "review_count", "useful", "funny",
        "cool", "average_stars"});
    Database::Table* review_table = new Database::Table(vector<string> {"review_id", "user_id", "business_id", "stars", "date",
        "text", "useful"});
    
    
    for (int i = 0; i < 10; i++) {
        getline(file, second_line);//read line
        const char* json = second_line.c_str();
        
        Document d;
        d.Parse(json);//parse json into document to iterate over it
        
      
        Business* b1 = new Business();
        b1->id = d["business_id"].GetString();
        b1->name = d["name"].GetString();
        b1->address = d["address"].GetString();
        b1->postal_code = d["postal_code"].GetString();
        b1->latitude = d["latitude"].GetDouble();
        b1->longitude = d["longitude"].GetDouble();
        b1->review_count = d["review_count"].GetInt();
       
        
        
        
        
        Database::Record* record = new Database::Record();
        record->newRecord.push_back(b1->id);
        record->newRecord.push_back(b1->name);
        record->newRecord.push_back(b1->address);
        record->newRecord.push_back(b1->postal_code);
        record->newRecord.push_back(to_string(b1->latitude));
        record->newRecord.push_back(to_string(b1->longitude));
        record->newRecord.push_back(to_string(b1->review_count));
        business_table->insert(record);
        
    }


	double pos2 = file.tellg();
	double offset2 = 1000000000;
	for (int i = 0; i < 4; ++i) {
		pos2 += offset2;
	}
	file.seekg(pos2);

	getline(file, first_line);

	for (int i = 0; i < 5; i++) {
		getline(file, second_line);//read line
		const char* json = second_line.c_str();
		Document d;
		d.Parse(json);//parse json into document to iterate over it


		Review* review = new Review();
		review->review_id = d["review_id"].GetString();
		review->user_id = d["user_id"].GetString();
		review->business_id = d["business_id"].GetString();
		review->stars = d["stars"].GetDouble();
		review->date = d["date"].GetString();
		review->text = d["text"].GetString();
		review->useful = d["useful"].GetInt();





		Database::Record* record3 = new Database::Record();
		record3->newRecord.push_back(review->review_id);
		record3->newRecord.push_back(review->user_id);
		record3->newRecord.push_back(review->business_id);
		record3->newRecord.push_back(to_string(review->stars));
		record3->newRecord.push_back(review->date);
		record3->newRecord.push_back(review->text);
		record3->newRecord.push_back(to_string(review->useful));
		review_table->insert(record3);

	}

	double pos = file.tellg();
	double offset = 1000000000;
	for (int i = 0; i < 3; ++i) {
		pos += offset;
	}
	file.seekg(pos);

	getline(file, first_line);
    
    
    for (int i = 0; i < 5; i++) {
        getline(file, second_line);//read line
        const char* json = second_line.c_str();
        Document d;
        d.Parse(json);//parse json into document to iterate over it
        
        
        User* user = new User();
        user->user_id = d["user_id"].GetString();
        user->name = d["name"].GetString();
        user->review_count = d["review_count"].GetInt();
        user->useful = d["useful"].GetInt();
        user->funny = d["funny"].GetInt();
        user->cool = d["cool"].GetInt();
        user->average_stars= d["average_stars"].GetDouble();
        
        
        
        
        
        Database::Record* record = new Database::Record();
        record->newRecord.push_back(user->user_id);
        record->newRecord.push_back(user->name);
        record->newRecord.push_back(to_string(user->review_count));
        record->newRecord.push_back(to_string(user->useful));
        record->newRecord.push_back(to_string(user->funny));
        record->newRecord.push_back(to_string(user->cool));
        record->newRecord.push_back(to_string(user->average_stars));
        user_table->insert(record);
        
    }
    
    Business_data->addTable("Business table", business_table);
    Business_data->addTable("User table", user_table);
    Business_data->addTable("Review table", review_table);
    std::cout << "Record count in Table: " << business_table->getSize() << endl;
    std::cout << "Table in database: " << Business_data->listTables()[0] << endl;
    std::cout << "Record added: ";
    //    for (int i = 1; i < record->getSize() + 1; ++i) {
    //    std::cout << *record->getEntry(i) << ", ";
    //}
    std::cout << endl;
    
    while (true) {
        cout << "What would you like to do? Enter 1 for Business Lookup. Enter 2 for User Look up. Enter -1 to exit" << endl;
        //1 for business lookup, 2 for user lookup, and 3 for user reviews
        //use cross joins for integrating data between two data sets
        int tempCase;
        cin >> tempCase;
        
        if (tempCase == 1) {
            //function call to return pertinent data
           // cout << "Enter Business name: " << endl;
            string business_id;
           // cin >> business_id;
			print_business_table(business_table);
			cout << "do you want  " << endl;
			Database::Table* table1 = Business_data->query(business_id, "Business table",">3");
			Database::Table* t = user_table->crossJoin(nullptr, review_table);
		
			print_table(t);
			
            
        }
        else if (tempCase == 2) {
            //user function call
			print_user_table(user_table);
        }
        else if (tempCase == -1) {
            return 0;
        }
    }
    
    //system("pause");
    return 0;
}
