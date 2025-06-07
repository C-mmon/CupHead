#include <bits/stdc++.h>
using namespace std;
vector <int> makearray(vector <vector <int>> &subseqs, int n)
{
	vector <int> result;
	vector <unordered_set <int>> adj (n);
	vector <int> indegree(n,0);
	//1) Build edges and compute indegrees.
    //    For each adjacent pair u -> v in every subsequence,
    //    insert an edge u→v if it doesn't already exist.
	for(auto seq: subseqs)
	{
		for(int j=1; j <(int) seq.size(); j++)
		{	
			int u= seq[j-1];
			int v = seq[j];
			 // insert returns a pair<iterator,bool>
            // .second == true if v was actually inserted (i.e. edge was new)
			if(adj[u].insert(v).second)
			{
				indegree[v]++;
			}
		}
	}//how will we perform the traversal
	priority_queue <int,vector<int>, greater<int>> minHeap;
	for(int i=0; i< n; i++)
	{
		if(indegree[i] == 0)
		{
			minHeap.push(i);
		}
	}

	while(!maxHeap.empty())
	{
		int node=minHeap.top();
		minHeap.pop();
		result.push_back(node);
		for(int n: adj[node])
		{
			indegree[n]--;
			if(indegree[n] == 0)
			{
				minHeap.push(n);
			}
		}
	}
	return result;

}
int main()
{
	 // Size of the required array
    int n = 10;

    // Given sub-sequences of the array
    vector<vector<int> > subseqs{ { 9, 1, 2, 8, 3 },
                                  { 6, 1, 2 },
                                  { 9, 6, 3, 4 },
                                  { 5, 2, 7 },
                                  { 0, 9, 5, 4 } };

    // Get the resultant array as vector
    vector<int> res = makearray(subseqs, n);

    // Printing the array
    for (auto x : res) {
        cout << x << " ";
    }

    return 0;
}
