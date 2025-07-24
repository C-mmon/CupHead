Given an array original array say y = [1,2,3,4,5] each day an addition array say x = [2,1,6,7,8] this is added to it. Now we need to find in which min day the total sum will be less than M. At each day we can remove any one element from the array.
ex: Day 0 : [1,2,3,4,5] Now sum = 15 if its less than M then 0 is our answer. Note: On day 0 we don't remove any element.
Day1: [1,2,3,4,5] + [2,1,6,7,8] = [3,3,9,11,13] Now we can remove any element say 11 . Now the sum is 3+3+9+0+13 = 28 if its less than M, then Day1 is our answer.
if we can't achieve this then return -1.

Day2: [3,3,9,0,13] + [2,1,6,7,8] = [5,4,15,7,21]
Now we can select any one element to remove say 15.
so array becomes : [5,4,0,7,21]

and so on......

Constraints: M<10^6>
Size of Array : N<20

Test Case 1:
M = 1
original Array = [10,15]
Daily Addition Array = [3,2]
Ans = -1

Test Case 2:
M = 33
original Array = [7,3,5,6,8,0,8]
Daily Addition Array = [2,4,1,1,2,3,1]
Ans = 6

Test Case 3:
M = 92
original Array = [35,58,39]
Daily Addition Array = [30,20,10]
Ans = 2

Test Case 4:
M = 905
original Array = [170,203,171,42,60,111,152]
Daily Addition Array = [60,32,63,65,70,50,63]
Ans = -1
