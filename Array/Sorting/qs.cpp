#include <bits/stdc++.h>
using namespace std;

int partition(vector <int> &arr, int low, int high)
{
	int pivot=  arr[high];
	int p=low;
	for(int i=low; i< high;i++)
	{
		if(arr[i]>pivot)
		{
			swap(arr[p], arr[i]);
			p++;
		}
	}
	swap(arr[p], arr[high]);
	return p;

}
void quickSort(vector <int> &arr, int low, int high)
{
	if(low< high)
	{
		int piv = partition(arr, low, high);
		quickSort(arr, low, piv-1);
		quickSort(arr, piv+1, high);
	}
	return ;
}
int main()
{
	vector <int> arr {100,88,1,2};
	quickSort(arr, 0, arr.size()-1);
	for(auto i: arr)
	{
		cout << i << endl;
	}
}
