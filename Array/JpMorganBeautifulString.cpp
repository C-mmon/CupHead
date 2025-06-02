class Solution {
public:
    int beautifulSubstrings(string s) {
        int count0 = 0, count1 = 0, result = 0;

        for (char c : s) {
            if (c == '0') count0++;
            else if (c == '1') count1++;

            if (count0 == count1) {
                result++;
                count0 = count1 = 0;
            }
        }

        return result == 0 ? -1 : result;
    }
};



class Solution {
public:
    const long long int mod = 1000000007;

    int numWays(string s) {
        // Count the number of ones
        int ones = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ones++;
            }
        }

        // Case when all characters are '0'
        if (ones == 0) {
            long long n = s.size();
            //n-1c2
            return ((n - 1) * (n - 2) / 2) % mod;
        }

        // Find number of zeros after first one-third
        int i = 0, x = ones / 3;
        while (i < s.size() && x != 0) {
            if (s[i] == '1') {
                x--;
            }
            i++;
        }

        int startZeros = 0;
        while (i < s.size() && s[i] == '0') {
            startZeros++;
            i++;
        }

        // Find number of zeros after second one-third
        int j = s.size() - 1;
        x = ones / 3;
        while (j >= 0 && x != 0) {
            if (s[j] == '1') {
                x--;
            }
            j--;
        }

        int endZeros = 0;
        while (j >= 0 && s[j] == '0') {
            endZeros++;
            j--;
        }

        return ((long long)(startZeros + 1) * (endZeros + 1)) % mod;
    }
};
