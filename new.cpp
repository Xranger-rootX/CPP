#include<iostream>
#include<string>
using namespace std;
 
class product{
public:
    string name;
    double price;
    int quantity;


    double caltol(){
        return price*quantity;
    }
    void display(){
          cout<<"Name: "<<name<<endl;
        cout<<"Quantity: "<<quantity<<endl;
         cout<<"Price: "<<price<<endl;
         cout<<"Total: "<<caltol()<<endl;
    }
    

};


int main(){
    cout<<"Enter the name of the product: ";
    product p1;
    cin>>p1.name;
    cout<<"Enter the price of the product: ";
    cin>>p1.price;
    cout<<"Enter the quantity of the product: ";
    cin>>p1.quantity;
    p1.display();

}