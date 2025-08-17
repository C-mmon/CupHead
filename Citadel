class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int startDay = events[0][0];
        // mistake dont assume the events are sorted by the end time
        int endDay = events[events.size() - 1][1];
        for (auto& e : events)
            endDay = max(endDay, e[1]);

        priority_queue<int, vector<int>, greater<int>> minHeap;
        int eventIterator = 0;
        int count = 0;
        for (int i = startDay; i <= endDay; i++) {
            // remove all the events from the minheap which are expired before
            // starting the current event

            while (!minHeap.empty() && minHeap.top() < i) {
                minHeap.pop();
            }
            // if the minheap at this point becomes empty

            while (eventIterator < events.size() &&
                   i == events[eventIterator][0]) {
                minHeap.push(events[eventIterator][1]); // we are storing only
                                                        // the end time
                eventIterator++;
            }
            // we need to handle the case where we reached the last day

            // we can only execute one given at a particular day
            // out of all the event insert, we are going to select the event
            // which has the minimum end time

            // we remove one single event for the particular day
            if (!minHeap.empty()) {
                minHeap.pop();
                count++;
            }
            if (minHeap.empty() && eventIterator == events.size()) {
                break; // early break condition
            }
        }
        return count;
    }
};
