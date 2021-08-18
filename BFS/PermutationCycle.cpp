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

int main()
{
	
	int test;
	cin >> test;

	

	while(test--)
	{
		int n;
		cin >> n;
		int arr[1001] = {0,};
		int narr[1001] = {0,};
		int check[1001] = {0,};
		int local = 1;
		vector<int> list[n+1];
		// 테스트 케이스 별 선언
		 
		for(int i = 1; i<=n; i++) arr[i] = i;
		for(int i = 1 ; i<=n;i++) 
		{
			int a;
			cin >> a;
			narr[i] = a;
		}
		
		for(int i = 1; i<=n; i++)
		{
			list[arr[i]].push_back(narr[i]);
		}
		
		// 인접리스트 완성
		
		queue<int> q;
		for(int i = 1; i<=n; i++)
		{
			if(check[i] != 0) continue;
			check[i] = local;
			q.push(i);
			
			while(!q.empty())
			{
				int temp = q.front();
				q.pop();
			
				for(int i = 0; i<list[temp].size(); i++)
				{
					if(check[list[temp][i]] == 0)
					{
						check[list[temp][i]] = local;
						q.push(list[temp][i]);
					
					}
				}
			}
			
			local++;
		}
		// BFS 탐색 수행 및 사이클 갯수 추출
		printf("%d\n", local-1);
    }
		
}
	
