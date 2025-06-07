#include <iostream>
#include <vector>
using namespace std;

// Check if all digits are 9
bool allNine(const vector<int>& v) {
    for (int d : v)
        if (d != 9) return false;
    return true;
}

// Return the next palindrome greater than the input vector of digits
vector<int> nextPalindrome(vector<int> v) {
    int n = v.size();
    if (allNine(v)) {
        // e.g. 9 9 9 → 1 0 0 0 1
        vector<int> r(n + 1, 0);
        r.front() = r.back() = 1;
        return r;
    }

    int mid = n / 2;
    int i = mid - 1;
    int j = (n % 2 ? mid + 1 : mid);

    // Skip matching middle region
    while (i >= 0 && v[i] == v[j]) {
        i--; j++;
    }
    bool leftSmaller = (i < 0 || v[i] < v[j]);

    // Mirror left to right
    while (i >= 0) {
        v[j++] = v[i--];
    }

    // If left side was smaller, propagate carry from the middle outwards
    if (leftSmaller) {
        int carry = 1;
        i = mid - 1;
        if (n % 2) {
            // handle middle digit explicitly
            if (v[mid] == 9) {
                v[mid] = 0;
                carry = 1;
            } else {
                v[mid]++;
                carry = 0;
            }
            j = mid + 1;
        } else {
            j = mid;
        }
        // propagate carry and mirror
        while (i >= 0 && carry) {
            if (v[i] == 9) {
                v[i] = 0;
                carry = 1;
            } else {
                v[i]++;
                carry = 0;
            }
            v[j++] = v[i--];
        }
    }

    return v;
}

int main() {
    vector<int> num = {9,4,1,8,7,9,7,8,3,2,2};
    vector<int> pal = nextPalindrome(num);
    for (int d : pal) cout << d;
    cout << "\n";
    return 0;
}
