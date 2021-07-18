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
struct Talk
{
	int day;
	int cost;
	
	Talk(int a, int b)
	{
		day = a;
		cost = b;
	}
	
};

int n;
vector<Talk> map;
int check[16];
int cost[16];


void DFS(int depth, int sum)
{
	if(depth > n)
	{
		return;
	}
	else
	{
		if(cost[depth] < sum) cost[depth] = sum; 
		DFS(depth+map[depth].day, sum+map[depth].cost);
		DFS(depth+1, sum);
	}
}
int main (void)
{
	cin >> n;
	int max = 0;
	for(int i = 0; i < n ; i++)
	{
		int a, b;
		cin >> a >> b;
		
		map.push_back(Talk(a, b));
			//printf("%d %d\n", map[i].day, map[i].cost);
	}
	
	
	
	DFS(0, 0);
	
	
	for(int i = 0; i <= n ; i++ )
	{
		if(cost[i] > max) max = cost[i];
		//printf("%d ",cost[i]);
	}
	
	cout << max;

}
