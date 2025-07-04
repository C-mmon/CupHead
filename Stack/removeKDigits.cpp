class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for(char digit: num)
        {
            while(!res.empty() && k>0 && res.back() > digit)
            {
                k--;
                res.pop_back();
            }
            res.push_back(digit);
        }

        if(k >0)
        {
            
            res.resize(res.size()-k);
        }

        //we need to remove all trailing zero
        int i=0;
        while(i < res.size() && res[i] == '0')
        {
            i++;
        }
        res= res.substr(i);

        if(res.empty())
        {
            return "0";
        }
        return res;
    }
};
