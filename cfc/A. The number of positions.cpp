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

int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
    int n,a,b,ans,x;
    cin>>n>>a>>b;
    ans=b+1;
    if(a+b>=n){
      ans-=((a+b+1)-n);
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
