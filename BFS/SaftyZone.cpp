#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>

#define BAEKJOON_2468
using namespace std;

int map[101][101];
int n;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

struct Loc
{
	int x;
	int y;
	
	Loc(int a, int b)
	{
		x = a;
		y = b;
	}
};
int main ()
{
	//freopen("input.txt", "rt", stdin);
	
	cin >> n;
	int max_rain = 0;
	int max_area = 0;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			cin >> map[i][j];
			if(max_rain < map[i][j]) max_rain = map[i][j];
		}
	}
	
	for(int k = 0; k<=max_rain; k++)
	{
		int tmap[101][101] = {0,};
		int check[101][101] = {0, };
		queue<Loc> q;
		int local_number = 0;
		
		
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j<n; j++)
			{
				if(map[i][j] > k) 	tmap[i][j] = 1;
				else				tmap[i][j] = 0;
			}
		}
		
		
//		printf("Rain : %d\n", k);
//		
//		for(int i = 0; i<n; i++)
//		{
//			for(int j = 0; j<n; j++)
//			{
//				printf("%d ", tmap[i][j]);
//			}
//			printf("\n");
//		}
		
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j<n; j++)
			{
				if(tmap[i][j] == 1 && check[i][j] == 0)
				{
					q.push(Loc(i, j));
					check[i][j] = ++local_number;
				}
				
				
				while(!q.empty())
				{
					Loc loc_tmp = q.front();
					q.pop();
					
					for(int t = 0; t < 4; t++)
					{
						int xpos = loc_tmp.x + dx[t];
						int ypos = loc_tmp.y + dy[t];
						
						if(xpos < 0 || ypos < 0 || xpos >= n || ypos >= n) continue;
						
						if(tmap[xpos][ypos] == 1 && check[xpos][ypos] == 0)
						{
							check[xpos][ypos] = local_number;
							q.push(Loc(xpos,ypos));
						}
					}
					
				}
				
				
			}
		}
//		printf("Check\n");
//		for(int i = 0; i<n; i++)
//		{
//			for(int j = 0; j<n; j++)
//			{
//				printf("%d ", check[i][j]);
//			}
//			printf("\n");
//		}
		
		if(max_area < local_number) max_area = local_number;
		
		
		
		
	
		
	}
	
	cout << max_area << endl;
}
