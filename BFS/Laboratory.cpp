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


int main_lab[9][9];
int sub_lab[9][9];



int n, m;
int res_x[3];
int res_y[3];

int maxi = -21470000;
vector<dot> road;
vector<dot> virus;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void DFS(int l, int s)
{
	if(l == 3)
	{
		for(int j = 0; j<l ; j++)
		{
			//printf("%d %d ,",res_x[j], res_y[j]);
		}
		//printf("\n");
		
		
		int check[9][9] = {0,};
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++) sub_lab[i][j] = main_lab[i][j];
		}
		for(int j = 0; j<l ; j++) sub_lab[res_x[j]][res_y[j]] = 1; // 벽 3개 생성  
		
//		for(int i = 0; i < n; i++)
//		{
//			for(int j = 0; j < m; j++)
//			{
//				printf("%d ", sub_lab[i][j]);
//			}
//			printf("\n");
//		}
		
		//printf("\n");
		queue<dot> q;
		
		for(int i = 0; i < virus.size() ; i++)
		{
			q.push( dot(virus[i].x, virus[i].y) );
			check[virus[i].x][virus[i].y] = 1;
		}
		while(!q.empty())
		{
			dot temp = q.front();
			q.pop();
			
			for(int k = 0; k < 4; k++)
			{
				int xpos = temp.x + dx[k];
				int ypos = temp.y + dy[k];
				
				if(xpos < 0 || ypos < 0 || xpos >= n || ypos >= m) continue;
				
				if(sub_lab[xpos][ypos] == 0 && check[xpos][ypos] == 0)
				{
					//printf("Xpos : %d Ypos : %d\n", xpos, ypos);
					sub_lab[xpos][ypos] = 2;
					check[xpos][ypos] = 1;
					q.push(dot(xpos, ypos));
				}
			}
		}
		
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<m; j++)
			{
				if(sub_lab[i][j] == 0) cnt++;
			}
		}
		
		if(maxi < cnt) maxi = cnt;
	}
	
	
	else
	{
		for(int i = s ; i<road.size() ;i++)
		{
			res_x[l] = road[i].x;
			res_y[l] = road[i].y;
			DFS(l+1, i+1);
		}
	}
}

int main()
{
	freopen("input.txt","rt",stdin);
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> main_lab[i][j];
			if(main_lab[i][j] == 0) road.push_back(dot(i, j)); // 비어있는 벽 
			else if(main_lab[i][j] == 2) virus.push_back(dot(i, j)); // 바이러스 있는 곳 
			//printf("%d ", main_lab[i][j]);
		}
		//printf("\n");
	}
	
//	for (int i = 0; i<empty.size(); i++)
//	{
//		printf("%d %d \n", empty[i].x, empty[i].y);
//		printf("%d %d \n", virus[i].x, virus[i].y);
//	}
//	for (int i = 0; i<virus.size(); i++)
//	{
//		printf("%d %d \n", virus[i].x, virus[i].y);
//	}
	
	DFS(0,0);
	cout << maxi;
}
