// https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=627
// Lee Jin Ho 
// Data : 2022.01.14
// Image Processing

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

//#define DEBUG
using namespace std;

struct dot
{
    int x;
    int y;
    dot(int a, int b)
    {
        x = a;
        y = b;
    }
};

struct point
{
    int x;
    int y;
    int value;
    point(int a, int b, int c)
    {
        x = a;
        y = b;
        value = c;
    }
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main (void)
{
    int h, w;
    cin >> h >> w;
    vector< vector<int>> map(h+1, vector<int>(w+1,0));

    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            cin >> map[i][j];
        }
    }

    int test = 0;
    vector<point> parr;
    cin >> test;
    for(int i = 0; i < test; i++) 
    {
        int x, y, z;
        cin >> x >> y >> z;
        parr.push_back(point(x, y, z));
    }
    for(int idx = 0; idx < test; idx++)
    {
        vector< vector<int>> check(h+1, vector<int>(w+1,0));
        vector<dot> darr;
        int tval = parr[idx].value;
        int bval = map[parr[idx].x][parr[idx].y];

        queue<dot> q;
        q.push(dot(parr[idx].x, parr[idx].y));
        //check[parr[idx].x][parr[idx].y] = 1;
        //cout << "Xpos : " <<parr[idx].x << " Ypos :  " << parr[idx].y << " Value : " << tval <<  endl;
        while(!q.empty())
        {
            dot temp = q.front();
            q.pop();
            map[temp.x][temp.y] = tval;
            //cout << "Xpos : " <<temp.x << " Ypos :  " << temp.y << " Value : " << tval <<  endl;
            for(int k =0; k < 4; k++)
            {
                int xpos = temp.x + dx[k];
                int ypos = temp.y + dy[k];

                if(xpos < 1 || ypos < 1 || xpos > h || ypos > w) continue;
                if(check[xpos][ypos] == 0 && map[xpos][ypos] == bval)
                {
                    check[xpos][ypos] = 1;
                    q.push(dot(xpos, ypos));
                    darr.push_back(dot(xpos,ypos));
                }
            }
        }
        //cout << "Change!\n";
        #if 0
        for(int i = 0 ; i < darr.size(); i++)
        {
            map[darr[i].x][darr[i].y] = tval;
        }
        #endif
        
        #ifdef DEBUG
        cout << "Inside!\n";
        for(int i = 1 ; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        #endif
       
        
        
    }
    
     #if 1
        for(int i = 1 ; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
    #endif


}