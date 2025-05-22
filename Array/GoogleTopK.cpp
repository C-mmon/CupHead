This problem require the use of two multiset, multiset why? because element can repeat itself.

But if elements can store duplicate element, it also has a trade off, lets say you were to delete some element from the multiset.

You would think oh, i will just do a quick erase, but the bad thing is that, it will end up erasing all the occurrence of the given value.

I will tell you later, how to tackle this problem, but lets say that you have created two multiset,.

one multiset to store the first half till K and the second multiset to store the remaininig number.



Now, if we have done this partitioning, we have to realize one thing, we should always maintain element such that first the size of the 

first multiset is k and the size of the remaining multiset is window-k.

Next thing is that we want to ensure that all the elements in the topk are greater then all the elements in the second half of the set.



So basically it would look something like this [10,20,30], [40,50]

the top k elemeennt if k=3, will be the end of the first multiset.



Now, we have to take care of two things,

When sliding windows comes, it comes with two variable, left and right.

we have to remove the left entry but we do not know in which set it lies, second thing we want to insert a new entry but we do not know

in which set we have to insert.

Now, for the new right element, all we have to do is comparing,

[smallest_value......largestvalue] <- multiset 1.

compare right with kth largest element.



 If new_num < *top_k_ms.begin()

Add new_num to bottom_elements_ms.

Add new_num to current_sum.

else

Add new_num to top_k_ms.



After addition, we have to perform rebalancing, if top_k_ms.size() > k: This means top_k_ms now contains k+1 elements. We need to move its smallest element (which is now the (k+1)-th largest overall) to bottom_elements_ms.



Now talkking about removal, as I said earlier, we cant just straight away remove element,

To remove just one instance of old_num, you need to find its iterator first and then use erase(iterator).

Now again perform the comparison operation, if the old num element is smnaller than top k element,

it means it lies in this set, so find the instance and delete it
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<double> getAverages(const vector<int>& nums, int windowSize, int k) {
        vector<double> result;
        if (windowSize == 0 || k >= windowSize || nums.size() < windowSize) return result;

        multiset<int> top_k, bottom;
        long long sum = 0;

        // Fill initial window
        for (int i = 0; i < windowSize; ++i) {
            bottom.insert(nums[i]);
            sum += nums[i];
        }
        balance(top_k, bottom, sum, k);

        result.push_back((double)sum / (windowSize - k));

        // Slide window
        for (int i = windowSize; i < nums.size(); ++i) {
            int out = nums[i - windowSize], in = nums[i];

            // Remove outgoing
            if (bottom.count(out)) {
                bottom.erase(bottom.find(out));
                sum -= out;
            } else {
                top_k.erase(top_k.find(out));
            }

            // Add incoming
            if (!top_k.empty() && in >= *top_k.begin()) {
                top_k.insert(in);
            } else {
                bottom.insert(in);
                sum += in;
            }

            balance(top_k, bottom, sum, k);

            result.push_back((double)sum / (windowSize - k));
        }
        return result;
    }

private:
    void balance(multiset<int>& top_k, multiset<int>& bottom, long long& sum, int k) {
        while ((int)top_k.size() < k && !bottom.empty()) {
            auto it = prev(bottom.end());
            top_k.insert(*it);
            sum -= *it;
            bottom.erase(it);
        }
        while ((int)top_k.size() > k) {
            auto it = top_k.begin();
            bottom.insert(*it);
            sum += *it;
            top_k.erase(it);
        }
    }
};
