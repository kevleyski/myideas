#include <iostream>
using namespace std;

extern int leet1_test();
extern int leet1_test2();

int main() {
    int timer = clock();
    //leet1_test();
    leet1_test2();

    cout << endl << "time=" << clock() - timer << endl;

    return 0;
}
