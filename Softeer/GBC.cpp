#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include <algorithm>

using namespace std;

int main ()
{
	int n, m;
	cin >> n >> m;
	int tmp_meter = 0;
	int max = 0;
	
	vector<int> nbuilding; 	// GBC의 정해진 제한 속도 
	vector<int> mbuilding;	// 광우가 GBC에서 움직인 속도 
	
	for(int i = 0; i<n; i++)
	{
		int meter, vel;
		cin >> meter >> vel;
		
		for(int j = tmp_meter; j<tmp_meter+meter; j++) // 들어오는 값만큼 반복해서 해당 m에서의 제한 속도 입력 
		{
			nbuilding.push_back(vel);
		}
		tmp_meter += meter;
		
	}
	
	tmp_meter = 0;
	
	for(int i = 0; i<m; i++)
	{
		int meter, vel;
		cin >> meter >> vel;
		
		for(int j = tmp_meter; j < tmp_meter + meter; j++) // 들어오는 값만큼 반복해서 해당 m에서 광우가 움직인 속도 입력 
		{
			mbuilding.push_back(vel);
		}
		tmp_meter += meter;
	}
	
	for(int i = 0; i<=100; i++) // 0~100까지 제한 속도를 가장 크게 넘긴 층 확인. 
	{
		int tmp = mbuilding[i] - nbuilding[i];
		if(max < tmp) max = tmp; // 제한 속도를 넘겼을 때 업데이트. 제한 속도를 넘겼을 떄이므로 max의 초기 값이 0이다. 
	}
	
	printf("%d\n", max);
}
