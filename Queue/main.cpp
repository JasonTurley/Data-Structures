/**
 * @file main.cpp
 *
 * clang++ -std=c++11 queue.cpp main.cpp
 */
#include <iostream>
#include <string>
#include <cassert>

#include "queue.h"
#include "testers.h"

using namespace std;

void testCaseHandler(string testCase)
{
    if (testCase == "1") {
        test1();
    } else if (testCase == "2") {
        test2();
    } else if (testCase == "3") {
        test3();
    } else if (testCase == "4") {
        test4();
    } else {
        cout << "Please enter a valid test case.\n";
        exit(1);
    }
}

// Driver function
int main(int argc, char* argv[]) 
{
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <test case number>\n";
        exit(1);
    }

    testCaseHandler(argv[1]); 

    return 0;
}
