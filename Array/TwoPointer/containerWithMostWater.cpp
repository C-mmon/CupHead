class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        //two pointer approach
        //int left = 0 and int right = n-1
        //max water height = distance between them * difference in height 
        //note: we need to maximize the area
        // 1,8,6,2,5,4,8,3,7

        int left = 0;
        int right = height.size()-1;

        int max_area = (right- left)* min(height[right], height[left]);
        //assuming max area

        while(left<right)
        {
            if(height[left] > height[right])
            {
                right--;
            }
            else if(height[left]  == height[right])
            {
                left++;
                right--;

            }
            else
            {
                left++;
            }
            if( (right- left)* min(height[right], height[left]) > max_area)
            {
                max_area = (right- left)* min(height[right], height[left]);
            }
            
        } 
        return max_area;
    }
};