class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers,
                              int capacity) {

        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        unordered_set <int> passengerSet(passengers.begin(), passengers.end());
        int lastLatestTime = -1;
        int currCap = 0;
        int j=0;
        for(int i=0;i<buses.size(); i++)
        {
            currCap= 0;
            //silly mistake
            while (j < passengers.size() && passengers[j] <= buses[i] && currCap < capacity) {
                j++;
                currCap++;
            }

            int candidateTime;
            if (currCap < capacity) {
                // bus is not full
                candidateTime = buses[i];
            } else {
                // check the last unboard passenger
                candidateTime = passengers[j - 1] - 1;
            }
            while (passengerSet.count(candidateTime)) {
                candidateTime--;
            }
            
            lastLatestTime = max(lastLatestTime, candidateTime);
        }
        return lastLatestTime;
    }
};
