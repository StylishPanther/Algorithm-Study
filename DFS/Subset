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
int n;
void DFS(int l)
{
	if(l==n+1)
	{
		for(int i=1; i<=n; i++) if(ch[i]) cout << i << ' ';
		cout << endl;
	}
	else
	{
		ch[l]=1;
		DFS(l+1);
		ch[l]=0;
		DFS(l+1);
	}
}


int main (void)
{
	cin>>n;
	DFS(1);
}
