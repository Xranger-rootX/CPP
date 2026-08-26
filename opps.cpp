#include<iostream>
#include<string>
using namespace std;

class rectangle{
public:
    int length;
    int breadth;
    int area(){
        return length*breadth;
    }
    int perimeter(){
        return 2*(length+breadth);
    }

};


int main() {

    cout<<"Enter length and breadth of rectangle"<<endl;
    rectangle r1;
    cin>>r1.length;
    cin>>r1.breadth;

    cout<<"Area of rectangle is "<<r1.area()<<endl;
    cout<<"Perimeter of rectangle is "<<r1.perimeter()<<endl;


}