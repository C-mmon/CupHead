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
