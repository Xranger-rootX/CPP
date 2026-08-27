//vectors --> dynimic size of allocation 
#include <iostream>
#include <vector>
using namespace std;

int main(){

    //creating a vector
    vector<int> v;
 //vector <type> vector_name;

    v.push_back(10); //--> adding elements to the vector
    v.push_back(20);
    v.push_back(30);

    //printing the vector multipe ways

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    //using iterator
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }

    //using auto keyword
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }

    


    //for each loop
    for(int value:v){
        cout<<value<<" ";
    }
    cout<<endl;


//deleting elements from the vector
    v.pop_back(); //removes the last element
    cout<<"After pop_back: ";
    for(int value:v){
        cout<<value<<" ";
    }
    cout<<endl;

//inserting elements at a specific position
    v.insert(v.begin()+1,15); //inserts 15 at index 1
    cout<<"After insert: ";
    for(int value:v){
        cout<<value<<" ";
    }
    cout<<endl;

//deleting elements from a specific position
    v.erase(v.begin()+1); //removes element at index 1
    cout<<"After erase: ";
    for(int value:v){
        cout<<value<<" ";
    }


//clearing the vector
    v.clear(); //removes all elements from the vector
    cout<<"After clear: ";
    for(int value:v){
        cout<<value<<" ";
    }

//checking if the vector is empty
    if(v.empty()){
        cout<<"Vector is empty";
    }


    return 0;
}



//create ; read ; update ; delete CRUD in vectors
 