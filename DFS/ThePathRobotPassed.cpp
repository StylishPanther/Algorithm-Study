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
char cmap[26][26];
int map[26][26];
int check[26][26];
int map_area;
queue<char> ans;
char direction[4] ={'>', '<', 'v', '^'};
int dx[4] = {0, 0, 2, -2};
int dy[4] = {2, -2, 0, 0};

struct Loc
{
	int x;
	int y;
	char dir;
	
	Loc(int a, int b, char c)
	{
		x = a;
		y = b;
		dir = c;
	}
};
int h, w;

char dir_decide(char cur_dir, char next_dir)
{
	if(cur_dir == '>' && next_dir == '^') return 'L';
	if(cur_dir == '>' && next_dir == 'v') return 'R';
	
	if(cur_dir == '<' && next_dir == '^') return 'R';
	if(cur_dir == '<' && next_dir == 'v') return 'L';
	
	if(cur_dir == '^' && next_dir == '>') return 'R';
	if(cur_dir == '^' && next_dir == '<') return 'L';
	
	if(cur_dir == 'v' && next_dir == '>') return 'L';
	if(cur_dir == 'v' && next_dir == '<') return 'R';
	
	//return 'L';
}

void DFS(Loc dot, int l)
{
	if(l == map_area)
	{
		while(!ans.empty())
		{
			cout << ans.front();
			ans.pop();
		}
	}
	else
	{
		for(int k = 0; k<4; k++)
		{
			int one_xpos = dot.x + dx[k] / 2;
			int one_ypos = dot.y + dy[k] / 2;
			
			char temp;
			int xpos = dot.x + dx[k];
			int ypos = dot.y + dy[k];
			
			
			if(xpos < 0 || ypos < 0 || one_xpos >= h || one_ypos >= w || map[one_xpos][one_ypos] == 0 || check[one_xpos][one_ypos] == 1 || check[xpos][ypos] == 1) continue;
			
			if(map[one_xpos][one_ypos] == map[dot.x][dot.y]) temp = direction[k];
			
			if(dot.dir == temp) ans.push('A');
			else
			{	
			//	printf("%c %c\n", dot.dir, temp);
				ans.push(dir_decide(dot.dir , temp));
				ans.push('A');
			}
			check[dot.x][dot.y] = 1;
			check[one_xpos][one_ypos] = 1;
			//printf("Point : %d %d Dir : %c\n", xpos, ypos, temp);
			DFS(Loc(xpos, ypos, temp), l+2);
			
		}
	}
}
int main ()
{
	
	int flag = 1;
	//freopen("input.txt","rt",stdin);
	
	cin >> h >> w;
	Loc spoint = Loc(0, 0, ' ');
	queue<char> ans;
	for(int i = 0 ; i < h; i++)
	{
		cin >> cmap[i];
	}
	 // 입력을 문자열로 받는다 
	 
	for(int i = 0 ; i<h; i++)
	{
		for(int j = 0 ; j<w; j++)
		{
			int cnt = 0;
			if(cmap[i][j] == '#')
			{
				map[i][j] = 1;
				map_area++;
			}
			else				  map[i][j] = 0;
			//printf("%d ",map[i][j]);			
		}
		//ENTER;
	}
	for(int i = 0 ; i<h; i++)
	{
		for(int j = 0 ; j<w; j++)
		{
			int cnt = 0;
			for(int k = 0; k<4; k++)
			{
				int xpos = i + dx[k] / 2;
				int ypos = j + dy[k] / 2;
				if(xpos < 0 || ypos < 0 || xpos >= h || ypos >= w) continue;
				if(map[i][j] == 1 && map[xpos][ypos] == 1) cnt++;
			}
			
			if(cnt == 1)
			{
				//printf("%d %d\n", i, j);
				spoint.x = i;
				spoint.y = j;
			}
		}
	}
	
	for(int k = 0; k<4; k++)
	{
		int xpos = spoint.x + dx[k] / 2;
		int ypos = spoint.y + dy[k] / 2;
		if(xpos < 0 || ypos < 0 || xpos >= h || ypos >= w) continue;
		if(map[xpos][ypos] == map[spoint.x][spoint.y]) spoint.dir = direction[k];
	}
	
	printf("%d %d\n%c\n", spoint.x + 1, spoint.y + 1, spoint.dir);
	DFS(spoint, 1);
}
	
