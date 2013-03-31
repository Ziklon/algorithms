#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
long long gn(long long num, long long di){
   int tot=num/di;
   int k=di;
   while(di<num){
      di=di*k;
      tot+=(num/di);
   }
   return tot;
   
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,K;
    scanf("%d\n",&T);
    REP(i,0,T){
      scanf("%d\n",&K);
      cout<<min(gn(K,5),gn(K,2))<<endl;
    }  
    //system("pause");
    return 0;
}
