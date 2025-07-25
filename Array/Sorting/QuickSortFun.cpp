#include <bits/stdc++.h>
using namespace std;

int partition(vector <int> &arr, int low, int high)
{
	int pivot=  arr[high];
	vector <int> lessThanPivot;
	vector <int> greaterThanPivot;
	int countPivot =0;
	for(int i=low; i<=high;i++)
	{
		if(arr[i] < pivot)
		{
			lessThanPivot.push_back(arr[i]);
		}
		else if(arr[i] == pivot)
		{
			countPivot++;
		}
		else
		{
			greaterThanPivot.push_back(arr[i]);
		}
	}
	int ogArr=low;
	for(int i=0; i < lessThanPivot.size(); i++)
	{
		arr[ogArr++] = lessThanPivot[i];
	}
	for(int j=0;j<countPivot; j++)
	{
		arr[ogArr++] = pivot;
	}
	for(int k=0; k< greaterThanPivot.size(); k++)
	{
		arr[ogArr++] = greaterThanPivot[k];
	}
	return low +lessThanPivot.size()+countPivot/2;
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
