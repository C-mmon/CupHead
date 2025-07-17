//Minimize sum of squares of adjacent element diff
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector <int> store = {3, 5, 1, 8};
	int maxAns = INT_MIN;
	pair <int, int> prSum;
	int currSum =0;
	for(int i=1; i<store.size(); i++)
	{
		long long int currPowDiff = pow(abs(store[i]-store[i-1]),2);
		if(currPowDiff > maxAns)
		{
			prSum.first= i;
			prSum.second =i-1;
			maxAns = currPowDiff;
		}
		currSum += currPowDiff;
	}
	//we can add an element closer to both
	int elementToAdd = (int) (store[prSum.first] + store[prSum.second])/2;
	currSum -= maxAns;
	currSum += pow(abs(store[prSum.first]-elementToAdd),2) + pow(abs(store[prSum.second]-elementToAdd),2);
	cout  << currSum << endl;

}
