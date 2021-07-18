#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>


int map[101][101];
int check[101][101];



int m, n, k;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
using namespace std;

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

int main()
{
	cin >> m >> n >> k;
	queue<Loc> q;
	int cnt = 0;
	int area_num = 0;
	
	vector<int> area; 
	while(k--)
	{
		int a, b, c, d;
		
		cin >> a >> b >> c >> d;
		for (int i = a; i<c ; i++)	
		{
			for (int j = b; j<d ; j++)
			{
				map[i][j] = 1;
			}
		}
	}
	

	for (int i = 0; i<n ; i++)	
		{
			for (int j = 0; j<m ; j++)
			{
				if(map[i][j]==0)
				{
					q.push(Loc(i, j));
					map[i][j] = 1;
					//printf("Xpos : %d, Ypos : %d\n", i, j);
					area_num++;
				}
					
				while(!q.empty())	
				{
					cnt++;
					
					Loc temp = q.front();
					q.pop();
					
					
					for(int r = 0; r<4; r++)
					{
						int xpos = temp.x + dx[r];
						int ypos = temp.y + dy[r];
					
						if(xpos < 0 || ypos < 0 || xpos >= n || ypos >= m || map[xpos][ypos] == 1) continue;
						
						//printf("Xpos : %d, Ypos : %d\n", xpos, ypos);	
						q.push(Loc(xpos, ypos));
						
						map[xpos][ypos] = 1;
					}
				}
				
				if(cnt!=0) area.push_back(cnt);
				cnt = 0;
			}
		}
		
		
		sort(area.begin(), area.end());
		
		cout << area_num << endl;
		for(int r = 0 ; r < area.size() ; r++) cout << area[r] << ' ';
		
		
//		printf("%d\n", area_num);
//		printf("%d\n ", area.size());
}
