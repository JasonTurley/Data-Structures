#include <iostream>

using std::string;
using namespace std;

void print_reverse_string (string str)
{
	for (int i = str.length()-1; i > -1; i--) 
		cout << str.at(i);
}

int main() {
	
	//print_reverse_string("Happy");
	
	return 0;
}