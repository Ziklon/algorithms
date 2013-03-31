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

int P[1<<7];
int N,M,T,val;

int find(int u){
 if(u == P[u]) 
      return u;
 else 
    return P[u]=find(P[u]);
}

void join(int a, int b){
   P[find(a)] = find(b);
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif   
   scanf("%d %d",&N,&M);
   vector<set<int> > vs(N);
   
   REP(i,1<<7)P[i]=i;
   int ans=0;
   REP(i,N){       
       scanf("%d",&T); 
       if(T==0)ans++;       
       REP(j,T){
          scanf("%d",&val);
          vs[i].insert(val);
       }
   }
   REP(i,N)REP(j,N){
       int ii=find(i);
       int jj=find(j);
       if(jj==ii)continue;
       if(vs[ii].size()==0 || vs[jj].size()==0)continue;
       vector<int> vi(vs[ii].begin(),vs[ii].end());       
       REP(k,vi.size()){                      
          if(vs[jj].count(vi[k])!=0){
             join(ii,jj);
             int root=find(ii);
             vs[root].insert(vs[ii].begin(),vs[ii].end());             
             vs[root].insert(vs[jj].begin(),vs[jj].end());
          }  
       }                
   }
      
   set<int> si;   
   REP(i,N)if(vs[i].size()>0)si.insert(find(i));
   if(si.size()>1)ans+=(si.size()-1);
   cout<<ans<<endl;   
   return 0;      
}
