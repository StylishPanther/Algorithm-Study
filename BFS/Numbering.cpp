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

#ifdef BAEKJOON_2667


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

int map[27][27];
int check[27][27];
char cmap[27][27];
int area[1000];

vector<int> varea;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main (void)
{
	int n;
	int cnt = 0;
	int local_number = 0;
	queue<Loc> q;
	
	cin >> n;
	
	for (int i = 0 ; i<n; i++)	
	{
		cin >> cmap[i];
	}
	
	for (int i = 0 ; i<n; i++)
	{
		for (int j = 0 ; j<n; j++)
		{
			map[i][j] = cmap[i][j] - '0';
	//printf("%d ", map[i][j]);
		}
		//printf("\n");
	}
	
	for(int i = 0 ; i< n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if(map[i][j] == 1 && check[i][j] == 0 ) 
			{
				q.push(Loc(i, j));
				check[i][j] =  ++local_number;
			}
		
			while(!q.empty())
			{
				Loc temp = q.front();
				q.pop();
				
				for(int k = 0 ; k < 4 ; k++)
				{
					int xpos = temp.x + dx[k];
					int ypos = temp.y + dy[k];
					
					if(xpos < 0 || ypos < 0 || xpos >= n || ypos >= n ) continue;
					
					if(map[xpos][ypos] == 1 && check[xpos][ypos] == 0)
					{
						check[xpos][ypos] = local_number;
						q.push(Loc(xpos, ypos));
					}
					
				}
			}

		}
	}
	
	cout << local_number << endl;
	
//	for (int i = 0 ; i<n; i++)
//	{
//		for (int j = 0 ; j<n; j++)
//		{
//			
//			printf("%d ", check[i][j]);
//		}
//		printf("\n");
//	}
	for (int i = 0 ; i<n; i++)
	{
		for (int j = 0 ; j<n; j++)
		{
			for(int k = 1; k <= local_number ; k++)
			{
				if(check[i][j] == k) area[k]++;
			}
		}
	}
	
	for(int k = 1; k <= local_number ; k++) varea.push_back( area[k] );
	sort(varea.begin(), varea.end());
	for (int i = 0; i<varea.size() ; i++) printf("%d\n",varea[i] );
	
}

#endif
