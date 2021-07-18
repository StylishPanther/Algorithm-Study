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

#ifdef BAEKJOON_1759

//Make the Password

int r, n;
vector<char> letter;
int check[20];
char res[20];
void find_password(int s, int l)
{
	if (l == r)
	{
		int consonant = 0;
		int vowel = 0;
		int flag = 0;
		
		for(int j =0; j<l; j++)
		{
			
			if(res[j] == 'a' || res[j] == 'e' || res[j] == 'i' ||  res[j] == 'o'|| res[j] == 'u') consonant++;
			else																				vowel++;
		}
		
		if(consonant >=1 && vowel >= 2)
		{
			for(int j =0; j<l; j++) printf("%c",res[j]);
			printf("\n");
		}
	}
	
	else
	{
		for(int i = s; i<n; i++)
		{
			
			res[l] = letter[i];
			find_password(i+1, l+1);
		}
	}
}
int main ()
{
	cin >> r >> n;
	for (int i = 0; i<n;i++){
		char a;
		cin >> a;
		letter.push_back(a)	;
	} 
	
	sort(letter.begin(), letter.end());
	
	for (int i = 0; i<n;i++)
	{
		printf("%c ", letter[i]);
	}
	printf("\n");;
	
	find_password(0,0);
	
	
	
}
