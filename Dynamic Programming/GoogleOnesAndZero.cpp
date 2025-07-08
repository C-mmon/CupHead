class TopDown {
    const int MOD = 1e9+7;
    int n;

    bool isOdd(int num) {
        return num % 2;
    }

    int solveWithMemo(vector<vector<vector<int>>>& dp, const vector<int>& nums, int i, int consecutiveOdd, int consecutiveEven) {
        if(consecutiveOdd == 3 || consecutiveEven == 3)
            return 0;
        
        if(i == n)
            return 1;

        if(dp[i][consecutiveOdd][consecutiveEven] != -1)
            return dp[i][consecutiveOdd][consecutiveEven];
        
        int currSkip = solveWithMemo(dp, nums, i + 1, consecutiveOdd, consecutiveEven);
        int currTake = solveWithMemo(dp, nums, i + 1, (isOdd(nums[i]) ? consecutiveOdd + 1 : 0), 
                                                      (!isOdd(nums[i]) ? consecutiveEven + 1 : 0));

        return dp[i][consecutiveOdd][consecutiveEven] = (currSkip + currTake) % MOD;
    }

public:
    // O(N) & O(N)
    int countSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(3, -1)));
        return solveWithMemo(dp, nums, 0, 0, 0) - 1;
    }
};
