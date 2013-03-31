/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int N,x,y,a,M,i,j,k;
bool G[105][105];
int val[105][105];
bool vis[105][105];
int di[]={0,0,1,-1,1,-1,1,-1, 2,1,-1,-2,-1,-2,1,2};
int dj[]={1,-1,0,0,1,-1,-1,1, 1,2,-2,-1,2,1,-2,-1};


int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(scanf("%d %d",&N,&M)==2){
       if(N==0 && M==0)break;
       fill(G,0);
       fill(vis,0);
       fill(val,0);
       REP(i,0,M){
         scanf("%d %d",&x,&y);
         G[x][y]=1;
       } 
       scanf("%d %d\n",&x,&y);        
       if(G[x][y])
         printf("oops!\n");
       else{
         REP(i,1,N+1)
            REP(j,1,N+1){
               if(G[i][j])
                  val[i][j]=9;
               else{
                  int cnt=0;
                  REP(k,0,8){
                     int X=i+di[k];
                     int Y=j+dj[k];
                     if(X>0 && Y>0 && X<=N && Y<=N)
                        cnt+=G[X][Y];
                  }
                  val[i][j]=cnt;
               }
            }   
          queue<pair<int,int> >Q;
          Q.push(make_pair(x,y));
          vis[x][y]=1;
          while(!Q.empty()){
            pair<int,int> cur=Q.front();
            Q.pop();
            x=cur.first;
            y=cur.second;
            if(val[x][y]==0){
               REP(k,0,8){
                  int X=x+di[k];
                  int Y=y+dj[k];         
                  if(X>0 && Y>0 && X<=N && Y<=N && !vis[X][Y]){
                     Q.push(make_pair(X,Y));
                     vis[X][Y]=1;
                  }
               }
            }
          }
          REP(i,0,N){
            REP(j,0,N)
               if(!vis[i+1][j+1])  
                  printf(".");
               else
                  printf("%d",val[i+1][j+1]);
            printf("\n");
          }
            
         }
         
      printf("\n");
    }  
    //system("pause");
    return 0;
}
