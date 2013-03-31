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
string cads[102];
char buff[1024];
bool ok(int& N, string a){
   string b=a;
   reverse(all(b));
   REP(i,1,N)
      if(cads[i].find(a)==-1 && cads[i].find(b)==-1)
         return 0;
   return 1;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,N,M,ans;
    scanf("%d\n",&T);
    REP(i,0,T){
      scanf("%d\n",&N);
      REP(j,0,N){
         scanf("%s\n",buff);
         cads[j]=buff;
      }
      ans=0;
      M=cads[0].sz;
      for(int j=M;j>=1 && ans==0;j--){
         for(int k=0;k+j<=M && ans==0;k++){
            if(ok(N,cads[0].substr(k,j)))
               ans=j;
         }
      }
      printf("%d\n",ans);
      
    }  
    //system("pause");
    return 0;
}
