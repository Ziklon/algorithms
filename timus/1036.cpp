/*
ID: winftc2
PROG: milk
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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int dp[52][1005];

int go(int p, int s){
  if(s<0)return 0;
  if(p==0){
    if(s==0)return 1;
    return 0;
  }
  int& ref=dp[p][s];
  if(ref!=-1)return ref;
  ref=0;
  for(int i=0;i<10;i++){
    ref+=go(p-1,s-i);
  }
  return ref;
  
}

int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
    int N,S;
    cin>>N>>S;
    fill(dp,-1);
    cout<<go(N,S)<<endl;
   system("pause");
   return 0;
}
