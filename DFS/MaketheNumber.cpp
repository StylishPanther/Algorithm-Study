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
// Partial Set that has the same sigma

int ch[22];
int num[22];
int n, k;
//int sum = 0;
int cnt;
int flag = 0;
void DFS(int depth, int sum)
{
	if(depth > n)
	{
	
		//cout << endl;
		
		if(sum == k)  cnt++;
			
		//printf("CNT : %d\n", cnt);
	}
	else
	{
		DFS(depth+1,sum+num[depth]);
		DFS(depth+1,sum);
		DFS(depth+1,sum-num[depth]);
	}
}
int main (void)
{
	
	//freopen("input.txt", "rt", stdin);
	cin >> n >> k;
	for (int i = 1 ; i<=n ; i++)  cin >> num[i];
	
	DFS(1,0);
	
	if(cnt!=0) cout << cnt;
	else 	 cout << "-1";
}
