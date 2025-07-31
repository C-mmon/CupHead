class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map <int,int> mp;
        for(auto num: nums1)
        {
            mp[num]=-1;
        }
        vector <int> store (nums1.size(), 0);
        stack <int> st;
        int maxElem = INT_MIN;
        for(int j=nums2.size()-1; j >=0; j--)
        {
            while(!st.empty() && nums2[j] > nums2[st.top()])
            {
                st.pop();
            }
            //we need to update our map
            if(mp.find(nums2[j]) != mp.end())
            {
                if(!st.empty())
                {
                    mp[nums2[j]]= nums2[st.top()];
                }
            }
            st.push(j);
        }
        for(int i=0; i< nums1.size();i++)
        {
            store[i] = mp[nums1[i]];
        }
        return store;

    }
};
