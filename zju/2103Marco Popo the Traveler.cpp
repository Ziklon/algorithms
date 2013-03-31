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
#define INF 1000

short dp[1<<20][20];
int N,C,H,x,y,c;

vector<pair<int,pair<int,int> > > edges;


short mini(int a, int b){
    if(a<b)return a;
    return b;
}
short go(int mask, int last){
    if(__builtin_popcount(mask)==H)return 0;
    short& ref=dp[mask][last];
    if(ref!=-1)return ref;
    ref=INF;
    pair<int,pair<int,int> >cur=edges[last];
    
    REP(i,H){
        if(mask&(1<<i))continue;
        
        pair<int,pair<int,int> > to=edges[i];
        set<int> S;
        S.insert(to.second.first);
        S.insert(to.second.second);
        S.insert(cur.second.first);
        S.insert(cur.second.second);
        if(S.size()==3){
            short cc=0;
            if(cur.first!=to.first)cc++;
            ref=mini(ref,(go(mask|1<<i,i)+cc));            
        }        
    }
    return ref;    
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   while(scanf("%d %d %d",&N,&C,&H)==3){
        if(N==C&&C==H && N==0)break;
        edges.clear();
        REP(i,H){
            scanf("%d %d %d",&x,&y,&c);
            edges.push_back(make_pair(c,make_pair(x,y)));
        }
        short ans=INF;
        memset(dp,-1,sizeof dp);
        
        REP(i,H)ans=min(ans,go(1<<i,i));
        
        if(ans>=INF)printf("No\n");
        else printf("%d\n",ans); 
                           
   }
   return 0;      
}
