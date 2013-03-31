#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#define REP(i,a) for(int i=0;i<int(a);i++)
using namespace std;
typedef long long ll;

int N,M;
char G[55][55];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

bool vis[55][55][4][2];
struct node{
    int x,y,d,c;
    node(int _x, int _y, int _d, int _c){
        x=_x;
        y=_y;
        d=_d;
        c=_c;
    }
};


int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d %d\n",&N,&M);
   REP(i,N){       
       REP(j,M)scanf("%c",&G[i][j]);
       scanf("\n");
   }
   bool ans=1;
   int xs=0;
   int ys=0;
      
   REP(i,N)REP(j,M)if(G[i][j]=='B' && ans){       
        memset(vis,0,sizeof vis);
        queue<node> Q;
        REP(k,4){
            Q.push(node(i,j,k,0));
            vis[i][j][k][0]=1;
        }
        while(!Q.empty()){
            node cur=Q.front();Q.pop();
            //cur dir
            xs=cur.x+dx[cur.d];
            ys=cur.y+dy[cur.d];
            if(min(xs,ys)>=0 && xs<N && ys<M && G[xs][ys]=='B' && vis[xs][ys][cur.d][cur.c]==0){
                Q.push(node(xs,ys,cur.d,cur.c));
                vis[xs][ys][cur.d][cur.c]=1;
            }
            if(cur.c==0){
                REP(k,4){
                    if(k==cur.d)continue;                                    
                    xs=dx[k]+cur.x;
                    ys=dy[k]+cur.y;
                    if(min(xs,ys)>=0 && xs<N && ys<M && G[xs][ys]=='B' && vis[xs][ys][k][1]==0){
                        Q.push(node(xs,ys,k,1));
                        vis[xs][ys][k][1]=1;
                    }
                }
            }  
    
       }
       REP(k,N)REP(m,M)if(G[k][m]=='B'){
            int cnt=0;
            REP(a,4)REP(b,2)if(vis[k][m][a][b]==1)cnt++;
            if(cnt==0)ans=0;
       }
    }       
   puts(ans?"YES":"NO");
          
   return 0;      
}
