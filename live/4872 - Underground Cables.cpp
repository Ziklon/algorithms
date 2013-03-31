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
#define MAXN 1003
int N,x,y;
int A[MAXN],B[MAXN],P[MAXN];
double cost,ans;
void make(int N){
   REP(i,N)P[i]=i;     
}
int find(int u){
    if(P[u]==u)return u;
    return P[u]=find(P[u]);
}
int join(int u, int v){
    P[find(u)]=find(v);
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   while(scanf("%d",&N)==1 && N){
        
        REP(i,N)scanf("%d %d",A+i,B+i);
        
        vector<pair<double,pair<int,int> > > v;
        for(int i=0;i<N;i++)for(int j=i+1;j<N;j++){
            cost=hypot(A[i]-A[j],B[i]-B[j]);
            v.push_back(make_pair(cost,make_pair(i,j)));            
        }
        sort(v.begin(),v.end());
        ans=0;
        make(N);
        
        for(int i=0;i<v.size();i++){
            cost=v[i].first;
            x=v[i].second.first;
            y=v[i].second.second;
            if(find(x)!=find(y)){
                join(x,y);
                ans+=cost;
            }            
        }
        printf("%.2f\n",ans);  
    
   }
   return 0;      
}
