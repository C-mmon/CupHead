#include <iostream>
#include <vector>
using namespace std;

//Apparently, every single element is decreasing and increasing element of its own self.


vector<int> valleyLengths(const vector<int>& A) {
    int n = A.size();
    vector<int> left(n, 1), right(n, 1), result(n);

    // Compute left: strictly decreasing ending at i
    for (int i = 1; i < n; ++i) {
        if (A[i - 1] > A[i]) {
            left[i] = left[i - 1] + 1;
        }
    }

    // Compute right: strictly increasing starting at i
    for (int i = n - 2; i >= 0; --i) {
        if (A[i] < A[i + 1]) {
            right[i] = right[i + 1] + 1;
        }
    }

    // Combine to get valley length at each index
    for (int i = 0; i < n; ++i) {
//Since we’re counting i in both, we subtract 1:
        result[i] = left[i] + right[i] - 1;
    }

    return result;
}

int main() {
    vector<int> A = {7, 2, 1, 5, 7, 9};
    vector<int> res = valleyLengths(A);

    for (int len : res)
        cout << len << " ";
    cout << endl;

    return 0;
}

