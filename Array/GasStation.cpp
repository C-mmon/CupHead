class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {


       int tank =0;
       int total =0;
       int startIndex=0;
        for(int i=0; i< gas.size(); i++)
        {
            int netGain = gas[i]-cost[i];
            tank += netGain;
            total += netGain;
            if(tank <0 )
            {
                startIndex = i+1;
                tank =0;
            }

        }
        if(total >= 0 )
        {
            return startIndex;
        }
        else
        {
            return -1;
        }

    }
};
