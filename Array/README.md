# [Random Selection with Weights](./randomPicksWithWeight.cpp)
## Implementation Approach
   - Create a cumulative sum array
   - Generates random number `n` between 0 and total sum-1
   - Uses `upper_bound` to find the first element greater than `n`
   - Returns the index of that element

Application: 
A good implementation of this problem can be implementing a random load balancer, 
with a given weight so that load balance can distrubute request across servers based 
on their processing weights.
