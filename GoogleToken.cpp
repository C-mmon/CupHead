#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s = "T..C..C";
  vector <int> tokenPos(3,0); 
  vector <int> coinCount(3,0);
  for(int i=0; i < (int)s.size(); i++)
      int mod = i % 3;
      if s[i] == 'T'
          tokenPos[mod] =  1;
      else
          coinCount[mod] += 1;
    return accumualate(coinCount.begin(), coinCount.end(), coinCount);
}
      
