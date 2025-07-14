class Solution {
public:
int solve(int i, int j, vector <vector <int>> &memo,  vector<int>& cuts)
{
    if(j-i <=1)
    {
        return 0;
    }
    if(memo[i][j] != -1)
    {
        return memo[i][j];
    }
    int ans  =INT_MAX;
    for(int k=i+1; k<j; k++)
    {
        int currAns  = solve(i,k, memo, cuts)+ solve(k, j, memo, cuts)+ cuts[j]-cuts[i];
        ans = min(currAns, ans);
    }
    return  memo[i][j]=ans;
}
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        //there can be 1 to 100 cuts, we add 0 and n, there will be 
        vector <vector<int>> memo(102, vector <int> (102,-1));
        return solve(0, cuts.size()-1, memo, cuts);
    }
};
