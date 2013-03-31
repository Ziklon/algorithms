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
   string binNum="";
   cin>>binNum;
   int ans=0;
   int p=binNum.find_last_of("1");
   if(p==0)
    ans=binNum.sz-1;
   else{
    ans=binNum.sz+1;
    ans+=count(binNum.begin(),binNum.begin()+p,'0');
   }
    cout<<ans<<endl;
   system("pause");
   return 0;
}
