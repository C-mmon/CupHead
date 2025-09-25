class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //Purposefully, insert 0 at the end 
        heights.push_back(0);
        stack <int> s;
        int maxArea =0;
        for(int i=0; i< heights.size(); i++)
        {
            while(!s.empty() && heights[s.top()] > heights[i])
            {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i-s.top()-1;
                maxArea= max(maxArea, h*w);
            }
            s.push(i);
        }
        return maxArea;
    }
};
