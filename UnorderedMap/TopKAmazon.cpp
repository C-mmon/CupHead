#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec = {5, 2, 1, 3, 2, 1, 1, 5, 3, 3}; // example stream
    int k = 3;

    unordered_map<int, int> freq;

    // Min-heap comparator: smallest frequency on top, tie-break by bigger element to keep consistent order
    auto comp = [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first)
            return a.second < b.second; // if freq same, pop smaller element first
        return a.first > b.first; // min heap by frequency
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> minHeap(comp);

    for (int i = 0; i < (int)vec.size(); i++) {
        int num = vec[i];
        freq[num]++;

        // Push updated frequency and element to the heap
        minHeap.push({freq[num], num});

        // Keep only top k elements in the heap by popping smaller frequency elements
        while ((int)minHeap.size() > k) {
            minHeap.pop();
        }

        // Create a copy of heap to print top-k without modifying original
        auto tempHeap = minHeap;
        vector<pair<int, int>> topElements;

        while (!tempHeap.empty()) {
            topElements.push_back(tempHeap.top());
            tempHeap.pop();
        }

        // Reverse to print highest freq first
        reverse(topElements.begin(), topElements.end());

        cout << "Top " << k << " elements after processing element " << num << ": ";
        for (auto &p : topElements) {
            cout << p.second << "(" << p.first << ") ";
        }
        cout << endl;
    }

    return 0;
}
