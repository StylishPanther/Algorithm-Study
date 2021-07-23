#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include <algorithm>

using namespace std;

int main ()
{
	int n;
	int maxi = -INT_MAX;
	//freopen("input.txt","rt",stdin);
	
	cin >> n;
	int idx = 1;
	int upper_ans = 0;
	int lower_ans = 0;
	
	vector<int> bridge;
	
	vector<int> upper;
	vector<int> lower;
	
	
	vector<int> upper_num(n+1);
	vector<int> lower_num(n+1);
	
	for (int i = 0; i < n; i++) 
	{
		int x;
    	cin >> x;
    	bridge.push_back(x);
    	//printf("%d ", bridge[i]);
    }
    
	upper.push_back(-INT_MAX);
	lower.push_back(-INT_MAX);
	
	for (int i = 0; i < n; i++) 
	{
		int x = bridge[i];
		//printf("x : %d\n", x);
		
		
    	if (upper.back() < x) 
		{
           upper.push_back(x);
           upper_ans++;
    	   //printf("Up Ans : %d ",upper_ans);
    	   
           //for (int j = 0; j <=n; j++) printf("%d ", upper[j]);
           //printf("\n");
		}
    	else 
		{
			
	        vector<int>::iterator iter = lower_bound(upper.begin(), upper.end(), x);
	        
	        *iter = x;
	    }
	    upper_num[i] = upper_ans;
    
	}
	
	for (int i = n-1 ; i >=0; i--) 
	{
		int x = bridge[i];
		//printf("x : %d\n", x);
		
		
    	if (lower.back() < x) 
		{
           lower.push_back(x);
           lower_ans++;
    	   //printf("Lower Ans : %d ",lower_ans);
    	   
           //for (int j = 0; j <=n; j++) printf("%d ", upper[j]);
           //printf("\n");
		}
    	else 
		{
			
	        vector<int>::iterator iter = lower_bound(lower.begin(), lower.end(), x);
	        
	        *iter = x;
	    }
	    lower_num[i] = lower_ans;
    
	}
	
//	for (int i = 0; i < n; i++) printf("%d ", upper_num[i]);
//	cout << endl;
//	for (int i = 0; i < n; i++) printf("%d ", lower_num[i]);
//	cout << endl;
	
	for (int i = 0; i < n; i++)
	{
		int temp = upper_num[i] + lower_num[i] - 1;
		if(maxi < temp) maxi = temp;
	}
	
	
	cout << maxi << endl;
}
