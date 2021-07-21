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

#define ENTER printf("\n")
int dx[6] = {0, 0, 0, 0 , 1, -1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};
struct Loc
{
	int x;
	int y;
	int z;
	
	Loc(int a, int b, int c)
	{
		x = a;
		y = b;
		z = c;
	}
};

int main ()
{
	//freopen("input.txt", "rt", stdin);
	while(1)
	{
		
		int l, r, c;
		int escape = 0;
		char building[31][31][31];
		int check[31][31][31] ={0, };
		queue<pair<Loc, int> > q;
		
		
		cin >> l >> r >> c;
		
		if(l == 0 && r == 0 & c == 0) break; // 프로그램 종료 
		
		for(int i = 0; i < l; i++)
		{
			for(int j = 0; j<r; j++)
			{
				cin >> building[i][j];
			}
		}
		
		for(int i = 0; i < l; i++)
		{
			for(int j = 0; j<r; j++)
			{
				for(int k = 0; k<c; k++) 
				{
					if(building[i][j][k] == 'S')
					{
						check[i][j][k]=1;
						q.push(make_pair(Loc(i,j,k), 0));
					}
				//ENTER;
				}	
			}
			//TER;
		}
		
		
//		for(int i = 0; i < l; i++)
//		{
//			for(int j = 0; j<r; j++)
//			{
//				for(int k = 0; k<c; k++) 
//				{
//					printf("%c ",building[i][j][k]);
//				}	
//				ENTER;
//			}
//			ENTER;
//		}
		
		
		while(!q.empty())
		{
			Loc temp = q.front().first;
			int minute = q.front().second;
			
			q.pop();
			
			if(building[temp.x][temp.y][temp.z] == 'E')
			{
				//printf("Check\n");
				escape = minute;
				break;
			}
			
			for(int t = 0; t<6; t++)
			{
				int xpos = temp.x + dx[t];
				int ypos = temp.y + dy[t];
				int zpos = temp.z + dz[t];
				//printf("Xpos : %d Ypos : %d Zpos : %d\n", xpos, ypos, zpos);
				if(xpos < 0 || ypos < 0 || zpos < 0 || xpos >= l || ypos >= r || zpos >= c ) continue;
				//printf("Xpos : %d Ypos : %d Zpos : %d Level : %d\n", xpos, ypos, zpos, minute);
				if(building[xpos][ypos][zpos] != '#' && check[xpos][ypos][zpos] == 0)
				{
					
					check[xpos][ypos][zpos] = 1;
					q.push(make_pair(Loc(xpos, ypos, zpos), minute + 1));
				}
				
					//				for(int i = 0; i < l; i++)
					//		{
					//			for(int j = 0; j<r; j++)
					//			{
					//				for(int k = 0; k<c; k++) 
					//				{
					//					printf("%d ",check[i][j][k]);
					//				}	
					//				ENTER;
					//			}
					//			ENTER;
					//		}
			}
		}
		
		if(escape > 0) printf("Escaped in %d minute(s).\n", escape);
		else 		   printf("Trapped!\n");
		
		while(!q.empty())
		{
			q.pop();
		}
	
	}
	
	return 0;
}
