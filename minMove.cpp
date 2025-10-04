#include <bits/stdc++.h>
using namespace std;

// Returns minimum number of operations using Non-Adjacent Form (NAF)
long long minOperations(long long n) {
    if (n <= 0) return 0;
    long long count = 0;
    while (n != 0) {
        if ((n & 1LL) == 0) {
            // n is even, just shift right
            n >>= 1;
        } else {
            // n is odd: choose whether to add or subtract 1
            if ((n & 3LL) == 1 || n == 1) {
                n -= 1;  // subtract 1
            } else {
                n += 1;  // add 1
            }
            count++;    // this step counts as one operation
            n >>= 1;    // shift after adjusting
        }
    }
    return count;
}

int main() {
    long long n;
    cin >> n;
    cout << minOperations(n) << "\n";
    return 0;
}
