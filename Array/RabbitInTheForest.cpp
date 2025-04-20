class Solution {
public:
    int numRabbits(vector<int>& answers) {
                unordered_map<int, int> store;
        for (int i = 0; i < answers.size(); i++) {
            store[answers[i]]++;
        }

        int ans = 0;
        for (auto it : store) {
            int key = it.first;   // how many others the rabbit sees
            int value = it.second; // how many rabbits gave this answer
            
            if (key == 0) {
                // each rabbit sees 0 others, so they're all unique
                ans += value;
            } else {
                int same_color_count = key + 1;
                // how many full "batches" of same_color_count we need
                int full_batches = value / same_color_count;
                ans += full_batches * same_color_count;

                if (value % same_color_count != 0) {
                    // some rabbits left over, need one more batch
                    ans += same_color_count;
                }
            }
        }

        return ans;
    }
};
