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



int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   int N,tmp;
   vector<int> odd,even;
   scanf("%d",&N);
   REP(i,N){
      scanf("%d",&tmp);
      if(tmp&1)
        odd.push_back(tmp);
      else
        even.push_back(tmp);
   }
   sort(odd.rbegin(),odd.rend());
   sort(even.rbegin(),even.rend());
   N=min(odd.size(),even.size());
   int ans=0;
   REP(i,N)ans+=odd[i]+even[i];
   
   if(N==0 && odd.size()>0)ans+=odd[0];   
   
   printf("%d\n",ans);
       
   return 0;      
}
