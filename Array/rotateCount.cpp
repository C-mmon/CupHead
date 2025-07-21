#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector <int> rotate {15,18, 2, 3,6,12};

	//find the k over here


	int left =0;
	int right=rotate.size()-1;
	while(left < right)
	{
		int mid = left + (right-left)/2;
		//that means the right half is sorted,
		if(rotate[mid] >= rotate[right])
		{
			left  = mid+1;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}
