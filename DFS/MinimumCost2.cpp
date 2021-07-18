#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>

using namespace std;
// Minimum Cost with Adjacent List 


vector< pair<int, int> > map[21];
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
		for(int i = 0; i < map[v].size(); i++)
		{
			if(check[map[v][i].first]==0)
			{
				check[map[v][i].first]=1;
				DFS(map[v][i].first	,sum + (map[v][i].second));
				check[map[v][i].first]=0;
			}
		}
	}
}
int main (void)
{
	freopen("input.txt","rt",stdin);
	cin >> n >> k;
	
	for(int i = 0;i<k;i++) 
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back(pair<int, int> (b,c));
	}
	
	DFS(1,0);
	
	printf("%d\n",mini);
}
