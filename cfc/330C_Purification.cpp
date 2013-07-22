#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
#define MAXN 150
int N;
char B[MAXN][MAXN];

bool can[MAXN][MAXN];
int main(){
   scanf("%d\n",&N);
   REP(i,N){
       REP(j,N)scanf("%c",&B[i][j]);
       scanf("\n");
   }
   memset(can,0,sizeof can);
   vector<pair<int,int> > ans1;
   vector<pair<int,int> > ans2;

   
   //fila
   REP(i,N)REP(j,N)if(B[i][j]=='.'){
            REP(k,N)can[i][k]=1;
            REP(k,N)can[k][j]=1;
            ans1.push_back(make_pair(i+1,j+1));
            break;
   }
   bool found1=1;
   bool found2=1;
   if(ans1.size()<N)found1=0;
    memset(can,0,sizeof can);
    REP(j,N)REP(i,N)if(B[i][j]=='.'){
            REP(k,N)can[i][k]=1;
            REP(k,N)can[k][j]=1;
            ans2.push_back(make_pair(i+1,j+1));
            break;
    }
   if(ans2.size()<N)found2=0;

   if(found1)REP(i,N)printf("%d %d\n",ans1[i].first,ans1[i].second);
   else if(found2)REP(i,N)printf("%d %d\n",ans2[i].first,ans2[i].second);
   else printf("-1\n");        

   return 0;      
}
