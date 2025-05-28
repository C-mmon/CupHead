class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector <int> res;
        //we need to execute for atlest mat.size()*2-1
        int row=  mat.size();
        int col = mat[0].size();
        int outerLoop = row+col-1;
        //when going from top to bottom it is what up (0,2) we are going up
        // when going from bottom to down its is down // otherwise we are going down
        for(int s=0; s< outerLoop;s++)
        {
            //for all i+j = s
            for(int x=0; x <=s; x++)
            {
                int i= x;
                int j= s-i; 
                // When the diagonal index is even we want to the first pair to be (s, 0) and when it is odd when want the first pair to be (0, s), and we decrease or increase i/j by 1 accordingly.
                if(s %2 ==0)
                {
                    swap(i,j);
                }
                //if the values are all square based no problem, problem will be during rectangle one 

                //need to take care of extra condition
                if(i >= col || j>= row)
                {
                    continue;
                }
                res.push_back(mat[i][j]); 
            }
        }
        return res;
    }
};
