class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        //[3,2,2,1]
        // 1,2,2,3, limit 3
        int left =0;
        int right = people.size()-1;
        int boatCount =0;
        while(left <= right)
        {
            if(people[left] + people[right] <= limit || left == right)
            {
                left++;
                right--;
                
            } 
            else if(people[left] >= limit)
            {
                left++;
            }
            else 
            {
                right--;
            }
            boatCount++;
        }
        return boatCount;
    }
};
