#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    vector<TrieNode*> children;
    bool isWord;
    int data;
    int maxVal;
    
    TrieNode() 
    {
        children.resize(26, nullptr); // Initialize all children to nullptr
        isWord = false;
        data = 0;
        maxVal = 0;
    }
};

class Solution {
private:

    void insert(TrieNode* root, const string& word, int score) 
    {
        TrieNode* node = root;
        for (char ch : word) 
        {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
            node->maxVal = max(node->maxVal, score);
        }
        node->isWord = true;
        node->data = score;
    }

    int queryMax(TrieNode* root, const string& prefix) 
    {
        TrieNode* node = root;
        for (char ch : prefix) 
        {
            int idx = ch - 'a';
            if (!node->children[idx]) return 0;  // No match
            node = node->children[idx];
        }
        return node->maxVal;
    }

public:
    vector<int> findMaxScore(const vector<pair<string, int>>& items, const vector<string>& queries) 
    {
        TrieNode* root = new TrieNode();
        
        for (const auto& p : items)
            insert(root, p.first, p.second);

        vector<int> results;
        for (const string& query : queries) 
       {
            results.push_back(queryMax(root, query));
        }
        return results;
    }
};

int main() 
{
vector<pair<string, int>> items = {
        {"google", 100},
        {"goggle", 5},
        {"go", 95},
        {"banana", 10},
        {"ban", 50},
        {"band", 30},
        {"bat", 60},
        {"batter", 70},
        {"batman", 80},
        {"batmobile", 90}
    };

    vector<string> queries = {"go", "goo", "ban", "bat", "batter", "batman", "batmobile", "zebra"};

    Solution sol;

    vector<int> results = sol.findMaxScore(items, queries);
    for (int i = 0; i < queries.size(); ++i) {
        cout << "Query \"" << queries[i] << "\" -> max score = " << results[i] << "\n";
    }

    return 0;
}
