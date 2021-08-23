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

#define PLUS		0
#define MINUS		1
#define MULTIPLY	2
#define DIVIDE		3

int n;
int arr[101];
int sym[4];
int maxi = -2140000000; 
int mini = 2140000000; 
void dfs(int depth, int sum)
{
	//printf("Sum : %d\n", sum);
	if(depth == n)
	{
		//printf("Sum : %d\n", sum);
		if(maxi < sum) maxi = sum;
		if(mini > sum) mini = sum;
		
	}
	
	else
	{
		
			if(sym[PLUS] > 0) // 덧셈 탐색 
			{
			 	sym[PLUS]--;
			 	dfs(depth+1, sum + arr[depth]);
			 	sym[PLUS]++;
			}
			if(sym[MINUS] > 0) // 뺄셈 탐색 
			{
				sym[MINUS]--;
			 	dfs(depth+1, sum - arr[depth]);
			 	sym[MINUS]++;
			}
			if(sym[MULTIPLY] > 0) // 곱셈 탐색 
			{
				sym[MULTIPLY]--;
			 	dfs(depth+1, sum * arr[depth]);
			 	sym[MULTIPLY]++;	
			}
			if(sym[DIVIDE] > 0) // 나눗셈 탐색 
			{
				sym[DIVIDE]--;
			 	dfs(depth+1, sum / arr[depth]);
			 	sym[DIVIDE]++;
			}
			
	}
}


int main ()
{
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	
	for(int i = 0; i<4; i++)
	{
		cin >> sym[i];
	}
	// 입력 값 받는 부분
	
	dfs(1, arr[0]);

	printf("%d\n%d\n", maxi, mini);
	
  return 0;
}
