#include<iostream>
#include<string>
using namespace std;
 
class Bank{
public:
    string name;
    double balance;

    void deposit(double amount){
        if (amount > 0){
            balance+=amount;
            cout<<"invalid";
        }
    }
    
    void withdraw(double amount){
        if (amount<=0){
            cout<<"invalid amount";
        }
        else if(amount>balance){
            cout<<"insufficient balance";
        }
        else{
            balance-=amount;
            cout<<"Withdrawl succ";
        }
    
    
    }

    int getBalance(){
        return balance;
    }

};
int main(){
    Bank b1;
    b1.name="Harsha";
    b1.balance=1000;

    cout<<"Enter the amount to deposit: ";
    double amount;
    cin>>amount;
    b1.deposit(amount);
    cout<<"Balance after deposit: "<<b1.getBalance()<<endl;

    cout<<"Enter the amount to withdraw: ";
    double withdrawAmount;
    cin>>withdrawAmount;
    b1.withdraw(withdrawAmount);
    cout<<"Balance after withdrawal: "<<b1.getBalance()<<endl;

    return 0;
}