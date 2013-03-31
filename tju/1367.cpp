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
int A[1005];
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int k,n,p,c;
    double ans;
    while(scanf("%d %d",&k,&n)==2){
      p=0;
      k++;
      REP(i,0,n){
         A[i]=p;
         p=(p+1)%k;
      }
      ans=0;
      c=0;
      REP(i,0,n){
         bool ok=1;
         if(i>0 && abs(A[i-1]-A[i])>1)ok=0;
         if(i<(n-1) && abs(A[i+1]-A[i])>1)ok=0;
         ans+=ok;
      }
      cout<<ans<<endl;
      if(n==1)ans=1;
      else
         ans=ans/(n);
      ans*=100.0;
      printf("%0.5f\n",ans);
      
    }  
    //system("pause");
    return 0;
}
