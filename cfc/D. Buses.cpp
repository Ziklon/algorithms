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
#define MOD 1000000007
using namespace std;
vector<pair<int,int> >v;
int n,m,x,y;
long long dp[100000+5];
long long go(int c){
    if(n==c)return 1;
    long long& ref=dp[c];
    if(ref!=-1)return ref;
    ref=0;
    REP(i,c+1,m+1)
      if(vis[i])
        ref+=go(i)%MOD;
    ref=ref%MOD;
    return ref;
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d %d",&n,&m);
    REP(i,0,100000+5){
      dp[i]=-1;
      vis[i]=0;
    }
    REP(i,0,m){
        scanf("%d %d",&x,&y);
        v.push_back(make_pair(x,y));
    }
    cout<<go(0)<<endl;
    //system("pause");
    return 0;
}
