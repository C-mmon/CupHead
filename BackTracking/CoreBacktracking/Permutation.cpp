class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
          //avoid duplicates
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            //recursion(num, i, j, res) generates permutations by fixing one element at position i, then recursing to fix the rest.
            recursion(num, i+1, j, res);
            swap(num[i], num[k]);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};

//Time complexity
