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
#define INF 1<<20
using namespace std;
typedef long long ll;

int tree[1<<10],N,x,y;
int term[1<<10];
char name;

vector<int> G[1<<10];
int dp[1<<10][2];
int go(int node, int who){
    if(term[node]!=INF)return term[node];    
    int& ref=dp[node][who];
    if(ref!=-INF)return ref;
    int ansa=10;
    int ansb=-10;
    REP(i,G[node].size()){
        int v=G[node][i];
        int tmp=go(v,who>0?0:1);
        if(who==0)
            ansa=min(ansa,tmp);
        else 
            ansb=max(ansb,tmp);
    }    
    if(who==0)ref=ansa;
    else ref=ansb;    
    return ref;    
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d\n",&N); 
   map<string,int> M;
   M["+1"]=1;
   M["0"]=0;
   M["-1"]=-1;
   
   REP(i,N+4){
        G[i].clear();
        term[i]=INF;
        for(int k=0;k<2;k++)dp[i][k]=-INF;
   }   
   REP(t,N-1){
        scanf("%c",&name);
        if(name=='N'){
            scanf("%d\n",&x);
            G[x].push_back(t+2);
        }else{
            char buff[22];
            scanf("%d %s\n",&x,buff);
            term[t+2]=M[buff];
            //cout<<"4444 --- "<<term[t+2]<<endl;
            G[x].push_back(t+2);
        }
   }
   int ans=go(1,1);
   if(ans>0)printf("+%d\n",ans);
   else printf("%d\n",ans);       
   return 0;      
}
