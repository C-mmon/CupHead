#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    vector <int> store {3,4,1,2,5};
    vector <pair<int, int>> pq;
    for(int i=0; i< store.size(); i++)
    {
        pq.push_back(make_pair(store[i], i));
    }
    sort(pq.begin(), pq.end());
    int count =0;
    vector <bool> visited(pq.size(), false);
    
    for(int i = 0; i < pq.size(); i++) {
        int temp = i;
        //if the index does not match as simple as that
        while(!visited[temp] && pq[temp].second != temp) {
            visited[temp] = true;
            temp = pq[temp].second;
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
