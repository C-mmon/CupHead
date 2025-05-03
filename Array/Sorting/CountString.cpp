Ques 1: Given a sorted string S of length N consisting of only lowercase english alphabets. The task is to return the length of longest substring consisting of same characters.

Input: aaabbccccdde
Ans: 4 (substring is "cccc")

First Approach: Linear traversal, TC: O(N)
Iterate through the string and maintain a counter of same characters. Update global answer whenever encounter a different character. Repeat till end of string is reached.

Second Approach: Binary Search, TC: 26*log(N)
For every 26 characters in ['a' to 'z'], we do a binary search.
Find the first and last position of the character in string 'S'.
Update global answer with maximum of all answers i:e [last - first + 1].
