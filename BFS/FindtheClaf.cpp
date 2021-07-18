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


int Q[1000], front = -1, back = -1;
int check[10001];
int count[10001];
vector<int> map[10001];


int dx[3] = {1, -1, 5};
int main (void)
{
	int x;
	queue<int> q;
	int n, k;
	cin >> n >> k;
	
	
	check[n] = 0;
	q.push(n);
	
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		for(int i = 0; i<3; i++)
		{
			int pos = x+dx[i];
			if(pos == k)
			{
				cout << check[x] + 1 << endl;
				return 0;
			}
			
			else if(check[pos] == 0)
			{
				check[pos] = check[x] + 1;
				q.push(pos);
			}
		}
	}
}
