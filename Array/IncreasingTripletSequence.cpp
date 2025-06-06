class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
               int first = INT_MAX, second = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                first = num;            // smallest so far
            } else if (num <= second) {
                second = num;           // second smallest so far
            } else {
                return true;            // found third element > second
            }
        }

        return false;
    }
};
