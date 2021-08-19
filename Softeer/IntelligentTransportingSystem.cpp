#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include <algorithm>

using namespace std;

typedef struct light 
{
	int x[3];
	int y[3];
	char indir;
	char outdir[3];
	
	
}LIGHT;
struct state
{
	int x;
	int y;
	char dir;
	int time;
	state(int a, int b, char c, int t)
	{
		x = a;
		y = b;
		dir = c;
		time = t;
	}
};

LIGHT sign[12]=  { {{-1, 0, 1}, {0,1,0}, 'R',{'U','R','D'} } , {{0, -1, 0}, {-1,0,1}, 'U',{'L','U','R'}}, {{1, 0, -1}, {0,-1,0}, 'L',{'D','L','U'}}, {{0, 1, 0}, {-1,0, 1}, 'D',{'L','D','R'}}, 
				{{-1, 0, INF }, {0,1, INF}, 'R',{'U','R','N'}},  {{0, -1, INF}, {-1,0,INF}, 'U', {'L','U','N'}} ,  {{0, 1, INF}, {-1, 0, INF}, 'L',{'L','D','N'}}, {{1, 0, INF}, {0,1,INF},'D', {'D','R','N'}},
				{{0, 1, INF }, {1,0, INF}, 'R',{'R','D','N'}}, {{-1, 0, INF}, {0, 1,INF}, 'U',{'U','R','N'}}, {{0, -1, INF}, {-1, 0, INF}, 'L',{'L','U','N'}}, { {0, 1, INF}, {-1, 0, INF}, 'D', {'L','D','N'} } };
		
LIGHT map[4][101][101];
int check[101][101];
int n, second;

int main ()
{

	//freopen("input.txt","rt",stdin);
	int ans = 0;
	cin >> n >> second;
	
	for(int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			for(int k = 0; k<4; k++)
			{
				int tmp;
				cin >> tmp;
				map[k][i][j] = sign[tmp-1];
				//for(int  l= 0; l < 3; l++) printf("%d %d %c ", map[k][i][j].x[l], map[k][i][j].y[l], map[k][i][j].outdir[l]);
				//printf("%c \n", map[k][i][j].indir);
			}
		}
	}
	queue<state> q;
	
	
	q.push(state(0,0,'U',0));
	check[0][0] = 1;
	while(!q.empty())
	{
		state tmp = q.front();
		
		q.pop();
		int cur_signal = tmp.time % 4;
//		for (int i = 0; i< n; i++)
//		{
//			for(int j =0; j<n; j++)
//			{
//				printf("%d ",check[i][j]);
//			}
//			printf("\n");
//		}
		//printf("Xpos : %d Ypos : %d Indir-state : %c  indir_map : %c cur_time : %d\n",tmp.x , tmp.y, tmp.dir, map[cur_signal][tmp.x][tmp.y].indir ,tmp.time);
		if(tmp.time == second) break;
		
		
	
		
		if(map[cur_signal][tmp.x][tmp.y].indir == tmp.dir) // 들어오는 차와 다음 신호의 방향이  같으면 
		{
			for(int k = 0; k<3; k++) 
			{
				int xpos = tmp.x + map[cur_signal][tmp.x][tmp.y].x[k];
				int ypos = tmp.y + map[cur_signal][tmp.x][tmp.y].y[k];
				char tdir = map[cur_signal][tmp.x][tmp.y].outdir[k];
				int ttime = tmp.time;
				//printf("Xpos : %d Ypos : %d Indir-state : %c  indir_map : %c outdir : %c cur_time : %d\n", xpos , ypos, map[cur_signal][tmp.x][tmp.y].indir,tmp.dir, tdir ,ttime);
				
				if(xpos < 0 || ypos < 0 || xpos >= n || ypos >= n || tdir =='N') continue;
				//printf("Xpos : %d Ypos : %d Indir-state : %c  indir_map : %c outdir : %c cur_time : %d\n", xpos , ypos, map[cur_signal][tmp.x][tmp.y].indir,tmp.dir, tdir ,ttime);
				//printf("Xpos : %d Ypos : %d outdir : %c cur_time : %d\n",xpos, ypos, tdir, ttime);
				check[xpos][ypos] = 1;
				q.push( state(xpos, ypos, tdir, ttime+1));
				
				
			}
		}
		
	}
	
//	for (int i = 0; i< n; i++)
//	{
//		for(int j =0; j<n; j++)
//		{
//			printf("%d ",check[i][j]);
//		}
//		printf("\n");
//	}
	
	for (int i = 0; i< n; i++)
	{
		for(int j =0; j<n; j++)
		{
			if(check[i][j] == 1) ans++;
		}
	}
		
	cout << ans;
}
