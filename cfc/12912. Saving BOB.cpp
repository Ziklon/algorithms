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

int T,N,K;

vector<int> G[10];

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   
   
   
   
   REP(t,T){
        scanf("%d %d",&N,&K);        
        REP(i,10){
            G[i].clear();
            REP(j,10){
                if(i==j)continue;
                if(abs(i-j)>=K)
                    G[i].push_back(j);
            }
        }
        cout<<endl<<endl;
        
        REP(i,10){
            cout<<i<<endl;
            
            REP(j,G[i].size())cout<<G[i][j]<<" ";            
            cout<<endl;
            
        } 
                     
   }
   return 0;      
}
