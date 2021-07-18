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
//BAEKJOON_1987
// Alphabet
vector< pair<char, int> > alphabet;
char map[22][22];

struct Loc{
	
	int r;
	int c;
	
	Loc(int a, int b)
	{
		r = a;
		c = b;
	}
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0 , -1, 1};

int cnt;
int maxi = -214700000;
int r, c;

void DFS (Loc temp, int l)
{
	
		if(maxi < l) maxi = l;
		
	
	
	
		for(int k = 0; k < 4; k++)
		{
			int xpos  = temp.r +dx[k];
			int ypos  = temp.c +dy[k];
			
			//for (int i= 0; i<26; i++) if(alphabet[i].first == map[0][0]) alphabet[i].second = 1;
		
			if(xpos < 0 || ypos < 0 || xpos >= r || ypos >= c || alphabet[map[xpos][ypos] -'A'].second == 1) continue;
			
			alphabet[map[xpos][ypos] -'A'].second = 1;
			DFS(Loc(xpos, ypos), l+1);
			alphabet[map[xpos][ypos] -'A'].second = 0;
			
		}
	
}
int main ()
{
	cin >> r >> c;
	
	for(int i = 0; i<r; i++)
	{
		for(int j = 0; j<c; j++)
		{
			cin >> map[i][j];
			//printf("%c ", map[i][j]);
		}
		//printf("\n");
	}
	
	for (int i= 0; i<26; i++)
	{
		alphabet.push_back(make_pair('A'+ i, 0));
		//printf("%c %d \n", alphabet[i].first, alphabet[i].second);
	}
	
	alphabet[map[0][0] -'A'].second = 1;
	DFS(Loc(0,0), 0);
	
	cout << maxi+1;
    return 0;
}
