class Solution {
public:
    string longestPalindrome(string s) {
                int maxLen=INT_MIN;
        string store;
        //odd length
        for(int i=0;i<s.length();i++)
        {
            int left=i;
            int right=i;
            while(left>=0 and right<s.length() and s[left]==s[right])
            {
                if((right-left+1)>maxLen)
                {
                    maxLen=right-left+1;
                    store=s.substr(left,maxLen);

                }
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>=0 and right<s.length() and s[left]==s[right])
            {
                if((right-left+1)>maxLen)
                {
                    maxLen=right-left+1;
                    store=s.substr(left,maxLen);

                }
                left--;
                right++;
            }
            
            
        }
        return store;
    }
};
