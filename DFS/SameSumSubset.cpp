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

int ch[11];
int num[11];
int n;
int flag = 0;
void DFS(int depth)
{
	if(depth > n)
	{
		int pos = 0;
		int neg = 0;
//		for(int i=1; i<=n; i++) if(ch[i]) cout << num[i] << ' ';
//		cout << endl;
//		for(int i=1; i<=n; i++) if(!ch[i]) cout << num[i] << ' ';
//		cout << endl;
		for(int i=1; i<=n; i++) if(ch[i]) pos+=num[i];
		for(int i=1; i<=n; i++) if(!ch[i]) neg+=num[i];
		if(pos == neg) flag = 1;
	}
	else
	{
		ch[depth]=1;
		DFS(depth+1);
		ch[depth]=0;
		DFS(depth+1);
	}
}
int main (void)
{
	
	cin >> n;
	for (int i = 1; i<=n; i++) cin >> num[i];
	
	DFS(1);
	
	if(flag) cout << "YES";
	else 	 cout << "NO";
}
