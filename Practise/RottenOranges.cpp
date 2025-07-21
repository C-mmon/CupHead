#include <bits/stdc++.h>

using namespace std;
//-1,0 // 0,1 // 1,0 // 0,-1
vector <int> dir {-1, 0, 1, 0,-1};
int main()
{
	vector<vector<int>> mat {{2,1,0,2,1},{0,0,1,2,1},{1,0,0,2,1}};
	queue<pair<int,int>> q;
	int countGoodOrange=0;
	for(int i=0; i< mat.size(); i++)
	{
		for(int j=0; j< mat[0].size(); j++)
		{
			if(mat[i][j] == 2)
			{
				q.push({i, j});
			}
			else if(mat[i][j] == 1)
			{
				countGoodOrange++;
			}
		}
	}
	if(countGoodOrange == 0)
	{
		 cout << 0 << endl;
	}
	else if(countGoodOrange != 0 && q.size() ==0)
	{
		cout << -1 << endl;
	}
	
	int time =-1;
	while(!q.empty())
	{
		int qSize= q.size();
		for(int i=0; i<qSize; i++)
		{
			pair<int, int> badOrange = q.front();
			q.pop();
			for(int j=1; j<=4; j++)
			{
				int newX = badOrange.first+ dir[j];
				int newY = badOrange.second+ dir[j-1];
				if(newX>=0 && newY>=0  && newX < mat.size() && newY< mat[0].size() && mat[newX][newY] == 1)
				{
				mat[newX][newY] =	2;
				q.push({newX, newY});
				countGoodOrange--;
				}
			}
		}
		time++;
	}
	if(countGoodOrange == 0)
	{
		cout << time<<endl;
	}
	else
	{
		cout << -1 <<endl;
	}
}
