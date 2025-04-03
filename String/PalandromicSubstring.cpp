class Solution {
    public:
        int countSubstrings(string s) {
              int counter = 0, n = s.size();
            for (int i = 0; i < n; i++) {
                for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                    counter++;
                }
                for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                    counter++;
                }
            }
            return counter;
        }
    };

    //In this question, there can be two possibilities:
    //  1. Odd length palindrome: i.e. 121, 12321, 1234321
    //  2. Even length palindrome: i.e. 1221, 123321, 12344321
    ////  So, we can iterate over the string and for each character, we can check for both odd and even length palindromes by expanding around the center character(s).
    //  The time complexity of this approach is O(n^2) in the worst case, where n is the length of the string.