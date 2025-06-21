class Solution {
public:
    int numTeams(vector<int>& rating) {
        int result = 0;
        //for each soldier count how many soldier on the left and on the right have less and greater rating 

        for(int i=1;i< rating.size()-1;i++)
        {
            int less[2] = {};
            int greater[2] = {};
            for(int j=0;j<rating.size();j++)
            {
                // confusion writing 
                // if the rating of i is less than rating j, increment the less, but
                // it could happen, this less value is on the left hand side or the right hand side of the current element 
                //
                if(rating[i] < rating[j])
                {
                    ++less[j>i];
                    //less[0]  and less[1]
                }
    
                if(rating[i] > rating[j])
                {
                    ++greater[j>i];
                }
            }
            result +=less[0]*greater[1] + greater[0] * less[1];
        }
        return result;
        //we need to reset less and greater count after certain point 
        //how to decide the loop parameter, the inner loop we do not care, we will just run from 0 to n 
        // the outer loop will only take care of reseting the loop value

        // for the first element and the last element we do not need to check
    } 
};
