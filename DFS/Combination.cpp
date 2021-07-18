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
// Make the Combination

int n, r, ch[20];
int num[20];
int res[20];


void dfs(int s, int L){

	if(L==r)
	{
		for(int j=0; j<L; j++){
			printf("%d ", res[j]);
		}
		printf("\n");
	}
	else{
		for(int i=s; i<n; i++){
				res[L]=num[i+1];
				dfs(i+1, L+1);
		}
	}
}

int main(){
	scanf("%d %d", &n, &r);
	
	for (int i = 1; i<=n; i++) cin >> num[i];
	
	dfs(0, 0);
	return 0;
}
