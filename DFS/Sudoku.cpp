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

#define SIZE 9 
struct Loc
{
	int x;
	int y;
	Loc (int a, int b)
	{
		x = a;
		y = b;
	}
};

vector<Loc> spot;
int cnt;
int check[1000];
int map[10][10];
void DFS (Loc temp, int l)
{
	if(l == spot.size())
	{
		
		for(int i = 0; i<SIZE ; i++)
		{
			for(int j = 0 ; j<SIZE ; j++)
			{
				printf("%d ",map[i][j]);
			}
				printf("\n");
		}	
		
		exit(0);
		
	}
	
	else
	{
		for(int i = 1; i<=SIZE; i++) // 1~9까지의 경우의 수 탐색 
		{
			int square_flag = 1;
			int hor_line_flag = 1;
			int ver_line_flag = 1;
			
			for(int k = 0; k < SIZE; k++) if(map[temp.x][k] == i) hor_line_flag = 0; // 가로 라인 확인 
			for(int k = 0; k < SIZE; k++) if(map[k][temp.y] == i) ver_line_flag = 0; // 가로 라인 확인 
			
			
			// 스퀘어 확 인  
			if(temp.x >= 0 && temp.x <=2) // y축으로 1~3 
			{
				if(temp.y >= 0 && temp.y <=2) // x축으로 1~3 
				{
					for(int a = 0; a < 3; a++)
					{
						for(int b = 0; b < 3; b++)
						{
							if(map[a][b] == i) square_flag = 0;
						}
					}
				}
				
				else if(temp.y >= 3 && temp.y <=5) // x 축으로 4~6 
				{
					for(int a = 0; a < 3; a++)
					{
						for(int b = 3; b < 6; b++)
						{
							if(map[a][b] == i) square_flag = 0;
						}
					}
				}
				
				else if(temp.y >= 6 && temp.y <=8) // x 축으로 4~6 
				{
					for(int a = 0; a < 3; a++)
					{
						for(int b = 6; b < 9; b++)
						{
							if(map[a][b] == i) square_flag = 0;
						}
					}
				}	
			} 
			
			else if(temp.x >= 3 && temp.x <=5) // y축으로 3~6 
			{
				if(temp.y >= 0 && temp.y <=2) // x축으로 1~3 
				{
					for(int a = 3; a < 6; a++)
					{
						for(int b = 0; b < 3; b++)
						{
							if(map[a][b] == i) square_flag = 0;
						}
					}
				}
				
				else if(temp.y >= 3 && temp.y <=5) // x 축으로 4~6 
				{
					for(int a = 3; a < 6; a++)
					{
						for(int b = 3; b < 6; b++)
						{
							if(map[a][b] == i) square_flag = 0;
						}
					}
				}
				
				else if(temp.y >= 6 && temp.y <=8) // x 축으로 7~9 
				{
					for(int a = 3; a < 6; a++)
					{
						for(int b = 6; b < 9; b++)
						{
							if(map[a][b] == i) square_flag = 0;
						}
					}
				}	
			} 
			
			else if(temp.x >= 6 && temp.x <=8) // y축으로 7 ~ 9
			{
				if(temp.y >= 0 && temp.y <=2) // x축으로 1~3 
				{
					for(int a = 6; a < 9; a++)
					{
						for(int b = 0; b < 3; b++)
						{
							if(map[a][b] == i) square_flag = 0;
						}
					}
				}
				
				else if(temp.y >= 3 && temp.y <=5) // x 축으로 4~6 
				{
					for(int a = 6; a < 9; a++)
					{
						for(int b = 3; b < 6; b++)
						{
							if(map[a][b] == i) square_flag = 0;
						}
					}
				}
				
				else if(temp.y >= 6 && temp.y <=8) // x 축으로 7~9 
				{
					for(int a = 6; a < 9; a++)
					{
						for(int b = 6; b < 9; b++)
						{
							if(map[a][b] == i) square_flag = 0;
						}
					}
				}	
			} 
			
			//printf("%d %d %d Level : %d\n", ver_line_flag, hor_line_flag, square_flag, l);
			
			
			if(ver_line_flag == 1 && square_flag == 1 && hor_line_flag == 1 && check[l] == 0)
			{
				//printf("Cnt : %d\n", cnt++);
				map[temp.x][temp.y] = i;
				check[l] = 1;
				DFS(spot[l+1], l+1);
				check[l] = 0;
				map[temp.x][temp.y] = 0;
			}
			
			
			
			
		}
	}
}

int main ()
{
	
	//freopen("input.txt","rt",stdin);
	for(int i = 0; i<SIZE ; i++)
	{
		for(int j = 0 ; j<SIZE ; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 0) spot.push_back(Loc(i, j));
			
		}
	}
	
	//printf("Spot Size : %d\n", spot.size());
	for(int i = 0; i<spot.size() ; i++)
	{
		//printf("%d %d\n", spot[i].x, spot[i].y);
	}
	
	DFS(Loc(spot[0]), 0);
}
