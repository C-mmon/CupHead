#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> calculateTwoGroup(int group1, int group2, vector<vector<int>> &groups, int K)
{    const auto &A = groups[group1];
    const auto &B = groups[group2];
    int nA = A.size();
    int nB = B.size();

    vector<int> best(K+1, 0);
    vector<int> result;
    for (int i = 0; i <= nA && i <= K; ++i) {
        int sumA = (i == 0 ? 0LL : A[i-1]);
        for (int j = 0; j <= nB && i + j <= K; ++j) {
            int sumB = (j == 0 ? 0LL : B[j-1]);
            int score = sumA + sumB + i*i+ j*j;
            best[i + j] = max(best[i + j], score);
        }
    }
    return best;
}

int maxCardPoints(const vector<int> &symbols, const vector<int> &values, int K)
{
    int n = values.size();

    vector<vector<int>> groups(4);
    for (int i = 0; i < n; i++)
    {
        groups[symbols[i]].push_back(values[i]);
    }

    // Sort and convert to prefix sums
    for (int i = 0; i < 4; i++)
    {
        sort(groups[i].rbegin(), groups[i].rend());
        for (int j = 1; j < groups[i].size(); j++)
        {
            groups[i][j] += groups[i][j - 1];
        }
    }

    // Calculate scores for two halves
    vector<int> firstSum = calculateTwoGroup(0, 1, groups, K);
    vector<int> secondSum = calculateTwoGroup(2, 3, groups, K);

    // Find max sum of combinations
    int maxAns = 0;
    for (int i = 0; i <= K; i++)
    {
        int j = K - i;
        if (i < firstSum.size() && j < secondSum.size())
        {
            maxAns = max(maxAns, firstSum[i] + secondSum[j]);
        }
    }

    return maxAns;
}

int main()
{
    int K = 5;
    vector<int> symbols = {0, 1, 2, 2, 2};
    vector<int> values = {10, 20, 1, 2, 500};

    int result = maxCardPoints(symbols, values, K);
    cout << result << endl; 

    return 0;
}
