int n = arr.size();
vector<int> candidates = {arr[n / 4], arr[n / 2], arr[(3 * n) / 4]};

for (int num : candidates) {
    auto left = lower_bound(arr.begin(), arr.end(), num);
    auto right = upper_bound(arr.begin(), arr.end(), num);
    
    if (right - left > n / 4) {
        return num;
    }
}

return -1; // Should never reach here as per problem constraints.