//We are given an array of integers and an integer k.
//We need to find the length of the longest subarray that contains at most k different integers.

//exactly(K) = atMost(K) - atMost(K-1)
class Solution {
    public:
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            int sub_with_max_element_k = subarray_with_atmost_k(nums,k);
            int reduced_sub_with_max_k = subarray_with_atmost_k(nums,k-1);
            return (sub_with_max_element_k - reduced_sub_with_max_k);
        }
        int subarray_with_atmost_k(vector<int>& nums,int k){
            unordered_map<int,int> map;
            int left = 0 , right = 0,ans = 0;
            while(right<nums.size()){
                map[nums[right]]++;
                while(map.size()>k){
                    map[nums[left]]--;
                    if(map[nums[left]]==0)map.erase(nums[left]);
                    left++;
                }
                ans += right-left+1; // basically the size of subarray;
                right++;
            }
            return ans;
        }
    };


    //Similar question: Count number of nice subarrays
    int numberOfSubarrays(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k - 1);
    }

    int atMost(vector<int>& A, int k) {
        int res = 0, i = 0, n = A.size();
        for (int j = 0; j < n; j++) {
            k -= A[j] % 2;
            while (k < 0)
                k += A[i++] % 2;
            res += j - i + 1;
        }
        return res;
    }

    //Simlar Question: Replace the substring for balanced string

    // calculate the frequency of each character in the string
    // imagine this, if we can erase all the characters in the string, we can get a balanced string
    // so we need to find the minimum number of characters we need to erase to get a balanced string
    class Solution {
        public int balancedString(String s) {
                int n = s.length(), minLength = n, excessCount = 0;
        int[] charCount = new int[128]; 
        charCount['Q'] = charCount['W'] = charCount['E'] = charCount['R'] = -n / 4;
    
        // Count excess characters
        for (char ch : s.toCharArray()) {
            if (++charCount[ch] == 1) excessCount++;  // When a character goes from 0 to 1, it's in excess
        }
    
        // If already balanced, no replacements needed
        if (excessCount == 0) return 0;
    
        // Sliding window approach
        int left = 0;
        for (int right = 0; right < n; right++) {
            // Expand the window from the right
            if (--charCount[s.charAt(right)] == 0) excessCount--;
    
            // Once we have a valid window, try to shrink from the left
            while (excessCount == 0) {
                minLength = Math.min(minLength, right - left + 1);
                
                // Shrink from the left
                if (++charCount[s.charAt(left)] == 1) excessCount++;
                left++;
            }
        }
    
        return minLength;
        }
    }


    //num subarrays with sum equals to k
    class Solution {
        public:
            int numSubarraysWithSum(vector<int>& nums, int goal) {
                return atMost(nums, goal) - atMost(nums, goal-1);
            }
            int atMost(vector<int>& nums, int goal){
                int head, tail = 0, sum = 0, result = 0;
                for (head = 0; head < nums.size(); head++) {
                    sum += nums[head];
                    while (sum > goal && tail <= head) {
                        sum -= nums[tail];
                        tail++;
                    }
                    result += head - tail + 1;
                }
                return result;
            }
        };



//Fruits in basket
def totalFruit(self, fruits: List[int]) -> int:
#you only have two basket where each basket can hold only one type of fruit and can hold unlimited fruit
#this is sliding window question, where you need to figure out the max fruit you can hold 
#use a sliding window starting from the first two left and right, which are already there in your basket 
# keep expanding towards the right, starting from right = 2, if we cannot hold the right fruit, then we keep decrementing from left


left = 0  # Left pointer of the sliding window
max_fruits = 0
fruit_count = {}  # Dictionary to track fruit frequency in the window

for right in range(len(fruits)):
    fruit_count[fruits[right]] = fruit_count.get(fruits[right], 0) + 1

    while len(fruit_count) > 2:  # If more than 2 fruit types exist, shrink the window
        fruit_count[fruits[left]] -= 1
        if fruit_count[fruits[left]] == 0:
            del fruit_count[fruits[left]]  # Remove fruit type if its count is 0
        left += 1  # Move left pointer

    max_fruits = max(max_fruits, right - left + 1)  # Update max window size

return max_fruits

Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
    
            // Two pointer approach
            int left = 0;
            int right = 0;
            int sum = 0;
            int minLen = INT_MAX;
            while (right < nums.size()) {
                sum += nums[right];
                while (sum >= target) {
                    minLen = min(right - left + 1, minLen);
                    // decrement the left pointer until sum becomes less
                    sum -= nums[left];
                    left++;                
                }
    
                right++;
            }
            return minLen == INT_MAX ? 0 : minLen;
        }
    };