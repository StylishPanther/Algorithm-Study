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


int n;
vector< pair<int, int> > map[26];
int mini = 214700000;
int check[50];
void DFS(int l, int s)
{
	if(l == (n/2))
	{
		int one = 0;
	//	int one_cnt  = 0;
		int zero = 0;
	//	int zero_cnt;
//		for(int i = 0 ; i<n; i++)
//		{
//			if(check[i] == 0) printf("%d ", check[i]);
//			if(check[i] == 1) printf("%d ", check[i]);
//		}
//		printf("\n");
		
		for(int i = 0; i<n; i++)
		{
			for(int j = 0; j<map[i].size() ; j++)
			{
				
				
					if(check[i] == 1 && check[map[i][j].first] == 1) one += map[i][j].second;
					else if(check[i] == 0 && check[map[i][j].first] == 0) zero += map[i][j].second;
				
				
				//printf("i : %d, j : %d Ones : %d Zeors : %d Cost : %d\n",i , j , one, zero, map[i][j].second);
			}
			
			
		}
		
		if(mini > abs(one - zero) ) mini = abs(one - zero);
		//printf("Ones : %d Zeors : %d mini : %d\n", one, zero, mini);
		
		
	}
	else
	{
		
		for(int i = s ; i<n ; i++)
		{
			if(check[i] == 1) continue;
			check[i] = 1;
			DFS(l+1, i);
			check[i] = 0;
			
		}
	}
}
int main ()
{
	//freopen("input.txt","rt",stdin);
	cin >> n;
	
	for(int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			int a;
			cin >> a;
			 
			if(i!=j) map[i].push_back(make_pair(j, a));
		}
	}
	
//	for(int i = 0; i<n; i++)
//	{
//		for (int j = 0; j < map[i].size(); j++)
//		{
//			printf("%d %d %d\n", i, map[i][j].first, map[i][j].second );
//		}
//		printf("\n");
//	}
	
	DFS(0,0);
	
	cout << mini;
	
	
}
