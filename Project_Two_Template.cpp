//============================================================================
// Name        : HashTable.cpp
// Author      : John Watson
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <algorithm>
#include <climits>
#include <iostream>
#include <string> // atoi
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

const unsigned int DEFAULT_SIZE = 179;

double strToDouble(string str, char ch);

// define a structure to hold Couse information
struct Course {
    string CouseId; // unique identifier
    string name;
    string prerequisite;
};

//============================================================================
// Hash Table class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a hash table with chaining.
 */
class HashTable {

private:
    // Define structures to hold Courses
    struct Node {
        Course Course;
        unsigned int key;
        Node *next;

        // default constructor
        Node() {
            key = UINT_MAX;
            next = nullptr;
        }

        // initialize with a Course
        Node(Course aCourse) : Node() {
            Course = aCourse;
        }

        // initialize with a Course and a key
        Node(Course aCourse, unsigned int aKey) : Node(aCourse) {
            key = aKey;
        }
    };

    vector<Node> nodes;

    unsigned int tableSize = DEFAULT_SIZE;

    unsigned int hash(int key);

public:
    HashTable();
    HashTable(unsigned int size);
    virtual ~HashTable();
    void Insert(Course Course);
    void PrintAll();
    void Remove(string CourseId);
    Course Search(string CourseId);
};

/**
 * Default constructor
 */
HashTable::HashTable() {
    int startHash = 1;
    Node *next;

    unsigned int tableSize = DEFAULT_SIZE;

}

/**
 * Constructor for specifying size of the table
 * Use to improve efficiency of hashing algorithm
 * by reducing collisions without wasting memory.
 */
HashTable::HashTable(unsigned int size) {
    unsigned int tableSize = size;
}


/**
 * Destructor
 */
HashTable::~HashTable() {
    int startHash = 1;
    Node *next;
}

/**
 * Calculate the hash value of a given key.
 * Note that key is specifically defined as
 * unsigned int to prevent undefined results
 * of a negative list index.
 *
 * @param key The key to hash
 * @return hash(key) The calculated hash
 */
unsigned int HashTable::hash(int key) {
    return hash(key);
}

/**
 * Insert a Course
 *
 * @param Course The Course to insert
 */
void HashTable::Insert(Course Course) {
   Node(Course);
   Node *next;

}

/**
 * Print all Courses
 */
void HashTable::PrintAll() {
    int currSelect;
    unsigned int sKey;
    while (tableSize >= currSelect) {
        Node currNode;
        Node *currNode = currNode*;
        displayCourse(currNode.Course);
        currSelect++;
    }

}
/**
 * Remove a Course
 *
 * @param CourseId The Course id to search for
 */
void HashTable::Remove(string CourseId) {
    int currSelect;
    unsigned int sKey;
    while (tableSize >= currSelect) {
        Node currNode;
        if (currNode.Course.CourseId == CourseId){
        delete currNode;
        }
        currSelect++;
    }
}

/**
 * Search for the specified CourseId
 *
 * @param CourseId The Course id to search for
 */
Course HashTable::Search(string CourseId) {
    Course Course;
    int currSelect;
    unsigned int sKey;
    while (tableSize >= currSelect) {
        Node currNode;
        Node *currNode = currNode*;
        if (currNode.Course.CourseId == CourseId){
        displayCourse(currNode.Course);
        }
        currSelect++;
    }

    return Course;
}


//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the Course information to the console (std::out)
 *
 * @param Course struct containing the Course info
 */
void displayCourse(Course Course) {
    cout << Course.CourseId << ": " << Course.name << " | "
            << Course.prequisite << endl;
    return;
}

/**
 * Load a CSV file containing Courses into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the Courses read
 */
void loadCourses(string csvPath, HashTable* hashTable) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser using the given path
    csv::Parser file = csv::Parser(csvPath);

    // read and display header row - optional
    vector<string> header = file.getHeader();
    for (auto const& c : header) {
        cout << c << " | ";
    }
    cout << "" << endl;

    try {
        // loop to read rows of a CSV file
        for (unsigned int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of Courses
            Course Course;
            Course.CourseId = file[i][1];
            Course.title = file[i][2];
            Course.fund = file[i][8=3];

            //cout << "Item: " << Course.title << ", Fund: " << Course.fund << ", Amount: " << Course.amount << endl;

            // push this Course to the end
            hashTable->Insert(Course);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl;
    }
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}

/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, CourseKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        CourseKey = "98109";
        break;
    case 3:
        csvPath = argv[1];
        CourseKey = argv[2];
        break;
    default:
        csvPath = "eCourse_Monthly_Sales_Dec_2016.csv";
        CourseKey = "98109";
    }

    // Define a timer variable
    clock_t ticks;

    // Define a hash table to hold all the Courses
    HashTable* CourseTable;

    Course Course;
    CourseTable = new HashTable();
    
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Courses" << endl;
        cout << "  2. Display All Courses" << endl;
        cout << "  3. Find Course" << endl;
        cout << "  4. Remove Course" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            
            // Initialize a timer variable before loading Courses
            ticks = clock();

            // Complete the method call to load the Courses
            loadCourses(csvPath, CourseTable);

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 2:
            CourseTable->PrintAll();
            break;

        case 3:
            ticks = clock();

            Course = CourseTable->Search(CourseKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!Course.CourseId.empty()) {
                displayCourse(Course);
            } else {
                cout << "Course Id " << CourseKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
            break;

        case 4:
            CourseTable->Remove(CourseKey);
            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
