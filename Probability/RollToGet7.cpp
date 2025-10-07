The idea is to roll the six-sided die twice.
Let result of the first Roll be R1, and the result of the second roll be R.
Calculate the result using N = 6(R-1) + R2;
This will give you a number from 1 to 36
If the remainder is 0, return 7, else 


  Now the smallest possible number in this is R1= 1 and R2= 1
  N = 6 *(R1-1) + R2;
  R max will be when R1= 6 and R2= 6
  N = 6 * (6-1) + 6 = 36
  R(final) = (N-1) mod 7 + 1;
  We accept N when N is less than 35, there is only one case

repeat:
  R1=  roll()
  R2 = roll()
