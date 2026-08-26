//static vs non static
#include <iostream>
using namespace std;

class bank {
private:
    static int totalacc;

public:
    bank() {
        totalacc++;
    }

    static void outacc() {
        cout << "Total Bank Acc: " << totalacc << "\n";
    }
};


int bank::totalacc = 0;

int main() {

    bank a1;
    bank a2;
    bank a3;

    bank::outacc();

    return 0;
}