class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hmap(256, 0);
        int maxLen = 1; // There will be at least one unique character
        int leftPtr = 0;
        int rightPtr = 1; 
        int len = s.length();
        if (len == 0) {
            return 0;
        }
        hmap[s[leftPtr]]++; // Use the character itself as the index

        while (rightPtr < len) {
            // Just add the character
            if (hmap[s[rightPtr]] == 0) {
                hmap[s[rightPtr]]++;
                maxLen = max(rightPtr - leftPtr + 1, maxLen);
                rightPtr++;
            } else {
                hmap[s[rightPtr]]++;
                while (hmap[s[rightPtr]] != 1) {
                    // Increment the left pointer
                    hmap[s[leftPtr]]--;
                    leftPtr++;
                }
                rightPtr++;
            }
        }

        return maxLen;
    }
};
