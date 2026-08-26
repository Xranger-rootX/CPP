#include <iostream>
using namespace std;
int main(){
    int marks[5]={10,20,30,40,50};
    //double marks[5]={10.5,20.6,30.6,40.8,50.7};
    int x = marks[0]+marks[3];
    cout<<x<<endl;
    //cout<<marks[3] <<endl;



    cout<<marks[3] <<endl;
    // string name[5]={"Amit","Sumit","Rohit","Ramesh","Suresh"};
    // cout<<name[0]<<endl;
    // cout<<name[3]<<endl;
    cout<<"Enter length and breadth of rectangle"<<endl;
    int l,b;
    cin>>l;
    cin>>b;
    int area = l*b;
    cout<<area<<endl;

    cout<<"Enter two numbers to swap"<<endl;
    int temp,n1,n2;
    cin>>n1;
    cin>>n2;
    temp = n1;
    n1 = n2;
    n2 = temp;
    cout<<n1<<" "<<n2<<endl;


    int a,b;
    cin>>a;
    cin>>b;
    a ^= b;
    b ^= a;
    a ^= b;
    cout<<a<<" "<<b<<endl;


// int a = 5;
// int b = 10;

// a = a + b; // a is now 15
// b = a - b; // b is now 5
// a = a - b; // a is now 10

//check wether is a number is positive, negative or zero
    int num;
    cin>>num;
    if(num>0){  
        cout<<"Positive"<<endl;
    }
    else if(num<0){
        cout<<"Negative"<<endl;
    }
    else{
        cout<<"Zero"<<endl;
    }

    int num1,num2,num3;
    cin>>num1;
    cin>>num2;
    cin>>num3;
    if(num1>num2 && num1>num3){
        cout<<num1<<" is the largest number"<<endl;
    }
    else if(num2>num1 && num2>num3){
        cout<<num2<<" is the largest number"<<endl; 
    }
    else{
        cout<<num3<<" is the largest number"<<endl;
    }

for (int i=0;i<5;i++){
    cout <<marks[i]<<endl;
    int sum = 0;
    sum = sum + marks[i];

}


for (int i=0;i<=100;i++){
    if (i%2!=0){
        cout<<i<<endl;  
    }



class std{
    public:
        string name;
        int age;
};

int main(){
    std s1;
    std s2;

    cin>>s1.name;
    cin>>s1.age;
    cin>>s2.name;
    cin>>s2.age;

cout<<s1.name<<" "<<s1.age<<endl;
cout<<s2.name<<" "<<s2.age<<endl;







    
    return 0;
}

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


cout<<"Enter length and breadth of rectangle"<<endl;
    rectangle r1;
    cin>>r1.length;
    cin>>r1.breadth;

    cout<<"Area of rectangle is "<<r1.area()<<endl;
    cout<<"Perimeter of rectangle is "<<r1.perimeter()<<endl;
