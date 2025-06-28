#include <iostream>
using namespace std;
typedef int (*functionPtr)(int *, int *);
int func(int* ptrA, int * ptrB)
{
    return *ptrA+*ptrB;
}
int main()
{
    int a=10;
    int b=20;
    functionPtr c = func;
    cout << c(&a, &b) <<endl;
    return 0;
}
