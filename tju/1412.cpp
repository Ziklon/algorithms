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
#define REP(i, a) FOR(i, 0, a)
#define GI ({int _t; scanf("%d", &_t); _t;})
#define DBGV(_v) { REP(_i, _v.size()) { cout << _v[_i] << "\t";} cout << endl;}
using namespace std;

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int n=GI,k,x;
  double dev;
  while(n--){
  	 k=GI;
  	 dev=0;
  	 for(int i=0;i<k;i++){
		x=GI;
		dev+=x*0.9;		
	 }
	 dev=dev/k;
	 printf("%0.3f\n",dev);
  } 
  return 0;
}
