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
int a,b,x,y,n;
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(cin>>a>>b){
	  cin>>n;
	  bool ok=0;
	  int dev=1<<30;
	  while(n--){
		 cin>>x>>y;
		 if((x>=a && y>=b)|| (x>=b && y>=a)){
		 	dev=min(dev,x*y);
		 	ok=1;
		}
	  }
	  if(ok)cout<<dev<<endl;
	  else cout<<-1<<endl;
	}
  return 0;
}
