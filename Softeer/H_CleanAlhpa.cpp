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


#define MOD 1000000007

int main()
{
	long long int p, n;	
	long long int ptmp;
	long long int ans = 0;
	
	cin >> p >> n;
	
	vector<long long int> virus(n);
	vector<long long int> mod(n);
	
	
	
	for(int i = 0; i<n; i++)
	{
		cin >> virus[i];
	}

	ptmp = 1;
	for(int i = n-1; i >= 0; i--)
	{	
		mod[i] = ptmp;
		ptmp = (((ptmp % MOD) * p) % MOD);
	}
	
	for(int i = 0; i<n; i++)
	{
		ans = (((ans % MOD) + ((virus[i] % MOD) * mod[i])) % MOD);
	}
	
	cout << ans << endl;	
	
	return 0;
}
