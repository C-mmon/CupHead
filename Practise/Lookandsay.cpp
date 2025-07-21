//Look and say sequence
//mind assumption and code execution missed the print
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string t = "1";
	for(int i=1; i<n; i++)
	{
		int count=1;
		string temp="";
		int j;
		for(j=1; j <t.size(); j++)
		{
			if(t[j]==  t[j-1])
			{
				count++;
			}
			else
			{
				temp += to_string(count) +t[j-1];
				count =1;
			}
		}
		//for the last one we still need to do some extraa work
		// t[j-1] =2 = 1+2+ 11
		temp += to_string(count) +t[j-1];
		t= temp;
	   }
	cout << t<<endl;
}


