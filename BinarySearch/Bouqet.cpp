class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
                long long total = (long long)m * k;
        if (total > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans=0;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(checkPossible(mid, bloomDay, m, k))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low  = mid+1;
            }
        }
        return ans;
        }
        bool checkPossible(int mid, vector<int>& bloomDay, int m, int k)
        {
            int count=0;
            int flowers=0;
            for(int i=0; i< bloomDay.size();i++)
            {
                //the bloom day should be less than mid 
                if(bloomDay[i] <= mid)
                {
                    flowers++;
                    if(flowers== k)
                    {
                        count++;
                        class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
                long long total = (long long)m * k;
        if (total > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans=0;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(checkPossible(mid, bloomDay, m, k))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low  = mid+1;
            }
        }
        return ans;
        }
        bool checkPossible(int mid, vector<int>& bloomDay, int m, int k)
        {
            int count=0;
            int flowers=0;
            for(int i=0; i< bloomDay.size();i++)
            {
                //the bloom day should be less than mid 
                if(bloomDay[i] <= mid)
                {
                    flowers++;
                    if(flowers== k)
                    {
                        count++;
                        if (count >= m) return true; // Early return
                        flowers=0;
                    }
                }
                else
                {
                    flowers=0;
                }
            }
            if(count >= m)
            {
                return true;
            }
            else
            {
                return false;
            }

        }
};
                        flowers=0;
                    }
                }
                else
                {
                    flowers=0;
                }
            }
            if(count >= m)
            {
                return true;
            }
            else
            {
                return false;
            }

        }
};
