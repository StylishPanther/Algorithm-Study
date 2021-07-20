#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <algorithm>

#define BAEKJOON_5014
using namespace std;

int main()
{
	int f, s, g, u, d;
	int ans = -1;
	int dx[2]={0, };
	vector<int> check(1000001, 0);
	//freopen("input.txt","rt",stdin);
	cin >> f >> s >> g >> u >> d;
	
	// f : 고층 건물  
	// s : 현재 내 위치  
	// g : 스타트 링크의 위치
	// u : 위로 u층을 올라가는 버튼 
	// d : 아래로 d 층을 내려가는 버튼
	
	queue<pair<int, int> > q;
	
	check[s] = 1;
	q.push(make_pair(s, 0));
	
	dx[0] = u; 	// Up Limit
	dx[1] = -d; // Down Limit
	
	while(!q.empty())
	{
	
		int temp = q.front().first;
		int level = q.front().second;
		//printf("Pos :%d Level : %d\n",temp, level);
		q.pop();
		
		if(temp == g)
		{
			ans = level;
			break;
		}
		
		
		for(int k = 0; k < 2; k++)
		{
			int xpos = temp + dx[k];		
			
			if(xpos < 1 || xpos > f || check[xpos] == 1) continue;
			check[xpos] = 1;
			q.push(make_pair(xpos, level+1));
		}
		
		
	} 
	
	
	if(ans >= 0) cout << ans;
	else 		 cout << "use the stairs";
}
