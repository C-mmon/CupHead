// First - Given item prices, apply the discount of the first later item with lesser-or-equal price, compute the total of all final prices.

//We need to maintain a stack such that when we are scan from right to left.
#include <stdio.h>
#include <stack>
int main()
{
    stack <int> st;
    std::vector <int> vec {8,4,2,1};
// we need to start the next smaller element on the right
    for(int i =  vec.size()-1; i >=0; i--)
    {
        
