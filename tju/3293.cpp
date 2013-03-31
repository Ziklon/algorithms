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
#define sz size()
#define pb push_back
#define mp make_pair
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
long long a,b,c,x,dev;

long long fastExp(long long a, long long n){
	if(n==0)return 1;
	long long dev=fastExp(a,n/2)%200907;
	dev=(dev*dev)%200907;
	if(n&1)
		dev=dev*a;
	return dev%200907;
}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n;
  scanf("%d\n",&n);
  while(n--){
  	scanf("%lld %lld %lld %lld\n",&a,&b,&c,&x);
  	if(a-b==b-c)
  		dev=((a%200907)+((x-1)%200907)*((b-a)%200907))%200907;
  	else{
		dev=a*fastExp(b/a,x-1);
	}
	cout<<(dev%200907)<<endl;
  }


  return 0;
}
