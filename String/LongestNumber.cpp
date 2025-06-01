class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.empty())
        {
            return "";
        }
        vector<string> arr;
        for (auto i : nums)
            arr.push_back(to_string(i));
        sort(begin(arr), end(arr),
             [](string& s1, string& s2) { return s1 + s2 > s2 + s1; });
        string ans;
        if (arr[0] == "0") {
            return "0";
        }
        for(auto s: arr)
        {
            ans+=s;
        }
        return ans;
    }
};
