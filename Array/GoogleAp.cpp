#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector <int> a = {7,2,3,4};
	int n = a.size();
	long long totalSum =0;
	for(int i=0; i< n; i++)
	{
	//we are starting a new segment 
		int j=i+1;
		int diff = a[j] - a[i];
		if(j <n && abs(diff) == 1)
		{
			//i, i+1
			//i, j 
			while(j< n && a[j] - a[j-1] == diff)
			{
				j++;
			}
			for(int k=i; k< j;k++){
				int left = k-i+1;
				int right  = j-k;
				totalSum+=1LL* a[k] * left*right;
			}
			//now we need to shift our ith pointer 
			i = j-1;
		}
		else{
			totalSum += a[i]; //computing the sum of the single element 
		}
	}
	cout << totalSum << endl;
	return totalSum;		
}
