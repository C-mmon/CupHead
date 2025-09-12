Binary Search Logic:
Start from 0 to distance d.
while( high - low < eps):
{
 mid = (low+ high)/2;
 Check feasiability(mid)
  -> if feasible then high = mid
  -> else, low =  mid

We can return any answer high or low.
