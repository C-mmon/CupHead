#include <bits/stdc++.h>
using namespace std;

//Longest Consecutive Subsequence
int main()
{
	vector <int> arr {2,6,1,9,4,5,3};
	unordered_set <int> st (arr.begin(), arr.end());
	int ans=0;
	for(auto i: st)
	{
		if(st.find(i-1) == st.end())
		{
			int len=1;
			int temp= i+1;
			while(st.find(temp) != st.end())
			{
				len++;
				st.erase(temp);
				temp++;
			}
			ans = max(len, ans);
		}
	}
	cout << ans << endl;
	return 0;
}

