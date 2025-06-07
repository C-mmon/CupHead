int maximizeProduct(const vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return 0;

    vector<int> left_max(n);
    left_max[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        left_max[i] = max(left_max[i - 1], arr[i]);
    }

    vector<int> right_max(n);
    right_max[n - 1] = arr[n - 1];
    for (int k = n - 2; k >= 0; --k) {
        right_max[k] = max(right_max[k + 1], arr[k]);
    }

    int max_product = -INT_MIN; // sufficiently small

    for (int j = 1; j < n - 1; ++j) {
        int arr_i = left_max[j - 1];
        int arr_j = arr[j];
        int arr_k = right_max[j + 1];

        int current_product = (arr_i - arr_j) * arr_k;
        if (current_product > max_product) {
            max_product = current_product;
        }
    }

    // If max_product was never updated, return 0
    if (max_product == -INT_MIN) return 0;
    return max_product;
}
