#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main (void)
{
	int n, box, k;
	cin >> n >> box >> k;
	int ktmp = k;
	int cnt = 0;
	int temp_box = 0;
	int total = 0;
	int mini = INT_MAX;
	vector<int> rail;
	
	for (int i = 0; i<n; i++)
	{
		int tmp;
		cin >> tmp;
		rail.push_back(tmp);
	}
	
	sort(rail.begin(), rail.end());
	
	do
	{
		
		while(ktmp)
		{
			temp_box += rail[cnt++]; // 박스에 물품 넣기 
			
			if(cnt >= n) cnt = 0; //인덱스 범위 벗어나면 처음부터 다시 작업 
			
			 
			if(temp_box + rail[cnt] > box )  // 현재 박스에 다음 물건을 넣으면 꽉찰 때,  
			{
				ktmp--;
				total += temp_box;
				temp_box = 0; // 동작 횟수를 감소시키고 박스를 비운다. 
			}
			
		}
		
		
		//printf("CT : %d\n", total);
		if(mini > total) mini = total;
		
		cnt = 0;
		temp_box = 0;
		total = 0;
		ktmp = k;
	}
	while(next_permutation(rail.begin(), rail.end()));
	
	printf("%d\n", mini);
}
