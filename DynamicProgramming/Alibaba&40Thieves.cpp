#include <iostream>
#include <vector>

using namespace std;

int map[21][21];
int dy [21][21];

int main ()
{
	int n;
	cin >> n;	
	
	for (int i=1; i<=n; i++)
	{
		for(int j = 1; j<=n; j++)
		{
			cin >> map[i][j];
		}
	}
	
	for(int i = 1; i<=n; i++) dy[i][1] = dy[i-1][1] + map[i][1];
	for(int i = 1; i<=n; i++) dy[1][i] = dy[1][i-1] + map[1][i];
	
	for(int i =2 ; i<=n; i++)
	{
		for(int j = 2; j<=n; j++)
		{
			int temp = dy[i][j-1] > dy[i-1][j] ? dy[i-1][j] : dy[i][j-1];
			dy[i][j] = temp + map[i][j];
		}
	}
	
	cout << dy[n][n];
	
}
