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

struct jewel
{
	int weight;
	int ppw;
	
	jewel(int a, int b)
	{
		weight = a;
		ppw = b;
	}
	
	bool operator<(const jewel &b)const{
		return ppw < b.ppw;
	}
};

int main ()
{
	priority_queue<jewel> q;
	
	int limit = 0;
	int maxi = 0;
	int num = 0;
	
	//freopen("input.txt","rt",stdin);
	cin >> limit >> num;
	while(num--)
	{
		int a, b;
		cin >> a >> b;
		q.push(jewel(a, b));
	}
	
	
	while(limit > 0)
	{
		jewel temp = q.top();
		
		if(limit - temp.weight < 0) maxi += limit * temp.ppw;
		else                        maxi += temp.weight * temp.ppw;
		
		limit -= temp.weight;
		//printf("Weight : %d PPW : %d\n", temp.weight, temp.ppw);
		q.pop();
	}
	
	cout << maxi << endl;
}

