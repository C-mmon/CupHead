#include <bits/stdc++.h>

using namespace std;
int main()
{
	int a=10; //value will 8421 // 1010
	int b=10;
	int ans=0;
	while(a >0 )
	{
		if(a&1)
		{
			ans+=b;
		}
		a=a>>1;
		b=b<<1;
	}
	cout << ans<<endl;
}
