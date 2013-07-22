#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
#define MAXN 1005
int N,M;
char B[MAXN][MAXN];
int dist[MAXN][MAXN];
int main(){
   scanf("%d %d\n",&N,&M);
   queue<pair<int,int> >Q;
   int xs,ys;
   REP(i,N){
        REP(j,M){
            scanf("%c",&B[i][j]);
            if(B[i][j]=='E'){
                Q.push(make_pair(i,j));
                dist[i][j]=0;
            }
            if(B[i][j]=='S'){
                xs=i;
                ys=j;
            }
        }
        scanf("\n");
   }
   int dx[]={0,0,1,-1};
   int dy[]={1,-1,0,0};
   memset(dist,-1,sizeof dist);
   while(!Q.empty()){
        pair<int,int> cur=Q.front();Q.pop();
        REP(i,4){
            int x=cur.first+dx[i];
            int y=cur.second+dy[i];
            if(min(x,y)>=0 && x<N && y<M && dist[x][y]==-1 && B[x][y]!='T'){
                dist[x][y]=dist[cur.first][cur.second]+1;
                Q.push(make_pair(x,y));
            }
        }
   }
   int ans=0;
   REP(i,N)REP(j,M)if(isdigit(B[i][j]) && dist[i][j]<=dist[xs][ys] && dist[i][j]!=-1){
        ans+=(B[i][j]-'0');
   }
   cout<<ans<<endl;
   return 0;      
}
