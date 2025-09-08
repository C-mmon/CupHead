#include <bits/stdc++.h>
using namespace std;
//Few things to take care, when taking the input, we are taking the long long 
// Take care of the corner, of the leading zero and the length is greater than zero
//Only iterate from for non-zero and further in the rnage of [2,3,4,5,6,7,8]
//final thing if the given pair is present we need to decide the count of the total pair 

int main()
{
    int n;
    while(!(cin>>n))
    {
        return 0;
    }
    unordered_map<string, long long> freq;
    freq.reserve(n * 2);
    
    for(int i=0; i<n; i++)
    {
        long long x;
        cin >> x;
        string s = to_string(x);
        freq[s]++;
    }
    long long total =0;
    for(auto &kv:  freq)
    {
        const string &s = kv.first;
        long long cnt = kv.second;
        int l = (int)s.size();
        for(int i=0; i<l; i++)
        {
            int org = s[i]-'0';
            for(int d: {org-1, org+1})
            {
                if(d < 0 || d >9)
                {
                    continue;
                }
                string cand = s;
                cand[i] = char('0'+ d);
                
                //skip the single zero
                if(cand[i] == '0' && cand.size() >1) 
                {
                    continue;
                }
                 auto it = freq.find(cand);
                if (it == freq.end()) continue;
                if (cand > s) total += cnt * it->second;
            }
        }
    }
    
    cout << total <<endl;
    
    
    return 0;
}
