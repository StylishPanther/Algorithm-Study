
#define BAEKJOON_9019

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

int main (void)
{
	int test;
	int final;
	int start;
	//printf("Origin : %d, L_Shifted : %d, R_Shifted : %d\n", 1, L(1), R(1));
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	//freopen("input.txt","rt",stdin);
	cin >> test;
	queue<pair<int, string> > q;
	int check[10001] = {0,};
	while(test--)
	{
		//reg = 0;
		
		
		
		cin >> start >> final;
		
		//printf("%d %d\n",start,final);
		check[start] = 1;
		q.push(make_pair(start, ""));
		
		while(!q.empty())
		{
			int pos = q.front().first;
			string order = q.front().second;
			q.pop();
			if(pos == final) 
			{
			
				//printf("Temp : %d Search Completed!\n", pos);
				cout << order << endl;
				break;
			}
			
			for(int k = 0; k<4; k++)
			{
				//cout << k << ' '<< pos << ' ' << order << endl;
				
				
					if(k == 0) 		
					{
						int next = (pos * 2 < 10000) ? pos * 2 : ((pos * 2) % 10000);
						if(check[next] == 0)
						{
						
							check[next] = 1;
							q.push(make_pair(next, order+"D"));
						}
					}
					else if(k == 1) 
					{
						int next =  pos - 1 < 0 ? 9999 : pos - 1;
						if(check[next] == 0)
						{
						
							check[next] = 1;
							q.push(make_pair(next, order+"S"));
						}
					}
					else if(k == 2) 
					{
						int n = pos / 1000;
						int temp = (pos % 1000) * 10;
						int next =  temp+n;
						
						if(check[next] == 0)
						{
							check[next] = 1;
							q.push(make_pair(next, order+"L"));
						}
					}
					else if(k == 3) 
					{
						
						int n = pos % 10;
						int temp = pos / 10;
						int next = 1000 * n + temp;
						
						if(check[next] == 0)
						{
							check[next] = 1;
							q.push(make_pair(next, order+"R"));
						}
					}				
				}
			
		}

		for(int i = 0; i<10000; i++) check[i] = 0;
		while(!q.empty())
		{
			q.pop();
		}
	
	}
	
	return 0;
}
