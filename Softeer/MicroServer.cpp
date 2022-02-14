// https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=628
// Lee Jin Ho 
// Data : 2022.01.14



#include <iostream>
#include <algorithm>
#include <vector>

#define STORAGE 900
using namespace std;

int main (void)
{
    int test;
    cin >> test;
    while(test--)
    {
        int idx;
        int start = 0;
        int group = 0;
        cin >> idx;
        vector<int> input;
        for(int i = 0; i < idx ; i++)
        {
            int temp;
            cin >> temp;
            input.push_back(temp);
        }

        sort(input.begin(),  input.end());
        //for(int i = 0; i <idx; i++) cout << input[i] << endl;
        printf("Passing\n");
        int tsum = 0;
        
        cout << group << endl;
    }
}



