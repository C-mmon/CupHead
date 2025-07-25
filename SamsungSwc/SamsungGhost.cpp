#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector <int> A = {2,5,10,14,18};
	vector <int> B = {3,2,4,5,6};
	vector <pair<int,int>> store;
	int usedEnergy =20;

	for(int i=0; i< A.size(); i++)
	{
		store.push_back({A[i], B[i]});
	}
	sort(store.begin(), store.end());
	int maxCost =0;
	for(int i=0; i< store.size(); i++)
	{
		vector <int> cost;
		int currCost=0;
		int count=1;
		for(int j=i+1; j< store.size(); j++)
		{
			if(store[j].second >= store[i].second)
			{
				cost.push_back((store[j].first-store[i].first)*store[j].second);
			}
		}
		sort(cost.begin(), cost.end());
		for(auto energy: cost)
		{
			if(energy + currCost > usedEnergy)
			{
				break;
			}
			count++;
			currCost += energy;
		}
		maxCost = max(maxCost, count);
	}
	cout << maxCost << endl;
}
