class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low =1;
        int high = position.back()- position.front();
        int ans =0;

        while(low <= high)
        {
            //you want to converge on the indexes
            int mid = low + (high-low)/2;
            if(checkArragement(position, mid, m))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high =  mid-1;
            }
        }
        return ans;
    }
        bool checkArragement(vector <int>& position, int mid, int m)
        {
            int count =1;
            int lastPosition = position[0];
            //once you start iterating you will start choosing position which are greater than mid
            for(int i=1; i< position.size(); i++)
            {
                if(position[i] - lastPosition >= mid)
                {
                    lastPosition = position[i];
                    count++;
                }
                if(count >= m)
                {
                    return true;
                }
            }
            return false;
        }
};
