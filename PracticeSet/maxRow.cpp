// What a dumb guy, why the fuck you wrote '1' instead of 1.

#include <bits/stdc++.h>
using namespace std;

bool check(vector <vector<int>> &mat, int col)
{
	for(int i=0; i< mat.size(); i++)
	{
		if(mat[i][col] == 1)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	//binary search on the column 
	vector <vector<int>> mat {{0,1,1,1}, {0,0,1,1}, {0,1,1,1}, {0,0,0,0}};
	int left =0;
	int right =mat[0].size()-1;
	int ans=0;
	while(left <= right)
	{
		//function to check if atleast one one exist, that means 
		int mid = left + (right-left)/2;
		if(check (mat, mid))
		{	
		ans = mid;
		right = mid-1;		
		}
		else
		{
			left = mid+1;
		}
	}
	cout << ans <<endl;
}
