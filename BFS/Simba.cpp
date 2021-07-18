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

int map[26][26];
int check[26][26];
int simba[8];


int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n;
struct State {
   int x, y, dis;
   State(int a, int b, int c) {
      x = a;
      y = b;
      dis = c;
   }
   
   bool operator<(const State &b)const
   {
      if(dis == b.dis)
      {
         if(x == b.x) return y>b.y;
         else      	  return x>b.x;
      }
      
      else return dis > b.dis;
   }
};

struct Lion {
   
   int x, y, size, ate;
   void sizeup()
   {
      size++;
      ate = 0;
   }
};
// Structure


int main() 
{
   
   freopen("input.txt","rt", stdin);
   priority_queue<State> q;
   Lion simba; 
   int res;
   

   cin >> n;
   
   
   for (int i = 1; i<=n; i++)
      for (int j = 1 ; j<=n; j++) 
      {
         cin >> map[i][j];
         //printf("Simba : %d %d\n",q.front().x, q.front().y);
         if(map[i][j] == 9) 
         {
            simba.x = i;
            simba.y = j;
            
            map[i][j] = 0;
         }
      }
      
      
   q.push(State(simba.x, simba.y, 0) );
   simba.size = 2;
   simba.ate = 0;
   
   while(!q.empty())
   {
   
      State temp = q.top();
      q.pop();
      
      int x = temp.x;
      int y = temp.y;
      int dis = temp.dis;
      // 맨 처음에 심바의 위치 입력
      
      if(map[x][y] != 0 && map[x][y] < simba.size) // 잡아먹을 수 있으면
      {
         simba.x = x;
         simba.y = y;
         simba.ate++;
         if(simba.ate >= simba.size) simba.sizeup();
         map[x][y] = 0;
         
         for(int i = 1; i<=n; i++)
         {
            for (int j = 1; j<=n ;  j++)
            {
               check[i][j] = 0;
            }
         }
         
         while(!q.empty()) q.pop();
         res = temp.dis;
      }
       
      // 다음 토끼를 잡아먹을 위치 탐 
      for (int k = 0 ; k < 4; k++)
      {
         
         int xpos = x + dx[k]; 
         int ypos = y + dy[k];
         if(xpos < 1 || xpos > n || ypos < 1 || ypos > n || map[   xpos][ypos] > simba.size || check[xpos][ypos] > 0) continue;
         
         q.push(State(xpos, ypos, dis+1));
         check[xpos][ypos] = 1;
         
      }
   }
   
   cout << res;
}
