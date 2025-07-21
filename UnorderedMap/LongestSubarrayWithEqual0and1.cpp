#include <bits/stdc++.h>

using namespace std;

int main()
{
	//conver all the on
	vector <int> store {1,1,0,0,0,0,1,1,1,1,1,0,0}; 
	unordered_map <int,int> mp; //check if we have seen this sum previously and store its index position

	int prefixSum =0;
	int maxAns =0;
	for(int i=0 ; i < store.size(); i++)
	{
		int currentNum = store[i] == 0 ? -1: 1;
		//store the sum 
		prefixSum += currentNum;
		if(prefixSum == 0)
		{
			//always take the basic sum and try to understand with that 
			maxAns = max(i+1, maxAns);
		}
		//find the given unordered map 
		if(mp.find(prefixSum) != mp.end())
		{
			//why did I this wrong, understand if you are storing the prefix index
			// note, we will only come here, when the prefixsum is not in zero, that means we are somewhere between 3rd 
			// 6th index.
			maxAns = max(maxAns, i-mp[prefixSum]);
		}
		else
		{
			mp[prefixSum]=i;
		}
		 //problem is that if we store here immediately, the next time same prefix length has been detected
		//we can never detect
	}
	cout << maxAns <<endl;
}
