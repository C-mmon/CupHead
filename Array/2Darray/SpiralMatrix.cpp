class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
          int col = matrix[0].size();
        int row =  matrix.size();
        int left = 0;
        int right = col - 1;
        int up = 0;
        int down = row - 1;
        vector<int> ans;
        while (left <= right && up <= down) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[up][i]);
            }
            up++;

            for (int i = up; i <= down; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Right to Left
            if (up <= down) {
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[down][i]);
                }
                down--;
            }

            // Bottom to Top
            if (left <= right) {
                for (int i = down; i >= up; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
