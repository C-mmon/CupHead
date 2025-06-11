class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
     // freq array to store the frequency of each task
        int freq[26] = {0};
        int maxCount = 0;

        // Count the frequency of each task and find the maximum frequency
        for (char task : tasks) {
            freq[task - 'A']++;
            maxCount = max(maxCount, freq[task - 'A']);
        }

        // Calculate the total time needed for execution
        int time = (maxCount - 1) * (n + 1);
        for (int f : freq) {
            if (f == maxCount) {
                time++;
            }
        }

        // Return the maximum of total time needed and the length of the task list
        return max((int)tasks.size(), time);

    }
};
