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
  int S,N,ax,dev;
  cin>>S>>N;
  vector<int> v(N);
  for(int i=0;i<N;i++)
  	cin>>v[i];
  sort(all(v));
  ax=v[0]+v[1];
  dev=0;
  for(int i=2;i<N;i++)
  	if(ax+v[i]<=S)
  		dev++;
  if(ax+v[2]<=S)
  	  dev+=2;
  cout<<dev<<endl;
  return 0;
}
