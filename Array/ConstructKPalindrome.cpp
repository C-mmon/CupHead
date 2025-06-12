class Solution {
public:
    bool canConstruct(string s, int k) {
        bitset <26> odd;
        for(char &c: s)
        {
            odd.flip(c-'a');
        }
        return  odd.count() <= k && k<= s.size(); 
    }
};

Condition 1. odd characters <= k
Count the occurrences of all characters.
If one character has odd times occurrences,
there must be at least one palindrome,
with odd length and this character in the middle.
So we count the characters that appear odd times,
the number of odd character should not be bigger than k.

Condition 2. k <= s.length()
Also, if we have one character in each palindrome,
we will have at most s.length() palindromes,
so we need k <= s.length().

The above two condition are necessary and sufficient conditions for this problem.
So we return odd <= k <= n
