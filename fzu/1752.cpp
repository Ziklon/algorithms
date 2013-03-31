#include <vector>
#include <map>
#include <set>
#include <queue>
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
#define ull unsigned long long
#define sz size()
#define pb push_back
#define mp make_pair
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
ull a,b,m;

ull mul(ull a, ull b, ull m){
   ull dev=0,tmp=a%m;
   while(b){
		if(b&1)
			if((dev+=tmp)>=m)
				dev-=m;
	    if((tmp<<=1)>=m)
			tmp-=m;
	    b>>=1;
	}
	return dev;
}

ull fastExp(ull a, ull n, ull m){
	if(n==0)return 1;
	ull dev=fastExp(a,n>>1,m);
	dev=mul(dev,dev,m);
	if(n&1)
		dev=mul(dev,a,m);
	return dev;
}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(cin>>a>>b>>m){
    cout<<fastExp(a,b,m)<<endl;
  }

  return 0;
}
