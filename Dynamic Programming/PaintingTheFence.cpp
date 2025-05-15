//No more than two fence can have the same colour
// Lets sayy that I am on the ith fence, then ith+1 will have two option, if i-2 has been painted with different colour, then 
// then ith+1 can be painted with same colour as ith, or else, we can select a new colour from k-1 and start painting the current fence.

// same
//Problem with the above thought process is that, we need to account for i-2, which might not be correct.
// number of ways to paint the 
   if (n == 0) return 0;
    if (n == 1) return k;
int n, k; // n represent the fence and k represent the different colour 
vector <int> same (n+1,0);
//note we are using n+1 beause n=0 also represents the state and till n we need to have atleast n+1 same in our array.
vector <int> total (n+1,0);
vector <int> diff (n+1,0);

same[1] = 0 ;
diff[1] = k;
total[1] = k;
for(int i=2; i<=n;i++)
  same[i] = diff[i-1];
  diff[i]= total[i-1]*  (k-1);
  total[i] = same[i] + diff[i];


return total[n];

