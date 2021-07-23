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

int main ()
{
	int n, m;
	
	//freopen("input.txt","rt",stdin);
	cin >> n >> m;
	vector<int> weight(n+1);
	vector<bool> frog(n+1);
	vector<int> map[n+1];
	int fiw = 0;
	for(int i = 1; i<=n; i++) 
	{
		cin >> weight[i]; 
		//printf("%d ",weight[i]);
	}
	//printf("\n");
	
	for(int i = 1; i<=m; i++)
	{
		int a, b;
		cin >> a >> b;
		//printf("%d %d\n", a, b);
		map[a].push_back(b);
		map[b].push_back(a);
	}
	
	//소스 입력  
	for(int i = 1 ; i<=n ; i++)
	{
		//printf("%d \n",map[i].size());
		if(map[i].size() == 0) frog[i] = true;
		else
		{
			for(int k = 0 ; k<map[i].size() ; k++)
			{
				//printf("i : %d K : %d\n ", i,map[i][k]);
				if(weight[i] > weight[map[i][k]]) frog[i] = true;
				else					   			
				{
					frog[i] = false;	
					break;
				}
				
			}	
		}
	}
	// 인접 리스트 처리 
	 
	for(int i = 1 ; i<=n ; i++)
	{
		if(frog[i] == true) fiw++;
	}
	
	cout << fiw << endl;
}
