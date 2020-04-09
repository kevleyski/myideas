#include <iostream>
using namespace std;

extern int leet1_test();
extern int leet1_test2();
extern int leet2_test();
extern int leet3_test();
extern int kevs_malloctests();

int main() {
    int timer = clock();
    //leet1_test();
    //leet1_test2();
    //leet2_test();
    //leet3_test();
    kevs_malloctests();

    cout << endl << "time=" << clock() - timer << endl;

    return 0;
}
