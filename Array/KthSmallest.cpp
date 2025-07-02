class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();
        int mid =0;
        int left=matrix[0][0];
        int right = matrix[n-1][n-1];
        int answer=-1;
        while(left <= right)
        {
            mid = left+ (right-left)/2;
            int num=0;
            for(int i=0; i< n;i++)
            {
                int index = upper_bound(matrix[i].begin(), matrix[i].end(), mid)- matrix[i].begin();
                num+=index;
            }
            if(num < k)
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
                answer= mid;
            }
        }
        return answer;
    }
};
