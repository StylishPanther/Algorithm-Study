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
// Searching the Maze
int map[8][8];
int check[8][8];
int cnt;
int n, k;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void DFS (int h, int w)
{
	if(h==7 && w==7)
	{
		cnt++;
		
	}
	else
	{
		
			for(int k = 0 ; k < 4 ; k++)
			{
				if(h+dy[k] < 1 || h+dy[k] > 7 ||w+dx[k] < 1 || w+dx[k] > 7) continue;
				
					if(map[h][w] == 1 && check[h+dy[k]][w+dx[k]] == 0) 
					{
						check[h+dy[k]][w+dx[k]] = 1;
						DFS(h+dy[k],w+dx[k]);
						check[h+dy[k]][w+dx[k]] = 0;
					}
				
			}
	}
}


int main (void)
{
	
	//freopen("input.txt","rt",stdin);
	
	for (int i = 1; i<=7;i++)
	{
		for(int j = 1; j<=7;j++)
		{
			cin >> map[i][j];
			
			map[i][j] = map[i][j] == 0 ? 1 : 0; 
		} 
		
		//cout << endl;
	}
	//cout <<"Fucking\n";
	
	check[1][1] = 1;
	DFS(1,1);
	printf("%d\n",cnt);

}
