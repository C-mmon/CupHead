// User function Template for C++

class Solution {
  public:
  bool checkPlacement(vector <int>& stalls, int k, int distance)
  {
      int previousStall=stalls[0];
      k--;
      for(int i=1; i< stalls.size(); i++)
      {
          if(stalls[i] - previousStall >= distance )
          {
              previousStall = stalls[i];
              k--;
       
         }
         if(k==0)
         {
             return true;
         }
      }
      return false;
  }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int low=1;
        int high = stalls.back()-stalls.front(); //8
        int ans =0;
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(checkPlacement(stalls, k, mid))
            {
                ans = mid;
                low = mid+1; //we alwawyas 
            }
            else
            {
                high = mid-1;
            }
        }
        return ans;
    }
};
