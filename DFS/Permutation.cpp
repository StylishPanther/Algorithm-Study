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

// Make the Permutation
int n, r;

int num[16];
int check[16];
int res[16];
void DFS (int l, int p)
{
	res[l] = p;
	if(l >= r)
	{
		for(int i = 1; i<=r; i++)
		{
			printf("%d ", res[i]);
		}
		printf("\n");
	}
	
	else
	{
		for(int i = 1; i<=n; i++)
		{
			if(check[i] == 0)
			{
				check[i] = 1;
				DFS(l+1, num[i]);
			}
		}
		
	}
}
int main ()
{
	cin >> n >> r;
	
	for (int i = 1; i<=n; i++) cin >> num[i];
	
	
	DFS(0, 0);
}
#endif
