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

struct dot
{
	int x;
	int y;
	dot (int a, int b)
	{
		x = a;
		y = b;
	}
};

struct Loc
{
	int x;
	int y;
	int second;
	
	Loc(int a, int b, int c)
	{
		x = a;
		y = b;
		second = c;
		
	}
};

int main_lab[51][51];
int sub_lab[51][51];



int n, m;
int res_x[11];
int res_y[11];
int time = 0;
int mini = 21470000;

vector<dot> virus;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void DFS(int l, int s)
{
	if(l == m)
	{
//		for(int j = 0; j<l ; j++)
//		{
//			printf("%d %d ,",res_x[j], res_y[j]);
//		}
//		printf("\n");
		
		
		int check[51][51] = {0,};
		int cnt = 0;
		int flag = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++) 
			{
				if(main_lab[i][j] == 2)  sub_lab[i][j] = 0;
				else 					 sub_lab[i][j] = main_lab[i][j];
			}
		}
		
		for(int j = 0; j<l ; j++) sub_lab[res_x[j]][res_y[j]] = 2; // 바이러스 m개 결정  
//		printf("Before\n");
//		for(int i = 0; i < n; i++)
//		{
//			for(int j = 0; j < n; j++)
//			{
//				printf("%d ", sub_lab[i][j]);
//			}
//			printf("\n");
//		}
//		
//		printf("\n");
		queue<Loc> q;
		
		for(int i = 0; i < m ; i++)
		{
			q.push( Loc(res_x[i], res_y[i] , 0) );
			check[res_x[i]][res_y[i]] = 1;
		}
		while(!q.empty())
		{
			Loc temp = q.front();
			cnt = temp.second;
			q.pop();
			
			for(int k = 0; k < 4; k++)
			{
				int xpos = temp.x + dx[k];
				int ypos = temp.y + dy[k];
				
				if(xpos < 0 || ypos < 0 || xpos >= n || ypos >= n) continue;
				
				if(sub_lab[xpos][ypos] == 0 && check[xpos][ypos] == 0)
				{
					//printf("Xpos : %d Ypos : %d Second : %d\n", xpos, ypos, cnt);
					sub_lab[xpos][ypos] = 2;
					check[xpos][ypos] = 1;
					q.push(Loc(xpos, ypos, temp.second + 1 ));
				}
			}
		}
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(sub_lab[i][j] == 0) flag = 1;
			}
		}
//		printf("Flag : %d\n", flag);
//		printf("After\n");
//		for(int i = 0; i < n; i++)
//		{
//			for(int j = 0; j < n; j++)
//			{
//				printf("%d ", sub_lab[i][j]);
//			}
//			printf("\n");
//		}
		if(flag == 0) 
		{
			if(cnt < mini) mini = cnt;
		}
		
	}
	
	
	else
	{
		for(int i = s ; i<virus.size() ;i++)
		{
			res_x[l] = virus[i].x;
			res_y[l] = virus[i].y;
			DFS(l+1, i+1);
		}
	}
}

int main()
{
	//freopen("input.txt","rt",stdin);
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> main_lab[i][j];
			if(main_lab[i][j] == 2) virus.push_back(dot(i, j)); // 바이러스 있는 곳 
		}
		
	}
//	for (int i = 0; i < virus.size(); i++)
//	{
//		printf("%d %d \n", virus[i].x, virus[i].y);
//	}
	
	
	DFS(0,0);
	
	if(mini == 21470000 ) cout << "-1";
	else 				  cout << mini;
}
