/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
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
#define fill(x,i) memset(x,i,sizeof(x))
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;
#define MAX 42768
bool A[MAX];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    fill(A,1);
    A[0]=0;
    A[1]=0;
    for(int i=2;i*i<=MAX;i++)
      if(A[i])
        for(int j=2*i;j<MAX;j+=i)
          A[j]=0;
    vector<int> prime;
    REP(i,2,MAX)
      if(A[i])
        prime.push_back(i);
    int n,ans,x;
    while(scanf("%d",&n)==1 && n){
        ans=0;
        REP(i,0,prime.sz){
          x=n-prime[i];
          if(x<0)break;
          if(binary_search(all(prime),x))
            ans++;          
        }
        if(A[n/2])ans++;
        printf("%d\n",ans/2);
    }
     
    //system("pause");
    return 0;
}
