class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {

        //for n events, we can have n+1 gaps, think like this for two events we can have 3 gaps
        vector <int> gaps (startTime.size()+1);
        gaps[0]= startTime[0];
        gaps[startTime.size()]=eventTime- endTime[endTime.size()-1];
        for(int i=1; i< startTime.size(); i++)
        {
            gaps[i] = startTime[i]-endTime[i-1];
        }
        //we need to calculate the prefix, now prefix is always one more than previous
        vector <int> prefix (startTime.size()+2);
        prefix[0]=0;
        for(int i=0; i<gaps.size(); i++)
        {
            prefix[i+1] = gaps[i] + prefix[i];
        }
        int ans=0;
        for(int i=k+1 ;i< prefix.size(); i++)
        {
            //we want k+1 gap
            //prefix from i to j is from len 
            ans= max(ans, prefix[i]- prefix[i-k-1]);
        }
        return ans;
    }
};
