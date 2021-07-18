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

// Path Searching (Depth First Search) 

int map[31][31];
int check[31];
int cnt;
int n, k;

void DFS (int v)
{
	if(v == n)
	{
		cnt++;
	}
	else
	{
		for(int i = 1; i<=n; i++)
		{
			if(map[v][i]==1 && check[i]==0)
			{
				check[i] = 1;
				DFS(i);
				//cout << v << ' ';	
				check[i] = 0;
			}
		}
	}
}

int main (void)
{
	
	//freopen("input.txt","rt",stdin);
	cin >> n >> k;

	
	for (int i = 0; i< k;i++)
	{
		int a, b;
		
		cin >> a >> b;
		map[a][b] = 1;
		
		
		//cout << a << ' ' << b << endl;
	}
	
//	for (int i = 1; i<=n;i++)
//	{
//		for(int j = 1; j<=n;j++) //cout << map[i][j] << ' ';
//		//cout << endl;
//	}
	
	check[1] = 1;
	DFS(1);
	printf("%d\n",cnt);

}
