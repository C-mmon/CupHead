class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0;
        int high = matrix.size() * matrix[0].size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int newRow = mid / row ;
            int newColumn= mid % col;
            int middleElement = matrix[newRow][newColumn];
            if (middleElement == target) {
                return true;
            }
            else if(middleElement <  target)
            {
                low = mid+1;
            }
            else
            {
                high =  mid-1;
            }
        }
        return false;
    }
};
