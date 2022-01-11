#include <iostream>

using namespace std;

int main (void)
{
    int apple;
    cout << "Hello, World!" << endl;
    cin >> apple;
    volatile int cnt = 0;
    for(int i = 0; i < 1000000; i++)
    {
        cnt++;
    }
    cout << cnt << endl;
    cout << apple << endl;
    return 0;
}



