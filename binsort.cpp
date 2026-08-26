//3rd largest element in an array
#include<iostream>
using namespace std;
int main(){
    int arr[5]={1984,1987,2903,45,5};
    int n=5;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"3rd largest element: "<<arr[n-3];
}   
