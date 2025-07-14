class Solution {
public:
vector <vector <int>> store;
void backtracking(int startIndex,int n, int k, vector <int> &temp)
{
    if(k == 0)
    {
        store.push_back(temp);
        return ;
    }   
    for(int i=startIndex; i<=n; i++)
    {
        temp.push_back(i);
        k-=1;
        backtracking(i+1,n, k, temp);
        k+=1;
        temp.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        vector <int> temp;
        backtracking(1,n, k, temp); 
        return store;
    }
};
