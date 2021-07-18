#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>

using namepspace std;
// Minimum Cost with Adjacent Matrix

int map[21][21];
int check[21];
int mini = 210000;
int n, k;
void DFS(int v, int sum)
{
	if(v==n)
	{
		if(sum < mini) mini = sum;
	}
	else
	{
		for(int i = 1; i<=n; i++)
		{
			if(map[v][i]!=0 && check[v]==0)
			{
				check[v]=1;
				DFS(i,sum+map[v][i]);
				check[v]=0;
			}
		}
	}
}

int main (void)
{
	cin >> n >> k;
	for(int i = 0;i<k;i++) 
	{
		int a, b, c;
		
		cin >> a >> b >> c;
		map[a][b] = c;
	}
	
	DFS(1,0);
	
	printf("%d\n",mini);
}
