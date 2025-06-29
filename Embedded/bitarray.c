#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num=123456;
    bool duplicate = false;
    short int store=0;
    int rem;
    while(num != 0)
    {
        rem = num%10;
        
        if(store & 1 << rem)
        {
            duplicate= true;
        }
        //shift the 1 left side by rem and set that bit in store
        store |= 1<< rem;
        num = num/10;
    }
    cout << duplicate << endl;
    return 0;
}
