#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include <algorithm>

using namespace std;

int main ()
{	int n;

	int max = -214700000;
	int temp_max = 0;
//	freopen("input.txt","rt",stdin);
	cin >> n;
	vector<int>	bridge;
	vector<int> mb;
	
	for(int i = 0; i<n;i++)
	{
		int a;
		cin >> a;
		bridge.push_back(a);
		mb.push_back(1);
	}
	
	for (int i = 0; i < n; i++) 
	{
    	if (mb[i] == 0) mb[i] = 1;
    	for (int j = 0; j < i; j++) 
		{
	        if (bridge[i] > bridge[j]) 
			{
	            if (mb[i] < mb[j] + 1) 
				{
	                mb[i] = mb[j] + 1;
	            }
	        }
    	}
	}

	for(int i = 0; i<n; i++)
	{
		if(max < mb[i]) max = mb[i];	
	}
	
	cout << max << endl;
	
} 
