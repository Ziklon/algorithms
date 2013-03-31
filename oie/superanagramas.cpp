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
string x,y;
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int dev=0;
  while(cin>>x>>y){
    vector<int>a(26,0);
    dev=0;
    for(int i=0;i<x.sz;i++)
    	a[x[i]-'a']++;
    for(int i=0;i<y.sz;i++)
    	a[y[i]-'a']--;
    for(int i=0;i<a.sz;i++)
		dev+=abs(a[i]);
	cout<<dev<<endl;    
  }

  return 0;
}
