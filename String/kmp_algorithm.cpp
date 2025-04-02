#include <iostream>
#include <string>
#include <iostream>

using namespace std;
//KMP is string-searching algorithm that efficiently find occurence of a pattern string within a text string.
// It preprocesses the pattern to create a longest prefix-suffix (LPS) array, 
// which is used to skip unnecessary comparisons in the text.


//Key thing to remember about KMP is that 
// (i) LPS array stores the length of the longest prefix of the pattern that is also a suffix for each position in the pattern.
// This allows the algorithm to skip unnecessary comparisons when a mismatch occurs,

//When we say suffix, we dont mean the last character of the string
// we are referring to a substring that endds at the current position i in the pattern.

//LPS of the pattern P = "ABABCABAB" is 0,0,1,2,0,1,2,3,4


// (ii) The LPS array is built in O(m) time, where m is the length of the pattern.
// (iii) The search process itself is done in O(n) time, where n is the length of the text.
// (iv) The overall time complexity of the KMP algorithm is O(m + n), making it efficient for large texts and patterns.

//For each position i in the patter, ]
vector <int> buildLPS(const string& pattern)
{
    int  m = pattern.size();
    int i=1;
    int prevLenPrefix = 0;
    vector <int > LPS(m, 0); // Create LPS array
    LPS[0] = 0; // The first character has no proper prefix or suffix
    while(i < m)
    {
        if(pattern[i] == pattern[prevLenPrefix])
        {
            prevLenPrefix++;
            LPS[i] = prevLenPrefix;
            i++;
        }
        else
        {
            //when a mismatch occur, we need to find the length oif the longest prefix that is also a suffix 
            // for substring processed so far.
            //LPS[previousLenPrefix] tells us that
            if(prevLenPrefix != 0)
            {
                prevLenPrefix = LPS[prevLenPrefix - 1];
            }
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }
}
// KMP Search Function
void KMPSearch(const string& text, const string& pattern) {
    int m = pattern.size();
    int n = text.size();

    // Build the LPS array
    vector<int> lps = buildLPS(pattern);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            //Remember we have to go back to previous index its better to check for i-1.
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}
int main()
{
    string text ="ababcabcabababd";
    string pattern = "ababd";
    int m = pattern.size();
    int n = text.size();
    KMPSearch(text, pattern);
}