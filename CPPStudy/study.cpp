#include <iostream>

#define CHAPTER8

using namespace std;


void swapr (int & a, int & b);
void swapp (int * a, int * b);
void swapv (int a, int b);


const int & clone (int & ft)
{
    int newguy;
    newguy = ft;
    return newguy;
}

int main (void)
{
    

    
    #if 0
    //int w1, w2;
    //cin >> w1 >> w2;
    int a = 0;
    int b = 9999;
    cout << b << endl;
    
    //cout << "Before Swapping\n";
    //cout << 

    


    int rats = 10;
    int * pt = &rats;
    int &rodents = *pt; // assign the rats to rodents
    int bunnies = 50;
    pt = &bunnies;
    rodents = bunnies;

    cout << "rats : " << rats << endl;
    cout << "rodents : " << rodents << endl;
    cout << "*pt : " << *pt << endl;
    
    cout << "rats Addr : " << &rats << endl;
    cout << "rodents Addr : " << &rodents << endl;
    cout << "*pt Addr : " << pt << endl;
    
    
    int temp = 101;
    int &rodents = temp;
    int &rtemp = rodents;
    // cout << 
    
    cout << "temp : " << temp << endl;
    cout << "rodents : " << rodents << endl;
    rodents++;
    cout << "temp : " << temp << endl;
    cout << "rodents : " << rodents << endl;
    temp++;
    cout << "temp : " << temp << endl;
    cout << "rodents : " << rodents << endl;
#endif
}

void swapr (int & a, int & b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swapp (int * a, int * b)
{
    int temp;
    temp = *a;
    *a = * b;
    *b = temp;
}

void swapv (int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}