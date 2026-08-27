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




    //for each loop
    for(int value:v){
        cout<<value<<" ";
    }
    cout<<endl;




    return 0;
}



//create ; read ; update ; delete CRUD in vectors
 