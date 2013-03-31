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

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  long long a=10,b=10,dev=0;
  for(int i=0;b;i++){
  	cout<<a<<" "<<b<<endl;
  	if(b&1)
	  	dev+=a;
  	a<<=1;
  	b>>=1;
  }
  cout<<dev<<endl;
  cout<<(10*10)<<endl;

  system("pause");
  return 0;
}
