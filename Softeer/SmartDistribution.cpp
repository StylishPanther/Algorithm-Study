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

#define SOFTEER_SMARTDISTRIBUTION

#ifdef SOFTEER_SMARTDISTRIBUTION

char line[20001];
int check[20001];
int main()
{
	
	int n, k;
//	freopen("input.txt","rt",stdin);
	//cout << "Check" << endl;
	cin >> n >> k;
	
	int total = 0; 
	cin >> line;
	for (int i = 0; i < n; i++)
	{
	//	printf("%c %d\n", line[i], line[i] == 'P');
	}
	//printf("\n");
	
	for(int i = 0; i<n; i++)
	{
		//printf("%d %c %d\n", i,line[i], line[i] == 'P');
		if(line[i] == 'P')
		{
			//printf("Cur : %d\n", i);
			check[i] = 1; // 로봇이 있는 지역 체 
			
			for(int r = i - k ; r <= i+k; r++)
			{
				if(r < 0 || r >=n) continue; // 로봇 팔이 컨베이어 벨트의 범위를 벗어날때  
				if(check[r] == 0 && line[r] == 'H') 
				
				{
					
					check[r] = 1;
					total++;
					break;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		//printf("%d ", check[i]);
	}
	printf("%d \n", total);
	
	return 0;
}

	

#endif
