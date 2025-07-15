class Solution {
public:
//13,5,1,8,21,2
//1,2,5,8,13,21
//my only confusion, is how do we know we have to begin from begin element
//because starting from anywhere else would give us smaller value
    bool isPricePossible(vector<int>& price, int k, int bsPrice) {
        int lastPrice = price[0];
        int count = 1;
        for (int i = 1; i < price.size(); i++) {
            if (price[i] -lastPrice >= bsPrice) {
                count++;
                lastPrice = price[i];
            }
            if (count == k) {
                return true;
            }
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int low = 0;
        int high = price.back();
        int ans = -1;
        while (low <= high) {
            int canAchievePrice = low + (high - low) / 2;
            if (isPricePossible(price, k, canAchievePrice)) {
                ans = canAchievePrice;
                low = canAchievePrice + 1;
            } else {
                high = canAchievePrice - 1;
            }
        }
        return ans;
    }
};
