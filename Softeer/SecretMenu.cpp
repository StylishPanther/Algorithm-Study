// https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=623
// Lee Jin Ho 
// Data : 2022.01.12

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main (void)
{
    //cout << "Test\n";

    int m, n, k;
    string spat;
    string input;
    cin >> m >> n >> k;
    
    for(int i = 0; i < m; i++)
    {
        char temp;
        cin >> temp;
        spat.push_back(temp);
    }
    for(int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        input.push_back(temp);
    }
    
    cout << "Secret Pattern : " << spat << endl;
    cout << "Input : " << input << endl;
    // cout << string::npos << endl;
    if(input.find(spat, 0) != string::npos) cout << "secret" << endl;
    else                                    cout << "normal" << endl;
}