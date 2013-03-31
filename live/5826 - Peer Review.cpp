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

int N,K;
int P[1<<10];

void make(int N){
    REP(i,N)P[i]=i;
}

int find(int u){
    if(P[u]==u)return u;
    return P[u]=find(P[u]);
}
void join(int u, int v){
    P[find(u)]=find(v);
}
char name[124];

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   int idx=0,tmp;    
   while(scanf("%d %d",&K,&N)==2){
        if(N==K && N==0)break;
        int ans=0;
        vector<set<int> >vs(N);
        REP(i,N){
            scanf("%s",name);
            REP(j,K){
                scanf("%d",&tmp);tmp--;
                if(tmp!=i)vs[i].insert(tmp);
            }
            scanf("\n");
        }
        REP(i,N)ans+=(K-vs[i].size());        
        if(ans==0)printf("NO PROBLEMS FOUND\n");
        else if(ans==1)printf("1 PROBLEM FOUND\n");
        else printf("%d PROBLEMS FOUND\n",ans);        
        
   }
   
   return 0;      
}
