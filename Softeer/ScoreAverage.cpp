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
	int n, k;
	//freopen("input.txt","rt",stdin);
	
	cin >> n >> k;
	
	vector<int> num;
	int sum = 0;
	num.push_back(0);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		sum += a;
		num.push_back(sum);
	}
	
	
	while(k--)
	{
		int start, end;
		cin >> start >> end;
		int tsum = num[end] - num[start-1];

		double total = (double)(tsum) / (double)(end - start + 1 );
	
		printf("%.2lf\n", total);

	}	
	return 0;
}
