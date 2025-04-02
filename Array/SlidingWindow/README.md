# [Average of Moving Data Stream](./averageOfMovingDataStream.cpp)

## Implementation Approach
   - Use a sliding window of fixed size `k` to store the most recent `k` elements.
   - Maintain a running sum of the elements in the window.
   - For each new element:
     - Add it to the window.
     - Remove the oldest element if the window size exceeds `k`.
     - Update the running sum accordingly.
   - Calculate the average as `running_sum / window_size`.