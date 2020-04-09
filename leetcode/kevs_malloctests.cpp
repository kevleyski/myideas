#include <iostream>
#include <cstdlib>

int kevs_malloctests() {

    // Zombie checks

    char foo[] = "ERK";
    char foo2[] = {'E', 'R', 'K', '\0'};

    int num = sizeof(foo);
    num = sizeof(foo2);

    char* bar = (char*)malloc((num + 1) * sizeof(char));
    memcpy(bar, foo, num);
    bar[num - 1] = '*';
    bar[num] = '\0';


    std::cout << "bar=" << bar << std::endl;

    return 0;
}
