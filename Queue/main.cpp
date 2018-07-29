/**
 * Driver function.
 */

#include <iostream>
#include <string>
#include <cassert>

#include "queue.h"
#include "testers.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <test num>\n";
        exit(1);
    }

    string testCase = argv[1];
    
    if (testCase == "test1")
        test1();
    
            
    return 0;
}
