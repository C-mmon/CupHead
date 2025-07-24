Flow of Numbers
Given a seq {a0,a1,a2,......,a n-1} of length n, a good seq is one with below conditions

a0 = 0
abs(ai-ai+1)<=1 i.e consecutive numbers can differ by atmost one
Given n = length of seq and m = number of limited numbers L = (i,k) i.e max value at index i can be k,
find the maximum value that we can have in our sequence

ex i/p
4 // t = number of test cases
4 3 //
1 0
2 0
3 0 o/p = 0 0 0 0 0

5 2 // n,m
1 0
4 0 o/p = 1 // 0 0 1 1 0

5 1
4 1 o/p = 2 // 0 1 2 2 1 2

10 2
4 2
8 0 o/p =3


  You want to create a sequence {a[0] a[1], ... a[N-2], a[N-1]} whose length is N. The sequence must meet the following conditions:

a[0] should always be 0.
a[i], the ith number should always be 0 or a positive integer
the absolute value of the difference between ith and i+1 th number should be equal to or smaller than 1. In other words, every i satisfies the condition:
|a[i] - a[i+1]| <= 1.
There can be a limited value in the sequence. A limited value is given as (x,y). x means the place of a number & y means the maximum of a number. Given (2,5), the max value of a[2] can be 5. There may be M limited values and the following requirement is added:
Given a limited value of (x,y) the xth number cannot exceed y (a[x] <= y)
GIven the length of a sequence N, and M limited values, you need to find the way that maximizes the largest value when creating a sequence satisfying the a forementioned conditions. Then you are required to print the max value. There maybe multiple sequences that have a max value.

Example:
N = 10, M = 2
{(2,1) , (7,1)}
Output: 3
Explaination: The following sequence can be created using the given conditions
{0, 1, 1, 2, 3, 3, 2, 1, 2, 3}. And the max value here is 3.

N = 10, M = 5
{(1,3) (2,9) (4, 6) (7, 4) (9, 5)}
Output: 5

N = 10, M = 1
{(3, 1)}
Output: 7
Explaination: {0, 1, 1, 2, 3, 4, 5, 6, 7}
