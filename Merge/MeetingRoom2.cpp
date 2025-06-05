class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b) {
            return a.start < b.start;
        });

        // Min-heap to store the end times of meetings
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Add the first meeting's end time
        minHeap.push(intervals[0].end);

        for (int i = 1; i < intervals.size(); ++i) {
            // If the room is free, reuse it
            if (intervals[i].start >= minHeap.top()) {
                minHeap.pop();
            }
            // Allocate a new room (or reuse one)
            minHeap.push(intervals[i].end);
        }

        // Number of rooms is the size of the heap
        return minHeap.size();
    }
};
