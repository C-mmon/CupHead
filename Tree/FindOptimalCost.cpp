#include <iostream>
#include <climits>
using namespace std;

int optimalCost(int freq[], int i, int j, int level)
{
	//base case
	if(i> j)
	{
		return 0;//path nmot possible  
	}
	int minCost = INT_MAX;
	int currCost;
	for(int iterate= i;iterate <=j; iterate++)
	{
		int leftOptimalCost= optimalCost(freq, i, iterate-1, level+1);
		int rightOptimalCost = optimalCost(freq, iterate+1, j, level+1);
		currCost = leftOptimalCost+rightOptimalCost+freq[iterate]*level;
		minCost = min(minCost, currCost);
	}
	return minCost;
}
int main()
{
    int freq[] = { 25, 10, 20 };
    int n = sizeof(freq) / sizeof(freq[0]);
 
    cout << "The optimal cost of constructing BST is "
         << optimalCost(freq, 0, n - 1, 1);
 
    return 0;
}
