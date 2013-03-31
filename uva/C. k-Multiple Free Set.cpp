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
#define MAXN 100005
int N,K,ans,tmp,val;

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d %d",&N,&K);
   ans=0;
   set<int> S; 
   REP(i,N){
       scanf("%d",&tmp);
       S.insert(tmp);
   }   
   while(S.size()){
        tmp=*(--S.end());
        int cnt=1;      
        while(S.count(tmp)){
            cnt++;
            S.erase(tmp);            
            if(tmp%K!=0)break;            
            tmp/=K;
            
        }        
        ans+=(cnt/2);
   }
   cout<<ans<<endl;     
   return 0;      
}
