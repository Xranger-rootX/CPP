
#include <iostream>
using namespace std;
union AccountData{
    struct{
        char name[20];
        int accountNumber;
        float balance;
    } accountInfo;
} ;
int main() {
    AccountData account;
    double deposit,withdrawal;
    cin.getline(account.accountInfo.name, 20);
    cin >> account.accountInfo.accountNumber;
    cin >> account.accountInfo.balance;
    cout << "Account Holder: " << account.accountInfo.name << endl;
    cout << "Account Number: " << account.accountInfo.accountNumber << endl;    
