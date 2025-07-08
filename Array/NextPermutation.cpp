class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // example [2,3,6,5,4,1]
        // next permutation would be [2,]
        // hence from right to left, we find the some number that does not make
        // sense in the series
        //  permutation would be [2,4,6,5,3,1]
        //  but the problem is if we had simply exchanged like this, we wont be
        //  able to
        // so we need to sort all the element from swapIndex+1 position till end
        int k;
        int n = nums.size();
        for (k = n - 2; k >= 0; k--) { // next      //curr
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        // we would have decrement the k, after that the check would have failed
        if (k < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            // find the first number from right to left, which is actually
            // greater than 3
            int i;
            for (i = n - 1; i > k; i--) {
                if (nums[i] > nums[k]) {
                    break;
                }
            }
            swap(nums[k], nums[i]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
