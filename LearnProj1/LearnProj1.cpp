#include <iostream>
using namespace std;

#define PRINT(str) std::cout << str << std::endl 

void addOne(int* n) {
    (*n)++;
}

int main()
{
    int x = 8;
    PRINT(x);
    addOne(&x);
    PRINT(x);
}
