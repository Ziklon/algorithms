#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
char board[4][4];
int dx[]={0,1,0,1};
int dy[]={0,1,1,0};

int main(){
   REP(i,4){
        REP(j,4)scanf("%c",&board[i][j]);
        scanf("\n");
   }
   bool can=0;
   REP(i,3)REP(j,3){
       map<char,int> M;
       REP(k,4){
          int x=i+dx[k];
          int y=j+dy[k];
          M[board[x][y]]++;  
       }
       int mini=min(M['#'],M['.']);
       if(mini<=1)can=1; 
   }
   if(can)puts("YES");
   else puts("NO");
      
   return 0;      
}
