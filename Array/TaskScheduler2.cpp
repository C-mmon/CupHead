class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
               unordered_map<int, long long> lastExecuted;
        long long time = 0;
        for (int task : tasks) {
            if (lastExecuted.count(task)) {
                if (time - lastExecuted[task] <= space) {
                    time = lastExecuted[task] + space + 1;
                }
            }
            lastExecuted[task] = time;
            time++;
        }
        return time;
    }
};
