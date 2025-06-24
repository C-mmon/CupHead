#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>

using namespace std;

double shortestDistance(const string& document, const string& word1, const string& word2) {
    // Convert document to lowercase
    string lowerDoc = document;
    boost::algorithm::to_lower(lowerDoc);

    // Convert word1 and word2 to lowercase
    string w1 = word1, w2 = word2;
    boost::algorithm::to_lower(w1);
    boost::algorithm::to_lower(w2);

    vector<double> pos1, pos2;
    size_t index = 0, wordStart = 0;

    // Tokenize the document while tracking word start indices
    while (index < lowerDoc.size()) {
        // Skip leading spaces
        while (index < lowerDoc.size() && isspace(lowerDoc[index])) index++;

        wordStart = index;

        // Find end of word
        while (index < lowerDoc.size() && !isspace(lowerDoc[index])) index++;

        if (wordStart < index) {
            string currentWord = lowerDoc.substr(wordStart, index - wordStart);

            if (currentWord == w1) {
                pos1.push_back(wordStart + (index - wordStart) / 2.0);
            } else if (currentWord == w2) {
                pos2.push_back(wordStart + (index - wordStart) / 2.0);
            }
        }
    }

    // If either word is not found
    if (pos1.empty() || pos2.empty()) return -1.0;

    // Two-pointer approach to find minimum absolute difference
    int i = 0, j = 0;
    double minDist = numeric_limits<double>::max();

    while (i < pos1.size() && j < pos2.size()) {
        double d1 = pos1[i], d2 = pos2[j];
        minDist = min(minDist, abs(d1 - d2));

        if (d1 < d2) i++;
        else j++;
    }

    return minDist;
}
