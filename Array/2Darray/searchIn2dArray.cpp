//Perform a normal binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        int s = 0, e = n * m - 1;
        
        while(s <= e){
            int mid = (s + e) / 2;
            int row = mid / m;
            int col = mid % m;
            
            if(matrix[row][col] == target){
                return true;
            } else if(matrix[row][col] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return false;
    }
};