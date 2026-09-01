#include<iostream>
using namespace std;

//call by valude and call by reference
//swap two numbers using call by value and call by reference
void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByValue: a = " << a << ", b = " << b << endl;
}
void swapByReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside swapByReference: a = " << a << ", b = " << b << endl;
}
int main() {
    int x = 10, y = 20;
    cout << "Before swapByValue: x = " << x << ", y = " << y << endl;
    swapByValue(x, y);  
    swapByReference(x, y);
    cout << "After swapByReference: x = " << x << ", y = " << y << endl;
    return 0;
}

