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
#define ADD 		1
#define SUBTRACT 	2
#define MULTIPLY 	3
#define DIVIDE		4

int n;
char symbol[11];

int num[11];
int check[11];

int cnt = 1;
int mini = INT_MAX;
int maxi = -INT_MAX;
void DFS(int depth, int sum)
{
	//printf("Depth : %d, Sum : %d\n", depth, sum);
	
	if(depth == n)
	{
		if(mini > sum) 		mini = sum;
		if(maxi < sum ) 	maxi = sum;
		//printf("Max : %d, Mini : %d\n", maxi, mini);
	}
	
	else
	{
		
		for (int i = 1 ; i<=cnt; i++)
		{
			if(check[i]==0)
			{
			
				if( symbol[i] =='+' )
				{
					check[i] = 1;
					DFS(depth+1, sum + num[depth+1]);		
					check[i] = 0;
				}
				if( symbol[i] =='-' )
				{
					check[i] = 1;
					DFS(depth+1, sum - num[depth+1]);		
					check[i] = 0;
				}
				
				if( symbol[i] =='*' )
				{
					check[i] = 1;
					DFS(depth+1, sum * num[depth+1]);		
					check[i] = 0;
				}
				if( symbol[i] =='/' )
				{
					check[i] = 1;
					DFS(depth+1, sum / num[depth+1]);		
					check[i] = 0;
				}

			}
				
		}
				
	}
}

//symbol[i].size()
int main (void)
{
	int a;
	
	cin >> n;
	for (int i =1 ; i<=n; i++)
	{
		cin >> num[i];
		
		//cout  << num[i] << endl;
	}
	
	for (int i = 1; i <= 4 ; i++)
	{
		cin >> a;
		//cout << a << endl;
		for(int j = 0; j < a; j++)
		{
			if (i == ADD) 				symbol[cnt++] = '+';
			else if (i == SUBTRACT) 	symbol[cnt++] = '-';
			else if (i == MULTIPLY) 	symbol[cnt++] = '*';
			else if (i == DIVIDE) 		symbol[cnt++] = '/';
		}
		//printf("cnt : %d\n", cnt);
	}
	
	
	DFS(1, num[1]);
	
	cout << maxi << endl;
	cout << mini << endl;
}
#endif
