//create a uniion called value containing:
//int, float, and char
//store float and print it 
//then store a char and print it
//print the float and char values after storing them in the unionfu

#include <iostream>
using namespace std;

union value {
    int i;
    float f;
    char c;
};

int main() {
    value v;

    // Store a float and print it
    v.f = 3.14f;
    cout << "Stored float: " << v.f << endl;

    // Store a char and print it
    v.c = 'A';
    cout << "Stored char: " << v.c << endl;

    
    return 0;
}