#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
char board[101][101],c;
int N,M;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){     
   scanf("%d %d %c\n",&N,&M,&c);
   for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)scanf("%c",&board[i][j]);
        scanf("\n");    
   }
   set<char> S;     
   for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(board[i][j]==c){
        S.insert(c);
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(min(x,y)>=0 && x<N && y<M && board[x][y]!='.')
                S.insert(board[x][y]);            
        }    
   }
   int ans=S.size()-1;
   printf("%d\n",ans);
   return 0;      
}
