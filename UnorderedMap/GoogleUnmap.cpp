#include <stdio.h>
using namespace std;

//we need to find the max{x,y,z}- min{x,y,z} <=d
int main()
{
	vector <int> arr;


	//declared an array to insert a given number
	arr.insert(lower_bound(arr.begin(),arr.end(), value),value);
	int left =0;
	for(int right =0; right< arr.size(); right++)
	{
		//here we dont have to worry about left, because it will never move past arr[right]
		while(arr[right]-arr[left] >d) 
		{
			left++;
		}

		if(right-left+1 >= 3)
		{
			return {arr[left],arr[left+1], arr[right]};
		}
	}
	return {}
}
